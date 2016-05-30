//
//  DNA.cpp
//  Programming Project 3
//
//  Created by Andres Quinones on 12/10/14.
//  Copyright (c) 2014 Andres Quinones. All rights reserved.
//

#include "DNA.h"
#include <string.h>
#include <vector>

//for general function descriptions see DNA.h

char getComplim(char codon)
{
    if(codon == 'A')    //gets compliment of codon
        return 'T';
    if(codon == 'T')
        return 'A';
    if(codon == 'C')
        return 'G';
    if(codon == 'G')
        return 'C';
    return -1;
}

DNA::DNA()
{}

DNA::DNA(string s){
    codons=s;
}
bool DNA::isValid(){
    for(int i=0;i<codons.size();i++)
        if(!(codons[i]=='A' || codons[i]=='T' || codons[i]=='C' || codons[i]=='G'))
            //checks if dna codons belong to the set {A,T,C,G}
            return 0;
    return 1;
}

string DNA::getCodons(){
    return codons;
}

void DNA::setCodons(string c){
    codons=c;
}

string DNA::otherStrand()
{
    string compliment;
    for (long i=codons.size()-1;i>=0;i--)
        compliment += getComplim(codons[i]);
    //starting from the end of the codon get the compliment of the codon and append it to compliment.
    return compliment;
}

vector<int> DNA::searchForPolyT(int minTs)
// we are searching for when a polyT starts and where it ends
{
    vector<int> positions;
    bool startFound=0, endFound=0;
    int startPos, endPos, count=0;
    for(int i=0;i<codons.size();i++)
    {
        if (codons[i] == 'T' && !startFound)
            //if codon is T and a start of a ply T was not found already
        {
            startFound=1;
            //flag for start found set to true
            startPos=i;
            //store position of the start in startPos
        }
        if (codons[i]=='T' && codons[i+1]!= 'T' && startFound)
            //check if iteration is 'T' and the following codon is not a T. this is the end of a poly T.
        {
            endFound=1;
            endPos=i;
        }
        if(startFound && codons[i]=='T')
            //if a start was found then its okay to count the Ts
            count++;
        if (startFound && endFound)
            //after a start and an end was found
        {
            if (count>=minTs)
                //check if count is at least passed integer. if it passes check
            {
                positions.push_back(startPos);
                //add startPos to vector
                positions.push_back(endPos);
                //then add the coresponding endPos to the position after it
            }
            count =0;
            //reset all the flags to prepare to check for another poly T
            startFound=0;
            endFound=0;
        }
    }
    return positions;
}

int DNA::getGcContent()
{
    int count=0;
    for(int i=0;i<codons.size();i++)
    {
        if ( codons[i] == 'G' || codons[i] == 'C')
            //check if codon is a G or a C and count it
            count ++;
    }
    return count;
}

vector<int> DNA::getCpGIslands()
{
    vector<int> positions;
    for(int i=0;i<codons.size();i++)
    {
        if (codons[i] == 'C' && codons[i+1] == 'G')
            //check where codon is C and the following codon is a G
        {
            positions.push_back(i);
            //store that position in vector to return
            i++;
            //increment i because we dont need to check the following position because we know that it is G
        }
    }
    return positions;
}

