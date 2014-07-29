/* 
 * File:   CRC.h
 * Author: puppy
 *
 * Created on September 9, 2012, 5:23 PM
 */

#ifndef CRC_H
#define	CRC_H
#include <boost/crc.hpp>  // for boost::crc_32_type

#include <cstdlib>    // for EXIT_SUCCESS, EXIT_FAILURE
#include <exception>  // for std::exception
#include <fstream>    // for std::ifstream
#include <ios>        // for std::ios_base, etc.
#include <iostream>   // for std::cerr, std::cout
#include <ostream>    // for std::endl


// Redefine this to change to processing buffer size
#ifndef PRIVATE_BUFFER_SIZE
#define PRIVATE_BUFFER_SIZE  1024
#endif

// Global objects
std::streamsize const buffer_size = PRIVATE_BUFFER_SIZE;


class CRC {
public:
    CRC();
    int get_crc(const char *);
    ~CRC();
private:

};

#endif	/* CRC_H */

