//
//  DNA.h
//  Programming Project 3
//
//  Created by Andres Quinones on 12/10/14.
//  Copyright (c) 2014 Andres Quinones. All rights reserved.
//

#ifndef __Programming_Project_3__DNA__
#define __Programming_Project_3__DNA__

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
class DNA
{
private:
    string codons;
public:
    DNA();
    //default constructor
    
    DNA(string s);
    //constructor sets codons to s
    
    bool isValid();
    //chcks if codons is valid. returns 1 if it is and 0 if it isnt
    
    string getCodons();
    // getter for codons
    
    void setCodons(string c);
    //setter for codons
    
    string otherStrand();
    //gets the compliment to codons and flips it so it reads from 5' to 3'
    
    vector<int> searchForPolyT(int minTs);
    //searches for locations in codons where there there are at least a minTs number of consecutive Ts. returns a vector of integers where n=(0 || even) returnedVector[n] contains a start position and returnedVector[n+1] contains the corresponding end position.
    
    int getGcContent();
    //counts the number of Gs and Cs in codons
    
    vector<int> getCpGIslands();
    //searches for positions where there is a C followed by a G in codons and returns all of them in a vector.
    
};

#endif /* defined(__Programming_Project_3__DNA__) */
