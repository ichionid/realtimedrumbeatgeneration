/* 
 * File:   LetterPattern.h
 * Author: puppy
 *
 * Created on June 17, 2012, 4:05 PM
 */

#ifndef LETTERPATTERN_H
#define	LETTERPATTERN_H
#include <string>
#include <vector>
#include <iostream>
#include <math.h>
/*
 * MAX_LETTERS is the maximum amount of letters per phrase. Set to 4
 */
#define MAX_LETTERS 4
using namespace  std;

class LetterPattern {
public:
    LetterPattern();
    LetterPattern(vector<int> pattern, string representation);
    string GetName() const;
    void SetName(string name);
    vector<int> GetPattern() const;
    void SetPattern(vector<int> pattern);
    void setLettersUsed(int i);
    bool getLettersUsed(int i);
    bool allNotesUsed();
    ~LetterPattern();
private:
    //letters used holds a T/F array that
    //corresponds to the usage or not of a note of a specific letter patter
    //f.x. E
    bool* lettersUsed;
    string name;
    vector<int> pattern;
};

#endif	/* LETTERPATTERN_H */

