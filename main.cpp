
#include "RawNote.h"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include "boost/unordered_map.hpp"
#include "boost/thread.hpp"
#include "MarkovEngineConsumer.h"
#include "MidiHandlerProducer.h"
#include "Meter.h"
#include "SynchronizedQueue.h"
#include "Metronome.h"
#include "Calibrator.h"
#include "RealTimeIOMain.h"
#include "DrumMachineMain.h"
#include "CRC.h"
#include "CustomNumberDist.h"
#include "RAtestMain.h"
#if defined(__WINDOWS_MM__)
  #include <windows.h>
  #define SLEEP( milliseconds ) Sleep( (DWORD) milliseconds ) 
#else // Unix variants
  #include <unistd.h>
  #define SLEEP( milliseconds ) usleep( (unsigned long) (milliseconds * 1000.0) )
#endif

typedef boost::posix_time::ptime mytime;
typedef boost::posix_time::time_duration TimeDuration;

/**
 * meter_start is set in both producer and consumer by also using the offset.
 * This allows both threads to sync with each other. Notes are evaluated and 
 * placed in Letters(8th notes) according to the metronome that is considering 
 * the offset, this way we do not need to re-adjust other timing values with
 * the offset.
 * 
 * /

/**
 * @todo, RawNote->should be able to have a "flam" attribute and a
 *        repository for other note.
 * 
 */
int main(int argc, char** argv) {

    DrumMachineMain dmm;
    //RealTimeIOMain r;
    //RAtestMain ra;
    //VOMC v;
    //v.load("output/output_rock",0);    
    // Teh offset is defined as the id of the last element
    // This way can avoid mixing of states when we have states
    // similar to: 0,1,3,15,16, from file 1. 
    // If we'd consider offset equal to 5 then we would start creatig new states 
    // that would conflict with the ones of file 1
    //
    //v.load("output/output_rock4",v.vomc.at(v.vomc.size()-1)->GetId());
    //v.save_as("output/output_rock_save");
    /*CRC crc;
    cout << "CRC" << endl;
    cout << crc.get_crc("output/output") << endl;
    cout << crc.get_crc("output/output_2") << endl;
     */
    /*cout << "loaded vomc<<" << v.vomc.size() << endl;

    for (int i = 0; i < v.vomc.size(); i++) {
        cout << v.vomc.at(i)->GetConnected_states().size() << ",";
        cout << v.vomc.at(i)->GetLetters().size() << endl;
        for (int j = 0; j < v.vomc.at(i)->GetLetters().size(); j++) {
            cout << v.vomc.at(i)->GetLetters().at(j).getRawNotes().size() << ".";
            cout << v.vomc.at(i)->GetLetters().at(j).getPattern().GetName()<< ".";
        }
        cout << endl;
    }

    v.save_as("output/output2");
    CRC crc;
    cout << "CRC" << endl;
    cout << crc.get_crc("output/output") << endl;
    cout << crc.get_crc("output/output2") << endl;
     */
    /*RtMidiIn *midiin = 0;
    std::vector<unsigned char> message;
    int nBytes, i;
    double stamp;

    // RtMidiIn constructor
    try {
        midiin = new RtMidiIn();
    } catch (RtError &error) {
        error.printMessage();
        exit(EXIT_FAILURE);
    }

    // Check available ports vs. specified.
    unsigned int port = 0;
    unsigned int nPorts = midiin->getPortCount();
    try {
        midiin->openPort(1);
    } catch (RtError &error) {
        error.printMessage();
        goto cleanup;
    }

    // Don't ignore sysex, timing, or active sensing messages.
    midiin->ignoreTypes(true,true,true);

    // Install an interrupt handler function.
    //bool done = false;
    (void) signal(SIGINT, finish);

    // Periodically check input queue.
    std::cout << "Reading MIDI from port ... quit with Ctrl-C.\n";
    while (!done) {
        stamp = midiin->getMessage(&message);
        nBytes = message.size();
        for (i = 0; i < nBytes; i++)
            std::cout << "Byte " << i << " = " << (int) message[i] << ", ";
        if (nBytes > 0)
            std::cout << "stamp = " << stamp << std::endl;

        // Sleep for 10 milliseconds.
        SLEEP(10);
    }

    // Clean up
cleanup:
    delete midiin;

    return 0;*/
}
