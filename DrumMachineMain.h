/* 
 * File:   DrumMachineMain.h
 * Author: puppy
 *
 * Created on August 25, 2012, 1:09 PM
 */

#ifndef DRUMMACHINEMAIN_H
#define	DRUMMACHINEMAIN_H
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include "include/RtMidi.h"
#include "boost/unordered_map.hpp"
#include "boost/thread.hpp"
#include "MarkovEngineConsumer.h"
#include "MidiHandlerProducer.h"
#include "Meter.h"
#include "SynchronizedQueue.h"
#include "DrumMachine.h"

class DrumMachineMain {
public:
    DrumMachineMain();
    ~DrumMachineMain();
private:
    SynchronizedQueue<Meter>* sQueue;
};

#endif	/* DRUMMACHINEMAIN_H */

