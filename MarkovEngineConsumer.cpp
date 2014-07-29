/* 
 * File:   MarkovEngineConsumer.cpp
 * Author: Ioannis Chionidis
 * 
 * Created on June 4, 2012, 11:35 PM
 */

#include "MarkovEngineConsumer.h"
#include "Letter.h"

MarkovEngineConsumer::MarkovEngineConsumer() {
    helper = new Helper();
}
/**
 * 
 *@param queue is a <code>SynchronizedQueue<Meter>*</code> which 
 * communicates <code>Meter</code> objects among either <code>DrumMachine</code> or 
 * <code>MidiHandlerProducer</code> objects with <code>MarkovEngineConsumer</code> Objects.
 * @param tempo is <code>double</code> representing the simulation's tempo.
 * @param offset is <code>double</code> representing the timing offset not needed in the DrumMachine.
 * @param A is <code>int</code> representing the number of quarter notes per <code>Meter</code>.
 * @param metronome_start is <code>double</code> representing the start of the metronome.
 * @param meter_start is <code>double</code> representing the start of the meter.
 * @param h is <code>Helper *</code>.
 */
MarkovEngineConsumer::MarkovEngineConsumer(
SynchronizedQueue<Meter>* queue, double tempo, 
        double offset, int A, double metronome_start, double meter_start, Helper *h) {
    //////cout << "MarkovEngineConsumer Constructor" << endl;
    this->m_queue = queue;
    this->tempo = tempo;
    this->offset = offset;
    this->qn_duration = ceil(60000 / tempo);
    this->meter_duration = ceil((double) A * this->qn_duration);
    this->meter_length_in_qn = A;
    this->metronome_start = metronome_start;
    this->meter_start = meter_start;
    this->helper = h;
}

void MarkovEngineConsumer::load_files() {
    ifstream ifile_0("output/output_rock");
    if (ifile_0) {
        //////cout << "Load file" << endl;
        vomc.load("output/output_rock", 0);
        //////cout << "ID:" << vomc.vomc.at(vomc.vomc.size() - 1)->GetId() << endl;
        //////cout << "ID generator:" << vomc.vomc.at(vomc.vomc.size() - 1)->id_generator << endl;
    }

    ifstream ifile_1("output/output_rock3");
    if (ifile_1) {
        //////cout << "Load file" << endl;
        vomc.load("output/output_rock3", vomc.vomc.at(vomc.vomc.size() - 1)->GetId() + 1);
        //////cout << "ID:" << vomc.vomc.at(vomc.vomc.size() - 1)->GetId() << endl;
        //////cout << "ID generator:" << vomc.vomc.at(vomc.vomc.size() - 1)->id_generator << endl;
    }
    vomc.sort_vomc();
    vomc.print_connected_states();
}

