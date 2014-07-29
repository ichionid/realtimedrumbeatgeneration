/* 
 * File:   Letter.cpp
 * Author: puppy
 * 
 * Created on June 15, 2012, 2:19 PM
 */

#include "Letter.h"
/**
 * 
 * @param r1 is a <code>RawNote*</code>.
 * @return TRUE if the <code>RawNote*</code> already exists in the 
 *         <code>Letter</code>'s vector with the same pitch and position
 */
bool Letter::has_note_no_velocity(RawNote* r1) {
    for (int i = 0; i < rawNotes.size(); i++) {
        if (
                (rawNotes.at(i).GetPitch() == r1->GetPitch())
                &&
                (rawNotes.at(i).GetPosition() == r1->GetPosition())
                ) {
            return true;
        }
    }
    return false;
}
/**
 * 
 * @param r1 is a <code>RawNote*</code>.
 * @return TRUE if the <code>RawNote*</code> already exists in the 
 *         <code>Letter</code>'s vector with the same pitch, position 
 *         and velocity.
 */
bool Letter::has_note_with_velocity(RawNote* r1) {
    for (int i = 0; i < rawNotes.size(); i++) {
        if (
                (rawNotes.at(i).GetPitch() == r1->GetPitch())
                &&
                (rawNotes.at(i).GetPosition() == r1->GetPosition())
                &&
                (rawNotes.at(i).GetVelocity() == r1->GetVelocity())
                ) {
            return true;
        }
    }
    return false;
}
/**
 * 
 * @param helper is a <code>Helper *</code> whose possible notes will be 
 *       transferred to the current object instance;
 */
Letter::Letter(Helper *helper) {

    this->allPossibleNotes = helper->get_all_possible_notes();

}

Letter::Letter() {
    this->allPossibleNotes = new vector<LetterPattern > ();
    vector<int> vA;
    vA.push_back(0);
    LetterPattern A(vA, "Xooo");

     
    vector<int> vB;
    vB.push_back(1);
    LetterPattern B(vB, "oXoo");
    vector<int> vC;
    vC.push_back(2);
    LetterPattern C(vC, "ooXo");

    vector<int> vD;
    vD.push_back(3);
    LetterPattern D(vD, "oooX");

    vector<int> vE;
    vE.push_back(0);
    vE.push_back(1);
    LetterPattern E(vE, "XXoo");

    vector<int> vF;
    vF.push_back(1);
    vF.push_back(2);
    LetterPattern F(vF, "oXXo");

    vector<int> vG;
    vG.push_back(2);
    vG.push_back(3);
    LetterPattern G(vG, "ooXX");

    vector<int> vH;
    vH.push_back(0);
    vH.push_back(3);
    LetterPattern H(vH, "XooX");
    vector<int> vI;
    vI.push_back(0);
    vI.push_back(2);
    LetterPattern I(vI, "XoXo");
    vector<int> vJ;
    vJ.push_back(1);
    vJ.push_back(3);
    LetterPattern J(vJ, "oXoX");

    vector<int> vK;
    vK.push_back(0);
    vK.push_back(1);
    vK.push_back(2);
    LetterPattern K(vK, "XXXo");

    vector<int> vL;
    vL.push_back(1);
    vL.push_back(2);
    vL.push_back(3);
    LetterPattern L(vL, "oXXX");

    vector<int> vM;
    vM.push_back(0);
    vM.push_back(2);
    vM.push_back(3);
    LetterPattern M(vM, "XoXX");

    vector<int> vN;
    vN.push_back(0);
    vN.push_back(1);
    vN.push_back(3);
    LetterPattern N(vN, "XXoX");

    vector<int> vO;
    vO.push_back(0);
    vO.push_back(1);
    vO.push_back(2);
    vO.push_back(3);
    LetterPattern O(vO, "XXXX");
    vector<int> vR;
    vR.push_back(4);
    LetterPattern R(vR, "oXo");

    vector<int> vS;
    vS.push_back(5);
    LetterPattern S(vS, "ooX");

    vector<int> vT;
    vT.push_back(0);
    vT.push_back(4);
    LetterPattern T(vT, "XXo");

    vector<int> vU;
    vU.push_back(4);
    vU.push_back(5);
    LetterPattern U(vU, "oXX");

    vector<int> vV;
    vV.push_back(0);
    vV.push_back(5);
    LetterPattern V(vV, "XoX");

    vector<int> vW;
    vW.push_back(0);
    vW.push_back(4);
    vW.push_back(5);
    LetterPattern W(vW, "XXX");

    vector<int> vRest;
    LetterPattern Rest(vRest, "oooo");

    allPossibleNotes->push_back(A);
    allPossibleNotes->push_back(B);
    allPossibleNotes->push_back(C);
    allPossibleNotes->push_back(D);
    allPossibleNotes->push_back(E);
    allPossibleNotes->push_back(F);
    allPossibleNotes->push_back(G);
    allPossibleNotes->push_back(H);
    allPossibleNotes->push_back(I);
    
    allPossibleNotes->push_back(J);
    allPossibleNotes->push_back(K);
    allPossibleNotes->push_back(L);
    allPossibleNotes->push_back(M);
    allPossibleNotes->push_back(N);
    allPossibleNotes->push_back(O);
    
    allPossibleNotes->push_back(R);
    allPossibleNotes->push_back(S);
    allPossibleNotes->push_back(T);
    allPossibleNotes->push_back(U);
    allPossibleNotes->push_back(V);
    allPossibleNotes->push_back(W);
    allPossibleNotes->push_back(Rest);
}
/**
 * 
 * @return A <code>vector<RawNote></code> holding all the 
 *      <code>letter</code>'s notes.
 */
