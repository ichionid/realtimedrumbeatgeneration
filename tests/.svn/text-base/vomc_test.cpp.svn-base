/* 
 * File:   newsimpletest2.cpp
 * Author: puppy
 *
 * Created on Aug 14, 2012, 2:05:24 PM
 */

#include <stdlib.h>
#include <iostream>
#include <bitset>

#include "VOMC.h"

/*
 * Simple C++ Test Suite
 */

/**
 * vector<int> vA;
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
 */
void solver_1() {
    /**
     * INPUT:
     * xoxo xoxo xoxo xoxo | xoxo xoxo xoxo xoxo | xoxo xoxo xoxo xoxo
     * oooo xooo oooo xooo | oooo xooo oooo xooo | oooo xxoo oooo xooo
     * xooo oooo xooo oooo | xooo oooo xoox oooo | xxxx oooo xooo oooo 
     */
    VOMC* vomc = new VOMC();
    //1.Create input
    vector<int> vK;
    vK.push_back(0);
    vK.push_back(1);
    vK.push_back(2);
    LetterPattern K(vK, "XXXo");

    vector<int> vM;
    vM.push_back(0);
    vM.push_back(2);
    vM.push_back(3);
    LetterPattern M(vM, "XoXX");

    vector<int> vI;
    vI.push_back(0);
    vI.push_back(2);
    LetterPattern I(vI, "XoXo");

    vector<int> vO;
    vO.push_back(0);
    vO.push_back(1);
    vO.push_back(2);
    vO.push_back(3);
    LetterPattern O(vO,"XXXX");
    
    vector<int> vE;
    vE.push_back(0);
    vE.push_back(1);
    LetterPattern E(vE,"XXoo");
    
    Letter *lA,*lB,*lC,*lD,*lE;
    lA = new Letter();
    lB = new Letter();
    lC = new Letter();
    lD = new Letter();
    lE = new Letter();
    
    /*******************************************/
    RawNote* bd_A_0 = new RawNote(0, 0, 0, bd, 55);
    bd_A_0 -> SetPosition(0);
    RawNote* hh_A_0 = new RawNote(0, 0, 0, hh1, 55);
    hh_A_0 -> SetPosition(0);
    RawNote* hh_A_2 = new RawNote(0, 0, 0, hh1, 55);
    hh_A_2 -> SetPosition(2);
    lA -> add_note(*bd_A_0);
    lA -> add_note(*hh_A_0);
    lA -> add_note(*hh_A_2);
    lA -> setPattern(I);
    /*******************************************/

    /*******************************************/
    RawNote* sn_B_0 = new RawNote(0, 0, 0, sn, 55);
    sn_B_0 -> SetPosition(0);
    RawNote* hh_B_0 = new RawNote(0, 0, 0, hh1, 55);
    hh_B_0 -> SetPosition(0);
    RawNote* hh_B_2 = new RawNote(0, 0, 0, hh1, 55);
    hh_B_2 -> SetPosition(2);
    lB -> add_note(*sn_B_0);
    lB -> add_note(*hh_B_0);
    lB -> add_note(*hh_B_2);
    lB -> setPattern(I);
    /*******************************************/
    /*******************************************/
    RawNote* bd_C_0 = new RawNote(0, 0, 0, bd, 55);
    bd_C_0 -> SetPosition(0);
    RawNote* hh_C_0 = new RawNote(0, 0, 0, hh1, 55);
    hh_C_0 -> SetPosition(0);
    RawNote* hh_C_2 = new RawNote(0, 0, 0, hh1, 55);
    hh_C_2 -> SetPosition(2);
    RawNote* bd_C_3 = new RawNote(0, 0, 0, bd, 55);
    bd_C_0 -> SetPosition(3);
    lC -> add_note(*bd_C_0);
    lC -> add_note(*hh_C_0);
    lC -> add_note(*hh_C_2);
    lC -> add_note(*bd_C_3);
    lC -> setPattern(M);
    /*******************************************/
    /*******************************************/
    RawNote* bd_D_0 = new RawNote(0, 0, 0, bd, 55);
    bd_D_0 -> SetPosition(0);
    RawNote* hh_D_0 = new RawNote(0, 0, 0, hh1, 55);
    hh_D_0 -> SetPosition(0);
    RawNote* bd_D_1 = new RawNote(0, 0, 0, bd, 55);
    bd_D_1 -> SetPosition(1);
    RawNote* hh_D_2 = new RawNote(0, 0, 0, hh1, 55);
    hh_D_2 -> SetPosition(2);
    RawNote* bd_D_2 = new RawNote(0, 0, 0, bd, 55);
    bd_D_2 -> SetPosition(2);
    RawNote* bd_D_3 = new RawNote(0, 0, 0, bd, 55);
    bd_D_3 -> SetPosition(3);
    lD -> add_note(*bd_D_0);
    lD -> add_note(*hh_D_0);
    lD -> add_note(*bd_D_1);
    lD -> add_note(*hh_D_2);
    lD -> add_note(*bd_D_2);
    lD -> add_note(*bd_D_3);
    lD -> setPattern(O);
    /*******************************************/
    /*******************************************/
    RawNote* sn_E_0 = new RawNote(0, 0, 0, sn, 55);
    sn_E_0 -> SetPosition(0);
    RawNote* hh_E_0 = new RawNote(0, 0, 0, hh1, 55);
    hh_E_0 -> SetPosition(0);
    RawNote* sn_E_1 = new RawNote(0, 0, 0, sn, 55);
    sn_E_1 -> SetPosition(1);
    RawNote* hh_E_2 = new RawNote(0, 0, 0, hh1, 55);
    hh_E_2 -> SetPosition(2);
    lE -> add_note(*sn_E_0);
    lE -> add_note(*hh_E_0);
    lE -> add_note(*sn_E_1);
    lE -> add_note(*hh_E_2);
    lE -> setPattern(E);
    /*******************************************/
    
    vector<Letter> l1,l2,l3,lin;
    l1.push_back(*lA);
    l1.push_back(*lB);
    l1.push_back(*lA);
    l1.push_back(*lB);
    l2.push_back(*lA);
    l2.push_back(*lB);
    l2.push_back(*lC);
    l2.push_back(*lB);
    l3.push_back(*lD);
    l3.push_back(*lE);
    l3.push_back(*lA);
    l3.push_back(*lB);
    lin.push_back(*lC);
    lin.push_back(*lC);
    lin.push_back(*lD);
    lin.push_back(*lB);
    
    //2.Train
    vomc->train(l1);
    vomc->train(l2);
    vomc->train(l1);
    vomc->train(l3);

    vomc->print();
    //3.Fetch output
    State sout;
    try{
        sout = vomc->provide_response_pattern_remove(lin);
        sout = vomc->provide_response_pattern_remove(lin);
    }catch(int e){
        cout<<"Not solution found"<<endl;
        cout<<"Cia bella ;)"<<endl;
        throw "end of story";        
    }
    cout<<"***********OUTPUT**********"<<endl;
    if (sout.GetId() == -1) {
        cerr << "Markov found no response" << endl;
    }else{
        cout << "State.ID="<<sout.GetId()<<endl;
    }
    cout<<"Number of Letters:"<<sout.GetLetters().size()<<endl;
    
    for (int i = 0; i < sout.GetLetters().size(); i++) {
        cout<<sout.GetLetters().at(i).print_hihat();
    }
    cout<<endl;
    for (int i = 0; i < sout.GetLetters().size(); i++) {
        cout<<sout.GetLetters().at(i).print_instrument(sn);
    }
    cout<<endl;
    for (int i = 0; i < sout.GetLetters().size(); i++) {
        cout<<sout.GetLetters().at(i).print_instrument(bd);
    }
    cout<<endl;
}
void solver_2() {
    
    VOMC* vomc = new VOMC();
    //1.Create input
    vector<int> vK;
    vK.push_back(0);
    vK.push_back(1);
    vK.push_back(2);
    LetterPattern K(vK, "XXXo");

    vector<int> vM;
    vM.push_back(0);
    vM.push_back(2);
    vM.push_back(3);
    LetterPattern M(vM, "XoXX");

    vector<int> vI;
    vI.push_back(0);
    vI.push_back(2);
    LetterPattern I(vI, "XoXo");

    Letter *l_a_1, *l_a_2, *l_a_3, *l_a_4;
    Letter *l_b_1, *l_b_2, *l_b_3, *l_b_4;
    l_a_1 = new Letter();
    l_a_2 = new Letter();
    l_a_3 = new Letter();
    l_a_4 = new Letter();
    l_b_1 = new Letter();
    l_b_2 = l_a_2;
    l_b_3 = l_a_3;
    l_b_4 = new Letter();

    /*******************************************/
    RawNote* r1_a_a_0 = new RawNote(0, 0, 0, bd, 55);
    r1_a_a_0 -> SetPosition(0);
    RawNote* r1_a_a_1 = new RawNote(0, 0, 0, hh1, 55);
    r1_a_a_1 -> SetPosition(0);
    RawNote* r1_a_a_2 = new RawNote(0, 0, 0, hh1, 55);
    r1_a_a_2 -> SetPosition(2);
    l_a_1 -> add_note(*r1_a_a_0);
    l_a_1 -> add_note(*r1_a_a_1);
    l_a_1 -> add_note(*r1_a_a_2);
    l_a_1 -> setPattern(I);
    /*******************************************/

    /*******************************************/
    RawNote* r2_a_b_0 = new RawNote(0, 0, 0, bd, 55);
    r2_a_b_0 -> SetPosition(0);
    RawNote* r2_a_b_1 = new RawNote(0, 0, 0, hh1, 55);
    r2_a_b_1 -> SetPosition(0);
    RawNote* r2_a_b_2 = new RawNote(0, 0, 0, hh1, 55);
    r2_a_b_2 -> SetPosition(2);
    RawNote* r2_a_b_3 = new RawNote(0, 0, 0, bd, 55);
    r2_a_b_3 -> SetPosition(3);

    l_b_1 -> add_note(*r2_a_b_0);
    l_b_1 -> add_note(*r2_a_b_1);
    l_b_1 -> add_note(*r2_a_b_2);
    l_b_1 -> add_note(*r2_a_b_3);
    l_b_1 -> setPattern(M);
    /*******************************************/

    RawNote* r2_a_c_0 = new RawNote(0, 0, 0, bd, 55);
    r2_a_c_0 -> SetPosition(0);
    RawNote* r2_a_c_1 = new RawNote(0, 0, 0, hh1, 55);
    r2_a_c_1 -> SetPosition(0);
    RawNote* r2_a_c_2 = new RawNote(0, 0, 0, hh1, 55);
    r2_a_c_2 -> SetPosition(2);
    RawNote* r2_a_c_3 = new RawNote(0, 0, 0, bd, 55);
    r2_a_c_3 -> SetPosition(2);

    l_b_4 -> add_note(*r2_a_c_0);
    l_b_4 -> add_note(*r2_a_c_1);
    l_b_4 -> add_note(*r2_a_c_2);
    l_b_4 -> add_note(*r2_a_c_3);
    l_b_4 -> setPattern(K);
    /*******************************************/

    /*******************************************/
    RawNote* r1_a_b_0 = new RawNote(0, 0, 0, sn, 55);
    r1_a_b_0 -> SetPosition(0);
    RawNote* r1_a_b_1 = new RawNote(0, 0, 0, hh1, 55);
    r1_a_b_1 -> SetPosition(0);
    RawNote* r1_a_b_2 = new RawNote(0, 0, 0, hh1, 55);
    r1_a_b_2 -> SetPosition(2);

    l_a_2 -> add_note(*r1_a_b_0);
    l_a_2 -> add_note(*r1_a_b_1);
    l_a_2 -> add_note(*r1_a_b_2);
    l_a_2 -> setPattern(I);

    /*******************************************/

    RawNote* r1_a_c_0 = new RawNote(0, 0, 0, bd, 55);
    r1_a_c_0 -> SetPosition(0);
    RawNote* r1_a_c_1 = new RawNote(0, 0, 0, hh1, 55);
    r1_a_c_1 -> SetPosition(0);
    RawNote* r1_a_c_2 = new RawNote(0, 0, 0, bd, 55);
    r1_a_c_2 -> SetPosition(2);
    RawNote* r1_a_c_3 = new RawNote(0, 0, 0, hh1, 55);
    r1_a_c_3 -> SetPosition(2);

    l_a_3 -> add_note(*r1_a_c_0);
    l_a_3 -> add_note(*r1_a_c_1);
    l_a_3 -> add_note(*r1_a_c_2);
    l_a_3 -> add_note(*r1_a_c_3);
    l_a_3 -> setPattern(I);

    RawNote* r1_a_d_0 = new RawNote(0, 0, 0, sn, 55);
    r1_a_d_0 -> SetPosition(0);
    RawNote* r1_a_d_1 = new RawNote(0, 0, 0, hh1, 55);
    r1_a_d_1 -> SetPosition(0);
    RawNote* r1_a_d_2 = new RawNote(0, 0, 0, hh1, 55);
    r1_a_d_2 -> SetPosition(2);

    l_a_4 -> add_note(*r1_a_d_0);
    l_a_4 -> add_note(*r1_a_d_1);
    l_a_4 -> add_note(*r1_a_d_2);
    l_a_4 -> setPattern(I);

    vector<Letter> l;
    vector<Letter> l2;

    l.push_back(*l_a_1);
    l.push_back(*l_a_2);
    l.push_back(*l_a_3);
    l.push_back(*l_a_4);
    l2.push_back(*l_b_1);
    l2.push_back(*l_b_2);
    l2.push_back(*l_b_3);
    l2.push_back(*l_b_4);
    //2.Train
    vomc->train(l);
    vomc->train(l);
    vomc->train(l);
    vomc->train(l2);
    vomc->train(l);
    vomc->train(l);
    vomc->train(l);
    vomc->train(l2);

    vomc->print();
    //3.Fetch output
    State sout = vomc->provide_response_pattern_remove(l);
    cout<<"***********OUTPUT**********"<<endl;
    cout<<"Number of Letters:"<<sout.GetLetters().size()<<endl;
    for (int i = 0; i < sout.GetLetters().size(); i++) {
        cout<<sout.GetLetters().at(i).print_hihat();
    }
    cout<<endl;
    for (int i = 0; i < sout.GetLetters().size(); i++) {
        cout<<sout.GetLetters().at(i).print_instrument(sn);
    }
    cout<<endl;
    for (int i = 0; i < sout.GetLetters().size(); i++) {
        cout<<sout.GetLetters().at(i).print_instrument(bd);
    }
    cout<<endl;
}
/**
 * solver 3 will test the case of different velocity in the notes.
 * The response should be dropping back to the MQ, responding regardless
 * of the velocity.
 * 
 */