void MarkovEngineConsumer::operator () () {

    Rhythm_automata *ra;
    vector<RawNote> notesLeftOver;
    vector<Letter> first_vector_of_letters;
    vector<Letter> second_vector_of_letters;
    vector<Letter> letters(2 * this->meter_length_in_qn);
    this->vomc.init();
    State s_set_counter; //sets the value of the state counter
    int cnt_meters = 0;
    try {
        while (true) {

            s_set_counter.id_generator = this->vomc.vomc.size();
            ////////cout<<"Set Id Generator to"<<s_set_counter.id_generator<<endl;
            //cout << "MarkovEngineConsumer::Meter Start for the coming notes" << meter_start << endl;        
            rNotes = m_queue->Dequeue().get_notes();
            s_set_counter.id_generator = cnt_meters++ * 100;
            cout << "MarkovEngineConsumer::" << fixed << meter_start << endl;
            //cout << "MarkovEngineConsumer::Received.size()=" << rNotes.size() << endl;
            //DRUM MACHINE CASE
            if (!notesLeftOver.empty()) {
                for (int i = 0; i < notesLeftOver.size(); i++) {
                    rNotes.push_back(notesLeftOver.at(i));
                }
                notesLeftOver.clear();
            }
            //wait for start time to be set
            //this->helper->wait(NMTT_W * this->qn_duration);
            for (int i = 0; i < rNotes.size(); i++) {
                //cout << "GeneralTimeStamp::" << rNotes.at(i).GetGeneralTimeStamp() << endl;
                //cout << "Make a CHOICE" << endl;
                //cout << "meter_start" << meter_start << endl;
                //int vel_1 = ppp;
                if (rNotes.at(i).GetVelocity() < int(16)) {
                    rNotes.at(i).SetVelocity(int(16));
                } else if (rNotes.at(i).GetVelocity() < int(33)) {
                    rNotes.at(i).SetVelocity(int(33));
                    //cout << "33" << endl;
                } else if (rNotes.at(i).GetVelocity() < int(49)) {
                    rNotes.at(i).SetVelocity(int(49));
                    //cout << "49" << endl;
                } else if (rNotes.at(i).GetVelocity() < int(64)) {
                    rNotes.at(i).SetVelocity(int(64));
                    //cout << "64" << endl;
                } else if (rNotes.at(i).GetVelocity() < int(80)) {
                    rNotes.at(i).SetVelocity(int(80));
                    //cout << "80" << endl;

                } else if (rNotes.at(i).GetVelocity() < int(96)) {
                    rNotes.at(i).SetVelocity(int(96));
                    //cout << "96" << endl;

                } else if (rNotes.at(i).GetVelocity() < int(112)) {
                    //cout << "112" << endl;
                    rNotes.at(i).SetVelocity(int(112));
                } else {
                    //cout << "126" << endl;
                    rNotes.at(i).SetVelocity(int(126));
                }

                if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 0.5 * qn_duration - (qn_duration / 24))) {
                    letters.at(0).add_note(rNotes.at(i));
                    //  cout << " CHOICE : 0 " << endl;

                } else if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + qn_duration - (qn_duration / 24))) {

                    if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 0.5 * qn_duration)) {
                        rNotes.at(i).SetEighthNoteTimeStamp(0);
                    }
                    //cout << " CHOICE : 1 " << endl;
                    letters.at(1).add_note(rNotes.at(i));

                } else if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 1.5 * qn_duration - (qn_duration / 24))) {
                    if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + qn_duration)) {

                        rNotes.at(i).SetEighthNoteTimeStamp(0);
                    }
                    //cout << " CHOICE : 2 " << endl;
                    letters.at(2).add_note(rNotes.at(i));

                } else if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 2 * qn_duration - (qn_duration / 24))) {
                    if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 1.5 * qn_duration)) {
                        rNotes.at(i).SetEighthNoteTimeStamp(0);
                    }
                    //cout << " CHOICE :3 " << endl;
                    letters.at(3).add_note(rNotes.at(i));
                } else if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 2.5 * qn_duration - (qn_duration / 24))) {
                    if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 2. * qn_duration)) {
                        rNotes.at(i).SetEighthNoteTimeStamp(0);
                    }
                    //cout << " CHOICE : 4 " << endl;
                    letters.at(4).add_note(rNotes.at(i));

                } else if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 3 * qn_duration - (qn_duration / 24))) {
                    if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 2.5 * qn_duration)) {
                        rNotes.at(i).SetEighthNoteTimeStamp(0);
                    }
                    //cout << " CHOICE : 5 " << endl;
                    letters.at(5).add_note(rNotes.at(i));
                } else if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 3.5 * qn_duration - (qn_duration / 24))) {
                    if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 3. * qn_duration)) {
                        rNotes.at(i).SetEighthNoteTimeStamp(0);
                    }
                    //cout << " CHOICE :6 " << endl;
                    letters.at(6).add_note(rNotes.at(i));
                } else if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 4 * qn_duration - (qn_duration / 24))) {
                    if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 3.5 * qn_duration)) {
                        rNotes.at(i).SetEighthNoteTimeStamp(0);
                    }
                    //cout << " CHOICE :7 " << endl;
                    letters.at(7).add_note(rNotes.at(i));

                } else {
                    //  cout << " CHOICE :Leftover " << endl;
                    rNotes.at(i).SetEighthNoteTimeStamp(0);
                    notesLeftOver.push_back(rNotes.at(i));
                }
            }
            /*for (int i = 0; i < letters.size(); i++) {
                cout << "Letter[" << i << "]=" << letters.at(i).getRawNotes().size() << endl;
            }*/
            //1.EVALUATE LETTER
            //2.SET POSITION ACCORDING TO LETTER
            //3.TRAIN MARKOV CHAIN
            //4.GET OUTPUT
            //5.COMMUNICATE OUTPUT the player thread
            for (int i = 0; i < letters.size(); i++) {
                try {
                    letters.at(i).evaluate_letter(qn_duration / 2); //duration of 8th note
                } catch (int e) {
                    cout << "MarkovEngineConsumer exception in evaluate_letter(), number:" << e << endl;
                    throw 1;
                }
                try {
                    letters.at(i).setNotePositionAccordingToLetter();
                } catch (int e) {
                    cout << "MarkovEngineConsumer exception in setNotePositionAccordingToLetter(), number:" << e << endl;
                    throw 2;
                }
            }
            //3.Fill vectors to train Markov Chain
            first_vector_of_letters.push_back(letters.at(0));
            first_vector_of_letters.push_back(letters.at(1));
            first_vector_of_letters.push_back(letters.at(2));
            first_vector_of_letters.push_back(letters.at(3));
            second_vector_of_letters.push_back(letters.at(4));
            second_vector_of_letters.push_back(letters.at(5));
            second_vector_of_letters.push_back(letters.at(6));
            second_vector_of_letters.push_back(letters.at(7));

            try {
                vomc.train(first_vector_of_letters);
                vomc.train(second_vector_of_letters);
            } catch (...) {
                cout << "vomc.train() exception" << endl;
                throw 3;
            }
            cout << "Switters::" << endl;
            //vomc.print();
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
            cout << endl;
            //4 Get output	
            //////cout << "Attempt to find a solution" << endl;
            //vomc.print();
            State sout;
            try {
                sout = vomc.provide_response_pattern_remove(second_vector_of_letters);
                cout << "Solution::MC" << endl;

            } catch (...) {
                //////cout << "problemos!" << endl;
            }
            //////cout << "Attempted to find a solution" << endl;
            //sout.SetId(-1); //REMOVE TO RUN

            if (sout.GetId() == -1) {
                sout.SetLetters(first_vector_of_letters);
                sout.AddLetters(second_vector_of_letters);
                //////cout << "Solution::NO" << endl;
                //back up implementation with cellular
                ra = new Rhythm_automata(sout.get_rhythm_as_string());
                /*cout << "sout.get_rhythm_as_string()." << endl;
                for (int r = 0; r < sout.get_rhythm_as_string().size(); r++) {
                    cout << sout.get_rhythm_as_string().at(r) << endl;
                }*/

                ra->rules_init();
                bool** ra_rhythm;
                ra_rhythm = new bool *[sout.get_rhythm_as_string().at(0).size()];
                try {
                    ra_rhythm = ra->get_rhythm(40);
                    //ra->get_rhythm_single(5,40);
                    //cout << "Solution::RA.1" << endl;
                    sout = convert_bool_to_state(&letters, ra_rhythm);
                    //   cout << "Solution::RA.2" << endl;
                    // cout << "Rhythm Automata::" << endl;
                } catch (...) {

                    cout << "Solution::NO, play input" << endl;
                    sout.SetLetters(first_vector_of_letters);
                    sout.AddLetters(second_vector_of_letters);

                }
                /*for (int i = 0; i < sout.get_rhythm_as_string().size(); ++i)
                    delete [] ra_rhythm[i];
                delete [] ra_rhythm;*/

            } else {
                cout << "Markov::" << endl;
            }
            //show output

            sout.print_state_letters();
            //empty vectors
            first_vector_of_letters.clear();
            second_vector_of_letters.clear();
            //letters.clear();
            for (int i = 0; i < letters.size(); i++) {
                letters.at(i).empty_notes();
            }
            meter_start += meter_duration; //point to next meter
            /*cout << vomc.s_4_v_p_r << "," << vomc.s_3_v_p_r << "," << vomc.s_2_v_p_r << "," << vomc.s_1_v_p_r << endl;
            cout << vomc.s_4_p_r << "," << vomc.s_3_p_r << "," << vomc.s_2_p_r << "," << vomc.s_1_p_r << endl;
            cout << vomc.s_4_r << "," << vomc.s_3_r << "," << vomc.s_2_r << "," << vomc.s_1_r << endl;
            cout << "Total Meters" << ++cnt_meters << endl;
            if (cnt_meters == 8)break;
             */boost::this_thread::interruption_point();
            cout << "**********************************************" << endl;
            /*
             //cout<<"PRINT_VOMC"<<endl;
            //vomc.print();
             */
            //} else {
            //////cout << "Markov Engine Consumer ENDED" << endl;
            //  cout << "Save VOMC..." << endl;
            //vomc.save_as("output/tsifteteli.vomc");
            //cout << "Number of states:" << vomc.vomc.size() << endl;
            //cout << "VOMC saved" << endl;
            //////cout << "*****************************************" << endl;
            //////cout << "*****************************************" << endl;
            //////cout <    < "Solutions" << endl;
            /*//////cout << "s_4_v_p_r"<< double(s_4_v_p_r)/double(measure_counter) << endl;
            //////cout << "s_3_v_p_r"<< double(s_3_v_p_r)/double(measure_counter) << endl;
            //////cout << "s_2_v_p_r"<< double(s_2_v_p_r)/double(measure_counter) << endl;
            //////cout << "s_1_v_p_r"<< double(s_1_v_p_r)/double(measure_counter) << endl;
            //////cout << "s_4_p_r"<< double(s_4_p_r)/double(measure_counter) << endl;
            //////cout << "s_3_p_r"<< double(s_3_p_r)/double(measure_counter) << endl;
            //////cout << "s_2_p_r"<< double(s_2_p_r)/double(measure_counter) << endl;
            //////cout << "s_1_p_r"<< double(s_1_p_r)/double(measure_counter) << endl;
            //////cout << "s_4_r"<< double(s_4_r)/double(measure_counter) << endl;
            ///ccc///cout << "s_3_r"<< double(s_3_r)/double(measure_counter) << endl;
            //////cout << "s_2_r"<< double(s_2_r)/double(measure_counter) << endl;
            //////cout << "s_1_r"<< double(s_1_r)/double(measure_counter) << endl;
             */
            //return;
            //}
            //measure_counter++;
            //vomc.print();
        }
        cout << "VOMC finished" << endl;
        cout << "Number of Gen States " << vomc.vomc.size() << endl;
    } catch (int a) {

        cout << "MarkovEngineConsumer:: Exception Number:" << a << endl;

    } catch (...) {

        cout << "MarkovEngineConsumer::Unknown Exception in Markov Engine Consumer" << endl;

    }
    delete ra;
}

