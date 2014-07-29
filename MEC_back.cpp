/* 
 * File:   MarkovEngineConsumer.cpp
 * Author: puppy
 * 
 * Created on June 4, 2012, 11:35 PM
 */

#include "MarkovEngineConsumer.h"
#include "Letter.h"
MarkovEngineConsumer::MarkovEngineConsumer(SynchronizedQueue<Meter>* queue, double tempo, double offset, double A, double metronome_start, double meter_start) {
    cout << "MarkovEngineConsumer Constructor" << endl;
    this->m_queue = queue;
    this->tempo = tempo;
    this->offset = offset;
    this->qn_duration = 60000 / tempo;
    this->meter_duration = A * this->qn_duration;
    this->metronome_start = metronome_start;
    this->meter_start = meter_start;

}

// The THREAD reads data from the queue

void MarkovEngineConsumer::operator () () {

/*
    cout << "Consumer.meter_start:" << meter_start << endl;
    //Rhythm_automata *ra_mec;
    vector<RawNote> notesLeftOver;
    vector<Letter> first_vector_of_letters;
    vector<Letter> second_vector_of_letters;
    this->vomc.init();
    try {
        while (true) {

            // Get the data from the queue and print it
            cout << "CONSUMING meter_start:" << meter_start << endl;
            vector<Letter> letters(8);

            rNotes = m_queue->Dequeue().get_notes();
            //add left overs
            if (!notesLeftOver.empty()) {
                for (int i = 0; i < notesLeftOver.size(); i++) {
                    rNotes.push_back(notesLeftOver.at(i));
                }
                notesLeftOver.clear();
            }
            for (int i = 0; i < rNotes.size(); i++) {
                if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 0.5 * qn_duration - (qn_duration / 24))) {
                    //first Letter
                    letters.at(0).add_note(rNotes.at(i));

                } else if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + qn_duration - (qn_duration / 24))) {

                    if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 0.5 * qn_duration)) {
                        //coming from previous meter
                        rNotes.at(i).SetEighthNoteTimeStamp(0);
                    }
                    letters.at(1).add_note(rNotes.at(i));

                } else if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 1.5 * qn_duration - (qn_duration / 24))) {
                    //third Letter
                    if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + qn_duration)) {
                        //coming from previous meter
                        rNotes.at(i).SetEighthNoteTimeStamp(0);
                    }
                    letters.at(2).add_note(rNotes.at(i));

                } else if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 2 * qn_duration - (qn_duration / 24))) {
                    //fourth Letter
                    if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 1.5 * qn_duration)) {
                        //coming from previous meter
                        rNotes.at(i).SetEighthNoteTimeStamp(0);
                    }
                    letters.at(3).add_note(rNotes.at(i));
                } else if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 2.5 * qn_duration - (qn_duration / 24))) {
                    //fifth Letter
                    if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 2. * qn_duration)) {
                        //coming from previous meter
                        rNotes.at(i).SetEighthNoteTimeStamp(0);
                    }
                    letters.at(4).add_note(rNotes.at(i));

                } else if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 3 * qn_duration - (qn_duration / 24))) {
                    //sixth Letter
                    if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 2.5 * qn_duration)) {
                        //coming from previous meter
                        rNotes.at(i).SetEighthNoteTimeStamp(0);
                    }
                    letters.at(5).add_note(rNotes.at(i));
                } else if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 3.5 * qn_duration - (qn_duration / 24))) {
                    //seventh Letter
                    if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 3. * qn_duration)) {
                        //coming from previous meter
                        rNotes.at(i).SetEighthNoteTimeStamp(0);
                    }
                    letters.at(6).add_note(rNotes.at(i));
                } else if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 4 * qn_duration - (qn_duration / 24))) {
                    //eighth Letter
                    if (rNotes.at(i).GetGeneralTimeStamp()<(meter_start + 3.5 * qn_duration)) {
                        //coming from previous meter
                        rNotes.at(i).SetEighthNoteTimeStamp(0);
                        //second Letter
                    }
                    letters.at(7).add_note(rNotes.at(i));

                } else {
                    rNotes.at(i).SetEighthNoteTimeStamp(0);
                    notesLeftOver.push_back(rNotes.at(i));
                }
            }
            //cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
            //1.EVALUATE LETTER
            //2.SET POSITION ACCORDING TO LETTER
            //3.TRAIN MARKOV CHAIN
            //4.GET OUTPUT
            //5.COMMUNICATE OUTPUT the player thread
            for (int i = 0; i < letters.size(); i++) {
                if (!letters.at(i).isEmpty()) {
                    //1
                    try {
                        letters.at(i).evaluate_letter(qn_duration / 2); //duration of 8th note
                    } catch (int e) {
                        cout << "MarkovEngineConsumer exception in evaluate_letter(), number:" << e << endl;
                        throw 1;
                    }
                    //2
                    try {
                        letters.at(i).setNotePositionAccordingToLetter();
                    } catch (int e) {
                        cout << "MarkovEngineConsumer exception in setNotePositionAccordingToLetter(), number:" << e << endl;
                        throw 2;
                    }
                    //cout << letters.at(i).getPattern().GetName() << endl;
                    //letters.at(i).print_notes();
                }
            }
            //3
            //Fill vectors to train Markov Chain
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

            /*for (int i = 0; i < letters.size(); i++) {
                cout << endl << "Letter :: " << i << " Notes::" << letters.at(i).getRawNotes().size() << endl;
                for (int j = 0; j < letters.at(i).getRawNotes().size(); j++) {
                    cout << "Note :: " << j << endl;
                    cout << "Pitch :" << letters.at(i).getRawNotes().at(j).GetPitch() << endl;
                    cout << "Position :" << letters.at(i).getRawNotes().at(j).GetPosition() << endl;
                }
                cout << endl;
            }*/


            //4 Get output
            /*State sout = vomc.provide_response_pattern_remove(second_vector_of_letters);
            if (sout.GetId() == -1) {
                sout.SetLetters(first_vector_of_letters);
                sout.AddLetters(second_vector_of_letters);
                cout << "Solution::NO" << endl;
                //back up implementation with cellular
                sout.get_rhythm_as_string();
                ra = new Rhythm_automata(sout.get_rhythm_as_string());
                ra->rules_init();
                bool** ra_rhythm;
                ra_rhythm = new bool *[sout.get_rhythm_as_string().at(0).size()];
                try {

                    ra_rhythm = ra->get_rhythm(5);
                    //convert rhythm of bool** to state
                    sout = convert_bool_to_state(&letters,ra_rhythm);
                    cout << "Solution::YES, Rhythmic Automata" << endl;

                } catch (...) {

                    cout << "Solution::NO, play input" << endl;
                    sout.SetLetters(first_vector_of_letters);
                    sout.AddLetters(second_vector_of_letters);

                }
            } else {
                cout << "Solution::YES Markov" << endl;
                sout.print_state_letters();
            }
            //empty vectors
            first_vector_of_letters.clear();
            second_vector_of_letters.clear();
            //letters.clear();
            for (int i = 0; i < letters.size(); i++) {
                letters.at(i).empty_notes();
            }*/
/*            meter_start += meter_duration; //point to next meter
            boost::this_thread::interruption_point();
            cout << endl;
            cout << "    ----------------------" << endl;
            cout << "  --------------------------" << endl;
            cout << "------------------------------" << endl;

        }
    } catch (int a) {

        cout << "MarkovEngineConsumer:: Exception Number:" << a << endl;

    } catch (...) {

        cout << "MarkovEngineConsumer::Unknown Exception in Markov Engine Consumer" << endl;

    }*/
}

