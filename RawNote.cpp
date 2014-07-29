/* 
 * File:   RawNote.cpp
 * Author: puppy
 * 
 * Created on June 2, 2012, 11:38 AM
 */

#include <math.h>
#include <iostream>
#include "RawNote.h"
#include "LetterPattern.h"
using namespace std;

RawNote::RawNote(double limitedTimeStamp,
        double generalTimestamp,
        double eighthNoteTimeStamp,
        int pitch,
        int velocity
        ) {

    this->limitedTimeStamp = limitedTimeStamp;
    this->generalTimeStamp = generalTimestamp;
    this->pitch = pitch;
    this->velocity = velocity;
    this->eighthNoteTimeStamp = eighthNoteTimeStamp;
    this->weight = new double[6];

/*    cout<<"limitedTimeStamp::"<<this->limitedTimeStamp<<endl;
    cout<<"generalTimeStamp::"<<this->generalTimeStamp<<endl;
    cout<<"eighthNoteTimeStamp::"<<this->eighthNoteTimeStamp<<endl;
    cout<<"pitch::"<<this->pitch<<endl;
    cout<<"velocity::"<<this->velocity<<endl;*/
}
/**
 * 
 * @return, is a <code>double</code> representing the general timestamp of the 
 * note.
 */
double RawNote::GetGeneralTimeStamp() const {
    return generalTimeStamp;
}
/**
 * @param generalTimeStamp, is a <code>double</code> representing the general 
 * timestamp of the 
 * note.
 */
void RawNote::SetGeneralTimeStamp(double generalTimeStamp) {
    this->generalTimeStamp = generalTimeStamp;
}
/**
 * 
 * @return is a <code>double</code> representing the limited timestamp of the 
 * note.
 */
double RawNote::GetLimitedTimeStamp() const {
    return limitedTimeStamp;
}
/**
 * 
 * @param limitedTimeStamp, is a <code>double</code> representing the 
 * limited timestamp of the note.
 */
void RawNote::SetLimitedTimeStamp(double limitedTimeStamp) {
    this->limitedTimeStamp = limitedTimeStamp;
}
/**
 * 
 * @return An <code>int</code> representing the pitch of the 
 * note.
 */
int RawNote::GetPitch() const {
    return pitch;
}
/**
 * 
 * @param pitch, is an <code>int</code> representing the pitch of the 
 * note.
 */
void RawNote::SetPitch(int pitch) {
    this->pitch = pitch;
}
/**
 * 
 * @return An <code>int</code> representing the velocity of the 
 * note.
 */
int RawNote::GetVelocity() const {
    return velocity;
}
/**
 * 
 * @param velocity, is an <code>int</code> representing the velocity of the 
 * note.
 */
void RawNote::SetVelocity(int velocity) {
    this->velocity = velocity;
}
/**
 * 
 * @return A <code>double</code> representing the eighth note timestamp
 *  of the note.
 */
double RawNote::GetEighthNoteTimeStamp() const {
    return eighthNoteTimeStamp;
}
/**
 * 
 * @param eighthNoteTimeStamp, is a <code>double</code> representing the 
 * eighth note timestamp of the note.
 */
void RawNote::SetEighthNoteTimeStamp(double eighthNoteTimeStamp) {

    this->eighthNoteTimeStamp = eighthNoteTimeStamp;

}
/**
 * 
 * @return A <code>int</code> representing the position
 *  of the note.
 */
int RawNote::GetPosition() const {
    return position;
}
/**
 * 
 * @param position, is an <code>int</code> representing the position
 *  of the note.
 */
void RawNote::SetPosition(int position) {
    this->position = position;
}
/**
 * 
 * @param i, is an <code>int</code> representing the position
 *  whose weight we are interested in.
 * @return An <code>int</code> representing the specific weight 
 **/
double RawNote::GetWeight(int i) const {
    return this->weight[i];
}
/**
 * 
 * @param i, is an <code>int</code> representing the position
 *  whose weight we are interested in.
 * @param value, is a <code>double</code> representing the actual weight.
 */
void RawNote::SetWeight(int i, double value) {
    this->weight[i] = value;
}
//Find note of letter that is closest and mark it as used 
/**
 * 
 * @param l, is a <code>LetterPattern</code>
 * @return <code>double</code>
 */
double RawNote::retSmallestExistingWeight(LetterPattern* l) {
    double min = 10000;
    int pointer = -1;
    //parse all letters of pattern[0,1,2,3 or 0,4,5]
    //cout<<"Name:"<<l->GetName()<<endl;
    ////cout<<"l.GetPattern().size()"<<l->GetPattern().size()<<endl;
    for (int i = 0; i < l->GetPattern().size(); i++) {
        //get weight for specific position the exists in the note

        //  //cout<<"i="<<i<<endl;
        if (this->weight[l->GetPattern().at(i)] < min) {
            //assign smallest existing weight  until loop i
            min = this->weight[l->GetPattern().at(i)];
            pointer = i;
        }
    }

    l->setLettersUsed(pointer);
    ////cout<<"min:"<<min<<endl;
    return min;
}
/**
 * @param l, is <code>LetterPattern</code>*.
 */
void RawNote::setPositionOfSmallestExistingWeight(LetterPattern* l) {
    double min = 10000;
    int pointer;

    for (int i = 0; i < l->GetPattern().size(); i++) {
        ////cout<<"check:"<<l->GetPattern().at(i)<<endl;
        if (this->weight[l->GetPattern().at(i)] < min) {
            min = this->weight[l->GetPattern().at(i)];
            pointer = l->GetPattern().at(i);
        }
    }
    this->position = pointer;
}

RawNote::~RawNote() {
    //delete [] this->weight;
}