/**
 * 
 * @param l is a <code>*vector<Letter></code>.
 * @param rhythm is a <code>bool **</code> of size 
 * [voices][sum_of_letter_pattern_string].
 * @return A <code>State</code> that merging both inputs.
 */
State MarkovEngineConsumer::convert_bool_to_state(vector<Letter> *l, bool **rhythm) {
    // I need to acquire the size of the initial phrase
    // This is done to be able to differentiate among triplets and 
    // sixteenth notes.
    /*for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 32; j++) {
            if ((j % 4 == 0) && (j != 0)) {
                //cout << " ";
            }
            if (rhythm[i][j]) {
                //cout << "X";
            } else {
                //cout << ".";
            }
        }
        //cout << endl;
    }*/


    int letter_size;
    bool onset = false;
    string letter_pattern;
    //Rawnotes repository, this should be our source
    vector< vector<RawNote> > v_notes;
    vector<RawNote> v_0; //cr
    vector<RawNote> v_1; //hh
    vector<RawNote> v_2; //ht
    vector<RawNote> v_3; //sn
    vector<RawNote> v_4; //lt
    vector<RawNote> v_5; //bd
    v_notes.push_back(v_0);
    v_notes.push_back(v_1);
    v_notes.push_back(v_2);
    v_notes.push_back(v_3);
    v_notes.push_back(v_4);
    v_notes.push_back(v_5);

    //This is the destination state
    Letter l1(helper), l2(helper), l3(helper), l4(helper), l5(helper), l6(helper), l7(helper), l8(helper);
    //This will host the new patterns
    vector<Letter> v_l;
    v_l.push_back(l1);
    v_l.push_back(l2);
    v_l.push_back(l3);
    v_l.push_back(l4);
    v_l.push_back(l5);
    v_l.push_back(l6);
    v_l.push_back(l7);
    v_l.push_back(l8);

    State s;
    //fill all notes
    //according to every instrument timbre
    // for every letter

    // fill v_notes with notes to different voices
    // fill v_l copy buy copying l
    for (int i = 0; i < l->size(); i++) {
        //for every note of that letter
        for (int j = 0; j < l->at(i).getRawNotes().size(); j++) {

            if (l->at(i).getRawNotes().at(j).GetPitch() == cr) {
                //Pool of crash notes
                v_notes.at(0).push_back(l->at(i).getRawNotes().at(j));
            } else if ((l->at(i).getRawNotes().at(j).GetPitch() == hh1) &&
                    (l->at(i).getRawNotes().at(j).GetPitch() == hh2)
                    ) {
                //Pool of hihat notes
                v_notes.at(1).push_back(l->at(i).getRawNotes().at(j));
            } else if (l->at(i).getRawNotes().at(j).GetPitch() == t1) {
                //Pool of t1 notes
                v_notes.at(2).push_back(l->at(i).getRawNotes().at(j));
            } else if (l->at(i).getRawNotes().at(j).GetPitch() == sn) {
                //Pool of sn notes
                v_notes.at(3).push_back(l->at(i).getRawNotes().at(j));
            } else if (l->at(i).getRawNotes().at(j).GetPitch() == lt) {
                //Pool of lt notes
                v_notes.at(4).push_back(l->at(i).getRawNotes().at(j));
            } else if (l->at(i).getRawNotes().at(j).GetPitch() == bd) {
                //Pool of bd notes
                v_notes.at(5).push_back(l->at(i).getRawNotes().at(j));
            }
            //v_l.at(i).add_note(l->at(i).getRawNotes().at(j));
        }
        //v_l.at(i).setPattern(l->at(i).getPattern());
    }
    //add the notes to v_l
    int note_index = 0;

    //Discover letter new pattern and assign it to the new letters of the new state
    for (int i = 0; i < l->size(); i++) {
        letter_pattern = "";
        letter_size = l->at(i).getPattern().GetName().size();
        //Construct letter
        ////cout << "check::" << note_index + letter_size << endl;
        for (int k = note_index; k < (note_index + letter_size); k++) {
            //OR operation among all notes in the same position
            for (int j = 0; j < 6; j++) {
                if (rhythm[j][k]) {
                    onset = true;
                    break;
                }
            }
            if (onset) {
                letter_pattern += 'X';
            } else {
                letter_pattern += 'o';
            }
            onset = false;
        }
        note_index += letter_size;
        LetterPattern temp_lp;
        temp_lp.SetName(letter_pattern);
        v_l.at(i).setPattern(temp_lp);
        letter_pattern = "";
    }
    //Every letter pattern has been detected
    //2.Loop through all created letters and start adding letters when 'X'
    //add letter and remove pattern
    string xx_pattern;
    for (int i_voice = 0; i_voice < v_notes.size(); i_voice++) {
        vector<RawNote> temp_voice_vector;
        for (int temp_cnt = 0; temp_cnt < v_notes.at(i_voice).size(); temp_cnt++) {
            temp_voice_vector.push_back(v_notes.at(i_voice).at(temp_cnt));
        }

        xx_pattern = "";
        ////cout << "temp_voice_vector::" << temp_voice_vector.size() << endl;
        int pattern_size = get_size_of_pattern_for_all_letters_of_voice(i_voice, l);
        for (int i_position_in_pattern = pattern_size - 1; i_position_in_pattern >= 0; i_position_in_pattern--) {

            if (rhythm[i_voice][i_position_in_pattern] == true) {
                int letter_possition = get_letter_that_corresponds_to_possition_voice_combination(i_position_in_pattern, i_voice, l);
                //          //cout << "Attempt to add for voice::" << i_voice << endl;
                RawNote r = temp_voice_vector.back();
                r.SetPosition(get_position_in_letter(i_position_in_pattern, l));
                r.SetPitch(voice_to_pitch(i_voice));
                v_l.at(letter_possition).add_note(r);
                temp_voice_vector.pop_back();
            }
        }
    }
    s.SetLetters(v_l);
    return s;
}
/**
 * 
 * @param i_voice is a <code>int</code> converting voice 0...5 to the 
 * <code>int</code> representation of it.
 * @return A <code>int</code> representation of the voice mapped to 
 * an instrument midi representation.
 */