void solver_3() {
    /**
     * INPUT:
     * xoxo xoxo xoxo xoxo | xoxo xoxo xoxo xoxo | xoxo xoxo xoxo xoxo
     * oooo xooo oooo xooo | oooo xooo oooo xooo | oooo xxoo oooo xooo
     * xooo oooo xooo oooo | xooo oooo xoox oooo | xxxx oooo xooo oooo 
     */
    VOMC* vomc = new VOMC();
    //1.Create input
    vector<int> vK;
    vK.push_back(0);
    vK.push_back(1);
    vK.push_back(2);
    LetterPattern K(vK, "XXXo");

    vector<int> vM;
    vM.push_back(0);
    vM.push_back(2);
    vM.push_back(3);
    LetterPattern M(vM, "XoXX");

    vector<int> vI;
    vI.push_back(0);
    vI.push_back(2);
    LetterPattern I(vI, "XoXo");

    vector<int> vO;
    vO.push_back(0);
    vO.push_back(1);
    vO.push_back(2);
    vO.push_back(3);
    LetterPattern O(vO,"XXXX");
    
    vector<int> vE;
    vE.push_back(0);
    vE.push_back(1);
    LetterPattern E(vE,"XXoo");
    
    Letter *lA,*lB,*lB_quiet,*lC,*lD,*lE;
    lA = new Letter();
    lB = new Letter();
    lB_quiet = new Letter();
    lC = new Letter();
    lD = new Letter();
    lE = new Letter();
    
    /*******************************************/
    RawNote* bd_A_0 = new RawNote(0, 0, 0, bd, 55);
    bd_A_0 -> SetPosition(0);
    RawNote* hh_A_0 = new RawNote(0, 0, 0, hh1, 55);
    hh_A_0 -> SetPosition(0);
    RawNote* hh_A_2 = new RawNote(0, 0, 0, hh1, 55);
    hh_A_2 -> SetPosition(2);
    lA -> add_note(*bd_A_0);
    lA -> add_note(*hh_A_0);
    lA -> add_note(*hh_A_2);
    lA -> setPattern(I);
    /*******************************************/

    /*******************************************/
    RawNote* sn_B_0 = new RawNote(0, 0, 0, sn, 55);
    sn_B_0 -> SetPosition(0);
    RawNote* hh_B_0 = new RawNote(0, 0, 0, hh1, 55);
    hh_B_0 -> SetPosition(0);
    RawNote* hh_B_2 = new RawNote(0, 0, 0, hh1, 55);
    hh_B_2 -> SetPosition(2);
    lB -> add_note(*sn_B_0);
    lB -> add_note(*hh_B_0);
    lB -> add_note(*hh_B_2);
    lB -> setPattern(I);
    /*******************************************/
    /*******************************************/
    RawNote* sn_B_0_quiet = new RawNote(0, 0, 0, sn, 55);
    sn_B_0_quiet -> SetPosition(0);
    RawNote* hh_B_0_quiet = new RawNote(0, 0, 0, hh1, 55);
    hh_B_0_quiet -> SetPosition(0);
    RawNote* hh_B_2_quiet = new RawNote(0, 0, 0, hh1, 30);
    hh_B_2_quiet -> SetPosition(2);
    lB_quiet -> add_note(*sn_B_0_quiet);
    lB_quiet -> add_note(*hh_B_0_quiet);
    lB_quiet -> add_note(*hh_B_2_quiet);
    lB_quiet -> setPattern(I);
    /*******************************************/
    /*******************************************/
    RawNote* bd_C_0 = new RawNote(0, 0, 0, bd, 55);
    bd_C_0 -> SetPosition(0);
    RawNote* hh_C_0 = new RawNote(0, 0, 0, hh1, 55);
    hh_C_0 -> SetPosition(0);
    RawNote* hh_C_2 = new RawNote(0, 0, 0, hh1, 55);
    hh_C_2 -> SetPosition(2);
    RawNote* bd_C_3 = new RawNote(0, 0, 0, bd, 55);
    bd_C_0 -> SetPosition(3);
    lC -> add_note(*bd_C_0);
    lC -> add_note(*hh_C_0);
    lC -> add_note(*hh_C_2);
    lC -> add_note(*bd_C_3);
    lC -> setPattern(M);
    /*******************************************/
    /*******************************************/
    RawNote* bd_D_0 = new RawNote(0, 0, 0, bd, 55);
    bd_D_0 -> SetPosition(0);
    RawNote* hh_D_0 = new RawNote(0, 0, 0, hh1, 55);
    hh_D_0 -> SetPosition(0);
    RawNote* bd_D_1 = new RawNote(0, 0, 0, bd, 55);
    bd_D_1 -> SetPosition(1);
    RawNote* hh_D_2 = new RawNote(0, 0, 0, hh1, 55);
    hh_D_2 -> SetPosition(2);
    RawNote* bd_D_2 = new RawNote(0, 0, 0, bd, 55);
    bd_D_2 -> SetPosition(2);
    RawNote* bd_D_3 = new RawNote(0, 0, 0, bd, 55);
    bd_D_3 -> SetPosition(3);
    lD -> add_note(*bd_D_0);
    lD -> add_note(*hh_D_0);
    lD -> add_note(*bd_D_1);
    lD -> add_note(*hh_D_2);
    lD -> add_note(*bd_D_2);
    lD -> add_note(*bd_D_3);
    lD -> setPattern(O);
    /*******************************************/
    
    /*******************************************/
    RawNote* sn_E_0 = new RawNote(0, 0, 0, sn, 55);
    sn_E_0 -> SetPosition(0);
    RawNote* hh_E_0 = new RawNote(0, 0, 0, hh1, 55);
    hh_E_0 -> SetPosition(0);
    RawNote* sn_E_1 = new RawNote(0, 0, 0, sn, 55);
    sn_E_1 -> SetPosition(1);
    RawNote* hh_E_2 = new RawNote(0, 0, 0, hh1, 55);
    hh_E_2 -> SetPosition(2);
    lE -> add_note(*sn_E_0);
    lE -> add_note(*hh_E_0);
    lE -> add_note(*sn_E_1);
    lE -> add_note(*hh_E_2);
    lE -> setPattern(E);
    /*******************************************/
    
    vector<Letter> l1,l2,l3,lin;
    l1.push_back(*lA);
    l1.push_back(*lB);
    l1.push_back(*lA);
    l1.push_back(*lB);
    l2.push_back(*lA);
    l2.push_back(*lB);
    l2.push_back(*lC);
    l2.push_back(*lB);
    l3.push_back(*lD);
    l3.push_back(*lE);
    l3.push_back(*lA);
    l3.push_back(*lB);
    lin.push_back(*lC);
    lin.push_back(*lE);
    lin.push_back(*lE);
    lin.push_back(*lB_quiet);
    
    //2.Train
    vomc->train(l1);
    vomc->train(l2);
    vomc->train(l1);
    vomc->train(l3);

    vomc->print();
    //3.Fetch output
    State sout;
    try{
        sout = vomc->provide_response_pattern_remove(lin);
    }catch(int e){
        cout<<"Not solution found"<<endl;
        cout<<"Cia bella ;)"<<endl;
        throw "end of story";        
    }
    cout<<"***********OUTPUT**********"<<endl;
    if (sout.GetId() == -1) {
        cerr << "Markov found no response" << endl;
    }else{
        cout << "State.ID="<<sout.GetId()<<endl;
    }
    cout<<"Number of Letters:"<<sout.GetLetters().size()<<endl;
    
    for (int i = 0; i < sout.GetLetters().size(); i++) {
        cout<<sout.GetLetters().at(i).print_hihat();
    }
    cout<<endl;
    for (int i = 0; i < sout.GetLetters().size(); i++) {
        cout<<sout.GetLetters().at(i).print_instrument(sn);
    }
    cout<<endl;
    for (int i = 0; i < sout.GetLetters().size(); i++) {
        cout<<sout.GetLetters().at(i).print_instrument(bd);
    }
    cout<<endl;
}
/**
 * solver 3 will test the case of different pitch in the notes.
 * The response should be dropping back to the LQ, responding regardless
 * of the pitch.
 * 
 */
