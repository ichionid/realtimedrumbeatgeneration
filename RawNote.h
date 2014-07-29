/* 
 * File:   RawNote.h
 * Author: puppy
 *
 * Created on June 2, 2012, 11:38 AM
 */

#ifndef RAWNOTE_H
#define	RAWNOTE_H
#include "LetterPattern.h"
#include <vector>
using namespace std;

class RawNote {
public:
    RawNote(double limitedTimeStamp,double generalTimestamp,double eighthNoteTimeStamp,int pitch,int velocity);
    virtual ~RawNote();
    double GetGeneralTimeStamp() const;
    void SetGeneralTimeStamp(double generalTimeStamp);
    double GetLimitedTimeStamp() const;
    void SetLimitedTimeStamp(double limitedTimeStamp);
    int GetPitch() const;
    void SetPitch(int pitch) ;
    int GetVelocity() const;
    double GetEighthNoteTimeStamp() const;
    void SetVelocity(int velocity);
    void SetEighthNoteTimeStamp(double eighthNoteTimeStamp);
    int GetPosition() const ;
    void SetPosition(int position);
    double GetWeight(int i) const ;
    void SetWeight(int i, double value);
    double retSmallestExistingWeight(LetterPattern* l);
    void setPositionOfSmallestExistingWeight(LetterPattern* l);
private:
    double limitedTimeStamp;
    double generalTimeStamp;
    double eighthNoteTimeStamp;
    double* weight;
    int pitch;
    int velocity;
    int position;//0,1,2,3,(0,4,5:triplets)
};

#endif	/* RAWNOTE_H */