int MarkovEngineConsumer::voice_to_pitch(int i_voice) {
    if (i_voice == 0) {
        return cr;
    } else if (i_voice == 1) {
        return hh1;
    } else if (i_voice == 2) {
        return t1;
    } else if (i_voice == 3) {
        return sn;
    } else if (i_voice == 4) {
        return lt;
    } else if (i_voice == 5) {
        return bd;
    }
    //cout << "ERROR voice was not found!! in MarkovEngineConsumer::voice_to_pitch." << endl;
    return 0;
}
/**
 * 
 * @param i_position_in_pattern is an <code>int</code> representing the 
 *         position inside the pattern,
 * @param l is a <code>vector<Letter> *</code> of the pattern of interest.
 * @return An <code>int</code> representing the position inside the letter.
 */
int MarkovEngineConsumer::
get_position_in_letter(int i_position_in_pattern, vector<Letter> *l) {
    int current_size = 0;
    for (int i = 0; i < l->size(); i++) {
        if (i_position_in_pattern < current_size + l->at(i).getPattern().GetName().size()) {
            return i_position_in_pattern - current_size;
        }
        current_size += l->at(i).getPattern().GetName().size();
    }
    cout << "EXCEPTION IN MarkovEngineConsumer::get_position_in_letter(...)" << endl;
    throw "EXCEPTION IN MarkovEngineConsumer::get_position_in_letter(...)";
}
/**
 * 
 * @param position is an <code>int</code>.
 * @param voice is an <code>int</code>.
 * @param v_letters is an <code>int</code> 
 * internal helper function for RA
 */