void solver_4() {
    /**
     * INPUT:
     * xoxo xoxo xoxo xoxo | xoxo xoxo xoxo xoxo | xoxo xoxo xoxo xoxo
     * oooo xooo oooo xooo | oooo xooo oooo xooo | oooo xxoo oooo xooo
     * xooo oooo xooo oooo | xooo oooo xoox oooo | xxxx oooo xooo oooo 
     */
    VOMC* vomc = new VOMC();
    vomc->init();
    //1.Create input
    vector<int> vK;
    vK.push_back(0);
    vK.push_back(1);
    vK.push_back(2);
    LetterPattern K(vK, "XXXo");

    vector<int> vM;
    vM.push_back(0);
    vM.push_back(2);
    vM.push_back(3);
    LetterPattern M(vM, "XoXX");

    vector<int> vI;
    vI.push_back(0);
    vI.push_back(2);
    LetterPattern I(vI, "XoXo");

    vector<int> vO;
    vO.push_back(0);
    vO.push_back(1);
    vO.push_back(2);
    vO.push_back(3);
    LetterPattern O(vO,"XXXX");
    
    vector<int> vE;
    vE.push_back(0);
    vE.push_back(1);
    LetterPattern E(vE,"XXoo");
    
    Letter *lA,*lB,*lB_LQ,*lC,*lD,*lE;
    lA = new Letter();
    lB = new Letter();
    lB_LQ = new Letter();
    lC = new Letter();
    lD = new Letter();
    lE = new Letter();
    
    /*******************************************/
    RawNote* bd_A_0 = new RawNote(0, 0, 0, bd, 55);
    bd_A_0 -> SetPosition(0);
    RawNote* hh_A_0 = new RawNote(0, 0, 0, hh1, 55);
    hh_A_0 -> SetPosition(0);
    RawNote* hh_A_2 = new RawNote(0, 0, 0, hh1, 55);
    hh_A_2 -> SetPosition(2);
    lA -> add_note(*bd_A_0);
    lA -> add_note(*hh_A_0);
    lA -> add_note(*hh_A_2);
    lA -> setPattern(I);
    /*******************************************/

    /*******************************************/
    RawNote* sn_B_0 = new RawNote(0, 0, 0, sn, 55);
    sn_B_0 -> SetPosition(0);
    RawNote* hh_B_0 = new RawNote(0, 0, 0, hh1, 55);
    hh_B_0 -> SetPosition(0);
    RawNote* hh_B_2 = new RawNote(0, 0, 0, hh1, 55);
    hh_B_2 -> SetPosition(2);
    lB -> add_note(*sn_B_0);
    lB -> add_note(*hh_B_0);
    lB -> add_note(*hh_B_2);
    lB -> setPattern(I);
    /*******************************************/
    /*******************************************/
    RawNote* sn_B_0_LQ = new RawNote(0, 0, 0, sn, 55);
    sn_B_0_LQ -> SetPosition(0);
    RawNote* hh_B_0_LQ = new RawNote(0, 0, 0, hh1, 55);
    hh_B_0_LQ -> SetPosition(0);
    RawNote* hh_B_2_LQ = new RawNote(0, 0, 0, bd, 30);
    hh_B_2_LQ -> SetPosition(2);
    lB_LQ -> add_note(*sn_B_0_LQ);
    lB_LQ -> add_note(*hh_B_0_LQ);
    lB_LQ -> add_note(*hh_B_2_LQ);
    lB_LQ -> setPattern(I);
    /*******************************************/
    /*******************************************/
    RawNote* bd_C_0 = new RawNote(0, 0, 0, bd, 55);
    bd_C_0 -> SetPosition(0);
    RawNote* hh_C_0 = new RawNote(0, 0, 0, hh1, 55);
    hh_C_0 -> SetPosition(0);
    RawNote* hh_C_2 = new RawNote(0, 0, 0, hh1, 55);
    hh_C_2 -> SetPosition(2);
    RawNote* bd_C_3 = new RawNote(0, 0, 0, bd, 55);
    bd_C_0 -> SetPosition(3);
    lC -> add_note(*bd_C_0);
    lC -> add_note(*hh_C_0);
    lC -> add_note(*hh_C_2);
    lC -> add_note(*bd_C_3);
    lC -> setPattern(M);
    /*******************************************/
    /*******************************************/
    RawNote* bd_D_0 = new RawNote(0, 0, 0, bd, 55);
    bd_D_0 -> SetPosition(0);
    RawNote* hh_D_0 = new RawNote(0, 0, 0, hh1, 55);
    hh_D_0 -> SetPosition(0);
    RawNote* bd_D_1 = new RawNote(0, 0, 0, bd, 55);
    bd_D_1 -> SetPosition(1);
    RawNote* hh_D_2 = new RawNote(0, 0, 0, hh1, 55);
    hh_D_2 -> SetPosition(2);
    RawNote* bd_D_2 = new RawNote(0, 0, 0, bd, 55);
    bd_D_2 -> SetPosition(2);
    RawNote* bd_D_3 = new RawNote(0, 0, 0, bd, 55);
    bd_D_3 -> SetPosition(3);
    lD -> add_note(*bd_D_0);
    lD -> add_note(*hh_D_0);
    lD -> add_note(*bd_D_1);
    lD -> add_note(*hh_D_2);
    lD -> add_note(*bd_D_2);
    lD -> add_note(*bd_D_3);
    lD -> setPattern(O);
    /*******************************************/
    
    /*******************************************/
    RawNote* sn_E_0 = new RawNote(0, 0, 0, sn, 55);
    sn_E_0 -> SetPosition(0);
    RawNote* hh_E_0 = new RawNote(0, 0, 0, hh1, 55);
    hh_E_0 -> SetPosition(0);
    RawNote* sn_E_1 = new RawNote(0, 0, 0, sn, 55);
    sn_E_1 -> SetPosition(1);
    RawNote* hh_E_2 = new RawNote(0, 0, 0, hh1, 55);
    hh_E_2 -> SetPosition(2);
    lE -> add_note(*sn_E_0);
    lE -> add_note(*hh_E_0);
    lE -> add_note(*sn_E_1);
    lE -> add_note(*hh_E_2);
    lE -> setPattern(E);
    /*******************************************/
    
    vector<Letter> l1,l2,l3,lin;
    //ABAB
    l1.push_back(*lA);
    l1.push_back(*lB);
    l1.push_back(*lA);
    l1.push_back(*lB);
    //ABCB
    l2.push_back(*lA);
    l2.push_back(*lB);
    l2.push_back(*lC);
    l2.push_back(*lB);
    //DEAB
    l3.push_back(*lD);
    l3.push_back(*lE);
    l3.push_back(*lA);
    l3.push_back(*lB);
    //ABAB
    //checking against patters.IMPORTANT, don't get confused because A and 
    //B in this case would be the same!!
    lin.push_back(*lD);
    lin.push_back(*lD);
    lin.push_back(*lD);
    lin.push_back(*lB_LQ);
    
    //2.Train
    vomc->train(l1);
    vomc->train(l2);
    vomc->train(l1);
    vomc->train(l3);

    vomc->print();
    //3.Fetch output
    State sout;
    try{
        sout = vomc->provide_response_pattern_remove(lin);
        sout = vomc->provide_response_pattern_remove(lin);
    }catch(int e){
        cout<<"Not solution found"<<endl;
        cout<<"Cia bella ;)"<<endl;
        throw "end of story";        
    }
    cout<<"***********OUTPUT**********"<<endl;
    if (sout.GetId() == -1) {
        cerr << "Markov found no response" << endl;
    }else{
        cout << "State.ID="<<sout.GetId()<<endl;
    }
    cout<<"Number of Letters:"<<sout.GetLetters().size()<<endl;
    
    for (int i = 0; i < sout.GetLetters().size(); i++) {
        cout<<sout.GetLetters().at(i).print_hihat();
    }
    cout<<endl;
    for (int i = 0; i < sout.GetLetters().size(); i++) {
        cout<<sout.GetLetters().at(i).print_instrument(sn);
    }
    cout<<endl;
    for (int i = 0; i < sout.GetLetters().size(); i++) {
        cout<<sout.GetLetters().at(i).print_instrument(bd);
    }
    cout<<endl;
}

/* 
 * File:   newsimpletest2.cpp
 * Author: puppy
 *
 * Created on Sep 9, 2012, 12:21:48 PM
 */

#include <stdlib.h>
#include <iostream>
#include "VOMC.h"
/*
 * Simple C++ Test Suite
 */

void load_save() {
    
    VOMC v;
    v.load("output");
    v.save_as("outout2");
}


int main(int argc, char** argv) {
    load_save();
    cout<<"HERE"<<endl;         
    return (EXIT_SUCCESS);
}

