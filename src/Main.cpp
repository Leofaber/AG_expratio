/*
 * Copyright (c) 2017
 *     Leonardo Baroncelli, Giancarlo Zollino,
 *
 * Any information contained in this software
 * is property of the AGILE TEAM and is strictly
 * private and confidential.
 *
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip> 
#include "ExpRatioEvaluator.h"
#include <cstring>

const char* startString = {
"################################################################\n"
"###                   Task AG_expratio v1.0.1 -              ###"
};

const char* endString = {
"### Task AG_expratio exiting ............................... ###\n"
"################################################################"
};


int main(int argc, char *argv[])
{ 	

	cout << startString << endl;
	
	if(argc < 6 || argc >8)
	{
		printf("\nAt least 5 arguments expected (+ 2 optional)\n   - The .exp file path\n   - The name of the output file\n   - Normalize boolean: true if exp should be normalized, false otherwise\n   - The l coordinate\n    -The b coordinate\n\n(Optional)\n   - The minThreshold (default value = 0)\n   - The maxThreshold (default value = 100)\n");
		cout << endString << endl;		
		exit (EXIT_FAILURE);
	}

	else
	{	
        const char * imagePath = argv[1];
        const char * outfile = argv[2];
        const char *normalize = argv[3];
		double l = atof(argv[4]);
		double b = atof(argv[5]);
		double minThreshold = 0;
		double maxThreshold = 100;
		if(argc == 8){
			minThreshold = (double) atof(argv[6]);
		    maxThreshold = (double) atof(argv[7]);
		}
		
		bool doNormalization;
		if( strcmp(normalize, "true") == 0 )
			doNormalization = true;
		else
			doNormalization = false;
		
		
		//cout << "imagePath: " << imagePath << endl;
		//cout << "outfile: " <<outfile << endl;
		//cout << "normalize value: "<<normalize << " doNormalization: " << doNormalization <<endl;
		//cout << "minThreshold: " << minThreshold << endl;
		//cout << "maxThreshold: " <<maxThreshold << endl;
		//cout << "l: " <<l << endl;
		//cout << "b: "<<b << endl;
		
		ofstream resText(outfile);
		resText.setf(ios::fixed); 

		ExpRatioEvaluator exp(imagePath,doNormalization,minThreshold,maxThreshold,l,b);
		double *output = exp.computeExpRatioValues();

		resText << setprecision(5) << output[0];	// <<" "<< output[1] <<" "<< output[2] <<" "<< output[3]
		
		cout << "Created " <<outfile<< " log file."<<endl;
		resText.close();
	}
	 
	
	cout << endString << endl;
    return 0;
}