int MarkovEngineConsumer::
get_letter_that_corresponds_to_possition_voice_combination(int position, int voice, vector<Letter> *v_letters) {
    int current_size = 0;
    for (int i = 0; i < v_letters->size(); i++) {
        current_size += v_letters->at(i).getPattern().GetName().size();
        if (position < (current_size)) {
            return i;
        }
    }
    //cout << "EXCEPTION IN MarkovEngineConsumer::get_letter_that_corresponds_to_possition_voice_combination(...)" << endl;
    throw "EXCEPTION IN MarkovEngineConsumer::get_letter_that_corresponds_to_possition_voice_combination(...)";
}
/**
 * 
 * @param voice, an <code>int</code> representing the drum voice.
 * @param v_letters is a <code>vector<Letter> *</code>.
 * @return the size of <code>string</code> representation of the pattern of the specific pattern
 */
int MarkovEngineConsumer::get_size_of_pattern_for_all_letters_of_voice(int voice, vector<Letter> *v_letters) {
    string pattern = "";
    for (int i = 0; i < v_letters->size(); i++) {
        if (voice == 0) {
            pattern += rtrim(v_letters->at(i).print_instrument(cr));
        } else if (voice == 1) {
            pattern += rtrim(v_letters->at(i).print_hihat());
        } else if (voice == 2) {
            pattern += rtrim(v_letters->at(i).print_instrument(t1));
        } else if (voice == 3) {
            pattern += rtrim(v_letters->at(i).print_instrument(sn));
        } else if (voice == 4) {
            pattern += rtrim(v_letters->at(i).print_instrument(lt));
        } else if (voice == 5) {
            pattern += rtrim(v_letters->at(i).print_instrument(bd));
        }
    }
    return pattern.length();
}
/**
 * 
 * @param s is a <code>string</code> to be trimmed.
 * @return A <code>string</code> which represents the trimmed 
 * version of the input.
 */
