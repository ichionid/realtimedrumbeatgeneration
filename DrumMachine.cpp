
/* 
 * File:   DrumMachine.cpp
 * Author: Ioannis Chionidis
 * 
 * Created on August 18, 2012, 6:32 PM
 */

#include "DrumMachine.h"
#include "include/MidiFileIn.h"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include "include/RtMidi.h"
#include <map>
#include "include/Stk.h"

using namespace stk;

/**
 * 
 * @param filename is a <code>string</code> representing the input file name.
 * @param queue is a <code>SynchronizedQueue<Meter>*</code> which 
 * communicates <code>Meter</code> objects among either <code>DrumMachine</code> or 
 * <code>MidiHandlerProducer</code> objects with <code>MarkovEngineConsumer</code> Objects.
 * @param tempo is <code>double</code> representing the simulation's tempo.
 * @param offset is <code>double</code> representing the timing offset not needed in the DrumMachine.
 * @param A is <code>double</code> representing the number of quarter notes per <code>Meter</code>.
 * @param metronome_start is <code>double</code> representing the start of the metronome.
 * @param meter_start is <code>double</code> representing the start of the meter.
 */
DrumMachine::DrumMachine(string filename, SynchronizedQueue<Meter>* queue, double tempo, double offset, double A, double metronome_start, double meter_start) {
    cout << "DrumMachine constructor::" << filename << endl;
    drum_machine_ready = false;
    m_queue = queue;
    this->m_queue = queue;
    this->tempo = tempo;
    this->offset = offset; //should be zero in drum machine!     
    this->qn_duration = 60000 / tempo;
    this->meter_duration = A * this->qn_duration;
    this->metronome_start = metronome_start;
    this->meter_start = meter_start;
    raw_note_groups = new vector < vector <RawNote> > ();
    //holds the ticks per quarter note
    double eighth_note_division;

    //  Read the files in a temporary data structure which will then
    MidiFileIn m(filename);
    if (m.getDivision()&0x8000) {
        cout << "frames per second" << endl;
    } else {
        eighth_note_division = (1 / m.getTickSeconds()) / 4;
        cout << "ticks per 8th" << eighth_note_division << endl;
    }
    vector<unsigned char>* midiEvent;
    midiEvent = new vector<unsigned char>();

    unsigned long time;
    bool started = false;
    int channel = 0;
    //load midi file to note->groups
    vector<RawNote> map_rawnotes_delta;
    int accumulate_ticks = 0;
    while (true) {
        //get event
        time = m.getNextMidiEvent(midiEvent, channel);
        if (!midiEvent->empty()) {
            //check if it is an onset
            if (int(midiEvent->at(0)) == 137) {
                //event is a NOTE OFF. We need to register
                //the timing of the event
                accumulate_ticks += time;
            } else if (int(midiEvent->at(0)) == 153) {
                //it is a NOTE ON, we register the note and increase timing
                started = true;
                //increase accumulated ticks
                if ((accumulate_ticks + time >= eighth_note_division)) {
                    //push previous letter
                    cout << "New 8th NOTE" << endl;
                    raw_note_groups->push_back(map_rawnotes_delta);
                    //add rest
                    int number_of_rests = floor((accumulate_ticks + time) / eighth_note_division) - 1; //CHECK THIS
                    accumulate_ticks += time;
                    map_rawnotes_delta.clear();
                    //push back the appropriate amount of rests
                    for (int i = 0; i < number_of_rests; i++) {
                        raw_note_groups->push_back(map_rawnotes_delta);
                    }
                    cout << "add note with accumulated ticks::" << accumulate_ticks << endl;
                    cout << "eighth_note_division::" << eighth_note_division << endl;
                    cout << "fmod::" << fmod(double(accumulate_ticks), double(eighth_note_division)) << endl;
                    cout << "ALL::" << fmod(double(accumulate_ticks), double(eighth_note_division)) / double(eighth_note_division) << endl;
                    map_rawnotes_delta.
                            push_back(
                            RawNote(0,
                            0,
                            fmod(double(accumulate_ticks), double(eighth_note_division)) / double(eighth_note_division),
                            midiEvent->at(1),
                            midiEvent->at(2)
                            ));

                    accumulate_ticks = fmod(double(accumulate_ticks), double(eighth_note_division));
                } else {
                    //create note and add it to group
                    accumulate_ticks += time;
                    //        cout << "note pushed" << endl;
                    cout << "add note with accumulated ticks::" << accumulate_ticks << endl;
                    cout << "eighth_note_division::" << eighth_note_division << endl;
                    cout << "fmod::" << fmod(double(accumulate_ticks), double(eighth_note_division)) << endl;
                    cout << "ALL::" << fmod(double(accumulate_ticks), double(eighth_note_division)) / double(eighth_note_division) << endl;
                    map_rawnotes_delta.
                            push_back(
                            RawNote(0,
                            0,
                            fmod(double(accumulate_ticks), double(eighth_note_division)) / double(eighth_note_division),
                            midiEvent->at(1),
                            midiEvent->at(2)
                            ));
                    //          cout << "note pushεδ2" << endl;

                }
            }
        } else {
            //skim through channels to find notes
            if ((channel < (m.getNumberOfTracks() - 1)) && (!started)) {
                channel++;
            } else {
                break;
            }
        }
    }
    if (!map_rawnotes_delta.empty()) {
        raw_note_groups->push_back(map_rawnotes_delta);
    }

    //cout << "Number of 8th notes loaded:" << raw_note_groups->size() << endl;
    if (raw_note_groups->size() == 0) {
        throw "no input from .mid found";
    }

    for (int i = 0; i < raw_note_groups->size(); i++) {
        for (int j = 0; j < raw_note_groups->at(i).size(); j++) {
            cout << "Note" << endl;
            cout << raw_note_groups->at(i).at(j).GetEighthNoteTimeStamp() << endl;
            cout << raw_note_groups->at(i).at(j).GetPitch() << endl;
        }
    }
    drum_machine_ready = true;
    cout << "Get out!!!" << endl;
}

