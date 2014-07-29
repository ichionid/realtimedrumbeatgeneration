/* 
 * File:   Rhythm_automata.cpp
 * Author: puppy
 * 
 * Created on August 7, 2012, 5:07 PM
 */

#include <vector>

#include "Rhythm_automata.h"

Rhythm_automata::Rhythm_automata() {
    notes = 0;
    ////////cout << "Unit test purposes" << endl;
}
/**
 * 
 * @param input_string is a <code>string</code>
 * @return A trimmed <code>string</code>
 */
string Rhythm_automata::trim_rhythm_string(string input_string) {

    string trimmed_string = "";
    for (int i = 0; i < input_string.length(); i++) {
        ////////cout << input_string[i];
        if (input_string[i] == 'X' || input_string[i] == '.') {
            trimmed_string += input_string[i];
        }
    }
    ////////cout<<endl;
   // //cout<<"input:"<<input_string<<endl;
    ////cout<<"input.size():"<<input_string.length()<<endl;
    
    //cout<<"output:"<<trimmed_string<<endl;
    //cout<<"output:"<<trimmed_string.length()<<endl;
    return trimmed_string;

}
/**
 * 
 * @param initial_input_rhythm is a <code>vector<string></code> representing
 * the input rhythm.
 */
Rhythm_automata::Rhythm_automata(vector<string> initial_input_rhythm) {
    ////cout << "Rhythm Automata Constructor" << endl;
    ////cout << "Number of voices:" << initial_input_rhythm.size() << endl;
    notes = 0;
    vector<string> input_rhythm;
    for (int i = 0; i < initial_input_rhythm.size(); i++) {
        input_rhythm.push_back(trim_rhythm_string(initial_input_rhythm.at(i)));
    }
    rhythm = new bool *[input_rhythm.size()];
    initial_rhythm = new bool *[input_rhythm.size()];
    rules = new string *[input_rhythm.size()];
    for (int i = 0; i < input_rhythm.size(); i++) {
        rhythm[i] = new bool[input_rhythm.at(i).size() + 2];
        initial_rhythm[i] = new bool[input_rhythm.at(i).size() + 2];
        rules[i] = new string[input_rhythm.at(i).size()];
    }
    drum_voices = input_rhythm.size();
    notes = input_rhythm.at(0).size();
    //cout << "RA48::Voices::" << drum_voices << endl;
    //cout << "RA48::NOTES::" << notes << endl;

    /*//cout << "input_rhythm.at(0).size()" << input_rhythm.at(0).size() << endl;
    //cout << "input_rhythm.at(0).size()" << input_rhythm.at(1).size() << endl;
    //cout << "input_rhythm.at(0).size()" << input_rhythm.at(2).size() << endl;
    //cout << "input_rhythm.at(0).size()" << input_rhythm.at(3).size() << endl;
    //cout << "input_rhythm.at(0).size()" << input_rhythm.at(4).size() << endl;
    //cout << "input_rhythm.at(0).size()" << input_rhythm.at(5).size() << endl;
    */
    for (int i = 0; i < drum_voices; i++) {
        rhythm[i][0] = false;
        rhythm[i][notes + 1] = false; //oops :p
        initial_rhythm[i][0] = false;
        initial_rhythm[i][notes + 1] = false;
        string input_pattern = input_rhythm.at(i);
        for (int j = 1; j < notes + 1; j++) {
            //////////cout << input_pattern[j - 1];
            if (input_pattern[j - 1] == 'X') {
                ////////cout<<"X";
                rhythm[i][j] = true;
                initial_rhythm[i][j] = true;
            } else if (input_pattern[j - 1] == '.') {
                ////////cout<<".";
                rhythm[i][j] = false;
                initial_rhythm[i][j] = false;
            } else {
                rhythm[i][j] = false;
                initial_rhythm[i][j] = false;
            }
        }
        ////////cout << endl;
    }
    ////////cout<<"SPAM!!!!" << endl;

}

