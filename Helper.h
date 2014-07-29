#ifndef HELPER_H
#define	HELPER_H
#include <vector>
#include "LetterPattern.h"
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#define NMTTBSIS 2
#define NMTT_W 4
#define NMTT_C 6


using namespace std;

class Helper {
public:
    Helper();
    ~Helper();
    vector<LetterPattern>* get_all_possible_notes();
    void wait(double milliseconds);
private:
    vector<LetterPattern>* all_possible_notes;
};
#endif