vector<RawNote> Letter::getRawNotes() const {
    return rawNotes;
}
/**
 * 
 * @param rawNotes is a <code>vector<RawNote></code>
 *      that will be copied to <code>letter</code>'s <code>vector<RawNote></code>.
 **/
void Letter::setRawNotes(vector<RawNote> rawNotes) {
    this->rawNotes = rawNotes;
}
/**
 * 
 * @param r is a <code>RawNote</code> that will be added to the <code>vector<RawNote></code>
 *      of the Letter.
 */
void Letter::add_note(RawNote r) {
    rawNotes.push_back(r);
}

/**
 * Calculate Weights
 * Find out a letter whose weights match the specific notes.
 * We do not take into consideration, letters that have unused notes.
 * A note of a letter patten(A B ....W) is labeled "USED", if there is a weight
 * of one of the notes of the letter(rawnotes) that we are evaluating that
 * that has its minimum weight for that position.
 * 
 * @param eigthNoteDuration is a <code>double</code> that holds the duration of
 * an eighth note. This function will assign and evaluate the 
 * <code>letter</code>'s rhythmic pattern.        
 */
void Letter::evaluate_letter(double eigthNoteDuration) {
    //cout << "#####################" << endl;
    //cout<<"evaluate_letter::"<<this->getPattern().GetName() <<endl;
    if (rawNotes.size() > 0) {
        //calculate distance from all 6 possible positions
        for (int i = 0; i < rawNotes.size(); i++) {
            ////cout<<"Letter::rawNotes.at(i).GetEighthNoteTimeStamp():"<<rawNotes.at(i).GetEighthNoteTimeStamp()<<endl;
            rawNotes.at(i).SetWeight(0, fabs((double) (rawNotes.at(i).GetEighthNoteTimeStamp()) / eigthNoteDuration));
            rawNotes.at(i).SetWeight(1, fabs((double) (rawNotes.at(i).GetEighthNoteTimeStamp()-(1. / 4.) * eigthNoteDuration) / eigthNoteDuration));
            rawNotes.at(i).SetWeight(2, fabs((double) (rawNotes.at(i).GetEighthNoteTimeStamp()-(2. / 4.) * eigthNoteDuration) / eigthNoteDuration));
            rawNotes.at(i).SetWeight(3, fabs((double) (rawNotes.at(i).GetEighthNoteTimeStamp()-(3. / 4.) * eigthNoteDuration) / eigthNoteDuration));
            rawNotes.at(i).SetWeight(4, fabs((double) (rawNotes.at(i).GetEighthNoteTimeStamp()-(1. / 3.) * eigthNoteDuration) / eigthNoteDuration));
            rawNotes.at(i).SetWeight(5, fabs((double) (rawNotes.at(i).GetEighthNoteTimeStamp()-(2. / 3.) * eigthNoteDuration) / eigthNoteDuration));
            //DEBUG
            //cout<<"rawNotes.at(i).GetEighthNoteTimeStamp():"<<rawNotes.at(i).GetEighthNoteTimeStamp()<<endl;
            //cout<<"eigthNoteDuration:"<<eigthNoteDuration<<endl;
            /*for (int j = 0; j < 6; j++) {
                cout<<"Weight["<<j<<"]="<<rawNotes.at(i).GetWeight(j)<<endl;
            }*/
        }
        double minWeight = 10000;
        //calculate most probable combination
        double tempWeight;
        int letterIndex = -1;
        for (int i = 0; i < rawNotes.size(); i++) {
            //cout<<rawNotes.at(i).GetEighthNoteTimeStamp()<<endl;   
        }

        for (int l = 0; l < allPossibleNotes->size() - 1; l++) {

            if (allPossibleNotes->at(l).GetName() != "oooo") {
                tempWeight = 0;
                for (int i = 0; i < rawNotes.size(); i++) {
                    //add the weight of the note that exists in allPossible
                    //and is closest to our note
                    //Also mark the note of the Letter that has been used. 
                    //This is done in order to differentiate among letter matchings
                    tempWeight += rawNotes.at(i).retSmallestExistingWeight(&allPossibleNotes->at(l));

                }
                if ((tempWeight < minWeight) && allPossibleNotes->at(l).allNotesUsed()) {
                    minWeight = tempWeight;
                    letterIndex = l;
                }
            } else {
                //cout << "last one" << endl;
            }
        }

        if (letterIndex == -1) {
            //cout << "Letter.cpp:in" << endl;
            throw 10;
        }
        //set the pattern
        this->pattern = allPossibleNotes->at(letterIndex);
    } else {
        this->pattern = allPossibleNotes->at(allPossibleNotes->size() - 1);
    }

}
void Letter::setNotePositionAccordingToLetter() {

    for (int i = 0; i < rawNotes.size(); i++) {
        rawNotes.at(i).setPositionOfSmallestExistingWeight(&this->pattern);
    }
}

