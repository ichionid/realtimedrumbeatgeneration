/* 
 * File:   DrumMachine.h
 * Author: puppy
 *
 * Created on August 18, 2012, 6:32 PM
 */

#ifndef DRUMMACHINE_H
#define	DRUMMACHINE_H
#include <iostream>
#include <vector>
#include <fstream>
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
#include "Meter.h"
#include <vector>

using namespace std;

class DrumMachine {
public:
    DrumMachine(string filename,  SynchronizedQueue<Meter>* queue, double tempo, double offset,double A,double metronome_start,double meter_start);
    ~DrumMachine();
    void print_header();
    void parse_input_file_to_states();
    void operator () ();
    SynchronizedQueue<Meter>* m_queue;		// The queue to use
    Metronome* m;
    std::vector<char> *f;
    bool drum_machine_ready;
    //int is the proportion that multiplied by qn/2 will give us
    //the posiion inside the eighth note
    vector < vector <RawNote> > *raw_note_groups;

private :
    
    Meter meter;
    double tempo;
    double offset;
    double qn_duration;
    double meter_duration;  
    double metronome_start;
    double meter_start;
};

#endif	/* DRUMMACHINE_H */

