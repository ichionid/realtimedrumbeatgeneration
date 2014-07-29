/* 
 * File:   Calibrator.h
 * Author: puppy
 *
 * Created on June 12, 2012, 1:21 PM
 */

#ifndef CALIBRATOR_H
#define	CALIBRATOR_H
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <signal.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "include/RtMidi.h"
#include "Metronome.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include "SynchronizedQueue.h"
#include "MidiHandlerProducer.h"
#include "RawNote.h"
#include "Helper.h"


using namespace std;

//not a thread

class Calibrator {
public:
    Calibrator(Metronome* m, Helper *h);
    virtual ~Calibrator();
    double calculate_average();
private:
    long durOfCalibration;
    vector<long> timeDisperion;
    Metronome* m;
    double meter_start;
};

#endif	/* CALIBRATOR_H */