/**
 * 
 * @param i is an <code>int</code> representing the specific instrument
 * @param rule_1 is a <code>string</code> representing the rule 
 *      for neighboring sum=0
 * @param rule_2 is a <code>string</code> representing the rule 
 *      for neighboring sum=1
 * @param rule_3 is a <code>string</code> representing the rule 
 *      for neighboring sum=2
 * @param rule_4 is a <code>string</code> representing the rule 
 *      for neighboring sum=3
 */
void Rhythm_automata::define_instrument_rules(int i, string rule_1, string rule_2, string rule_3, string rule_4) {
    ////cout << rule_1 << "," << rule_2 << "," << rule_3 << "," << rule_4 << endl;
    rules[i][0] = rule_1;
    rules[i][1] = rule_2;
    rules[i][2] = rule_3;
    rules[i][3] = rule_4;

}

void Rhythm_automata::rules_init() {
    /*this->define_instrument_rules(0, "U", "U", "U", "U"); //cr
    this->define_instrument_rules(1, "U", "U", "U", "U"); //hh
    this->define_instrument_rules(2, "U", "U", "U", "U"); //rd
    this->define_instrument_rules(3, "U", "R", "N", "R"); //sn
    this->define_instrument_rules(4, "U", "U", "U", "U"); //lt
    this->define_instrument_rules(5, "U", "R", "N", "R"); //bd */
    for (int i = 0; i < 6; i++) {
        v_v_rules.push_back(vector<string > ());
    }
    //////cout << "v_v_rules.size():" << v_v_rules.size() << endl;

    v_v_rules.at(0).push_back("UUUU");

    v_v_rules.at(1).push_back("UUUU");

    v_v_rules.at(2).push_back("UUUU");

    v_v_rules.at(3).push_back("NURN");
    v_v_rules.at(3).push_back("URNR"); //Density Thining
    v_v_rules.at(3).push_back("NFFU"); //Evolving Inversion
    v_v_rules.at(3).push_back("NRRU"); //Emergent Cycles
    v_v_rules.at(3).push_back("RNFR"); // Rhythmic Phrasing

    v_v_rules.at(4).push_back("UUUU");

    v_v_rules.at(5).push_back("NURN");
    v_v_rules.at(5).push_back("URNR"); //Density Thining
    v_v_rules.at(5).push_back("NFFU"); //Evolving Inversion
    v_v_rules.at(5).push_back("NRRU"); //Emergent Cycles
    v_v_rules.at(5).push_back("RNFR"); // Rhythmic Phrasing
}

/**
 * 
 * @param hamming_distance is the upper limit
 *      of the distance. Hamming distance should be 
 *      >0 and <swap_distance
 * @return An <code>bool**</code> representing the response rhythm.
 */

bool** Rhythm_automata::get_rhythm(int hamming_distance) {

    for (int i = 0; i < drum_voices; i++) {
        get_rhythm_single(i, hamming_distance);
    }

    bool **return_rhythm;
    return_rhythm = new bool *[drum_voices];

    for (int i = 0; i < drum_voices; i++)
        return_rhythm[i] = new bool[notes];

    for (int i = 0; i < drum_voices; i++) {
        for (int j = 1; j < notes + 1; j++) {
            //////////cout<<i<<","<<j<<endl;
            return_rhythm[i][j - 1] = rhythm[i][j];
        }
    }
    return return_rhythm;
}
/**
 * 
 * @param voice is an <code>int</code> representing the voice of interest.
 * @param hamming_distance is an <code>int</code> representing the desired 
 *      swap distance.
 * @return An array of <code>bool</code> representing the response rhythm.
 */