/**
 * 
 * @param l, is a <code>*vector<Letter></code>
 * @param rhythm, is a <code>bool **</code> of size [voices][sum_of_letter_pattern_string]
 * @return 
 */
//State MarkovEngineConsumer::convert_bool_to_state(vector<Letter> *l, bool **rhythm) {
    // I need to acquire the size of the initial phrase
    // This is done to be able to differentiate among triplets and 
    // sixteenth notes.
  /*  int note_index = 0;
    int letter_size;
    bool onset = false;
    string letter_pattern;
    //Rawnotes repository, this should be or source
    vector< vector<RawNote*> > v_notes;
    vector<RawNote*> v_0; //hh
    vector<RawNote*> v_1; //t1
    vector<RawNote*> v_2; //sn
    vector<RawNote*> v_3; //lt
    vector<RawNote*> v_4; //bd
    v_notes.push_back(v_0);
    v_notes.push_back(v_1);
    v_notes.push_back(v_2);
    v_notes.push_back(v_3);
    v_notes.push_back(v_4);

    //This is the destination state
    Letter l1, l2, l3, l4, l5, l6, l7, l8;
    vector<Letter> v_l;
    v_l.push_back(l1);
    v_l.push_back(l2);
    v_l.push_back(l3);
    v_l.push_back(l4);
    v_l.push_back(l5);
    v_l.push_back(l6);
    v_l.push_back(l7);
    v_l.push_back(l8);
    State s(v_l);
*/
    /*for (int i = 0; i < l->size(); i++) {
        letter_pattern = "";
        letter_size = l->at(i).getPattern().GetName().size();
        //Construct letter
        for (int k = note_index; k < (note_index + letter_size); k++) {
            //OR operation among all notes in the same position
            for (int j = 0; j < drum_voices; j++) {
                if (rhythm[k][j]) {
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
        s.GetLetters().at(i).setPattern(temp_lp);
        letter_pattern = "";
    }*/
    //fill all notes
    //according to every instrument timbre
    /*for (int i = 0; i < l->size(); i++) {
        for (int j = 0; j < l->at(i).getRawNotes().size(); j++) {
            if (
                    (l->at(i).getRawNotes().at(j).GetPitch() == hh1)&&
                    (l->at(i).getRawNotes().at(j).GetPitch() == hh2)
                    ) {
                v_notes.at(0).push_back(&l->at(i).getRawNotes().at(j));
            } else if (l->at(i).getRawNotes().at(j).GetPitch() == t1) {
                v_notes.at(1).push_back(&l->at(i).getRawNotes().at(j));
            } else if (l->at(i).getRawNotes().at(j).GetPitch() == sn) {
                v_notes.at(2).push_back(&l->at(i).getRawNotes().at(j));
            } else if (l->at(i).getRawNotes().at(j).GetPitch() == lt) {
                v_notes.at(3).push_back(&l->at(i).getRawNotes().at(j));
            } else if (l->at(i).getRawNotes().at(j).GetPitch() == bd) {
                v_notes.at(4).push_back(&l->at(i).getRawNotes().at(j));
            }
        }
    }*/
    //Every letter pattern has been detected
    //2.Loop through all created letters and start adding letters when 'X'
    //add letter and remove pattern
    /*string hh_pattern = "";
    string t1_pattern = "";
    string sn_pattern = "";
    string lt_pattern = "";
    string bd_pattern = "";
    vector<string> voice_patterns;
    for (int letter_cnt = 0; letter_cnt < s.GetLetters().size(); letter_cnt++) {
        hh_pattern = s.GetLetters().at(letter_cnt).print_hihat();
        t1_pattern = s.GetLetters().at(letter_cnt).print_instrument(t1);
        sn_pattern = s.GetLetters().at(letter_cnt).print_instrument(sn);
        lt_pattern = s.GetLetters().at(letter_cnt).print_instrument(lt);
        bd_pattern = s.GetLetters().at(letter_cnt).print_instrument(bd);
        voice_patterns.push_back(hh_pattern);
        voice_patterns.push_back(t1_pattern);
        voice_patterns.push_back(sn_pattern);
        voice_patterns.push_back(lt_pattern);
        voice_patterns.push_back(bd_pattern);
        vector<RawNote> v_rawnotes;
        //for all patterns(of different voices)
        for (int i = 0; i < voice_patterns.size(); i++) {
            //for every sign of the pattern 'X' or 'o'
            for (int j = 0; j < voice_patterns.at(i).size(); j++) {
                if (voice_patterns.at(i)[j] == 'X') {

                    RawNote rawnote = (*v_notes.at(i).at(0));
                    if (voice_patterns.at(i).size() == 4) {
                        //16th notes
                        rawnote.SetPosition(j);

                    } else {
                        //triplets
                        if (j == 0) {

                            rawnote.SetPosition(0);

                        } else if (j == 1) {
                            
                            rawnote.SetPosition(4);
                            
                        } else {

                            rawnote.SetPosition(5);

                        }
                    }
                    v_rawnotes.push_back(rawnote);
                }
            }
        }
        s.GetLetters().at(letter_cnt).setRawNotes(v_rawnotes);
    }*/
//    State s;
//    return s;
//}

MarkovEngineConsumer::~MarkovEngineConsumer() {
    //cout << "MarkovEngineConsumer Destructor" << endl;
}