# DNA-RNA-Analyzer
CSCI 135

simple program to analyze a dna or rna string in a text file
for more information see hw3.pdf and biobackground.pdf
PDFs property of Hunter College


to compile 
g++ *.cpp -o analyze

format of command:
	(name of program) (type of file) (input file) (output file)
			    dna or rna
	
To analyze DNA string, type the following into terminal:

	./analyze dna MyDnaFile.txt output.txt

Program checks MyDnaFile.txt for string to analyze and outputs data to output.txt.


To analyze RNA string, type the following into terminal:

	./analyze rna MyRnaFile.txt rnaoutput.txt

Program checks MyRnaFile.txt for string to analyze and outputs data to rnaoutput.txt.