bool* Rhythm_automata::get_rhythm_single(int voice, int hamming_distance) {
    //cout << "Initial Rhythmos" << endl;
    //for (int i = 1; i < notes+1 ; i++) {
        //cout << rhythm[voice][i];
   // }

    //cout << endl;
    //////cout << "Voice::" << voice << endl;
    for (int rules_cnt = 0; rules_cnt < v_v_rules.at(voice).size(); rules_cnt++) {
        //cout << "Generate Rules::" << endl;
        //cout << "0::" << v_v_rules.at(voice).at(rules_cnt).substr(0, 1);
        //cout << ",1::" << v_v_rules.at(voice).at(rules_cnt).substr(1, 1);
        //cout << ",2::" << v_v_rules.at(voice).at(rules_cnt).substr(2, 1);
        //cout << ",3::" << v_v_rules.at(voice).at(rules_cnt).substr(3, 1) << endl;

        for (int i = 0; i < notes + 2; i++) {
            rhythm[voice][i] = initial_rhythm[voice][i]; //IMPORTANT ONLY FOR TESTING
        }
        define_instrument_rules(voice,
                v_v_rules.at(voice).at(rules_cnt).substr(0, 1),
                v_v_rules.at(voice).at(rules_cnt).substr(1, 1),
                v_v_rules.at(voice).at(rules_cnt).substr(2, 1),
                v_v_rules.at(voice).at(rules_cnt).substr(3, 1)
                );
        //cout << "Starting Rhythm::" << endl;
        //for (int i = 1; i < notes+1; i++) {
            //cout << rhythm[voice][i] <<",";
        //}
        //cout<<endl;
        for (int i = 0; i < MAX_ITERATIONS; i++) {
            this->next_generation(voice);
            if (i > 500) {
                //cout << i << "::";
                for (int j = 1; j < notes + 1; j++) {
                    if (rhythm[voice][j]) {
                        //cout << '|';
                    } else {
                        //cout << '.';
                    }
                }
                //cout << endl;
            }
            if (this->have_same_onsets_single_row(initial_rhythm[voice], rhythm[voice])) {
                ////cout << "FOUND::Same Onsets!!!! With Distance:";
                ////cout << this->calculate_hamming_distance_single_row(initial_rhythm[voice], rhythm[voice])<<endl;
                if (this->calculate_hamming_distance_single_row(initial_rhythm[voice], rhythm[voice]) <= hamming_distance) {
                    //cout << "FOUND:Rhythm!!!! at::" << i << "for voice " << voice << endl;
                    /////cout << " Distance::" << this->calculate_hamming_distance_single_row(initial_rhythm[voice], rhythm[voice]) << endl;
                    for (int j = 1; j < notes + 1; j++) {
                        if (rhythm[voice][j]) {
                            ////cout << '|';
                        } else {
                            ////cout << '.';
                        }
                    }
                    return rhythm[voice];
                }
            }
            //////cout << endl;
        }
    }

    //cout << "Rhythm_automata::Can not generate rhythm for it" << endl;
    throw "Rhythm_automata::Can not generate rhythm";
}
/**
 * 
 * @param i is an <code>int</code> representing the voice of interest.
 * @return A <code>bool</code> array of the next generation array.
 */
bool* Rhythm_automata::next_generation(int i) {

    bool old_rhythm[notes + 2];
    //////cout<<"Rhythm_automata::next_generation::"<<i<<endl;
    for (int j = 0; j < notes + 2; j++) {
        //    ////cout<<j<<endl;
        old_rhythm[j] = rhythm[i][j];
    }
    //sum holds the sum of the neighbors
    int sum = 0;
    for (int j = 0; j < notes + 2; j++) {
        sum = calculate_sum_of_neighboors_single(j, old_rhythm);
        if ((rules[i][sum].compare("R") == 0)) {
            rhythm[i][j] = false;

        } else if ((rules[i][sum].compare("N") == 0)) {
            rhythm[i][j] = true;
        } else if ((rules[i][sum].compare("F") == 0)) {
            if (rhythm[i][j]) {
                rhythm[i][j] = false;
            } else {
                rhythm[i][j] = true;
            }
        }
    }
    return rhythm[i];
}

