
/* 
 * File:   MidiHandlerProducer.cpp
 * Implements the producer of the model
 * Author: Ioannis Chionidis
 * 
 * Created on June 2, 2012, 11:12 AM
 */
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "SynchronizedQueue.h"
#include "MidiHandlerProducer.h"
#include <RtMidi.h>
#include "RawNote.h"
#include "Metronome.h"
#include "Helper.h"
using namespace std;
bool midiHandler_done;

static void midiHandler_finish(int ignore) {
    midiHandler_done = true;
}

//meter: A/B, where B =4. Everything will be expressed in Quarter Notes
//So in order to express 7/8 we put A=3.5
/**
 * 
 *@param queue, is a <code>SynchronizedQueue<Meter>*</code> which 
 * communicates <code>Meter</code> objects among either <code>DrumMachine</code> or 
 * <code>MidiHandlerProducer</code> objects with <code>MarkovEngineConsumer</code> Objects.
 * @param tempo, is <code>double</code> representing the simulation's tempo.
 * @param offset, is <code>double</code> representing the timing offset not needed in the DrumMachine.
 * @param A, is <code>double</code> representing the number of quarter notes per <code>Meter</code>.
 * @param metronome_start, is <code>double</code> representing the start of the metronome.
 * @param meter_start, is <code>double</code> representing the start of the meter.
 * @param h, is <code>Helper *</code>.
 * @param m, is <code>Metronome *</code>.
 */
MidiHandlerProducer::MidiHandlerProducer(SynchronizedQueue<Meter>* queue, double tempo, double offset, double A, double metronome_start, double meter_start, Helper *h, Metronome *m) {
    //cout << "MidiHandlerProducer constructor" << endl;
    m_queue = queue;
    this->m_queue = queue;
    this->tempo = tempo;
    this->offset = offset;
    this->qn_duration = ceil(60000 / tempo);
    this->eighth_note_duration = ceil(60000 / (2 * tempo));
    this->meter_duration = ceil(((double) A) * this->qn_duration);
    this->metronome_start = metronome_start;
    this->meter_start = meter_start;
    this->h = *h;
    this->m = m;
    //cout << "*************MIDIHANDLER INIT***********************" << endl;
    //cout << "QnDuration::" << this->qn_duration << endl;
    //cout << "MeterDuration::" << this->meter_duration << endl;
    //cout << "MetronomeStart::" << this->metronome_start << endl;
    //cout << "MeterStart::" << this->meter_start << endl;
    //cout << "*************MIDIHANDLER INITed***********************" << endl;

}

