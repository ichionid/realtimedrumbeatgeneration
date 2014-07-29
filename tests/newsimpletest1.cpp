/* 
 * File:   newsimpletest1.cpp
 * Author: puppy
 *
 * Created on Aug 14, 2012, 9:44:30 AM
 */

#include <stdlib.h>
#include <iostream>

#include "State.h"

/*
 * Simple C++ Test Suite
 */

void test1() {
    
    State s1;
    vector< pair <int,double > > v1_st;
    v1_st.push_back(pair<int, double>(1, 32));
    v1_st.push_back(pair<int, double>(1, 5));
    v1_st.push_back(pair<int, double>(1, 100));
    v1_st.push_back(pair<int, double>(1, -2));
    s1.bubblesort_vector_descending(&v1_st);
    for (int i = 0; i < v1_st.size(); i++) {
        cout<<"("<<v1_st.at(i).first<<","<<v1_st.at(i).second<<")"<<endl;
    }

}



int main(int argc, char** argv) {
    test1();
    return (EXIT_SUCCESS);
}

