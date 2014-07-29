/* 
 * File:   CustomNumberDist.cpp
 * Author: Ioannis Chionidis
 * 
 * Created on September 21, 2012, 3:29 PM
 */

#include "CustomNumberDist.h"

CustomNumberDist::CustomNumberDist() :
_rng(), var_nor(_rng, boost::normal_distribution<>(0.5, 1.0)) {
    //cout << "Normal Distribution Construction" << endl;
}
/** 
 * @return A <code>double</code> representing a random number following a normal distribution of 
 * standard deviation equal to 1 and mean equal to 0.5  
 */
double CustomNumberDist::generate() {
    double generated_number;
    while (true) {
        generated_number = var_nor();
        if ((generated_number <= 1) && (generated_number >= 0))
            return generated_number;
    }
}

CustomNumberDist::~CustomNumberDist() {
    //cout<<"CustomNumberDist::~CustomNumberDist(), Destructor at address" << this<<endl;
}
