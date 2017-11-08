# AG_expratio 1.0.5

Il software calcola il valore exp-ratio su di una mappa exposure data la coppia (l,b) della posizione del blob.
Per maggiori informazioni consultare: https://github.com/Leofaber/ExpRatioEvaluator

### Utilizzo: 

	./bin/AG_expratio outfile imagePath isExpMapNormalized l b createExpRatioMap minThreshold maxThreshold squareSize

### Input:

	outfile: il file di output (è possibile specificare anche il percorso)  
	
	imagePath: il percorso alla mappa di esposizone (.exp o .exp.gz) 
	
	isExpMapNormalized : se il valore è "no", si afferma che la mappa exp in input (imagePath) NON è normalizzata. Il software provvederà a normalizzarla.

	l: longitudine galattica ( double )
	
	b: latitudine galattica ( double )

	createExpNormalizedMap : se il valore è "yes" verrà scritta su file la mappa normalizzata. 

	createExpRatioMap: se il valore è "yes", verrà scritta su file la mappa exp-ratio ovvero quella mappa in cui il valore di ogni pixel rappresenta il valore della valutazione exp-ratio calcolato sul medesimo pixel. 
	
	minThreshold: la soglia minima sotto la quale il pixel è considerato "bad" per il calcolo dell'exp-ratio 
	
	maxThreshold: la soglia minima sopra la quale il pixel è considerato "bad" per il calcolo dell'exp-ratio 

	squareSize: la dimensione in pixel del lato della regione (quadrato) su cui si calcola l'exp-ratio 


### Esempio di utilizzo

	./bin/AG_expratio log.txt ../../mappetest/exp.exp no 45 30 yes yes 110 150 10

### Output

	1) L'outuput di ExpRatioEvaluator -> https://github.com/Leofaber/ExpRatioEvaluator
	2) Il file <outfile> che riporta il valore exp-ratio
	
### Dipendenze:

	ExpRatioEvaluator https://github.com/Leofaber/ExpRatioEvaluator
	
