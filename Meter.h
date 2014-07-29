/* 
 * File:   Meter.h
 * Author: puppy
 *
 * Created on June 9, 2012, 12:57 PM
 */

#ifndef METER_H
#define	METER_H
#include "RawNote.h"
#include <vector>
#include <iostream>

using namespace std;

class Meter {
public:
    Meter();
    void add_note(RawNote r);
    void delete_notes();
    vector<RawNote> get_notes();
    virtual ~Meter();
private:
    vector<RawNote> r;
};

#endif	/* METER_H */

