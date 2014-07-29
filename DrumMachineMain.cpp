/* 
 * File:   DrumMachineMain.cpp
 * Author: puppy
 * 
 * Created on August 25, 2012, 1:09 PM
 */

#include "DrumMachineMain.h"
DrumMachineMain::DrumMachineMain() {

   ////cout << "Markov thought patterns Started!" << endl;
    Helper h;
    double tempo = 60;
    int A = 4;
    //double B = 4;
    double offset = 0;
    double meter_start = 0;
    double metronome_start = 0;
    double meter_duration = (60000. / tempo)*4.;
    //std:://cout << boost::thread::hardware_concurrency() << " processors/cores detected." << endl << endl;
    boost::posix_time::ptime time = boost::posix_time::microsec_clock::local_time();

    sQueue = new SynchronizedQueue<Meter > ();

    //will give the next valid Qn in time, according to the metronome and offset
    meter_start = boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds();
    //fake metronome start since it is needed in the second function
    metronome_start = meter_start - meter_duration;

    MarkovEngineConsumer consumer(sQueue, tempo, offset, A, metronome_start, meter_start ,&h);
    //consumer.load_files();
   ////cout<<"LOAD ENDED"<<endl;
    //DrumMachine producer("rock3.mid", false, sQueue, tempo, offset, A, metronome_start, meter_start); //4 means 4/4(constant)    
    DrumMachine producer("experiments/test.mid", sQueue, tempo, offset, A, metronome_start, meter_start); //4 means 4/4(constant)    
    //DrumMachine producer("experiments/RAbib.mid", sQueue, tempo, offset, A, metronome_start, meter_start); //4 means 4/4(constant)    
    //DrumMachine producer("experiments/mem.mid", sQueue, tempo, offset, A, metronome_start, meter_start); //4 means 4/4(constant)    
    //DrumMachine producer("experiments/tsifteteli.mid", sQueue, tempo, offset, A, metronome_start, meter_start); //4 means 4/4(constant)    
    //DrumMachine producer("experiments/4_meter_t.mid", sQueue, tempo, offset, A, metronome_start, meter_start); //4 means 4/4(constant)    
    //DrumMachine producer("experiments/RAProblematic.mid", sQueue, tempo, offset, A, metronome_start, meter_start); //4 means 4/4(constant)    
    //DrumMachine producer("experiments/eftari.mid", sQueue, tempo, offset, A, metronome_start, meter_start); //4 means 4/4(constant)    
    //DrumMachine producer("rock1.mid",false,sQueue, tempo, offset, A,metronome_start, meter_start );//4 means 4/4(constant)    
    boost::thread* producerThread = new boost::thread(producer);
    boost::thread* consumerThread = new boost::thread(consumer);
    boost::thread_group threads;
    threads.add_thread(consumerThread);
    threads.add_thread(producerThread);
    producerThread->interrupt();
    threads.join_all(); // runs the threads!
    threads.interrupt_all();
}

DrumMachineMain::~DrumMachineMain(){
    delete sQueue;
}