void Rhythm_automata::next_generation() {

    bool **old_rhythm;
    old_rhythm = new bool *[drum_voices];

    for (int i = 0; i < drum_voices; i++)
        old_rhythm[i] = new bool[notes];

    for (int i = 0; i < drum_voices; i++) {
        for (int j = 0; j < notes; j++) {
            old_rhythm[i][j] = rhythm[i][j];
        }
    }

    //sum holds the sum of the neighbors
    int sum;

    for (int i = 0; i < drum_voices; i++) {
        sum = 0;
        for (int j = 0; j < notes; j++) {
            sum = calculate_sum_of_neighboors(i, j, old_rhythm);

            if ((rules[i][sum].compare("R") == 0)) {
                rhythm[i][j] = false;

            } else if ((rules[i][sum].compare("N") == 0)) {
                rhythm[i][j] = true;
            } else if ((rules[i][sum].compare("F") == 0)) {
                if (rhythm[i][j]) {
                    rhythm[i][j] = false;
                } else {
                    rhythm[i][j] = true;
                }
            }
        }
    }
}

/**
 * 
 * @param j is an <code>int</code> representing the column of the element
 * @param old_rhythm is a <code>bool*</code> representing the rhythm.
 * @return  TRUE for onset, FALSE for offset.
 */
int Rhythm_automata::calculate_sum_of_neighboors_single(int j, bool *old_rhythm) {
    int sum = 0;
    if (j == 0) {
        //special case::no neighbor on the left
        if (old_rhythm[j] == true) sum++;
        if (old_rhythm[j + 1] == true) sum++;

    } else if (j == (notes + 1)) {
        //special case::no neighbor on the right 
        //for 32 notes, we have 34 cells. The last has and index of 32+1
        if (old_rhythm[j])sum++;
        if (old_rhythm[j - 1])sum++;

    } else {
        if (old_rhythm[j])sum++;
        if (old_rhythm[j - 1])sum++;
        if (old_rhythm[j + 1])sum++;
    }
    return sum;
}

/**
 * 
 * @param i is an <code>int</code> representing the row of the element
 * @param j is an <code>int</code> representing the column of the element
 * @param old_rhythm is a <code>bool**</code> representing the rhythm.
 * @return TRUE for onset, FALSE for offset.
 */
int Rhythm_automata::calculate_sum_of_neighboors(int i, int j, bool **old_rhythm) {
    int sum = 0;
    if (j == 0) {
        //special case::no neighbor on the left
        if (old_rhythm[i][j] == true) sum++;
        if (old_rhythm[i][j + 1] == true) sum++;

    } else if (j == (sizeof (old_rhythm[0]) - 1)) {
        //special case::no neighbor on the right    
        if (old_rhythm[i][j])sum++;
        if (old_rhythm[i][j - 1])sum++;

    } else {

        if (old_rhythm[i][j])sum++;
        if (old_rhythm[i][j - 1])sum++;
        if (old_rhythm[i][j + 1])sum++;

    }
    return sum;
}
/**
 * 
 * @param rhythm_printed is a <code>bool**</code> of the rhythm to be 
 * printed.
 */
void Rhythm_automata::printout_rhythm(bool **rhythm_printed) {

    ////cout << "*****Rhythm*****" << endl;
    ////cout << "notes:" << notes << endl;
    for (int i = 0; i < drum_voices; i++) {
        for (int j = 0; j < notes; j++) {
            if (rhythm_printed[i][j + 1] == true) {
                cout << "X";
            } else {
                cout << "o";
            }
        }
        cout<< endl;
    }
    cout << "****************" << endl;
}
/**
 * 
 * @param drumvoices is a <code>int</code> representing the number of 
 * drum voices.
 * @param notes is a <code>int</code> representing the number of notes every
 * drum voice should have.
 */
void Rhythm_automata::rhythm_automata_random_rhythm(int drumvoices, int notes) {
    ////////cout << "Initialize a random rhythm" << endl;
    int iSecret;

    /* initialize random seed: */
    srand(time(NULL));

    for (int i = 0; i < drumvoices; i++) {
        for (int j = 0; j < notes; j++) {
            /* generate secret number: */
            iSecret = rand() % 10;
            if (iSecret > 4) {
                rhythm[i][j] = true;
            } else {
                rhythm[i][j] = false;
            }
        }
    }
}
/**
 * 
 * @param rhythm_1 is a <code>bool[]</code> representation of a rhythm.
 * @param rhythm_2 is a <code>bool[]</code> representation of a rhythm.
 * @return TRUE if they have the same amount of onsets, FALSE otherwise.
 */
