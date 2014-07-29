/* 
 * File:   RAtestMain.cpp
 * Author: puppy
 * 
 * Created on November 3, 2012, 1:11 PM
 */

#include "RAtestMain.h"
#include "Rhythm_automata.h"

RAtestMain::RAtestMain() {
    vector<string> input_rhythm;
    input_rhythm.push_back(".... .... .... ... ... ... .... ...."); //cr
    input_rhythm.push_back("X.X. X.X. X... ... ... ... .... ...."); //hh
    input_rhythm.push_back(".... .... .... ... X.. ... X... ...."); //t1
    input_rhythm.push_back(".... .... X... XXX .XX .XX .... ...."); //sn
    input_rhythm.push_back(".... .... .... ... ... ... .... ...."); //lt
    input_rhythm.push_back("X... .... .... ... ... X.. .... ...."); //bd
    Rhythm_automata *ra = new Rhythm_automata(input_rhythm);
    ra->rules_init();
    bool *pois_8a_me_8ymatai = ra->get_rhythm_single(5, 40);
    for (int j = 0; j < 30; j++) {

        if (pois_8a_me_8ymatai[j]) {

            cout << "X";

        } else {
            cout << ".";
        }
    }

}