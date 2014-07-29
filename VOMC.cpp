/* 
 * File:   VOMC.cpp
 * Author: Ioannis Chionidis
 * 
 * Created on July 2, 2012, 5:18 PM
 */

#include "VOMC.h"

void VOMC::sort_vomc() {
    // state pairs: elements whose first and second elements represent state ids
    // Every pair represents two states that are similar.
    // OK!
    vector< pair <int, int> > state_pairs;

    /*for (int i = 0; i < this->vomc.size(); i++) {

        cout << i << "=> " << vomc.at(i)->GetId() << endl;

    }*/
    //OK!
    for (int i = 0; i < this->vomc.size(); i++) {
        for (int j = 0; j < this->vomc.size(); j++) {
            if (i != j) {
                if (states_equal(this->vomc.at(i), this->vomc.at(j))) {
                    //cout << "(" << this->vomc.at(i)->GetId() << " = " << this->vomc.at(j)->GetId() << ")" << endl;
                    state_pairs.push_back(
                            make_pair(
                            this->vomc.at(i)->GetId(), this->vomc.at(j)->GetId()
                            )
                            );
                }
            }
        }
    }
    //take pairs and filter out duplicate 
    filter_duplicate_state_entries(&state_pairs);

    for (int i = 0; i < state_pairs.size(); i++) {
        pair<int, int> temp_state_pair = state_pairs.at(i);
        check_state_of_vomc_for_update(&this->vomc, &temp_state_pair);
    }

    //Merge similar states


    for (int i = 0; i < state_pairs.size(); i++) {

        pair<int, int> temp_state_pair = state_pairs.at(i);
        State *s1 = this->get_state_by_id(temp_state_pair.first);
        State *s2 = this->get_state_by_id(temp_state_pair.second);

        //merge state connections and vector of connected states
        map<int, double>::iterator it2;
        map<int, double>::iterator it1;
        //A.iterate through all connected states
        for (it2 = s2->connected_states.begin(); it2 != s2->connected_states.end(); it2++) {

            //     cout << "[" << (*it2).first << "," << (*it2).second << "]" << endl;

            it1 = s1->connected_states.find((*it2).first);

            if (it1 == s1->connected_states.end()) {
                //element of it2 not found in it1

                //       cout << "not found" << endl;
                s1->connected_states.insert(*it2);

            } else {

                //     cout << "found" << endl;
                double sum = (*it2).second + (*it1).second;
                //   cout << " sum:" << sum << endl;
                s1->connected_states.erase(it1);
                s1->connected_states.insert(make_pair((*it2).first, sum));

            }
        }
    }
    //this->print_connected_states();

    //C clear duplicate states
    for (int i = 0; i < state_pairs.size(); i++) {
        pair<int, int> temp_state_pair = state_pairs.at(i);
        //remove state[2]
        int position = -1;
        for (int j = 0; j < this->vomc.size(); j++) {
            if (temp_state_pair.second == this->vomc.at(j)->GetId()) {
                position = j;
                break;
            }
        }
        if (position != -1) {

            this->vomc.erase(this->vomc.begin() + position);

        } else {

            cout << "Unexpected Error: state with specific ID not found" << endl;
            throw "Unexpected Error: state with specific ID not found";

        }
    }

    //D. resolve vector of connected states according to connected states map
    update_vector_of_connected_states_from_connected_states();

}

VOMC::VOMC() {
    cout << "Starting Variable-Order Markov Chain" << endl;
    cout << vomc.size() << endl;
    s_4_v_p_r = 0;
    s_3_v_p_r = 0;
    s_2_v_p_r = 0;
    s_1_v_p_r = 0;
    s_4_p_r = 0;
    s_3_p_r = 0;
    s_2_p_r = 0;
    s_1_p_r = 0;
    s_4_r = 0;
    s_3_r = 0;
    s_2_r = 0;
    s_1_r = 0;

}

void VOMC::init() {
    this->choice_log_id = 0;
    this->rhythm_log_id = 0;
    this->states_log_id = 0;
}
/**
 * 
 * @param filename is a <code>const char*</code> representing the name of
 * the file that the VOMC will be stored in.
 */
void VOMC::save_as(const char *filename) {
    cout << "Saving file :" << filename << endl;
    ofstream myfile;
    myfile.open(filename);
    myfile << "Writing this to a file.\n";
    //for every state
    for (int i = 0; i < this->vomc.size(); i++) {
        myfile << "state_start\n";
        State s = *(this->vomc.at(i)); //Get data of address
        map<int, double>::iterator it;
        // show content:
        myfile << "connected_states_start\n";
        map<int, double> custom_map = vomc.at(i)->GetConnected_states();
        for (it = custom_map.begin(); it != custom_map.end(); it++) {
            myfile << (*it).first << "," << (*it).second << endl;
        }
        myfile << "connected_states_end\n";
        myfile << "id_start\n";
        myfile << vomc.at(i)->GetId() << "\n";
        myfile << "id_end\n";
        myfile << "vector_letters_start\n";
        for (int j = 0; j < vomc.at(i)->GetLetters().size(); j++) {
            myfile << "letter_start\n";
            for (int notes = 0; notes < vomc.at(i)->GetLetters().at(j).getRawNotes().size(); notes++) {
                myfile << "note_start\n";
                myfile << "pitch:" << vomc.at(i)->GetLetters().at(j).getRawNotes().at(notes).GetPitch() << '\n';
                myfile << "position:" << vomc.at(i)->GetLetters().at(j).getRawNotes().at(notes).GetPosition() << '\n';
                myfile << "velocity:" << vomc.at(i)->GetLetters().at(j).getRawNotes().at(notes).GetVelocity() << '\n';
                myfile << "note_end\n";
            }
            myfile << vomc.at(i)->GetLetters().at(j).getPattern().GetName() << "\n";
            myfile << "letter_end\n";
        }
        myfile << "vector_letter_end\n";
        myfile << "state_end\n";
        myfile << "\n\n";
    }
    myfile.close();
}
void VOMC::merge_same_states_of_vomc(vector<State*>* v_s) {
    throw "no need to implement!";
}

void VOMC::print_connected_states() {
    cout << "Print Connected States" << endl;
    for (int i = 0; i < this->vomc.size(); i++) {
        this->vomc.at(i)->print_connected_states();
    }
}

