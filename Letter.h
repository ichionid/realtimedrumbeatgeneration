/* 
 * File:   Letter.h
 * Author: puppy
 *
 * Created on June 15, 2012, 2:19 PM
 */

#ifndef LETTER_H
#define	LETTER_H
#include <iostream>
#include <vector>
#include "RawNote.h"
#include "Helper.h"

//drum machine testing with HYDROGEN
//#define rd 77
#define cr 36
#define hh1 37
#define hh2 37
#define t1 38
#define sn 39
#define lt 40
#define bd 41
//Guitar pro
/*
#define cr 55
#define hh1 51
#define hh2 51
#define t1 47
#define sn 38
#define lt 101
#define bd 35
*/
//real-time
/*
#define sn 38
#define t1 48
#define hh1 26
#define hh2 46
#define bd 36
#define lt 45
*/
//DD-55
/*
#define cr 49
#define sn 34
#define t1 48
#define hh1 45
#define hh2 45
#define bd 42
#define lt 41
*/using namespace std;

class Letter {

public:
    Letter();
    Letter(Helper *helper);
    ~Letter();
    
    void add_note(RawNote r);
    void evaluate_letter(double eigthNoteDuration);
    //setNotePositionAccordingToLetter should only be executed
    //after evaluate_letter is executed, utilizes LetterPattern pattern
    void setNotePositionAccordingToLetter();
    void empty_notes();
    LetterPattern getPattern() const;
    void setPattern(LetterPattern pattern);
    bool isEmpty();
    vector<RawNote> getRawNotes() const;
    void setRawNotes(vector<RawNote> rawNotes);
    
    bool has_note_no_velocity(RawNote* r1);
    bool has_note_with_velocity(RawNote* r1);
    
    /*Debug or Display functions*/
    string print_instrument(int intrument);
    string print_hihat();
    void print_notes();
    
private:
    /**
     * @param allPossibleNotes, is a <code>vector<LetterPattern></code> that 
     *  holds the value of all possible pattern combinations(24).
     * @param rawNotes, is a <code>vector<RawNote></code>
     */
    vector<LetterPattern> *allPossibleNotes;
    vector<RawNote> rawNotes;
    LetterPattern pattern;
    
};

#endif	/* LETTER_H */