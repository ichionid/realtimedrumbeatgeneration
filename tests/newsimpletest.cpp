/* 
 * File:   newsimpletest.cpp
 * Author: puppy
 *
 * Created on Aug 12, 2012, 11:05:03 AM
 */

#include <iostream>

#include "VOMC.h"

/*
 * Simple C++ Test Suite
 */
using namespace std;

void test_state_comparision(){

    cout<<"Testing the cases of identical states, and states where"<<endl;
    cout<<"velocity differs"<<endl;
    vector<Letter> test_vl1,test_vl2,test_vl3;
    Letter test_l1,test_l2,test_l3;
    
    vector<int> test_vD;
    test_vD.push_back(3);
    LetterPattern test_D(test_vD,"oooX");
    
    RawNote test_r1 = RawNote(0,0,0,5,5);
    test_r1.SetPosition(3);
    
    vector<int> test_vE;
    test_vE.push_back(0);
    test_vE.push_back(1);
    LetterPattern test_E(test_vE,"XXoo");
    RawNote test_r2 = RawNote(0,0,0,5,5);
    test_r2.SetPosition(0);
    //Rawnote (xx,xx,xx,pitch,velocity)                  
    RawNote test_r3 = RawNote(0,0,0,5,2);
    test_r3.SetPosition(1);
    
    RawNote test_r3_b = RawNote(0,0,0,5,5);//check against different velocity
    test_r3_b.SetPosition(1);
    
    test_l1.setPattern(test_D);
    test_l1.add_note(test_r1);
    
    test_l2.setPattern(test_E);
    test_l2.add_note(test_r2);
    test_l2.add_note(test_r3);

    test_l3.setPattern(test_E);
    test_l3.add_note(test_r2);
    test_l3.add_note(test_r3_b);
    
    test_vl1.push_back(test_l1);
    test_vl1.push_back(test_l2);
    
    test_vl2.push_back(test_l1);
    test_vl2.push_back(test_l2);
    
    test_vl3.push_back(test_l1);
    test_vl3.push_back(test_l3);
    
    State *test_s1 = new State(test_vl1);
    State *test_s2 = new State(test_vl2);   
    State *test_s3 = new State(test_vl3);   
    VOMC v;
    
    if(v.compare_remove_without_pitch_velocity(test_s1,test_s2)){
    
        cout<<"Den har ikke pitch og velocity. De er det sammen;)"<<endl;
    
    }else{
        
        cout<<"Den har ikke pitch og velocity. De er ikke det sammen;)"<<endl;
        
    }
    if(v.compare_remove_without_velocity(test_s1,test_s2)){
    
        cout<<"Den har ikke velocity. De er det sammen;)"<<endl;
    
    }else{
        
        cout<<"Den har ikke velocity. De er ikke det sammen;)"<<endl;
        
    }
    if(v.compare_remove(test_s1,test_s2)){
    
        cout<<"Tjeke bade velocity og pitch. De er det sammen;)"<<endl;
    
    }else{
        
        cout<<"Tjeke bade velocity og pitch. De er ikke det sammen;)"<<endl;
        
    }

    if(v.compare_remove_without_pitch_velocity(test_s1,test_s3)){
    
        cout<<"Don't check pitch og velocity. De er det sammen;)"<<endl;
    
    }else{
        
        cout<<"Don't check pitch og velocity. De er ikke det sammen;)"<<endl;
        
    }
    if(v.compare_remove_without_velocity(test_s1,test_s3)){
    
        cout<<"Don't check velocity. De er det sammen;)"<<endl;
    
    }else{
        
        cout<<"Don't check velocity. De er IKKE det sammen;)"<<endl;
        
    }
    if(v.compare_remove(test_s1,test_s3)){
    
        cout<<"Full check. De er det sammen;)"<<endl;
    
    }else{
        
        cout<<"Full check. De er IKKE det sammen;)"<<endl;
        
    }
    
    
}
void test_letter_has_note(){
    
    RawNote test_r1 = RawNote(0,0,0,5,5);
    test_r1.SetPosition(1);
    RawNote test_r2 = RawNote(0,0,0,5,5);
    test_r2.SetPosition(2);
    RawNote test_r_input = RawNote(0,0,0,5,2);
    test_r_input.SetPosition(2);
    Letter* test_letter_2 = new Letter();
    test_letter_2->add_note(test_r1);
    test_letter_2->add_note(test_r2);
    if(test_letter_2->has_note_with_velocity(&test_r_input)){
        cout<<"Velocity:Note exists"<<endl;
    }
    if(test_letter_2->has_note_no_velocity(&test_r_input)){
        cout<<"Note exists"<<endl;
    }
}

int main(int argc, char** argv) {
    test_state_comparision();
    //test_letter_has_note();
}

