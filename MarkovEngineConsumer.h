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
#include <boost/algorithm/string.hpp>
#include "Meter.h"
#include "Helper.h"
#include "SynchronizedQueue.h"
#include "VOMC.h"
#include "Metronome.h"
#include "Rhythm_automata.h"
#include <exception>
using namespace std;
using namespace boost::algorithm;

class MarkovEngineConsumer {
public:
    int voice_to_pitch(int i_voice);
    MarkovEngineConsumer();
    // Constructor with id and the queue to use.
    MarkovEngineConsumer(SynchronizedQueue<Meter>* queue, double tempo, double offset, int A, double metronome_start, double meter_start, Helper *h);
    // The thread function reads data from the queue
    void operator () ();
    void load_files();
    int get_position_in_letter(int i_position_in_pattern, vector<Letter> *l);
    int get_letter_that_corresponds_to_possition_voice_combination(int position, int voice, vector<Letter> *v_letters);
    void test_ra(Rhythm_automata *ra);
    SynchronizedQueue<Meter>* m_queue; // The queue to use
    State convert_bool_to_state(vector<Letter> *l, bool **rhythm);
    string rtrim(string s);
    Meter init_test_meter();
    int get_size_of_pattern_for_all_letters_of_voice(int voice, vector<Letter> *ll);
    ~MarkovEngineConsumer();
private:
    VOMC vomc;
    int meter_length_in_qn;
    Helper* helper;
    vector<RawNote> rNotes;
    double tempo;
    double offset;
    double qn_duration;
    double meter_duration;
    double metronome_start;
    double meter_start;
    vector<Meter> v_test_meter;
    Metronome *m;
};

#endif	/* MARKOVENGINECONSUMER_H */

