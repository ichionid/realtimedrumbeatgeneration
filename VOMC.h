/* 
 * File:   VOMC.h
 * Author: puppy
 *
 * Created on July 2, 2012, 5:18 PM
 */

#ifndef VOMC_H
#define	VOMC_H
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/foreach.hpp>
#include "State.h"
#include "Letter.h"
#include <iostream>
#include <fstream>


using namespace std;

class VOMC {
public:
    VOMC();
    void init();
    void train(vector<Letter> letters);
    void sub_train(vector<Letter> tempLettersA, vector<Letter> tempLettersB);
    int state_exists(vector<Letter> tempLettersA);
    bool note_exists(RawNote rawNote, vector<RawNote> rawNoteVector);
    State* get_state_by_id(int ID);
    bool states_equal(State *s1, State *s2);
    State provide_response_pattern_remove(vector<Letter> input_letters);
    bool compare_remove(State* s1, State* s2);
    bool compare_remove_without_velocity(State* s1, State* s2);
    bool compare_remove_without_pitch_velocity(State* s1, State* s2);

    vector<Letter> provide_response_pattern_weight(vector<Letter> input_letters);
    void compare_weight(State* s1, State* s2);
    State combine_states(State* s1, State* s2);

    bool find_letter_without_velocity(Letter* l1, vector<Letter>l2);
    bool find_letter_with_velocity(Letter* l1, vector<Letter>l2);

    State resolve_pattern(State *s1_in);
    State resolve_pattern_4_letters(State *s1_in);
    State resolve_pattern_8_letters(State *s1_in);
    // LOGGING FUNCTIONS
    void log_result(string choice);
    void log_produced_rhythm(State *s);
    void log_current_states();

    void save_as(const char *filename);
    void load(const char *filename, int offset);
    void sort_vomc();
    
    char* getArray(string s);
    void update_vector_of_connected_states_from_connected_states();
    void merge_same_states_of_vomc(vector<State*> *v_s);

    int choice_log_id, rhythm_log_id, states_log_id;
    
    void print();
    void print_connected_states();
    void print_vectors_of_connected_states();
    virtual ~VOMC();
    vector<State*> vomc;
    void check_state_of_vomc_for_update(vector<State*>* v_s, pair<int, int>* temp_pair_state);
    void filter_duplicate_state_entries(vector< pair <int, int > > *state_pairs);
    int s_4_v_p_r, s_3_v_p_r, s_2_v_p_r, s_1_v_p_r;
    int s_4_p_r,s_3_p_r,s_2_p_r,s_1_p_r;
    int s_4_r, s_3_r, s_2_r, s_1_r;

private:
    vector<Letter> previous_letters;
};

#endif	/* VOMC_H */

