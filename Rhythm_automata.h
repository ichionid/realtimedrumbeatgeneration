/* 
 * File:   rhythm_automata.h
 * Author: puppy
 *
 * Created on August 7, 2012, 5:07 PM
 */

#ifndef RHYTHM_AUTOMATA_H
#define	RHYTHM_AUTOMATA_H
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include "State.h"
#define MAX_ITERATIONS 600
using namespace std;

class Rhythm_automata {
public:
    Rhythm_automata();
    Rhythm_automata(vector<string> input_rhythm);
    void rhythm_automata_random_rhythm(int drumvoices, int notes);
    void define_instrument_rules(int i, string rule_1, string rule_2, string rule_3, string rule_4);
    bool** get_rhythm(int hamming_distance);
    bool* get_rhythm_single(int voice , int hamming_distance);
    State bool_rhythm_to_state(bool **rhythm_printed);
    void next_generation();
    int calculate_sum_of_neighboors_single(int j, bool *old_rhythm);
    bool* next_generation(int i); //returns generation for specific element
    void rules_init();
    bool have_same_onsets(bool **rhythm_1, bool **rhythm_2);
    int calculate_hamming_distance(bool **rhythm_1, bool **rhythm_2);
    bool have_same_onsets_single_row(bool rhythm_1[], bool rhythm_2[]);
    int calculate_hamming_distance_single_row(bool rhythm_1[], bool rhythm_2[]);
    void printout_rhythm(bool **rhythm_printed);
    int calculate_sum_of_neighboors(int i, int j, bool **old_rhythm);
    string trim_rhythm_string(string input_string);
    /**
     * @param rhythm, rows(5) represent drum voices,
     *  rhythm[0]-> hihat
     *  rhythm[1]-> ride
     *  rhythm[2]-> high tom
     *  rhythm[3]-> snare drum
     *  rhythm[4]-> bass drum
     *                columns(16) represent the 16th notes
     */
    bool **rhythm, **initial_rhythm;
    int drum_voices;
    int notes;
    //vector_vector_rules, contains
    //a vector<string> for each drum voice.
    //FX v_v_rules.at(0).contains the possible set of rules{vector}
    //for the "crash"
    vector< vector <string> > v_v_rules;
    /*
     * Every row will contain the rules for the corresponding voice
     * fx if we would like to apply the 
     * Delayed Stability rule(0 -> R, 1 -> N, 2 -> F, 3 -> U) for the hh,
     * then we would have: N,F,F,U as string elements in the
     * first row
     * 
     */
    string **rules;
    ~Rhythm_automata();
private:

};

#endif	/* RHYTHM_AUTOMATA_H */

