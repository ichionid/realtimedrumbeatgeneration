/* 
 * File:   MidiHandler.h
 * Author: Ioannis Chionidis
 *
 * Created on June 2, 2012, 11:12 AM
 */
#ifndef MIDIHANDLERPRODUCER_H
#define	MIDIHANDLERPRODUCER_H

#include <iostream>
#include <vector>
#include "Meter.h"
#include "Helper.h"
#include "Metronome.h"
#include "Letter.h"

using namespace std;

class MidiHandlerProducer {
public:
    MidiHandlerProducer(SynchronizedQueue<Meter>* queue, double tempo, double offset, double A, double metronome_start, double meter_start, Helper *h, Metronome *m);
    //void mycallback( double deltatime, std::vector< unsigned char > *message, void *userData );
    virtual ~MidiHandlerProducer();
    //    void Run();
    void operator () ();
    SynchronizedQueue<Meter>* m_queue; // The queue to use
    double calculate_average();
private:
    Metronome* m;
    vector<long> timeDisperion;
    Helper h;
    Meter meter;
    double tempo;
    double offset;
    double qn_duration;
    double eighth_note_duration;
    double meter_duration;
    int meter_length_in_qn;
    double metronome_start;
    double meter_start;
};

#endif	/* MIDIHANDLER_H */

