
/*
 * Copyright (c) 2017
 *     Leonardo Baroncelli, Giancarlo Zollino
 *
 * Any information contained in this software
 * is property of the AGILE TEAM and is strictly
 * private and confidential.
 * 
 * https://github.com/Leofaber/AG_expratio
*/



#include <iomanip> 
#include <cstring>

#include "ExpRatioEvaluator.h"



const char* startString = {
"################################################################\n"
"###                   Task AG_expratio v1.0.1 -              ###"
};

const char* endString = {
"### Task AG_expratio exiting ............................... ###\n"
"################################################################"
};

void printMatrix(double ** matrix, int rows, int cols){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j ++){
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}


int main(int argc, char *argv[])
{ 	

	cout << startString << endl;


	// DEFINIZIONE PARAMETRI DI DEFAULT ---------------------------------------------


	double minThreshold = 120;
	double maxThreshold = 140;
	int squareSize = 20;
	const char * isAlreadyNormalized = "false";
	const char * createExpRatioMap = "false";





	// CONTROLLO NUMERO PARAMETRI (TOO FEW, TOO MUCH) -------------------------------

	
	if(argc < 5 || argc > 10)
	{
		printf("\nAt least 4 arguments expected (+ 5 optional)\n   - The name of the output file\n   - The .exp file path\n   - The l coordinate\n    -The b coordinate\n\n(Optional)\n   - The isExpMapNormalized boolean: if 'true' we assert that the exp map given in input is already normalized. If 'false' the exp map will be normalized and it will be writed on file (default value = false)\n   - The createExpRatioMap boolean: if 'true' the ExpRatioMap will be writed on file. (default value = false)\n   - The minThreshold (default value = 120)\n   - The maxThreshold (default value = 140)\n   - The square size (default value = 20).\n");
		cout << endString << endl;		
		exit (EXIT_FAILURE);
	}

	else
	{	

		// PARAMETRI OBBLIGATORI ---------------------------------------------------
        const char * outfile = argv[1];
        const char * imagePath = argv[2];
		double l = atof(argv[3]);
		double b = atof(argv[4]);

        
		

		// PARAMETRI OPZIONALI -------------------------------------------
		if(argc == 6)
		{	
			if(((string)argv[5])!="d")
				isAlreadyNormalized = argv[5];
		}
		else if(argc == 7)
		{
			if(((string)argv[5])!="d")
				isAlreadyNormalized = argv[5];
			if(((string)argv[6])!="d")
				createExpRatioMap = argv[6];
		}
		else if(argc == 8)
		{	
			if(((string)argv[5])!="d")
				isAlreadyNormalized = argv[5];
			if(((string)argv[6])!="d")
				createExpRatioMap = argv[6];
			if(((string)argv[7])!="d")
				minThreshold = atof(argv[7]);
			}
		
		else if(argc == 9)
		{
			if(((string)argv[5])!="d")
				isAlreadyNormalized = argv[5];
			if(((string)argv[6])!="d")
				createExpRatioMap = argv[6];
			if(((string)argv[7])!="d")
				minThreshold = atof(argv[7]);
			if(((string)argv[8])!="d")
				maxThreshold = atof(argv[8]);
	
		}
		else if(argc == 10)
		{
			if(((string)argv[5])!="d")
				isAlreadyNormalized = argv[5];
			if(((string)argv[6])!="d")
				createExpRatioMap = argv[6];
			if(((string)argv[7])!="d")
				minThreshold = atof(argv[7]);
			if(((string)argv[8])!="d")
				maxThreshold = atof(argv[8]);
			if(((string)argv[9])!="d")
				squareSize = atof(argv[9]);
		}

				
		
		bool isAlreadyNormalizedBool;
		if( strcmp(isAlreadyNormalized, "true") == 0 ){
			isAlreadyNormalizedBool = true;
		}
		else{
			isAlreadyNormalizedBool = false;
		}
		
		bool createExpRatioMapBool;
		if( strcmp(createExpRatioMap, "true") == 0 ){
			createExpRatioMapBool = true;
		}
		else{
			createExpRatioMapBool = false;
		}
		



		
		// PRINT INPUT PARAMETERS -------------------------------------


		cout << "\noutfile: " << outfile << endl;
		cout << "imagePath: " << imagePath << endl;
		cout << "l: " << l << endl;
		cout << "b: " << b << endl;
		cout << "isAlreadyNormalized: " << isAlreadyNormalized << endl;
		cout << "createExpRatioMap: " << createExpRatioMap << endl;
		cout << "MinThreshold: " << minThreshold << endl;
		cout << "MaxThreshold: " << maxThreshold << endl;
		cout << "squareSize: " << squareSize << "\n" <<endl;
		



		// CORE LOGIC -----------------------------------------------


		ExpRatioEvaluator exp(imagePath, isAlreadyNormalizedBool, createExpRatioMapBool, minThreshold, maxThreshold, squareSize);
					
		double expRatio = exp.computeExpRatioValues(l,b);







		// OUTPUT ----------------------------------------------------
		
		
		ofstream resText(outfile);
		resText.setf(ios::fixed); 

		resText << setprecision(5) << expRatio; 
		
		cout << "Created " <<outfile<< " log file."<<endl;
		resText.close();
		
		cout << endString << endl;
		return 0;

	}
}
		
		
