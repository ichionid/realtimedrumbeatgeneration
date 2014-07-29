/* 
 * File:   RealTimeIOMain.cpp
 * Author: puppy
 * 
 * Created on August 25, 2012, 1:10 PM
 */
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
#include "Metronome.h"
#include "Calibrator.h"
#include "RealTimeIOMain.h"


typedef boost::posix_time::ptime mytime;
typedef boost::posix_time::time_duration TimeDuration;

RealTimeIOMain::RealTimeIOMain() {

    double tempo = 100;
    double A = 4;
    double B = 4;
    double offset = 0;
    double meter_start = 0;
    double metronome_start = 0;
    double meter_duration = (60000. / tempo)*4.;
    Helper h;
    std::cout << boost::thread::hardware_concurrency() << " processors/cores detected." << endl << endl;
    boost::posix_time::ptime time = boost::posix_time::microsec_clock::local_time();

    SynchronizedQueue<Meter>* sQueue = new SynchronizedQueue<Meter > ();
    Metronome metronome(tempo);

    //    metronome.SetStartTime(t1.time_of_day().total_milliseconds());
    // Start thread metronome
    cout << "Start Metronome" << endl;
    boost::thread* metronomeThread;
    try {
        metronomeThread = new boost::thread(metronome);
    } catch (...) {
        cout << "metronome excpeption<<" << endl;
        throw "Exception";
    }
    //metronome should take care of the calibration
    //meter_start = now + (meter_duration - fmod(now - (metronome.GetStartTime() + metronome.GetOffset()), meter_duration));

    //run Calibrator for 8 times and on the 9th start recording
    //Calibrator calibrator(&metronome, &h); //5 secs
    //offset = metronome.GetOffset();
    //metronome_start = metronome.GetStartTime();
    //MidiHandlerProducer(SynchronizedQueue<Meter>* queue, double tempo, double offset,double A,double meter_start);
    //double now = boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds();
    //will give the next valid Qn in time, according to the metronome and offset
    //meter_start = now + (meter_duration - fmod(now - (metronome.GetStartTime() + metronome.GetOffset()), meter_duration));
    
    meter_start = metronome.GetStartTime() + ceil(meter_duration/A) * (NMTT_W + NMTT_C + NMTTBSIS );
    MidiHandlerProducer producer(sQueue, tempo, offset, A, metronome_start, meter_start, &h, &metronome); //4 means 4/4(constant)    
    boost::thread* producerThread = new boost::thread(producer);
    h.wait(meter_duration);
    cout<<"RealTimeIOMain::metronome.GetStartTime()::"<<metronome.GetStartTime()<<endl;
    //cout<<"RealTimeIOMain::meter_duration/A::"<<meter_duration/A<<endl;
    //cout<<"RealTimeIOMain::NMTT_W + NMTT_C + NMTTBSIS::"<<NMTT_W + NMTT_C + NMTTBSIS<<endl;
    //cout<<"(meter_duration/A) * (NMTT_W + NMTT_C + NMTTBSIS )::"<<(meter_duration/A) * (NMTT_W + NMTT_C + NMTTBSIS )<<endl;
    meter_start = metronome.GetStartTime() + ceil(meter_duration/A) * (NMTT_W + NMTT_C + NMTTBSIS );
    MarkovEngineConsumer consumer(sQueue, tempo, offset, A, metronome_start, meter_start, &h);
    boost::thread* consumerThread = new boost::thread(consumer);

    boost::thread_group threads;
    try {
        threads.add_thread(producerThread);
    } catch (...) {
        cout << "Exception in producerThread" << endl;
    }
    //threads.add_thread(consumerThread);
    try {
        threads.add_thread(metronomeThread);
    } catch (...) {
        cout << "Exception in metronomeThread" << endl;
    }
    threads.join_all(); // runs the threads!*/
    getchar();
    getchar();
    //    threads.interrupt_all();
    //    threads.join_all(); // runs the threads!    
}

RealTimeIOMain::~RealTimeIOMain() {
}

        