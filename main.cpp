//
//  main.cpp
//  Programming Project 3
//
//  Created by Andres Quinones on 12/6/14.
//  Copyright (c) 2014 Andres Quinones. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include "DNA.h"
#include "RNA.h"

using namespace std;

int main(int argc, const char * argv[])
{
    if(argc !=4)
        //if more than 4 arguments were passed give an error and exit
    {
        cerr << "Please provide exactly 4 arguments!" << endl;
        return 0;
    }
    string firstArg = argv[1], infile = argv[2], outfile = argv[3], codons;
    //otherwise store arguments in variables and continue to program
    vector<int> positions;
    
    ifstream input;
    input.open(infile);
    if(!input)
        //in both cases, dna and rna, they contain one string file. so its safe to do this before we check the second string.
    {
        cout << "Error reading file" << endl;
        exit(1);
    }
    input >> codons;
    //get the string from the input file
    input.close();
    
    if (firstArg == "dna")
    {
        DNA dnaString(codons);
        ofstream output;
        output.open(outfile);
        if ( dnaString.isValid())
            //if the dna string is valid then it is safe to analyze and output data to the output file
        {
            //this is the format the data is printed in the outputfile \/
            output << "The compliment to the DNA string found in the file is:" << endl
            << dnaString.otherStrand() << endl << endl;
            //prints the other strand
            
            vector <int> positions = dnaString.searchForPolyT(4);
            for (int i=0; i<positions.size();i+=2)
                output << "Poly-T with size of at least 4 starts at " << positions[i] << " and ends at " << positions[i+1] << endl;
            output << endl;
            //above for loop prints all of the positions where there is a polyT of at least 4
            
            output << "The GC content of the DNA string is: " << dnaString.getGcContent() << endl << endl
                        //the above prints GC content data
            
                    << "CpG islands at positions ";
            positions = dnaString.getCpGIslands();
            //uses the positions vector we already have just to not make another vector variable
            for (int i=0; i<positions.size();i++)
                output << positions[i] << " ";
            //output all of the positions that getCpGIslands gave us
            output << endl;
        }
        else
            cout << "Error: File contains an invalid DNA string.";
            //if the DNA string isnt valid then output an error
        output.close();
        //close file if valid or not
        return 0;
    }
    
    if (firstArg == "rna")
    {
        RNA rnaString(codons);
        ofstream output;
        output.open(outfile);
        if (rnaString.isValid())
            //if the rna string is valid then encode it to amino acids
        {
            output << "RNA encodes to the output sequence of amino acids: " << endl
            << rnaString.convertToAminoAcids() << endl;
        }
        else
            cout << "Error: File contains an invalid RNA string.";
            //if not valid cout error
        output.close();
        //close the output file in both cases
        return 0;
    }
    
    cout << "That is not a valid first argument. Please enter dna or rna for the first argument." << endl;
    return 1;
}