void VOMC::print_vectors_of_connected_states() {
    cout << "Print Vector Of Connected States" << endl;
    for (int i = 0; i < this->vomc.size(); i++) {
        this->vomc.at(i)->print_sorted_states();
    }
}
/**
 * 
 * @param v_s is a <code>state</code>
 * @param temp_pair_state is a pair of <code>int</code> representing state IDs.
 */
void VOMC::check_state_of_vomc_for_update(vector<State*>* v_s, pair<int, int>* temp_pair_state) {

    for (int i = 0; i < v_s->size(); i++) {
        //check ID
        /* //Leave Id the same so that we can merge later on
         * if (v_s->at(i)->GetId() == temp_pair_state->second) {
             v_s->at(i)->SetId(temp_pair_state->first);
         }*/
        //check connected states
        typedef map < int, double > ::iterator it_type;
        for (it_type
            iterator = v_s->at(i)->connected_states.begin();
                iterator != v_s->at(i)->connected_states.end();
                iterator++) {
            if (iterator->first == temp_pair_state->second) {
                v_s->at(i)->connected_states.insert(make_pair(temp_pair_state->first, (*iterator).second));
                v_s->at(i)->connected_states.erase(iterator->first);
                break;
            }
        }
        //check vector_of_connected_states
        for (int j = 0; j < v_s->at(i)->vector_sorted_connected_states.size(); j++) {

            pair<int, int> temp_vscs = v_s->at(i)->vector_sorted_connected_states.at(j);

            if (temp_vscs.first == temp_pair_state->second) {

                v_s->at(i)->vector_sorted_connected_states.push_back(
                        make_pair(temp_pair_state->first, temp_vscs.second)
                        );
                v_s->at(i)->vector_sorted_connected_states.erase(
                        v_s->at(i)->vector_sorted_connected_states.begin() + j
                        );
                break;
            }
        }
    }
}
/**
 * 
 * @param state_pairs is a <code>vector< pair <int, int > > *</code> whose
 * existence will be check on the VOMC.
 */
void VOMC::filter_duplicate_state_entries(vector< pair <int, int > > *state_pairs) {

    for (int i = 0; i < state_pairs->size(); i++) {
        pair <int, int> temp_state_pair;
        for (int j = 0; j < state_pairs->size(); j++) {
            pair <int, int> temp_state_pair_2;
            //cout << "i,j:" << i << "," << j << endl;
            if (i != j) {
                temp_state_pair = state_pairs->at(i);
                temp_state_pair_2 = state_pairs->at(j);
                /*cout << "input_1 pair:" <<
                        temp_state_pair.first << "," << temp_state_pair.second << endl;
                cout << "input_2 pair:" <<
                        temp_state_pair_2.first << "," << temp_state_pair_2.second << endl;
                 */
                if ((temp_state_pair.first == temp_state_pair_2.second) &&
                        (temp_state_pair.second == temp_state_pair_2.first)) {
                    state_pairs->erase(state_pairs->begin() + j);
                    break;
                }
            }
        }
    }
}
/**
 * 
 * @param filename is a <code>const char*</code> representing the filepath
 * to load the VOMC from.
 * @param offset is a <code>int</code> representing the offset for the id.
 */
void VOMC::load(const char *filename, int offset) {
    //cout << "Load file:" << filename << endl;
    string line;
    ifstream myfile(filename);
    vector<Letter> v_letters_temp;
    cout << "offset=" << offset << endl;
    if (myfile.is_open()) {
        /**
         * 1.Start of File Parsing
         */
        while (myfile.good()) {
            getline(myfile, line);
            if (line == "state_start") {
                State *s = new State();

                getline(myfile, line);
                while (line != "state_end") {
                    //1.CONNECTED STATES
                    getline(myfile, line); //should contain connect states pair or "connected_states_end"
                    while (line != "connected_states_end") {
                        string index_str = "", occur_str = "";
                        index_str = strtok(getArray(line), " ,");
                        occur_str = strtok(NULL, " ,");
                        int index = offset + atoi(index_str.c_str());
                        double occurences = atof(occur_str.c_str());
                        s->connected_states.insert(pair<int, double>(index, occurences));
                        s->bubblesort_vector_descending(&s->vector_sorted_connected_states);
                        //fetch this at the the end
                        getline(myfile, line);
                    }
                    //2.GET ID 
                    getline(myfile, line); //id_start
                    getline(myfile, line); //id
                    //cout<<"Initial ID:"<<atoi(line.c_str())<<endl;
                    s->id_from_file = offset + atoi(line.c_str());
                    getline(myfile, line); //id_end
                    getline(myfile, line); //vector_letters_start
                    getline(myfile, line); //letter_start or letter_end

                    while (line == "letter_start") {
                        getline(myfile, line);
                        Letter letter_temp;

                        while (line == "note_start") {

                            getline(myfile, line); //note_start
                            //cout << "pitch before::" << line << endl;
                            //cout << line.size() << endl;
                            string pitch_str = "", position_str = "", velocity_str = "";
                            string pitch_str_2 = "", position_str_2 = "", velocity_str_2 = "";

                            strtok(getArray(line), " :");
                            pitch_str = strtok(NULL, " :");
                            pitch_str_2 = pitch_str.substr(0, (line.length() - 6));
                            //get chars 0...1
                            int pitch = atoi(pitch_str_2.c_str());
                            getline(myfile, line);
                            //cout << "position before::" << line << endl;
                            //cout << line.length() << endl;
                            strtok(getArray(line), " :");
                            position_str = strtok(NULL, " :");
                            position_str_2 = position_str.substr(0, (line.length() - 9));
                            //get chars 0...0-> only first char
                            int position = atoi(position_str_2.c_str());
                            getline(myfile, line);
                            //cout << "velocity before::" << line << endl;
                            //cout << line.size() << endl;
                            strtok(getArray(line), " :");
                            velocity_str = strtok(NULL, " :");
                            velocity_str_2 = velocity_str.substr(0, (line.length() - 9));
                            //get first 3 chars
                            int velocity = atoi(velocity_str_2.c_str());

                            RawNote r(0, 0, 0, pitch, velocity);
                            r.SetPosition(position);
                            getline(myfile, line); //note_end
                            getline(myfile, line); //note_start or pattern name
                            letter_temp.add_note(r);
                            //cout << "pitch::" << pitch << endl;
                            //cout << "velocity::" << velocity << endl;
                            //cout << "position::" << position << endl;
                        }
                        string pattern_str = line;
                        LetterPattern l;
                        l.SetName(pattern_str);
                        letter_temp.setPattern(l);
                        v_letters_temp.push_back(letter_temp);
                        //cout << "AddLetter" << endl;
                        getline(myfile, line);
                        getline(myfile, line); //either letter_start OR vector_letter_end
                        if (line == "vector_letter_end")break;
                    }
                    s->AddLetters(v_letters_temp);
                    //cout << "v_letters_temp.size()::" << v_letters_temp.size() << endl;
                    //cout << "s->GetLetters().size()::" << s->GetLetters().size() << endl;
                    v_letters_temp.clear();
                    if (line == "vector_letter_end")break;
                }
                //at the end check if state exists or null, if so then dont add it
                //check if state exists

                //cout << "s->GetLetters().size()::" << s->GetLetters().size() << endl;

                s->SetId(s->id_from_file);
                //cout << "new ID:" << s->GetId() << endl;
                vomc.push_back(s);
                getline(myfile, line); // state_end
                getline(myfile, line); // endl;
                getline(myfile, line); // endl; 
            }
        }
        myfile.close();
        update_vector_of_connected_states_from_connected_states();
    } else cout << "Unable to open file";
}

