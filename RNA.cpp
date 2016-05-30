//
//  RNA.cpp
//  Programming Project 3
//
//  Created by Andres Quinones on 12/10/14.
//  Copyright (c) 2014 Andres Quinones. All rights reserved.
//

#include "RNA.h"
#include <string.h>
using namespace std;

//for general function descriptions see RNA.h
int RNA::getTablePos(char codon)
{
    if (codon == 'A')
        return 0;
    if (codon == 'C')
        return 1;
    if (codon == 'G')
        return 2;
    if (codon == 'U')
        return 3;
    return -1;
}

char RNA::getAcidFromTablePos(int fPos, int sPos, int tPos)
{
    char aAcid, codonToAcid[4][4][4];
    
    codonToAcid[0][0][0] = 'K';     //all the amino acids a codon can encode to. A=0 C=1 G=2 U=3
    codonToAcid[0][0][1] = 'N';
    codonToAcid[0][0][2] = 'K';
    codonToAcid[0][0][3] = 'N';
    
    codonToAcid[0][1][0] = 'T';
    codonToAcid[0][1][1] = 'T';
    codonToAcid[0][1][2] = 'T';
    codonToAcid[0][1][3] = 'T';
    
    codonToAcid[0][2][0] = 'R';
    codonToAcid[0][2][1] = 'S';
    codonToAcid[0][2][2] = 'R';
    codonToAcid[0][2][3] = 'S';
    
    codonToAcid[0][3][0] = 'I';
    codonToAcid[0][3][1] = 'I';
    codonToAcid[0][3][2] = 'M';
    codonToAcid[0][3][3] = 'I';
    
    codonToAcid[1][0][0] = 'Q';
    codonToAcid[1][0][1] = 'H';
    codonToAcid[1][0][2] = 'Q';
    codonToAcid[1][0][3] = 'H';
    
    codonToAcid[1][1][0] = 'P';
    codonToAcid[1][1][1] = 'P';
    codonToAcid[1][1][2] = 'P';
    codonToAcid[1][1][3] = 'P';
    
    codonToAcid[1][2][0] = 'R';
    codonToAcid[1][2][1] = 'R';
    codonToAcid[1][2][2] = 'R';
    codonToAcid[1][2][3] = 'R';
    
    codonToAcid[1][3][0] = 'L';
    codonToAcid[1][3][1] = 'L';
    codonToAcid[1][3][2] = 'L';
    codonToAcid[1][3][3] = 'L';
    
    codonToAcid[2][0][0] = 'E';
    codonToAcid[2][0][1] = 'D';
    codonToAcid[2][0][2] = 'E';
    codonToAcid[2][0][3] = 'D';
    
    codonToAcid[2][1][0] = 'A';
    codonToAcid[2][1][1] = 'A';
    codonToAcid[2][1][2] = 'A';
    codonToAcid[2][1][3] = 'A';
    
    codonToAcid[2][2][0] = 'G';
    codonToAcid[2][2][1] = 'G';
    codonToAcid[2][2][2] = 'G';
    codonToAcid[2][2][3] = 'G';
    
    codonToAcid[2][3][0] = 'V';
    codonToAcid[2][3][1] = 'V';
    codonToAcid[2][3][2] = 'V';
    codonToAcid[2][3][3] = 'V';
    
    codonToAcid[3][0][0] = 'x';     //NOTE: STOP CODON IS REPRESENTED BY THE CHARACTER x HERE
    codonToAcid[3][0][1] = 'Y';
    codonToAcid[3][0][2] = 'x';     //AND HERE
    codonToAcid[3][0][3] = 'Y';
    
    codonToAcid[3][1][0] = 'S';
    codonToAcid[3][1][1] = 'S';
    codonToAcid[3][1][2] = 'S';
    codonToAcid[3][1][3] = 'S';
    
    codonToAcid[3][2][0] = 'x';     //AND HERE
    codonToAcid[3][2][1] = 'C';
    codonToAcid[3][2][2] = 'W';
    codonToAcid[3][2][3] = 'C';
    
    codonToAcid[3][3][0] = 'L';
    codonToAcid[3][3][1] = 'F';
    codonToAcid[3][3][2] = 'L';
    codonToAcid[3][3][3] = 'F';
    
    aAcid = codonToAcid[fPos][sPos][tPos];  // check from all the values what amino acid the three codons encode to
    return aAcid;   //return that amino acid
}

RNA::RNA()
{}

RNA::RNA(string s){
    codons=s;
}
bool RNA::isValid(){

    char fAAcid = getAcidFromTablePos(getTablePos(codons[0]), getTablePos(codons[1]), getTablePos(codons[2]));
    //gets the first amino acid the first three codons of the string encodes to
    char lAAcid = getAcidFromTablePos(getTablePos(codons[codons.size()-3]), getTablePos(codons[codons.size()-2]), getTablePos(codons[codons.size()-1]));
    //gets the last amino acid that the last three codons of the string encodes to

    for(int i=0;i<codons.size();i++)
        if(!(codons[i]=='A' || codons[i]=='U' || codons[i]=='C' || codons[i]=='G'))
            //checks if all the charcters in codons belong to the set {A,U,C,G}
            return 0;
    if( (codons.size()%3)!= 0)
        //makes sure that codons is divisable by 3 because each triple codes to 1 amino acid
        return 0;
    if (fAAcid!='M' || lAAcid !='x')
        //makes sure that the first amino acid is 'M', start codon, and the last amino acid is 'x', stop codon.
        return 0;
    return 1;
}

string RNA::getCodons(){
    return codons;
}

void RNA::setCodons(string c){
    codons=c;
}

string RNA::convertToAminoAcids()
{
    bool okay=0;
    int fCodPos,sCodPos,tCodPos;
    char aAcid;

    string aAcids;
    
    for(int i=0;i<codons.size();i+=3)
        //note increment by 3 because we're going to be dealing with every three codons every iteration
    {
        fCodPos = getTablePos(codons[i]);
        //convert first codon to a position in getAminoAcidfromTable
        sCodPos = getTablePos(codons[i+1]);
        //convert second codon to a position in getAminoAcidfromTable
        tCodPos = getTablePos(codons[i+2]);
        //convert third codon to a position in getAminoAcidfromTable
        aAcid=getAcidFromTablePos(fCodPos, sCodPos, tCodPos);
        //get the amino acid those three codons encode for
        if (aAcid == 'M')
            //if amino acid is the start codon
        {
            okay=1;
            //set flag to 1 to signify its okay to add acids to the amino acid string
            aAcids+= aAcid;
            //adds the 'M' that the start codon ecodes for
            continue; //next iteration
        }
        if(i+3==codons.size())
            //if were dealing with the last amino acid then we want to break because we dont want to add anymore -'s or go outside the string
            break;
        if (okay)
            //if okay then we're going to need a - between the amino acid abbreviations  (This check and the following never happen in the same iteration.
            aAcids+= '-';
        if(aAcid== 'x')
            //if stop codon then set flag to 0 to signify to stop adding AmAcids to the string
            okay=0;
        if (okay)
            //if okay add the amino acid we are dealing with to the string
            aAcids+= aAcid;
    }
    return aAcids;
    //returns the amino acid string that codons encodes for
}
