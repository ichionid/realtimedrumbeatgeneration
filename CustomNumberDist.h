/* 
 * File:   NormalDistribution.h
 * Author: puppy
 *
 * Created on September 21, 2012, 3:29 PM
 */

#ifndef CUSTOMNUMBERDIST_H
#define	CUSTOMNUMBERDIST_H
#include "boost/random/mersenne_twister.hpp" 
#include "boost/random/normal_distribution.hpp" 
#include "boost/random/variate_generator.hpp"
#include "boost/math/special_functions/sinc.hpp"
#include <iostream>
using namespace std;

class CustomNumberDist {
    boost::mt19937 _rng;
    boost::variate_generator<boost::mt19937&, boost::normal_distribution<> > var_nor;
public:
    CustomNumberDist();
    ~CustomNumberDist();
    double generate();
};

#endif	/* CustomNumberDist_h */

