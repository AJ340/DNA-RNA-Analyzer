//
//  RNA.h
//  Programming Project 3
//
//  Created by Andres Quinones on 12/10/14.
//  Copyright (c) 2014 Andres Quinones. All rights reserved.
//

#ifndef __Programming_Project_3__RNA__
#define __Programming_Project_3__RNA__

#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

//for general function descriptions see DNA.h

class RNA
{
private:
    string codons;
        int getTablePos(char codon);
    // converts codon to a number to used by getAcidFromCodon. A=0, C=1, G=3, U=3
    
    char getAcidFromTablePos(int fPos, int sPos, int tPos);
    // converting Codon to three integers (using getTablePos, those integers are passed and are looked up in the 3D array convertToAminoAcid[][][] to see what amino acid that triple encodes to. Abbreviated name for AminoAcid is returned

public:
    RNA();
    //default constructor
    
    RNA(string s);
    // constructor that sets codons to s
    
    bool isValid();
    //checks if codons is a valid string and returns 1 if it is and 0 if it isnt
    
    string getCodons();
    //getter for codons
    
    void setCodons(string c);
    //setter for codons
    
    string convertToAminoAcids();
    //coverts entire string codons to an amino acid chain by using getTablePos and getAcidFromTablePos
};

#endif /* defined(__Programming_Project_3__RNA__) */