LetterPattern Letter::getPattern() const {
    return pattern;
}
/**
 * 
 * @param pattern is a <code>LetterPattern</code> whose pattern will be copied
 *      to the internal object of the <code>Letter</code>
 */
void Letter::setPattern(LetterPattern pattern) {
    this->pattern = pattern;
}

void Letter::empty_notes() {
    rawNotes.clear();
}
/**
 * 
 * @return TRUE if <code>Letter</code> has no <code>RawNotes</code>, 
 *      FALSE otherwise.
 */
bool Letter::isEmpty() {
    return rawNotes.empty();
}

Letter::~Letter() {

}

/**
 * 
 * @param instrument is an <code>int</code> representing the midi instrument.
 * @return A <code>string</code>, representing the returned pattern.
 */
string Letter::print_instrument(int instrument) {

    string instrument_pattern = "";
    bool existed = false;
    if (this->pattern.GetName().size() == 4) {
        //triplet
        for (int i = 0; i < 4; i++) {
            existed = false;
            for (int j = 0; j < this->rawNotes.size(); j++) {
                //           //cout<<"note="<<j<<endl;
                if ((this->rawNotes.at(j).GetPosition() == i) && (this->rawNotes.at(j).GetPitch() == instrument)) {
                    instrument_pattern += "X";
                    existed = true;
                    break;
                }
            }
            if (!existed) {
                instrument_pattern += ".";
            }
        }
        instrument_pattern += " ";
    } else {
        //triplet
        //first note 
        for (int j = 0; j < this->rawNotes.size(); j++) {
            if ((this->rawNotes.at(j).GetPosition() == 0) && (this->rawNotes.at(j).GetPitch() == instrument)) {
                instrument_pattern += "X";
                existed = true;
                break;
            }
        }
        if (!existed)instrument_pattern += ".";
        //2nd note 
        existed = false;
        for (int j = 0; j < this->rawNotes.size(); j++) {
            if ((this->rawNotes.at(j).GetPosition() == 4) && (this->rawNotes.at(j).GetPitch() == instrument)) {
                instrument_pattern += "X";
                existed = true;
                break;
            }
        }
        if (!existed)instrument_pattern += ".";
        existed = false;
        //3rd note 
        for (int j = 0; j < this->rawNotes.size(); j++) {
            if ((this->rawNotes.at(j).GetPosition() == 5) && (this->rawNotes.at(j).GetPitch() == instrument)) {
                instrument_pattern += "X";
                existed = true;
                break;
            }
        }
        if (!existed)instrument_pattern += ".";

        instrument_pattern += "  ";

    }
    return instrument_pattern;
}

