/* 
 * File:   state.h
 * Author: puppy
 *
 * Created on July 2, 2012, 4:00 PM
 */

#ifndef STATE_H
#define	STATE_H
#include <map>
#include <algorithm>
#include <vector>
#include "CustomNumberDist.h"
#include "Letter.h"

using namespace std;

/**
 * @param id_generator, is a <code>static int</code>, that will hold an id
 *        counter for all possible states. Every time a new state will be
 *        generated, it will receive its unique id from this variable.
 * @param connected_states, is a <code>boost::unordered_map<int, double></code>
 *        The elements of the map are all the possible states that are
 *        related with the current state. The first value of every map entry
 *        represents the ID of the connected state and the second the
 *        probability to transit from the current state to that one.
 * @param id, is a <code>int</code> representing the unique id of the state.
 *        This is the name of the state when referenced from other states.
 * @param letters, is a <code>vector<Letter></code> that will hold all the 
 *        letters representing the state
 * 
 */
class State {
public:
    State(); //should not be used, it is only for testing
    State(vector<Letter> letters);
    virtual ~State();
    int GetId() const;
    void SetId(int id);
    vector<Letter> GetLetters() const;
    void SetLetters(vector<Letter> letters);
    void AddLetters(vector<Letter> letters);
    void inc_state(int state_id);
    void print_state_letters();
    bool has_state(int state_id);
    void print_connected_states();
    void print_sorted_states();
    vector<string> get_rhythm_as_string();
    map<int, double> GetConnected_states() const;
    //This is not shortable by value.
    //for this reason a vector holding a shorted
    //version of the connected_states_will be created
    map<int, double> connected_states;
    vector< pair <int, double > > vector_sorted_connected_states;
    void bubblesort_vector_descending(vector< pair <int, double > > *v_sort);
    int get_connected_state_stochastically();
    static int id_generator;
    CustomNumberDist *normal_dist;
    int id_from_file; //only used on load of a file
private:
    // should be static because it will be common incremental value 
    // for all states
    //int-> ID, double-> probability
    int id;

    vector<Letter> letters;

};

#endif	/* STATE_H */