bool Rhythm_automata::have_same_onsets_single_row(bool rhythm_1[], bool rhythm_2[]) {
    int rhyth_1_count, rhyth_2_count;
    rhyth_1_count = 0;
    rhyth_2_count = 0;
    for (int j = 1; j < notes + 1; j++) {
        if (rhythm_1[j])rhyth_1_count++;
        if (rhythm_2[j])rhyth_2_count++;
    }
    if (rhyth_1_count != rhyth_2_count) return false;
    return true;
}

/**
 * 
 * @param rhythm_1 is a <code>bool[]</code> representation of a rhythm.
 * @param rhythm_2 is a <code>bool[]</code> representation of a rhythm.
 * @return A <code>int</code> representing the swap distance among the
 * two rhythms.
 */
int Rhythm_automata::calculate_hamming_distance_single_row(bool rhythm_1[], bool rhythm_2[]) {
    int hamming_distance = 0;
    vector<int> v1;
    vector<int> v2;
    //if we want to ad the id of "j" then instead we add j-1
    //because of the fact that he initial rhythm has 2 elements add
    //at its limits
    for (int j = 1; j < notes + 1; j++) {
        if (rhythm_1[j])v1.push_back(j - 1);
        if (rhythm_2[j])v2.push_back(j - 1);
    }

    for (int j = 0; j < v1.size(); j++) {
        //////////cout << v1.at(j) << "," << v2.at(j) << endl;
        hamming_distance += fabs(v1.at(j) - v2.at(j));
    }
    return hamming_distance;
}
/*
 * @param rhythm_1 is a <code>bool**</code> representation of a rhythm.
 * @param rhythm_2 is a <code>bool**</code> representation of a rhythm.
 * @return A <code>int</code> representing the swap distance among the
 * @return TRUE if they have the same amount of onsets, FALSE otherwise.
 * */
bool Rhythm_automata::have_same_onsets(bool **rhythm_1, bool **rhythm_2) {
    int rhyth_1_count, rhyth_2_count;
    for (int i = 0; i < drum_voices; i++) {
        rhyth_1_count = 0;
        rhyth_2_count = 0;
        for (int j = 1; j < notes + 1; j++) {
            if (rhythm_1[i][j])rhyth_1_count++;
            if (rhythm_2[i][j])rhyth_2_count++;
        }
        if (rhyth_1_count != rhyth_2_count) return false;
    }
    return true;
}


/**
 * 
 * @param rhythm_1 is a <code>bool**</code> representation of a rhythm.
 * @param rhythm_2 is a <code>bool**</code> representation of a rhythm.
 * @return A <code>int</code> representing the swap distance among the
 * two rhythms.
 */
int Rhythm_automata::calculate_hamming_distance(bool **rhythm_1, bool **rhythm_2) {
    int hamming_distance = 0;
    vector< vector<int> > v_r1;
    vector< vector<int> > v_r2;

    for (int i = 0; i < drum_voices; i++) {
        vector<int> v1;
        vector<int> v2;
        for (int j = 1; j < notes + 1; j++) {
            if (rhythm_1[i][j])v1.push_back(j - 1);
            if (rhythm_2[i][j])v2.push_back(j - 1);
        }
        //////////cout << endl;
        v_r1.push_back(v1);
        v_r2.push_back(v2);
    }
    for (int i = 0; i < v_r1.size(); i++) {
        //////////cout << "v_r1.at(i).size():" << v_r1.at(i).size() << endl;
        //////////cout << "v_r2.at(i).size():" << v_r2.at(i).size() << endl;
        for (int j = 0; j < v_r1.at(i).size(); j++) {
            //////////cout << v_r1.at(i).at(j) << "," << v_r2.at(i).at(j) << endl;
            hamming_distance += fabs(v_r1.at(i).at(j) - v_r2.at(i).at(j));
        }
    }
    return hamming_distance;
}

Rhythm_automata::~Rhythm_automata() {
}