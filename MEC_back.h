/* 
 * File:   MarkovEngineConsumer.h
 * Author: puppy
 *
 * Created on June 4, 2012, 11:35 PM
 */

#ifndef MARKOVENGINECONSUMER_H
#define	MARKOVENGINECONSUMER_H
#include <iostream>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/date_time.hpp>
#include "Meter.h"
#include "SynchronizedQueue.h"
#include "Rhythm_automata.h"
#include "Meter.h"
#include "VOMC.h"
#include <exception>
#define drum_voices 5
using namespace std;

class MarkovEngineConsumer {
public:
    //MarkovEngineConsumer();
    MarkovEngineConsumer(SynchronizedQueue<Meter>* queue, double tempo, double offset, double A, double metronome_start, double meter_start);
    // The thread function reads data from the queue
    void operator () ();
    SynchronizedQueue<Meter>* m_queue; // The queue to use
    ~MarkovEngineConsumer();

private:

    State convert_bool_to_state(vector<Letter> *l, bool **rhythm);
    VOMC vomc;
    vector<RawNote> rNotes;
    double tempo;
    double offset;
    double qn_duration;
    double meter_duration;
    double metronome_start;
    double meter_start;
};

#endif	/* MARKOVENGINECONSUMER_H */