void MidiHandlerProducer::operator () () {
    RtMidiIn *midiin = new RtMidiIn();
    vector<unsigned char> message;
    int nBytes;
    double stamp;
    bool done = false;
    unsigned int nPorts = midiin->getPortCount();
    if (nPorts == 0) {
        //cout << "No ports available!\n";
        delete midiin;
        throw "No ports available!\n";
    }

    //h.wait(NMTTBSIS * this->qn_duration); //4/4
    for (int i = 0; i < NMTT_W + NMTTBSIS; i++) {
        /*if (i != (NMTT_W + NMTTBSIS - 1)) {
            //cout << "midiHandlerPRODUCER::InActive Tick::" << i << endl;
        } else if (i != (NMTT_W + NMTTBSIS - 1)) {
            //cout << "midiHandlerPRODUCER::PRE-LAST InActive Tick::" << i << endl;
        } else {
            //cout << "midiHandlerPRODUCER::LAST InActive Tick::" << i << endl;
        }*/
        while (boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds()
                < (m->GetStartTime() + this->qn_duration * i));
    }
    //cout << "1.Start CALIBRATION" << endl;
    long time_stamp = 0;
    double timeDiff = 0;

    //Configure MIDI
    midiin->openPort(1);
    midiHandler_done = false;
    (void) signal(SIGINT, midiHandler_finish);

    long t_offset = (NMTTBSIS + NMTT_C + NMTT_W) * m->GetQnDuration() + m->GetStartTime();
    while (boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds() < t_offset) {
        midiin->getMessage(&message);
        time_stamp = boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds();
        nBytes = message.size();
        if (nBytes > 2) {
            timeDiff = fmod(boost::lexical_cast<double>(time_stamp - m->GetStartTime()), boost::lexical_cast<double>(m->GetQnDuration())); //check how much it varies from the starting one
            if (((int) message.at(2) != 0) && ((int) message.at(1) == 34)) {
                timeDiff = fmod(boost::lexical_cast<double>(time_stamp - m->GetStartTime()), boost::lexical_cast<double>(m->GetQnDuration())); //check how much it varies from the starting one
                if (timeDiff > (m->GetQnDuration() / 2)) {//before onset
                    //cout << "Inside TimeDiff =" << timeDiff << endl;
                    timeDisperion.push_back(m->GetQnDuration() - timeDiff); //should be negative

                } else {//after onset

                    timeDisperion.push_back(timeDiff);

                }
            }
        }
    }
    //cout << "2. Finished CALIBRATION" << endl;
    ////cout << "Ticks from start::" << (boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds() - m->GetStartTime()) / m->GetQnDuration() << endl;

    for (int i = 0; i < timeDisperion.size(); i++) {
        //cout << timeDisperion.at(i) << endl;
    }
    double tStart_calculate_average = boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds();
    double metronome_offset = this->calculate_average();
    m->SetOffset(metronome_offset);
    double time_difference_calc_average = boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds() - tStart_calculate_average;
    ////cout << "Time to calculate average::" << time_difference_calc_average;
    long time_left = ((NMTTBSIS + NMTT_C + NMTT_W + 1) * m->GetStartTime())
            - boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds();
    ////cout << "Time Left until the next Qn::" << time_left << endl;
    //1meter_start = m->GetStartTime() + this->qn_duration * (NMTT_W + NMTT_C + NMTTBSIS);
    //cout << "Offset::" << m->GetOffset() << endl;
    //cout << "Offset::" << metronome_offset << endl;
    unsigned char noteOn = 144;
    try {
        while (!done) {
            double generalTimeStamp = boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds();
            stamp = midiin->getMessage(&message);
            nBytes = message.size();
            if (message.size() > 2) {
                unsigned char masked = (message.at(0) & (noteOn));
                if ((masked == noteOn)) {
                    if (((int) message.at(2) != 0) && (((int) message.at(1) == cr)
                            || ((int) message.at(1) == hh1)
                            || ((int) message.at(1) == hh2)
                            || ((int) message.at(1) == t1)
                            || ((int) message.at(1) == lt)
                            || ((int) message.at(1) == bd)
                            || ((int) message.at(1) == sn)
                            )) {
                        ////cout << "MidiHandler.pitch::" << (int) message.at(1) << endl;
                        ////cout << "the MidiHandler.velocity::" << (int) message.at(2) << endl;
                        meter.add_note(RawNote(stamp - metronome_offset, generalTimeStamp - metronome_offset, fmod(generalTimeStamp - meter_start - metronome_offset, eighth_note_duration), (int) message[1], (int) message[2]));
                    }
                }
            }
            if ((boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds() - meter_start - metronome_offset) >= meter_duration) {
                //cout << "MidiHandlerProducer::" << fixed << meter_start << endl;
                meter_start += meter_duration;
                //copy meter
                ////cout<<"MidiHandlerProducer::Send Data.size()="<< meter.get_notes().size()<<endl;
                m_queue->Enqueue(meter);
                //clear meter to add new notes
                //cout << "MarkovEngine::TX.size()::" << meter.get_notes().size() << endl;
                meter.delete_notes();
                ////cout << "MidiHandlerProducer::Parse next meter with basis meter_start::" << meter_start << endl;
            }
        }
    } catch (...) {

        //cout << endl << "MidiHandler EXCEPTION" << endl;
        throw "MidiHandlerProducer";
    }
}
/**
 * 
 * @return is a <code>double</code> representing the calculation of the
 * average of the internal timing vector. Used only inside this class.
 */
double MidiHandlerProducer::calculate_average() {

    long average = 0, newAverage = 0;
    long deviationA1 = 0, deviation = 0;
    for (int i = 0; i < timeDisperion.size(); i++) {
        average += timeDisperion.at(i);
        deviationA1 += pow(timeDisperion.at(i), 2);
    }

    average = average / timeDisperion.size();
    deviationA1 = deviationA1 / timeDisperion.size();
    deviation = sqrt(deviationA1 - pow(average, 2));
    for (int i = 0; i < timeDisperion.size(); i++) {
        if (abs(average - timeDisperion.at(i))<(2 * deviation)) {
            newAverage += timeDisperion.at(i);
        }
    }
    return newAverage = newAverage / timeDisperion.size();
}

MidiHandlerProducer::~MidiHandlerProducer() {
    //cout << "MidiHandlerProducer destructor";
}