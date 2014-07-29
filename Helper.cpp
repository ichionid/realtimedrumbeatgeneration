/* 
 * File:   Helper.cpp
 * Author: puppy
 * 
 * Created on September 23, 2012, 6:34 PM
 */

#include "Helper.h"
/**
 * 
 * @param milliseconds is a <code>double</code> representing the time 
 * the delay should take place for.
 */
void Helper::wait(double milliseconds){
    long start_t = boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds();
    while(boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds()<(start_t+milliseconds));
    cout<<"Waited::"<<boost::posix_time::microsec_clock::local_time().time_of_day().total_milliseconds()-start_t<<endl;
}
Helper::Helper() {
    all_possible_notes = new vector<LetterPattern>();
     vector<int> vA;
    vA.push_back(0);
    LetterPattern A(vA,"Xooo");
    
    vector<int> vB;
    vB.push_back(1);
    LetterPattern B(vB,"oXoo");
    
    vector<int> vC;
    vC.push_back(2);
    LetterPattern C(vC,"ooXo");
    
    vector<int> vD;
    vD.push_back(3);
    LetterPattern D(vD,"oooX");
    
    vector<int> vE;
    vE.push_back(0);
    vE.push_back(1);
    LetterPattern E(vE,"XXoo");
    
    vector<int> vF;
    vF.push_back(1);
    vF.push_back(2);
    LetterPattern F(vF,"oXXo");
    
    vector<int> vG;
    vG.push_back(2);
    vG.push_back(3);
    LetterPattern G(vG,"ooXX");
    
    vector<int> vH;
    vH.push_back(0);
    vH.push_back(3);
    LetterPattern H(vH,"XooX");
    
    vector<int> vI;
    vI.push_back(0);
    vI.push_back(2);
    LetterPattern I(vI,"XoXo");
    
    vector<int> vJ;
    vJ.push_back(1);
    vJ.push_back(3);
    LetterPattern J(vJ,"oXoX");
    
    vector<int> vK;
    vK.push_back(0);
    vK.push_back(1);
    vK.push_back(2);
    LetterPattern K(vK,"XXXo");
    
    vector<int> vL;
    vL.push_back(1);
    vL.push_back(2);
    vL.push_back(3);
    LetterPattern L(vL,"oXXX");
    
    vector<int> vM;
    vM.push_back(0);
    vM.push_back(2);
    vM.push_back(3);
    LetterPattern M(vM,"XoXX");
    
    vector<int> vN;
    vN.push_back(0);
    vN.push_back(1);
    vN.push_back(3);
    LetterPattern N(vN,"XXoX");
    
    vector<int> vO;
    vO.push_back(0);
    vO.push_back(1);
    vO.push_back(2);
    vO.push_back(3);
    LetterPattern O(vO,"XXXX");
    
    vector<int> vR;
    vR.push_back(4);
    LetterPattern R(vR,"oXo");
    
    vector<int> vS;
    vS.push_back(5);
    LetterPattern S(vS,"ooX");
    
    vector<int> vT;
    vT.push_back(0);
    vT.push_back(4);
    LetterPattern T(vT,"XXo");
    
    vector<int> vU;
    vU.push_back(4);
    vU.push_back(5);
    LetterPattern U(vU,"oXX");
    
    vector<int> vV;
    vV.push_back(0);
    vV.push_back(5);
    LetterPattern V(vV,"XoX");
    
    vector<int> vW;
    vW.push_back(0);
    vW.push_back(4);
    vW.push_back(5);
    LetterPattern W(vW,"XXX");
    
    all_possible_notes->push_back(A);
    all_possible_notes->push_back(B);
    all_possible_notes->push_back(C);
    all_possible_notes->push_back(D);
    all_possible_notes->push_back(E);
    all_possible_notes->push_back(F);
    all_possible_notes->push_back(G);
    all_possible_notes->push_back(H);
    all_possible_notes->push_back(I);
    all_possible_notes->push_back(J);
    all_possible_notes->push_back(K);
    all_possible_notes->push_back(L);
    all_possible_notes->push_back(M);
    all_possible_notes->push_back(N);
    all_possible_notes->push_back(O);
    all_possible_notes->push_back(R);
    all_possible_notes->push_back(S);
    all_possible_notes->push_back(T);
    all_possible_notes->push_back(U);
    all_possible_notes->push_back(V);
    all_possible_notes->push_back(W);
}
vector<LetterPattern>* Helper::get_all_possible_notes(){

    return all_possible_notes;
    
}
Helper::~Helper() {
}

