/* 
 * File:   LetterPattern.cpp
 * Author: Ioannis Chionidis
 * 
 * Created on June 17, 2012, 4:05 PM
 */

#include "LetterPattern.h"
//e.g. pattern = {0,1} letter= "E" 
LetterPattern::LetterPattern(){
//    //cout<<"LetterPatter Default Constructor-> should NEVER be USED"<<endl;
}
/**
 * 
 * @param pattern is a <code>vector<int></code> whose elements vary from 0 to 5.
 *              
 * @param representation is a <code>string</code> holding the pattern representation.
 */
LetterPattern::LetterPattern(vector<int> pattern, string representation) {
//    //cout<<"LetterPatter NOT Default Constructor"<<endl;    
    this->pattern = pattern;
    this->name = representation;
    this->lettersUsed = new bool[pattern.size()];
    for(int i=0;i<pattern.size();i++){
        lettersUsed[i]=false;
    }
} 
/**
 * @param i is a <code>int</code> representing the letter indexing that is going to be set as USED.
 */
void LetterPattern::setLettersUsed(int i){
    //cout<<i<<"<"<<sizeof(this->lettersUsed)/sizeof(bool)<<endl;
    //if(i>=sizeof(this->lettersUsed)/sizeof(bool))//cout<<"ERRORRRR"<<endl;
    this->lettersUsed[i]=true;
}
/**
 * 
 * @param i is a <code>int</code> representing the letter indexing 
 * @return TRUE if letter has been set as used, FALSE otherwise.
 */
bool LetterPattern::getLettersUsed(int i){
    return this->lettersUsed[i];
}
/**
 * 
 * @return a <code>string</code> representing the name of the LetterPattern.
 */
string LetterPattern::GetName() const {
    return name;
}
/**
 * @param name is a <code>string</code> representing the name of the pattern.
 */
void LetterPattern::SetName(string name) {
    this->name = name;
}
/**
 * 
 * @return a <code>boolean</code>, true if all notes have been used 
 * or false if a note has note been used.
 */
bool LetterPattern::allNotesUsed(){
  //  //cout<<"LetterPattern.cpp:allNotesUsed1"<<endl;
    bool ret  = true;
   // //cout<<"LetterPattern.cpp:allNotesUsed2"<<endl;
    //Ignore the last one! "oooo"
    for(int i = 0;i<pattern.size()-1;i++){
        ret=ret&&lettersUsed[i];
     //   //cout<<"LetterPattern.cpp:allNotesUsed,i="<<i<<endl;

    }
    ////cout<<"LetterPattern.cpp:allNotesUsed3"<<endl;
    return ret;
}
/** 
 * @return A <code>vector<int></code> of the positions been used(0...5)
 */
vector<int> LetterPattern::GetPattern() const {
    return pattern;
}
/**
 * @param pattern is a <code>vector<int></code> of the positions that will 
 * be copied to the internal <code>Letter's</code> object pattern.
 */
void LetterPattern::SetPattern(vector<int> pattern) {
    this->pattern = pattern;
}

LetterPattern::~LetterPattern( ) {
    //delete lettersUsed;
}

