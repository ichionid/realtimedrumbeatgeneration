/* 
 * File:   State.cpp
 * Author: Ioannis Chionidis
 * 
 * Created on July 2, 2012, 4:00 PM
 */

#include "State.h"

//static variable, initialized to 0
int State::id_generator = 0;
//allocate memory

State::State() {
    normal_dist = new CustomNumberDist();
    //cout<<"Testing constructor created"<<endl;
    //cout<<"This should not occur outside testing"<<endl;
    //this->id = id_generator++;

}
/**
 * 
 * @param letters, <code>vector<Letter></code> of the State to be created
 */

State::State(vector<Letter> letters) {

    this->letters = letters;
    this->id = id_generator++;
    this->normal_dist = new CustomNumberDist();
    //cout << normal_dist << endl;
}
//ok

State::~State() {
    //cout << "State Destructor" << endl;
    //cout << normal_dist << endl;
    //delete this->normal_dist;
}
/**
 * 
 * @return A <code>map<int,double></code>.
 */
map<int, double> State::GetConnected_states() const {
    return connected_states;
}
/**
 * 
 * @return A <code>vector<string></code>.
 */
vector<string> State::get_rhythm_as_string() {
    vector<string> rhythm;
    //hh,ht,sn,lt,bd
    string s_cr = "";
    string s_hh = "";
    string s_ht = "";
    string s_sn = "";
    string s_lt = "";
    string s_bd = "";
    for (int i = 0; i < letters.size(); i++) {
        s_cr += letters.at(i).print_instrument(cr);
        s_hh += letters.at(i).print_hihat();
        s_ht += letters.at(i).print_instrument(t1);
        s_sn += letters.at(i).print_instrument(sn);
        s_lt += letters.at(i).print_instrument(lt);
        s_bd += letters.at(i).print_instrument(bd);
    }
    cout << s_cr << endl;
    rhythm.push_back(s_cr);
    rhythm.push_back(s_hh);
    rhythm.push_back(s_ht);
    rhythm.push_back(s_sn);
    rhythm.push_back(s_lt);
    rhythm.push_back(s_bd);
    return rhythm;
}

void State::print_connected_states() {
    // show content:
    cout << "Printout connected states" << endl;
    for (map<int, double>::iterator it = this->connected_states.begin(); it != this->connected_states.end(); it++)
        cout << (*it).first << " => " << (*it).second << endl;

}

void State::print_sorted_states() {
    pair<int, double> pair_int_double;
    cout << "Printout vector of connected states" << endl;
    for (int i = 0; i < this->vector_sorted_connected_states.size(); i++) {
        pair_int_double = this->vector_sorted_connected_states.at(i);
        cout << pair_int_double.first << " => " << pair_int_double.second << endl;
    }
}

/**
 * 
 * @param state_id is an <code>int</code> the contains the ID of the state 
 * the occurrence of which will be increased by one
 */
void State::inc_state(int state_id) {
    // if(connected_states)
    if (connected_states.find(state_id) != connected_states.end()) {
        connected_states[state_id] += 1;
        for (int i = 0; i < vector_sorted_connected_states.size(); i++) {
            if (vector_sorted_connected_states.at(i).first == state_id) {
                vector_sorted_connected_states.at(i).second += 1;
            }
        }
    } else {
        connected_states.insert(pair<int, double>(state_id, 1));
        vector_sorted_connected_states.push_back(pair<int, double>(state_id, 1));
    }
    //short again the vector in case there should be a reordering
    bubblesort_vector_descending(&vector_sorted_connected_states);
}
void State::bubblesort_vector_descending(vector< pair <int, double > > *v_sort) {
    int n = v_sort->size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i <= n - 1; i++) {
            if (v_sort->at(i - 1) > v_sort->at(i)) {
                swap(v_sort->at(i - 1), v_sort->at(i));
                swapped = true;
            }
        }
    } while (swapped);

}
/**
 * 
 * @return An <code>int</code>.
 */
int State::GetId() const {
    return id;
}
/**
 * 
 * @param id is an <code>int</code>.
 */
void State::SetId(int id) {
    this->id = id;
}
/**
 * 
 * @return <code>vector<Letter></code>.
 */
vector<Letter> State::GetLetters() const {
    return letters;
}
/**
 * 
 * @param letters is a <code>vector<Letter></code>.
 */
void State::SetLetters(vector<Letter> letters) {
    this->letters = letters;
}

void State::print_state_letters() {
    //cout << "void State::print_state_letters()" << endl;
    /*cout << "Number of letters:"<<letters.size()<<endl;
    for (int i = 0; i < letters.size(); i++) {
        cout<<letters.at(i).getPattern().GetName()<<endl;
        cout<<letters.at(i).getRawNotes().size()<<endl;
    }*/
    cout << "cr:";
    for (int i = 0; i < letters.size(); i++) {
        cout << letters.at(i).print_instrument(cr);
    }
    cout << endl;
    cout << "hh:";
    for (int i = 0; i < letters.size(); i++) {
        cout << letters.at(i).print_hihat();
    }
    cout << endl;
    cout << "t1:";
    for (int i = 0; i < letters.size(); i++) {
        cout << letters.at(i).print_instrument(t1);
    }
    cout << endl;
    cout << "sn:";

    for (int i = 0; i < letters.size(); i++) {
        cout << letters.at(i).print_instrument(sn);
    }
    cout << endl;
    cout << "lt:";

    for (int i = 0; i < letters.size(); i++) {
        cout << letters.at(i).print_instrument(lt);
    }

    cout << endl;
    cout << "bd:";

    for (int i = 0; i < letters.size(); i++) {
        cout << letters.at(i).print_instrument(bd);
    }
    cout<<endl;
}
/**
 * 
 * @param letters is a <code>vector<Letter></code>
 */
void State::AddLetters(vector<Letter> letters) {
    for (int i = 0; i < letters.size(); i++) {
        this->letters.push_back(letters.at(i));
    }
}
/**
 * 
 * @return An <code>int</code> representing the state id.
 */
int State::get_connected_state_stochastically() {

    double random_number = normal_dist->generate();
    //create variable U. Check Markov Models, Algorithms and Applications p.23/211
    double total_occurences = 0;
    map<int, double> ::iterator iter;
    for (iter = connected_states.begin(); iter != connected_states.end(); iter++) {
        total_occurences += (*iter).second;
    }
    double frontier = 0; //if random_number is smaller then we choose that one STATE
    for (iter = connected_states.begin(); iter != connected_states.end(); iter++) {
        frontier += ((*iter).second / total_occurences);
        if (random_number <= frontier)return (*iter).first;
    }

    cout << "State::get_connected_state_stochastically() CANNOT resolve state" << endl;
    cout << "This should not happen because there is a check that" << endl;
    cout << "the connected states vector is not empty from the code that" << endl;
    cout << "calls this function." << endl;
    throw "Error in State::get_connected_state_stochastically()";
}