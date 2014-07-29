/* 
 * File:   CRC.cpp
 * Author: Ioannis Chionidis
 * 
 * Created on September 9, 2012, 5:23 PM
 */

#include "CRC.h"

CRC::CRC() {
}
/**
 * 
 * @param file is a <code>char const *<code> representing the file name.
 * @return An <code>int</code> representing the CRC 32 check sum.
 */
int CRC::get_crc(char const * file) {

    boost::crc_32_type result;
    std::ifstream ifs(file, std::ios_base::binary);
    if (ifs) {
        do {
            char buffer[ buffer_size ];
            ifs.read(buffer, buffer_size);
            result.process_bytes(buffer, ifs.gcount());
        } while (ifs);
    } else {
        std::cerr << "Failed to open file '" << file << "'."
                << std::endl;
        throw "Exception Failed to open file" ;
    }
    return result.checksum();
}

CRC::~CRC() {
}