void VOMC::update_vector_of_connected_states_from_connected_states() {

    for (int i = 0; i < this->vomc.size(); i++) {
        pair <int, double> temp_number;
        bool exists;
        map<int, double>::iterator pos;
        for (pos = this->vomc.at(i)->connected_states.begin();
                pos != this->vomc.at(i)->connected_states.end();
                ++pos) {
            exists = false;
            //check if the pos->first exists in vector_connected_states
            for (int j = 0;
                    j < this->vomc.at(i)->vector_sorted_connected_states.size();
                    j++) {
                temp_number =
                        this->vomc.at(i)->vector_sorted_connected_states.at(j);
                if (pos->first == temp_number.first) {
                    this->vomc.at(i)->vector_sorted_connected_states.at(j);
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                this->vomc.at(i)->
                        vector_sorted_connected_states.push_back(
                        make_pair(pos->first, pos->second)
                        );
            }
        }
    }
}

char* VOMC::getArray(string s) {
    char *buf = new char[s.length()];
    for (int i = 0; i < s.length(); i++) {
        buf[i] = s.at(i);
    }
    return buf;
}

/**
 * 
 * @param input_letters is a <code>State<Letter></code> that contains 3 
 *      letters given as input to the function. 
 * @return a <code>State</code> that will consist of the pattern that
 *      should follow according to the input
 *      
 */
State VOMC::provide_response_pattern_remove(vector<Letter> input_letters) {

    // The input is 4 letters long. fx ABCD
    // The algorithm should try to find answers for all 3 possible combinations
    // a->BCD, ab->CD, abc->D. 
    vector<Letter> vl_4, vl_3, vl_2, vl_1;
    //cout << "input_letters.at(0):" << input_letters.at(0).getPattern().GetName() << endl;
    // cout << "input_letters.at(1):" << input_letters.at(1).getPattern().GetName() << endl;
    // cout << "input_letters.at(2):" << input_letters.at(2).getPattern().GetName() << endl;
    // cout << "input_letters.at(3):" << input_letters.at(3).getPattern().GetName() << endl;

    vl_1.push_back(input_letters.at(3));
    vl_2.push_back(input_letters.at(2));
    vl_2.push_back(input_letters.at(3));
    vl_3.push_back(input_letters.at(1));
    vl_3.push_back(input_letters.at(2));
    vl_3.push_back(input_letters.at(3));
    vl_4.push_back(input_letters.at(0));
    vl_4.push_back(input_letters.at(1));
    vl_4.push_back(input_letters.at(2));
    vl_4.push_back(input_letters.at(3));
    /*cout << "4 letter" << endl;
    for (int i = 0; i < vl_4.size(); i++) {
        cout << vl_4.at(i).getPattern().GetName() << endl;
    }
    cout << "3 letter" << endl;
    for (int i = 0; i < vl_3.size(); i++) {
        cout << vl_3.at(i).getPattern().GetName() << endl;
    }
    cout << "2 letter" << endl;
    for (int i = 0; i < vl_2.size(); i++) {
        cout << vl_2.at(i).getPattern().GetName() << endl;
    }
    cout << "1 letter" << endl;
    for (int i = 0; i < vl_1.size(); i++) {
        cout << vl_1.at(i).getPattern().GetName() << endl;
    }
     */
    State *vomc_s1, *vomc_s2, *vomc_s3, *vomc_s4;
    State return_state;
    //if id states to -1 than solution has not been found
    return_state.SetId(-1);
    vomc_s1 = new State(vl_1);
    vomc_s2 = new State(vl_2);
    vomc_s3 = new State(vl_3);
    vomc_s4 = new State(vl_4);
    //HQ.0.Attempt to find a similar 4-letter state with pitch and velocity
    //cout << "4 Letter, pitch and velocity" << endl;
    for (unsigned int i = 0; i < vomc.size(); i++) {
        if (compare_remove(vomc.at(i), vomc_s4)) {
            return_state = resolve_pattern(vomc.at(i));
            //cout"Attempt state ID:"<<vomc.at(i)->GetId()<<endl;
            if (return_state.GetId() != -1) {
                /*log_produced_rhythm(&return_state);
                log_current_states();
                log_result("4 Letter, Pitch and Velocity");*/
                s_4_v_p_r++;
                delete vomc_s1, vomc_s2, vomc_s3, vomc_s4;
                return return_state;
            }
            //if the return state.id = -1 then no solution was found
            //continue searching
        }
    }
    //HQ.1.Attempt to find a similar 3-letter state with pitch and velocity
    //cout <<"3 Letter, pitch and velocity" << endl;
    for (unsigned int i = 0; i < vomc.size(); i++) {
        if (compare_remove(vomc.at(i), vomc_s3)) {
            return_state = resolve_pattern(vomc.at(i));
            //cout"Attempt state ID:"<<vomc.at(i)->GetId()<<endl;
            if (return_state.GetId() != -1) {
                /*log_produced_rhythm(&return_state);
                log_current_states();
                log_result("3 Letter, Pitch and Velocity");*/
                s_3_v_p_r++;
                delete vomc_s1, vomc_s2, vomc_s3, vomc_s4;
                return return_state;
            }
            //if the return state.id = -1 then no solution was found
            //continue searching
        }
    }
    //HQ.2.Attempt to find a similar 2-letter state with pitch and velocity
    //cout <<"2 Letter, pitch and velocity" << endl;
    for (unsigned int i = 0; i < vomc.size(); i++) {
        if (compare_remove(vomc.at(i), vomc_s2)) {
            //cout"Attempt state ID:"<<vomc.at(i)->GetId()<<endl;
            return_state = resolve_pattern(vomc.at(i));
            ////cout << "returned " << i << endl;
            if (return_state.GetId() != -1) {
                /*log_produced_rhythm(&return_state);
                log_current_states();
                log_result("2 Letter, Pitch and Velocity");*/
                s_2_v_p_r++;
                delete vomc_s1, vomc_s2, vomc_s3, vomc_s4;
                return return_state;
            }
        }
    }
    //HQ.3.Attempt to find a similar 1-letter state with pitch and velocity
    //cout <<"1 Letter, pitch and velocity" << endl;
    for (unsigned int i = 0; i < vomc.size(); i++) {
        if (compare_remove(vomc.at(i), vomc_s1)) {
            //cout"Attempt state ID:"<<vomc.at(i)->GetId()<<endl;
            return_state = resolve_pattern(vomc.at(i));
            if (return_state.GetId() != -1) {
                /*log_produced_rhythm(&return_state);
                log_current_states();
                log_result("1 Letter, Pitch and Velocity");*/
                s_1_v_p_r++;
                delete vomc_s1, vomc_s2, vomc_s3, vomc_s4;
                return return_state;
            }
        }
    }
    //MQ.1.Attempt to find a similar 3-letter state with pitch
    //cout <<"4 Letter, pitch" << endl;
    for (unsigned int i = 0; i < vomc.size(); i++) {
        if (compare_remove_without_velocity(vomc.at(i), vomc_s4)) {
            //cout"Attempt state ID:"<<vomc.at(i)->GetId()<<endl;
            return_state = resolve_pattern(vomc.at(i));
            if (return_state.GetId() != -1) {
                /*log_produced_rhythm(&return_state);
                log_current_states();
                log_result("4 Letter, Pitch");*/
                s_4_p_r++;
                delete vomc_s1, vomc_s2, vomc_s3, vomc_s4;
                return return_state;
            }
        }
    }
    //MQ.1.Attempt to find a similar 3-letter state with pitch
    //cout <<"3 Letter, pitch" << endl;
    for (unsigned int i = 0; i < vomc.size(); i++) {
        if (compare_remove_without_velocity(vomc.at(i), vomc_s3)) {
            return_state = resolve_pattern(vomc.at(i));
            //cout"Attempt state ID:"<<vomc.at(i)->GetId()<<endl;
            if (return_state.GetId() != -1) {
                /*log_produced_rhythm(&return_state);
                log_current_states();
                log_result("3 Letter, Pitch");*/
                s_3_p_r++;
                delete vomc_s1, vomc_s2, vomc_s3, vomc_s4;
                return return_state;
            }
        }
    }
    //MQ.2.Attempt to find a similar 2-letter state with pitch
    //cout <<"2 Letter, pitch" << endl;
    for (unsigned int i = 0; i < vomc.size(); i++) {
        if (compare_remove_without_velocity(vomc.at(i), vomc_s2)) {
            return_state = resolve_pattern(vomc.at(i));
            //cout"Attempt state ID:"<<vomc.at(i)->GetId()<<endl;
            if (return_state.GetId() != -1) {
                /*log_produced_rhythm(&return_state);
                log_current_states();
                log_result("2 Letter, Pitch");*/
                s_2_p_r++;
                delete vomc_s1, vomc_s2, vomc_s3, vomc_s4;
                return return_state;
            }
        }
    }
    //MQ.3.Attempt to find a similar 1-letter state with pitch
    //cout <<"1 Letter, pitch" << endl;
    for (unsigned int i = 0; i < vomc.size(); i++) {
        if (compare_remove_without_velocity(vomc.at(i), vomc_s1)) {
            //cout"Attempt state ID:"<<vomc.at(i)->GetId()<<endl;
            return_state = resolve_pattern(vomc.at(i));
            if (return_state.GetId() != -1) {
                /*log_produced_rhythm(&return_state);
                log_current_states();
                log_result("1 Letter, Pitch");*/
                s_1_p_r++;
                delete vomc_s1, vomc_s2, vomc_s3, vomc_s4;
                return return_state;
            }
        }
    }
    //LQ.0.Attempt to find a similar 3-letter state
    //cout <<"4 Letter" << endl;
    for (unsigned int i = 0; i < vomc.size(); i++) {
        if (compare_remove_without_pitch_velocity(vomc.at(i), vomc_s4)) {
            //cout"Attempt state ID:"<<vomc.at(i)->GetId()<<endl;
            return_state = resolve_pattern(vomc.at(i));
            if (return_state.GetId() != -1) {
                /*log_produced_rhythm(&return_state);
                log_current_states();
                log_result("4 Letter");*/
                s_4_r++;
                delete vomc_s1, vomc_s2, vomc_s3, vomc_s4;
                return return_state;
            }
        }
    }
    //LQ.1.Attempt to find a similar 3-letter state
    //cout <<"3 Letter" << endl;
    for (unsigned int i = 0; i < vomc.size(); i++) {
        if (compare_remove_without_pitch_velocity(vomc.at(i), vomc_s3)) {
            //cout"Attempt state ID:"<<vomc.at(i)->GetId()<<endl;
            return_state = resolve_pattern(vomc.at(i));
            if (return_state.GetId() != -1) {
                /*log_produced_rhythm(&return_state);
                log_current_states();
                log_result("3 Letter");*/
                s_3_r++;
                delete vomc_s1, vomc_s2, vomc_s3, vomc_s4;
                return return_state;
            }
        }
    }
    //LQ.2.Attempt to find a similar 2-letter state
    //cout <<"2 Letter" << endl;
    for (unsigned int i = 0; i < vomc.size(); i++) {
        if (compare_remove_without_pitch_velocity(vomc.at(i), vomc_s2)) {
            //cout"Attempt state ID:"<<vomc.at(i)->GetId()<<endl;
            return_state = resolve_pattern(vomc.at(i));
            if (return_state.GetId() != -1) {
                /*log_produced_rhythm(&return_state);
                log_current_states();
                log_result("2 Letter");*/
                s_2_r++;
                delete vomc_s1, vomc_s2, vomc_s3, vomc_s4;
                return return_state;
            }
        }
    }
    //LQ.3.Attempt to find a similar 1-letter state
    //cout <<"1 Letter" << endl;
    for (unsigned int i = 0; i < vomc.size(); i++) {
        if (compare_remove_without_pitch_velocity(vomc.at(i), vomc_s1)) {
            //cout"Attempt state ID:"<<vomc.at(i)->GetId()<<endl;
            return_state = resolve_pattern(vomc.at(i));
            if (return_state.GetId() != -1) {
                /*log_produced_rhythm(&return_state);
                log_current_states();
                log_result("1 Letter");*/
                s_1_r++;
                delete vomc_s1, vomc_s2, vomc_s3, vomc_s4;
                return return_state;
            }
        }
    }
    State s(input_letters);
    s.SetId(-1);
    /*log_current_states();
    log_produced_rhythm(&s);
    log_result("No solution");*/
    delete vomc_s1, vomc_s2, vomc_s3, vomc_s4;
    return s;
}


/**
 * 
 * @param s1_in, input state with 1 to 3 letters. I should add the rest
 * @return a <code>State</code> with an id different than -1
 */
// We will only need to extract a connected state, and it's connected state.
// Our goal is to extract 8 letter patters.
// A 1-letter pattern is connected to 3 letter patterns only = 4 letters total
// A 2-letter pattern is connected to 2 letter patterns only = 4 letters total
// A 3-letter pattern is connected to 1 letter patterns only = 4 letters total
// similarly wee extract 4 more.
//

State VOMC::resolve_pattern(State *s1_in) {
    // skim through all possible connect states, 
    // if we cannot extract 8 letters return state with -1
    State s_solution, s_current, s_not_found, s_next;
    s_current = *s1_in;
    s_not_found.SetId(-1);

    for (unsigned int i = 0; i < s_current.vector_sorted_connected_states.size(); i++) {
        // the choice of the states should be done with a random factor.
        // random_mixing_of "vector_sorted_connected_states" TODO
        // cout"current state"<<s_current.GetId()<<endl;
        while (true) {
            if (!s_current.vector_sorted_connected_states.empty()) {
                //FIRST>Deterministic Get the vector with the highest probability
                //s_next = *get_state_by_id(s_current->vector_sorted_connected_states.at(i).first);
                s_next = *get_state_by_id(s_current.get_connected_state_stochastically());
                //cout"next state"<<s_next.GetId()<<endl;
                //current_next_transition_state = s_next;
                s_solution = combine_states(&s_solution, &s_next);
                //if we reach 8 letters or more return. It is not possible to 
                //reach more than 8 letters
                if (s_solution.GetLetters().size() == 8) {
                    return s_solution;
                }
                if (s_solution.GetLetters().size() > 8) {
                    throw "More than 8 letters!Impossible!Well...never say never.";
                }
                s_current = s_next;
            } else {
                //try next state
                //cout"VOMC 705 no solution"<<endl;
                break;
            }
        }
        //3rd edition of pattern_resolve
    }
    return s_not_found;
}

State VOMC::resolve_pattern_4_letters(State * s1_in) {
    // skim through all possible connect states, 
    // if we cannot extract 4 letters return state with -1
    State *s1_out;
    State *s2_out;
    State s_out;
    s_out.SetId(-1);
    //cout << s1_in->GetId() << endl;
    for (unsigned int i = 0; i < s1_in->vector_sorted_connected_states.size(); i++) {
        //the choice of the states should be done with a random factor.
        //random_mixing_of "vector_sorted_connected_states" TODO
        s1_out = get_state_by_id(s1_in->vector_sorted_connected_states.at(i).first);
        //cout << "1st state found:" << s1_out->GetId() << endl;
        if (s1_out->GetLetters().size() == MAX_LETTERS) {
            return *s1_out;
        }
        if (!s1_out->vector_sorted_connected_states.empty()) {
            //get the element with the highest number of occurrences
            s2_out =
                    get_state_by_id(
                    s1_out->vector_sorted_connected_states.at(0).first
                    );
            //cout << "2nd state found:" << s2_out->GetId() << endl;
            s_out = combine_states(s1_out, s2_out);
            return s_out;
        } else {
            s_out.SetId(-1);
            return s_out;
        }
    }
    return s_out;
}
/**
 * 
 * @param s1 is a <code>State*</code>.
 * @param s2 is a <code>State*</code>.
 * @return A <code>State</code> created from the merging of the above two.
 */

State VOMC::combine_states(State* s1, State * s2) {

    State s_out;
    s_out.SetId(-2);
    s_out.SetLetters(s1->GetLetters());
    s_out.AddLetters(s2->GetLetters());
    return s_out;
}

/**
 * @param s1 is a <code>State*</code> which is going to be 
 *      compared with another state
 * @param s2 is a <code>State*</code>
 * @return A <code>bool</code> equal to TRUE if states are identical,
 *      FALSE otherwise.
 */
bool VOMC::compare_remove(State* s1, State * s2) {

    if (s1->GetLetters().size() == s2->GetLetters().size()) {
        //Check Letter Patterns
        //AND
        //check for Number of Notes per Letter
        for (unsigned int i = 0; i < s1->GetLetters().size(); i++) {
            if (
                    (
                    s1->GetLetters().at(i).getPattern().GetName().compare(
                    s2->GetLetters().at(i).getPattern().GetName()) != 0
                    )
                    ||
                    (
                    s1->GetLetters().at(i).getRawNotes().size() !=
                    s2->GetLetters().at(i).getRawNotes().size()
                    )
                    ) {
                return false;
            }
            //check that some of the notes in s1 does not exist in s2,
            //return FALSE
            for (unsigned int j = 0; j < s1->GetLetters().at(i).getRawNotes().size(); j++) {
                if (!(
                        s2->GetLetters().at(i).has_note_with_velocity(
                        &s1->GetLetters().at(i).getRawNotes().at(j)
                        )
                        )
                        ) {
                    return false;
                }
            }
        }
        //if it passed through 1,2 and 3 then states are identical!
        return true;
    }
    return false;
}

/**
 * @param s1 is a <code>State*</code> which is going to be 
 *      compared with another state
 * @param s2 is a <code>State*</code>
 * @return A <code>bool</code> equal to true if states are similar,
 *      false otherwise. States will be considered the same if the 
 *      following hold:
 *      Number of letters are the same
 *      Every letter will have the same pattern
 *      Every letter will have the same number of notes
 *      Every note of every letter should have the same timbre and position
 *      (For every letter in s1 we will try to find a match in s2)
 *      
 */

bool VOMC::compare_remove_without_velocity(State* s1, State * s2) {

    if (s1->GetLetters().size() == s2->GetLetters().size()) {
        //Check Letter Patterns
        //AND
        //check for Number of Notes per Letter
        for (unsigned int i = 0; i < s1->GetLetters().size(); i++) {
            if (
                    (
                    s1->GetLetters().at(i).getPattern().GetName().compare(
                    s2->GetLetters().at(i).getPattern().GetName()) != 0
                    )
                    ||
                    (
                    s1->GetLetters().at(i).getRawNotes().size() !=
                    s2->GetLetters().at(i).getRawNotes().size()
                    )
                    ) {
                return false;
            }
            //check that some of the notes in s1 does not exist in s2,
            //return FALSE
            for (unsigned int j = 0; j < s1->GetLetters().at(i).getRawNotes().size(); j++) {
                if (!(
                        s2->GetLetters().at(i).has_note_no_velocity(
                        &s1->GetLetters().at(i).getRawNotes().at(j)
                        )
                        )
                        ) {
                    return false;
                }
            }
        }
        //if it passed through 1,2 and 3 then states are identical!
        return true;
    }
    return false;
}

/**
 * @param s1 is a <code>State*</code> which is going to be 
 *      compared with another state
 * @param s2 is a <code>State*</code>
 * @return A <code>bool</code> equal to true if states are similar,
 *      false otherwise. For this we only check the state's patterns
 */

bool VOMC::compare_remove_without_pitch_velocity(State* s1, State * s2) {
    if (s1->GetLetters().size() == s2->GetLetters().size()) {
        for (unsigned int i = 0; i < s1->GetLetters().size(); i++) {
            if (s1->GetLetters().at(i).getPattern().GetName().compare(
                    s2->GetLetters().at(i).getPattern().GetName()) != 0
                    ) {
                return false;
            }
        }
        return true;
    }
    return false;
}

vector<Letter> VOMC::provide_response_pattern_weight(vector<Letter> input_letters) {
    // The input is 4 letters long. fx ABCD
    // The algorithm should try to find answers for all 3 possible combinations
    // a->BCD, ab->CD, abc->D. 
    // Every state will have a degree of similarity, 
    //          namely sds(State Degree Similarity)
    // For that state the probability of transiting to a next state will be
    //          defined as stp(State transition probability)
    // A first idea is that the weight of the returned value can be 
    // The multiplication of the above elements
    // A solution for all 3 possible combinations can be derived, if for all 3
    // we have a solution then we compare it

    throw "Not implemented yet";
}

void VOMC::compare_weight(State* s1, State * s2) {
    throw "Not implemented yet";
}

/**
 * 
 * @param letters is a <code>vector<Letter></code> that holds 4 letters. These
 *        are the input letters according to which, we will skim through all
 *        states in an attempt to either find an identical state, and increase
 *        its probability of occurrence
 *        or 
 *        create a new state and add it to @vomc@
 *       
 */
void VOMC::train(vector<Letter> letters) {

    vector<Letter> tempLettersA1;
    vector<Letter> tempLettersB1;
    //cout << letters.size() << "==4?" << endl;
    tempLettersA1.push_back(letters.at(0));
    tempLettersB1.push_back(letters.at(1));
    tempLettersB1.push_back(letters.at(2));
    tempLettersB1.push_back(letters.at(3));
    vector<Letter> tempLettersA2;
    vector<Letter> tempLettersB2;
    tempLettersA2.push_back(letters.at(0));
    tempLettersA2.push_back(letters.at(1));
    tempLettersB2.push_back(letters.at(2));
    tempLettersB2.push_back(letters.at(3));
    vector<Letter> tempLettersA3;
    vector<Letter> tempLettersB3;
    tempLettersA3.push_back(letters.at(0));
    tempLettersA3.push_back(letters.at(1));
    tempLettersA3.push_back(letters.at(2));
    tempLettersB3.push_back(letters.at(3));
    sub_train(tempLettersA1, tempLettersB1);
    sub_train(tempLettersA2, tempLettersB2);
    sub_train(tempLettersA3, tempLettersB3);
    if (!previous_letters.empty()) {
        //Train new with previous elements
        vector<Letter> tempLettersC1;
        tempLettersC1.push_back(previous_letters.at(3));
        vector<Letter> tempLettersC2;
        tempLettersC2.push_back(previous_letters.at(2));
        tempLettersC2.push_back(previous_letters.at(3));
        vector<Letter> tempLettersC3;
        tempLettersC3.push_back(previous_letters.at(1));
        tempLettersC3.push_back(previous_letters.at(2));
        tempLettersC3.push_back(previous_letters.at(3));
        sub_train(tempLettersC3, tempLettersA1);
        sub_train(tempLettersC2, tempLettersA2);
        sub_train(tempLettersC1, tempLettersA3);
        //connection from previous to next meter
        sub_train(previous_letters, letters);
        previous_letters.clear();
    }
    previous_letters = letters;
}
/**
 * 
 * @param tempLettersA is a <code>vector<Letter></code>.
 * @param tempLettersB is a <code>vector<Letter></code>.
 */
void VOMC::sub_train(vector<Letter> tempLettersA, vector<Letter> tempLettersB) {
    int stateA_id = state_exists(tempLettersA);

    State *tempStateA;

    if (stateA_id != -1) {
        // state A exists
        tempStateA = get_state_by_id(stateA_id);
        // cout << "VOMC Real-Time::state_exists" << endl;
    } else {
        // state A does not exist
        // Create state A 
        tempStateA = new State(tempLettersA);
        // cout << "VOMC Real-Time:: New State" << endl;
        // register it to the vomc
        vomc.push_back(tempStateA);
    }

    int stateB_id = state_exists(tempLettersB);
    
    if (stateB_id != -1) {
        // state B exists in VOMC
        tempStateA->inc_state(stateB_id);
    } else {
        // state B does not exist
        State* tempStateB;
        tempStateB = new State(tempLettersB);
        //register it to the vomc
        vomc.push_back(tempStateB);
        //Get newly created ID
        stateB_id = tempStateB->GetId();
        //record transition A->B
        tempStateA->inc_state(stateB_id);
    }
}

/**
 * 
 * @param ID is an <code>int</code>, representing the ID of the state
 *        we are looking for
 * @return State*, that has the same ID 
 */
State * VOMC::get_state_by_id(int ID) {

    for (unsigned int i = 0; i < vomc.size(); i++) {
        if (vomc.at(i)->GetId() == ID) {
            return vomc.at(i);
        }
    }
    throw "VOMC::get_state_by_id() could not find an ID";
}

/**
 * 
 * @param s1 is a <code>State*</code>.
 * @param s2 is a <code>State*</code>.
 * @return TRUE, if the two states are the same 
 *         or FALSE if the states are different.
 */
bool VOMC::states_equal(State *s1, State *s2) {

    if (s1->GetLetters().size() == s2->GetLetters().size()) {
        //scan letter
        for (unsigned int j = 0; j < s1->GetLetters().size(); j++) {
            //same pattern? for example "AD","AD"?
            if (s1->GetLetters().at(j).getPattern().GetName() == s2->GetLetters().at(j).getPattern().GetName()) {
                // same number of notes?
                if (s1->GetLetters().at(j).getRawNotes().size() == s2->GetLetters().at(j).getRawNotes().size()) {

                    for (unsigned int noteId = 0; noteId < s1->GetLetters().at(j).getRawNotes().size(); noteId++) {
                        if (!note_exists(
                                s1->GetLetters().at(j).getRawNotes().at(noteId),
                                s2->GetLetters().at(j).getRawNotes()
                                )
                                ) {
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * 
 * @param tempLettersA is a <code>vector<Letter></code>.
 * 
 * @return -1 if there does not exist a state containing exactly this letters, 
 *      else return the state-ID.
 * 
 */
int VOMC::state_exists(vector<Letter> tempLettersA) {
    bool foundState;
    for (unsigned int i = 0; i < this->vomc.size(); i++) {
        // same size?
        foundState = false;
        if (this->vomc.at(i)->GetLetters().size() == tempLettersA.size()) {
            // scan number of letters?
            for (unsigned int j = 0; j < this->vomc.at(i)->GetLetters().size(); j++) {
                //   same pattern? for example "AD","AD"?
                if (this->vomc.at(i)->GetLetters().at(j).getPattern().GetName() == tempLettersA.at(j).getPattern().GetName()) {
                    // same number of notes?
                    if (this->vomc.at(i)->GetLetters().at(j).getRawNotes().size() == tempLettersA.at(j).getRawNotes().size()) {

                        //find if every note of the tempLettersA pattern has a matching
                        foundState = true;
                        for (unsigned int noteId = 0; noteId < tempLettersA.at(j).getRawNotes().size(); noteId++) {
                            if (!note_exists(
                                    tempLettersA.at(j).getRawNotes().at(noteId),
                                    this->vomc.at(i)->GetLetters().at(j).getRawNotes()
                                    )
                                    ) {
                                foundState = false;
                                break;
                            }
                        }
                    } else {
                        foundState = false;
                        break;
                    }
                } else {
                    foundState = false;
                    break;
                }
                if (!foundState)break;
            }
            //all notes exist and since the number of notes is
            //the same, THEN the letters are considered 
            //equal
            if (foundState)
                return this->vomc.at(i)->GetId();
        }
    }
    return -1;
}

/**
 * 
 * @param rawNote is a <code>RawNote</code> whose existence in rawNoteVector 
 *                 will checked.
 * @param rawNoteVector is a <code>vector<RawNote></code>. 
 * @return true, if there is an identical note in rawNoteVector, 
 *         else returns false.
 */
bool VOMC::note_exists(RawNote rawNote, vector<RawNote> rawNoteVector) {

    //cout <<"Input note::"<< rawNote.GetPosition() << "," << rawNote.GetPitch() << "," << rawNote.GetVelocity() << endl;
    for (unsigned int i = 0; i < rawNoteVector.size(); i++) {
        //note will exist if it is on the same position
        //and has the same timbre/pitch
        //cout <<"Compare against::"<< rawNoteVector.at(i).GetPosition() << "," << rawNoteVector.at(i).GetPitch() << "," << rawNoteVector.at(i).GetVelocity() << endl;
        if (
                (rawNoteVector.at(i).GetPosition() == rawNote.GetPosition())
                &&
                (rawNoteVector.at(i).GetPitch() == rawNote.GetPitch())
                &&
                    (rawNoteVector.at(i).GetVelocity() == rawNote.GetVelocity())
                ) {
            //cout<<"Note found"<<endl;
            return true;
        }else{
            //cout<<"Check Next Note"<<endl;
        }
    }
    //cout<<"Note note found"<<endl;
    return false;

}

bool VOMC::find_letter_without_velocity(Letter* l1, vector<Letter>l2) {
    throw "not yet implemented";
}

bool VOMC::find_letter_with_velocity(Letter* l1, vector<Letter>l2) {
    throw "not yet implemented";
}

void VOMC::print() {
    cout << endl;
    cout << endl;
    cout << "VOMC printout" << endl;
    for (unsigned int i = 0; i < vomc.size(); i++) {
        map<int, double>::iterator it;
        cout << endl;
        cout << "ID:" << vomc.at(i)->GetId() << endl;
        //cout<<"Number of letters:"<< vomc.at(i)->GetLetters().size();
        //for (int j = 0; j < vomc.at(i)->GetLetters().size(); j++) {
        // cout<<"Letter:"<<j<<endl;
        //cout<<"Has:"<< vomc.at(i)->GetLetters().at(j).getRawNotes().size()<<" number of notes" <<endl;
        //}
        //for (unsigned int j = 0; j < vomc.at(i)->GetLetters().size(); j++) {
        //    cout << vomc.at(i)->GetLetters().at(j).getPattern().GetName() << endl;
        //}

        cout << "vector_sorted connected states" << endl;
        for (int k = 0; k < vomc.at(i)->vector_sorted_connected_states.size(); k++) {
            cout << vomc.at(i)->GetId() << "->";
            cout << vomc.at(i)->vector_sorted_connected_states.at(k).first << "(";
            cout << vomc.at(i)->vector_sorted_connected_states.at(k).second << ")"
                    << endl;
        }
        cout << "connected states" << endl;
        for (std::map<int, double>::iterator ob = vomc.at(i)->connected_states.begin(); ob != vomc.at(i)->connected_states.end(); ++ob) {
            cout << vomc.at(i)->GetId() << "->";
            cout << ob->first << "(";
            cout << ob->second << ")"
                    << endl;
        }
        //cout << "printoutnotes" << endl;
        for (int t = 0; t < vomc.at(i)->GetLetters().size(); t++) {
            cout << "Letter::" << t << endl;
            for (int p = 0; p < vomc.at(i)->GetLetters().at(t).getRawNotes().size(); p++) {
                cout << "Pitch::" << vomc.at(i)->GetLetters().at(t).getRawNotes().at(p).GetPitch() << endl;
                cout << "Velocity::" << vomc.at(i)->GetLetters().at(t).getRawNotes().at(p).GetVelocity() << endl;
                cout << "Position::" << vomc.at(i)->GetLetters().at(t).getRawNotes().at(p).GetPosition() << endl;
            }
        }
        vomc.at(i)->print_state_letters();
        //cout << "------------------" << endl;
    }
}
/**
 * 
 * @param choice is a <code>string</code> that will be registered in the 
 * logging file.
 */
void VOMC::log_result(string choice) {
    ofstream choice_file;
    choice_file.open("logger/choice_logger.txt", std::ios_base::app);
    choice_file << choice_log_id++ << ")" << choice << ". \n";
    choice_file.close();
}
/**
 * @param s is a <code>State *</code> that will be logged in the logger file.
 */
void VOMC::log_produced_rhythm(State * s) {
    ofstream rhythm_file;
    rhythm_file.open("logger/rhythm_logger.txt", std::ios_base::app);
    rhythm_file << "*************************************************" << endl;
    rhythm_file << "*************************************************" << endl;
    rhythm_file << "ID::" << rhythm_log_id++ << endl;
    rhythm_file << "\n";
    for (int i = 0; i < s->GetLetters().size(); i++) {
        rhythm_file << s->GetLetters().at(i).print_hihat() << " ";
    }
    rhythm_file << "\n";
    for (int i = 0; i < s->GetLetters().size(); i++) {
        rhythm_file << s->GetLetters().at(i).print_instrument(t1) << " ";
    }
    rhythm_file << "\n";
    for (int i = 0; i < s->GetLetters().size(); i++) {
        rhythm_file << s->GetLetters().at(i).print_instrument(sn) << " ";
    }
    rhythm_file << "\n";
    for (int i = 0; i < s->GetLetters().size(); i++) {
        rhythm_file << s->GetLetters().at(i).print_instrument(lt) << " ";
    }
    rhythm_file << "\n";
    for (int i = 0; i < s->GetLetters().size(); i++) {
        rhythm_file << s->GetLetters().at(i).print_instrument(bd) << " ";
    }
    rhythm_file << "\n";
    rhythm_file.close();
}

/**
 * 
 * @param v is a <code>VOMC*</code> containing all states.
 * The connection diagram of these states will be drawn.
 * fx for state 1:
 * ID:1 => 3 [5]
 * ID:1 => 2 [12]
 * etc etc
 */
void VOMC::log_current_states() {
    ofstream state_file;
    state_file.open("logger/state_logger.txt", std::ios_base::app);
    state_file << "VOMC printout ID::" << states_log_id++ << endl;
    state_file << "\n";
    for (unsigned int i = 0; i < this->vomc.size(); i++) {
        map<int, double>::iterator it;
        state_file << "ID:" << this->vomc.at(i)->GetId() << endl;
        state_file << "\n";
        state_file << "Number of letters:" << this->vomc.at(i)->GetLetters().size();
        for (int j = 0; j < this->vomc.at(i)->GetLetters().size(); j++) {
            // state_file<<"Letter:"<<j<<endl;
            state_file << "Has:" << this->vomc.at(i)->GetLetters().at(j).getRawNotes().size() << " number of notes" << endl;
        }
        state_file << "\n";
        for (unsigned int j = 0; j < this->vomc.at(i)->GetLetters().size(); j++) {
            state_file << this->vomc.at(i)->GetLetters().at(j).getPattern().GetName() << endl;
        }

        state_file << "vector_sorted connected states" << endl;
        state_file << "\n";
        for (int k = 0; k < this->vomc.at(i)->vector_sorted_connected_states.size(); k++) {
            state_file << this->vomc.at(i)->GetId() << "->";
            state_file << this->vomc.at(i)->vector_sorted_connected_states.at(k).first << "(";
            state_file << this->vomc.at(i)->vector_sorted_connected_states.at(k).second << ")"
                    << endl;
        }
        /*state_file << "connected states" << endl;
        for (std::map<int, double>::iterator ob = this->vomc.at(i)->connected_states.begin(); ob != this->vomc.at(i)->connected_states.end(); ++ob) {
            state_file << this->vomc.at(i)->GetId() << "->";
            state_file << ob->first << "(";
            state_file << ob->second << ")" << endl;
        }*/
        state_file << "------------------" << endl;
    }
    state_file << "\n";
    state_file << "\n";
    state_file << "\n";

    state_file.close();

}

VOMC::~VOMC() {
    //cout << "VOMC destroyed." << endl;
}