/**
 * 
 * @return A <code>string</code>. Hihat printing is different from printing
 * other instruments due to the fact that it can have 2 different timbre for 2 
 * different hihat sounds
 * 
 */
string Letter::print_hihat() {

    string instrument_pattern = "";
    bool existed = false;
    if (this->pattern.GetName().size() == 4) {
        //triplet
        for (int i = 0; i < 4; i++) {
            existed = false;
            //   //cout<<"i="<<i<<endl;
            for (int j = 0; j < this->rawNotes.size(); j++) {
                //           //cout<<"note="<<j<<endl;
                if ((this->rawNotes.at(j).GetPosition() == i) && ((this->rawNotes.at(j).GetPitch() == hh1) || (this->rawNotes.at(j).GetPitch() == hh2))) {
                    instrument_pattern += "X";
                    existed = true;
                    break;
                }
            }
            if (!existed) {
                instrument_pattern += ".";
            }
        }
        instrument_pattern += " ";
    } else {
        //triplet
        //first note 
        for (int j = 0; j < this->rawNotes.size(); j++) {
            if ((this->rawNotes.at(j).GetPosition() == 0) && ((this->rawNotes.at(j).GetPitch() == hh1) || (this->rawNotes.at(j).GetPitch() == hh2))) {
                instrument_pattern += "X";
                existed = true;
                break;
            }
        }
        if (!existed)instrument_pattern += ".";
        //2nd note 
        existed = false;
        for (int j = 0; j < this->rawNotes.size(); j++) {
            if ((this->rawNotes.at(j).GetPosition() == 4) && ((this->rawNotes.at(j).GetPitch() == hh1) || (this->rawNotes.at(j).GetPitch() == hh2))) {
                instrument_pattern += "X";
                existed = true;
                break;
            }
        }
        if (!existed)instrument_pattern += ".";
        existed = false;
        //3rd note 
        for (int j = 0; j < this->rawNotes.size(); j++) {
            if ((this->rawNotes.at(j).GetPosition() == 5) && ((this->rawNotes.at(j).GetPitch() == hh1) || (this->rawNotes.at(j).GetPitch() == hh2))) {
                instrument_pattern += "X";
                existed = true;
                break;
            }
        }
        if (!existed)instrument_pattern += ".";

        instrument_pattern += "  ";

    }
    return instrument_pattern;
}

void Letter::print_notes() {

    //cout << "Number of notes:" << this->rawNotes.size() << endl;

    for (int i = 0; i < rawNotes.size(); i++) {
        RawNote rawNote = rawNotes.at(i);
        //cout << "Note:" << rawNotes.at(i).GetEighthNoteTimeStamp() << endl;
        //cout << "Position:" << rawNotes.at(i).GetPosition() << endl;
        //cout << "Pitch:" << rawNotes.at(i).GetPitch() << endl;

        /*for (int j = 0; j < 6; j++) {
            cout << "Weight[" << j << "]=" << rawNotes.at(i).GetWeight(j) << endl;
        }
        cout << "Timbre:" << rawNote.GetPitch() << endl;
        cout << "Velocity:" << rawNote.GetVelocity() << endl;
        cout << "TimeCutDown:" << rawNote.GetLimitedTimeStamp() << endl;
        cout << "TimeGeneral:" << rawNote.GetGeneralTimeStamp() << endl;*/
    }
} 