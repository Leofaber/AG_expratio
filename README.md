# AG_expratio 1.0.4

Il software calcola il valore exp-ratio su di una mappa exposure data la coppia (l,b) della posizione del blob.
Per maggiori informazioni consultare: https://github.com/Leofaber/ExpRatioEvaluator

### Utilizzo: 

	./bin/AG_expratio outfile imagePath isExpMapNormalized l b createExpRatioMap minThreshold maxThreshold squareSize

### Input:

	outfile: il file di output (è possibile specificare anche il percorso) ( const char * )
	
	imagePath: il percorso alla mappa di esposizone (.exp o .exp.gz) ( const char * )
	
	isExpMapNormalized : se il valore è "false", si afferma che la mappa exp in input (imagePath) NON è normalizzata. Il software provvederà a normalizzarla.

	l: longitudine galattica ( double )
	
	b: latitudine galattica ( double )

	
(OPZIONALI) -> è possibile specificare "d" per usare il valore di default

	createExpNormalizedMap : se il valore è true verrà scritta su file la mappa normalizzata. ( true/false ) ( default = false)

	createExpRatioMap: se il valore è "true", verrà scritta su file la mappa exp-ratio ovvero quella mappa in cui il valore di ogni pixel rappresenta il valore della valutazione exp-ratio calcolato sul medesimo pixel. ( true/false ) ( default = false)

	minThreshold: la soglia minima sotto la quale il pixel è considerato "bad" per il calcolo dell'exp-ratio ( double ) ( default = 120 )
	
	maxThreshold: la soglia minima sopra la quale il pixel è considerato "bad" per il calcolo dell'exp-ratio ( double ) ( default = 140 )

	squareSize: la dimensione in pixel del lato della regione (quadrato) su cui si calcola l'exp-ratio ( int ) ( default = 10 )

### Esempio di utilizzo

	./bin/AG_expratio log.txt ../../mappetest/exp.exp false 45 30 true true d 150 d

### Output

	1) L'outuput di ExpRatioEvaluator -> https://github.com/Leofaber/ExpRatioEvaluator
	2) Il file <outfile> che riporta il valore exp-ratio
	
### Dipendenze:

	ExpRatioEvaluator https://github.com/Leofaber/ExpRatioEvaluator
	