string MarkovEngineConsumer::rtrim(string s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

void MarkovEngineConsumer::test_ra(Rhythm_automata * ra) {

    //   ra->get_rhythm_single(1,10);
    //ra->get_rhythm(10);
    //cout << "Snare" << endl;
    boost::posix_time::ptime mst1 = boost::posix_time::microsec_clock::local_time();
    try {
        ra->get_rhythm_single(3, 30);
    } catch (...) {

        //cout << endl;
    }
    //cout << "Bass" << endl;
    try {
        ra->get_rhythm_single(5, 30);
    } catch (...) {
        //cout << endl;
    }

}
// The THREAD reads data from the queue
// Test does not work RT

Meter MarkovEngineConsumer::init_test_meter() {
    cout << "EEEE:In here" << endl;
    Meter m1, m2;

    m1.add_note(RawNote(-212, 44502185, -50, 42, 62));
    m1.add_note(RawNote(-212.993965, 44502200, -35, 45, 120));
    m1.add_note(RawNote(-212.994005, 44502701, 466, 45, 123));
    m1.add_note(RawNote(-212, 44503209, 474, 34, 117));
    m1.add_note(RawNote(-212, 44503214, 479, 45, 95));

    m1.add_note(RawNote(-212, 44503706, 471, 45, 97));
    m1.add_note(RawNote(-212, 44504230, 495, 42, 127));
    m1.add_note(RawNote(-212, 44504748, 13, 45, 116));
    m1.add_note(RawNote(-212, 44505243, 8, 34, 101));

    m1.add_note(RawNote(-212, 44505253, 18, 45, 101));
    m1.add_note(RawNote(-212, 44505752, 17, 45, 122));
    m1.add_note(RawNote(-212, 44506227, 492, 42, 125));

    m2.add_note(RawNote(-212, 44506242, 7, 45, 91));
    m2.add_note(RawNote(-212.98, 44506729, 494, 45, 83));
    m2.add_note(RawNote(-212.999011, 44507239, 4, 34, 93));
    m2.add_note(RawNote(-212.995993, 44507244.0, 9, 45, 113));

    m2.add_note(RawNote(-212, 44507736, 1, 45, 123));
    m2.add_note(RawNote(-212.989010, 44508249.0, 14, 42, 123));
    m2.add_note(RawNote(-212.990009, 44508271, 36, 45, 117));

    m2.add_note(RawNote(-212993, 44508767, 32, 45, 50));
    m2.add_note(RawNote(-212.978987, 44509236, 1, 34, 119));
    m2.add_note(RawNote(-212.978995, 44509713, 478, 45, 71));
    v_test_meter.push_back(m1);
    v_test_meter.push_back(m2);
}

MarkovEngineConsumer::~MarkovEngineConsumer() {
    //////cout << "MarkovEngineConsumer Destructor" << endl;
}