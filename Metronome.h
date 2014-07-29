/* 
 * File:   Metronome.h
 * Author: puppy
 *
 * Created on June 9, 2012, 7:22 PM
 */

#ifndef METRONOME_H
#define	METRONOME_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <vector>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include "Helper.h"
#include "include/RtMidi.h"
typedef boost::posix_time::ptime Time;
typedef boost::posix_time::time_duration TimeDuration;

using namespace std;
static int id=0;
/**
 *  @param offset, is a <code>double</code> will be set during calibration and will be used in order 
 *  to modify the position of the note, in other words it will only be used
 *  in the initialization of a raw note.
 *  @param QnDuration, is a <code>double</code> representing the duration 
 *         of a Quarter Note.
 *  @param startTime, is a <code>double</code> representing the starting point 
 *         of the metronome, it is set by the main and used ONLY in here.
 *  @param tempo, is a <code>double</code> representing the tempo of the groove.
 */
class Metronome {
public:
    Metronome();
    Metronome(double tempo);
    void operator () ();
    virtual ~Metronome();
    double GetTempo() const;
    double GetQnDuration() const;
    double GetStartTime() const;
    double GetOffset() const;
    void SetTempo(double tempo);
    void SetStartTime(double startTime);
    void SetQnDuration(double duration);
    void SetOffset(double duration);
    bool GetStartTimeReady()const;
    void SetStartTimeReady(bool startTimeReady);

private:
    double offset;
    double QnDuration;
    double tempo;
    double startTime;
    double startTimeReady;

};

#endif	/* METRONOME_H */

