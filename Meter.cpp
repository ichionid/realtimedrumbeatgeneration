/* 
 * File:   Meter.cpp
 * Author: Ioannis Chionidis
 * 
 * Created on June 9, 2012, 12:57 PM
 */

#include "Meter.h"

Meter::Meter() {
    std:cout<<"Meter Constructor";
}
/**
 * 
 * @param note is a <code>RawNote</code> to be added to the <code>meter</code>.
 */
void Meter::add_note(RawNote note){
    r.push_back(note);
}
void Meter::delete_notes(){
    r.clear();
}
/**
 * 
 * @return get <code>vector<RawNote> </code> of the object.
 */
vector<RawNote> Meter::get_notes(){
    return r;
}
Meter::~Meter( ) {
    ;
}