void DrumMachine::operator () () {
    cout << "1.DrumMachine::Waiting" << endl;

    while ((!drum_machine_ready) && (boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds() <= meter_start)) {
        ;
    }
    ////cout << "2.DrumMachine::Markov is recording the Drum Machine!!" << endl;
    vector<RawNote> vector_rn;
    double accumulated_letter_time_offset = 0; //points to the next letter
    //raw_note_groups->size()
    for (int i = 0; i < raw_note_groups->size(); i++) {
        //Letters::GroupOfNotes
        vector_rn = raw_note_groups->at(i);
        for (int j = 0; j < vector_rn.size(); j++) {
            vector_rn.at(j).SetEighthNoteTimeStamp(
                    vector_rn.at(j).GetEighthNoteTimeStamp() * double(qn_duration / 2)
                    );
            vector_rn.at(j).SetGeneralTimeStamp(
                    meter_start + accumulated_letter_time_offset +
                    vector_rn.at(j).GetEighthNoteTimeStamp()
                    );
            vector_rn.at(j).SetLimitedTimeStamp(
                    meter_start + accumulated_letter_time_offset +
                    vector_rn.at(j).GetEighthNoteTimeStamp()
                    );
            meter.add_note(vector_rn.at(j));
        }
        if (accumulated_letter_time_offset == (3.5 * qn_duration)) {
            accumulated_letter_time_offset = 0;
            //////cout << "New meter to be sent!" << endl;
            while ((boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds()) < (meter_duration + meter_start))
                ;
            ////cout << meter_start << endl;
            //wait and go!
            meter_start += meter_duration;
            //copy meter
            //////cout << "ENQUE meter::" << meter.get_notes().size() << endl;
            m_queue->Enqueue(meter);
            //clear meter to add new notes
            meter.delete_notes();
        } else {
            accumulated_letter_time_offset += (qn_duration / 2);
        }
    }
    m_queue->Enqueue(meter); //send a packet of empty meter to signal the end!
    ////cout << "End of DrumMachineThread" << endl;
}

DrumMachine::~DrumMachine() {
    cout << "DrumMachine destructor" << endl;
}