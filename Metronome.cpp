/* 
 * File:   Metronome.cpp
 * Author: Ioannis Chionidis
 * 
 * Created on June 9, 2012, 7:22 PM
 */

#include "Metronome.h"

// Platform-dependent sleep routines.
#if defined(__WINDOWS_MM__)
#include <windows.h>
#define SLEEP( milliseconds ) Sleep( (DWORD) milliseconds ) 
#else // Unix variants
#include <unistd.h>
#define SLEEP( milliseconds ) usleep( (unsigned long) (milliseconds * 1000.0) )
#endif

Metronome::Metronome() {
    cout << "Metronomeless instance" << endl;
    this->startTimeReady = false;
}
/**
 * 
 * @param tempo, is a <code>double</code>.
 */
Metronome::Metronome(double tempo) {
    this->startTimeReady = false;
    this->startTime = boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds();
    std::cout << "Metronome Constructor" << std::endl;
    this->tempo = tempo;
    this->QnDuration = ceil(60000 / tempo);
    cout<<"*************METRONOME INIT***********************"<<endl;
    std::cout << "Tempo" << this->tempo << std::endl;
    std::cout << "QnDuration" << this->QnDuration << std::endl;
    cout << "Metronome Initial start Time::" << startTime << endl;
    id++;
}
/**
 * @return A <code>double</code> representing the tempo of the metronome
 */
double Metronome::GetTempo() const {
    return tempo;
}
/**
 * 
 * @param tempo, a <code>double</code> representing the tempo of the metronome
 */
void Metronome::SetTempo(double tempo) {
    this->tempo = tempo;
}

void Metronome::operator () () {
    RtMidiOut *midiout = new RtMidiOut();
    std::vector<unsigned char> message;
    midiout->openVirtualPort();
    // Check available ports.
    std::string portName;
    double onTime = this->QnDuration / 2;

    unsigned int nPorts = midiout->getPortCount();

    if (nPorts == 0) {
        std::cout << "No ports available!\n";
        return;
    }

    std::cout << "\nThere are " << nPorts << " MIDI output ports available.\n";

    for (unsigned int i = 0; i < nPorts; i++) {
        try {
            portName = midiout->getPortName(i);
        } catch (RtError &error) {
            error.printMessage();
            return;
        }
        std::cout << "  Output Port #" << i + 1 << ": " << portName << '\n';
    }
    std::cout << '\n';
    // Open first available port.
    midiout->openPort(3);

    // Program change: 192, 5
    message.push_back(192);
    message.push_back(5);
    midiout->sendMessage(&message);

    SLEEP(5);

    message[0] = 0xF1;
    message[1] = 60;
    midiout->sendMessage(&message);

    // Control Change: 176, 7, 100 (volume)
    message[0] = 176;
    message[1] = 7;
    message.push_back(100);
    midiout->sendMessage(&message);

    // Timestamp of Metronome
    /*cout<<"started:"<<t1.time_of_day().total_milliseconds()<<endl;
    this->startTime = t1.time_of_day().total_milliseconds();
    cout<<"started:"<<this->startTime<<endl;
     */
    //Time tNew(boost::posix_time::microsec_clock::local_time());
    //cout << "BEFORE::METRONOME ::startTime::" << startTime << endl;
    //this->startTime = boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds();
    //cout << "RENIEW::METRONOME ::startTime::" << startTime << endl;
    //startTimeReady = true;
    //This should loop every Qn
    int cnt = 0;
    int max_cnt = (NMTTBSIS + NMTT_W + NMTT_C) - 1; //11
    bool calibration_ended = false;
    for (;;) {
        //cout<<"Metronome::"<<cnt++<<endl;
        //cout<<"Loop:"<<"="<< boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds()-startTime<<endl;   
        //double startTime = boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds();
        // Note On: 144, 64, 90
        message[0] = 144;
        message[1] = 64;
        message[2] = 90;
        midiout->sendMessage(&message);

        if (calibration_ended) {
            if (cnt >= 4) {
                cnt = 0;
            }
            cout << "Metronome[" << cnt << "]" << endl;
        } else {
            if (cnt >= (NMTTBSIS + NMTT_W + NMTT_C) - 1) {
                calibration_ended = true;
            } else {
                if (max_cnt != 0) {
                    cout << "Metronome::Meter left:" << max_cnt-- << endl;
                } else {
                    cout << "Metronome::You're off no the Next Click!!" << endl;
                }
            }
        }
        cnt++;

        SLEEP(onTime / 2);

        // Note Off: 128, 64, 40
        message[0] = 128;
        message[1] = 64;
        message[2] = 40;
        midiout->sendMessage(&message);
        while ((boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds() - startTime) < QnDuration / 2) {
            ;
        }
        message[0] = 144;
        message[1] = 64;
        message[2] = 50;
        midiout->sendMessage(&message);

        SLEEP(onTime / 2);

        // Note Off: 128, 64, 40
        message[0] = 128;
        message[1] = 64;
        message[2] = 40;
        midiout->sendMessage(&message);

        //cout<<"QnDuration="<<QnDuration<<endl;
        while ((boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds() - startTime) < QnDuration) {
            ;
        }
        cout << "Metronome::" << startTime << endl;
        startTime += QnDuration; //so the the loop is statically related to first normalization
    }
    // Clean up
cleanup:
    delete midiout;

}

Metronome::~Metronome() {
    std::cout << "Metronome Destructor" << std::endl;
}
/**
 * 
 * @return A <code>double</code> representing the offset
 *      calculated by the calibration.
 */
double Metronome::GetOffset() const {
    return offset;
}
/**
 * 
 * @param offset, is a <code>double</code> representing the offset
 *      calculated by the calibration.
 */
void Metronome::SetOffset(double offset) {
    this->offset = offset;
}
/**
 * 
 * @return A <code>double</code> representing the start time of the
 *      metronome.
 */
double Metronome::GetStartTime()const {
    return startTime;
}
/**
 * 
 * @param startTime, is a <code>double</code> representing the start time of the
 *      metronome.
 */
void Metronome::SetStartTime(double startTime) {
    cout << "Metronome::SetStartTime::" << startTime << endl;
    this->startTime = startTime;
}
/**
 * 
 * @return is a <code>bool</code> signaling if the start time has been set.
 */
bool Metronome::GetStartTimeReady()const {
    return this->startTimeReady;
}
/**
 * @param startTimeReady, is a <code>bool</code> signaling if the start 
 * time has been set.
 */
void Metronome::SetStartTimeReady(bool startTimeReady) {
    this->startTimeReady = startTimeReady;
}
/**
 * 
 * @return is a <code>double</code> representing the quarter note duration
 */
double Metronome::GetQnDuration() const {
    return QnDuration;
}
/**
 * @param QnDuration, is a <code>double</code> 
 * representing the quarter note duration
 */
void Metronome::SetQnDuration(double QnDuration) {
    this->QnDuration = QnDuration;
}

