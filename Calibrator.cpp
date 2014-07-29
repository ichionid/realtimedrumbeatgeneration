/* 
 * File:   Calibrator.cpp
 * Author: Ioannis Chionidis
 * 
 * Created on June 12, 2012, 1:21 PM
 */

#include "Calibrator.h"
typedef boost::posix_time::ptime Time;
typedef boost::posix_time::time_duration TimeDuration;

bool calibrator_done;

static void calibrator_finish(int ignore) {
    calibrator_done = true;
}
/**
 * Obsolete
 */
Calibrator::Calibrator(Metronome* m, Helper *h) {

    this->m = m;
    this->durOfCalibration = durOfCalibration;
    RtMidiIn *midiin = new RtMidiIn();
    vector<unsigned char> message;
    int nBytes;

    // Check available ports.
    unsigned int nPorts = midiin->getPortCount();
    if (nPorts == 0) {
        cout << "No ports available!\n";
        delete midiin;
        return;
    }


    //cout << "Reading MIDI from port 1 quit with Ctrl-C.\n";
    long timeDiff;
    //while ((((TimeDuration)(boost::posix_time::microsec_clock::local_time()-tStart)).total_milliseconds())< (tStart*number_of_ticks)) {
    //cout << "CALIBRATOR::GetQnDuration::" << m->GetQnDuration() << endl;
    //cout << "CALIBRATOR::Wait Start Time to be set::" << endl;
    //wait for 2 QN for startTime to be set
    long now_t = boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds();
    //cout << "CALIBRATOR::MEM CHECK"<<endl;
    //while (boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds()
    //        < (now_t + m->GetQnDuration()*NUMBER_METRONOME_TICKS_TO_BEFORE_STARTTIME_IS_SET));
    h->wait(NMTTBSIS * m->GetQnDuration());//4/4
                 // 4            4+4       
    for (int i = NMTTBSIS; i < NMTT_W + NMTTBSIS; i++) {
        if (i != (NMTT_W + NMTTBSIS - 1)) {
            cout << "CALIBRATOR::InActive Tick::" << i << endl;
        } else if (i != (NMTT_W + NMTTBSIS - 1)) {
            cout << "CALIBRATOR::PRE-LAST InActive Tick::" << i << endl;
        } else {
            cout << "CALIBRATOR::LAST InActive Tick::" << i << endl;
        }
        while (boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds()
                < (m->GetStartTime() + m->GetQnDuration() * i));
    }
   midiin->openPort(1);

    // Don't ignore sysex, timing, or active sensing messages.
    //   midiin->ignoreTypes(true, false, true);
    // midiin->ignoreTypes(true, true, true);
    // Install an interrupt handler function.
    calibrator_done = false;
    (void) signal(SIGINT, calibrator_finish);

    // Periodically check input queue.
    /*while (boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds() < wait_time) {
        ;
    }*/
    cout << "Start feeding Calibration!" << endl;

    long time_stamp = 0;
    double stamp;

    long t_offset = (NMTTBSIS + NMTT_C + NMTT_W) * m->GetQnDuration() + m->GetStartTime();
    cout<<"t_offset::"<<t_offset<<endl;
    cout<<"m->GetQnDuration()::"<<m->GetQnDuration()<<endl;
    cout<<"m->GetStartTime()::"<<m->GetStartTime()<<endl;
    
    cout << "Start Recording Calibration Notes" << endl;
    while (boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds() < t_offset) {
        midiin->getMessage(&message);
        //STAMP EVENT
        time_stamp = boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds();
        //cout << "Inside_1" << endl;
        nBytes = message.size();
        //cout << "Inside_2" << endl;

        if (nBytes > 2) {
            cout << "Calibrator.cpp::nBytes > 2" << endl;

            timeDiff = fmod(boost::lexical_cast<double>(time_stamp - m->GetStartTime()), boost::lexical_cast<double>(m->GetQnDuration())); //check how much it varies from the starting one
            //cout << "Inside_4" << endl;
            if (((int) message.at(2) != 0) && ((int) message.at(1) == 34)) {
                //Time t1(boost::posix_time::microsec_clock::local_time());//stamp event
              //  cout << "Inside_5" << endl;
                timeDiff = fmod(boost::lexical_cast<double>(time_stamp - m->GetStartTime()), boost::lexical_cast<double>(m->GetQnDuration())); //check how much it varies from the starting one
                //cout << "Inside TimeDiff =" << timeDiff << endl;
                /*cout << (int) message.at(0) <<endl;
                cout << (int) message.at(1) <<endl;
                cout << (int) message.at(2) <<endl;*/
                if (timeDiff > (m->GetQnDuration() / 2)) {//before onset
                    cout << "Inside TimeDiff =" << timeDiff << endl;
                    timeDisperion.push_back(m->GetQnDuration() - timeDiff); //should be negative

                } else {//after onset

                    timeDisperion.push_back(timeDiff);

                }
            }
        }
    }
    cout<<"Ticks from start::"<<(boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds()-m->GetStartTime())/m->GetQnDuration()<<endl;
    for (int i = 0; i < timeDisperion.size(); i++) {
        cout << timeDisperion.at(i) << endl;
    }
    double tStart_calculate_average = boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds();
    m->SetOffset(this->calculate_average());
    double time_difference_calc_average = boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds() - tStart_calculate_average;
    cout << "Time to calculate average::" << time_difference_calc_average;
    double time_left = ((NMTTBSIS + NMTT_C + NMTT_W + 1) * m->GetStartTime())
            - boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds();
    cout << "Time Left until the next Qn::" << time_left << endl;
    
    delete midiin;
}

Calibrator::~Calibrator() {
    cout << "Calibrator Destructor" << endl;
}

double Calibrator::calculate_average() {

    long average = 0, newAverage = 0;
    long deviationA1 = 0, deviation = 0;
    for (int i = 0; i < timeDisperion.size(); i++) {
        average += timeDisperion.at(i);
        deviationA1 += pow(timeDisperion.at(i), 2);
    }

    average = average / timeDisperion.size();
    deviationA1 = deviationA1 / timeDisperion.size();
    deviation = sqrt(deviationA1 - pow(average, 2));
    for (int i = 0; i < timeDisperion.size(); i++) {
        if (abs(average - timeDisperion.at(i))<(2 * deviation)) {
            newAverage += timeDisperion.at(i);
        }
    }
    return newAverage = newAverage / timeDisperion.size();
}

