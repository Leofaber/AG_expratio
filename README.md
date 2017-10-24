# AG_expratio 1.0.2

Il software calcola il valore exp-ratio su di una mappa exposure data la coppia (l,b) della posizione del blob.
Per maggiori informazioni consultare: https://github.com/Leofaber/ExpRatioEvaluator

### Utilizzo: 

	./bin/AG_expratio outfile imagePath l b isExpMapNormalized createExpRatioMap minThreshold maxThreshold squareSize

### Input:

	outfile: il file di output (è possibile specificare anche il percorso) ( const char * )
	
	imagePath: il percorso alla mappa di esposizone (.exp o .exp.gz) ( const char * )

	l: longitudine galattica ( double )
	
	b: latitudine galattica ( double )

	
(OPZIONALI) -> è possibile specificare "d" per usare il valore di default

	isExpMapNormalized : se il valore è "false", si afferma che la mappa exp in input NON è normalizzata. Il software provvederà a normalizzarla ed a scriverla su file. ( default = false)

	createExpRatioMap: se il valore è "true", viene creata una mappa (FITS) nella quale il valore di ogni pixel rappresenta il valore dell'ExpRatioEvaluator calcolato sul medesimo pixel. Se il valore è "false" non viene creata alcuna mappa. ( true/false ) ( default = false)

	minThreshold: la soglia minima sotto la quale il pixel è considerato "bad" per il calcolo dell'exp-ratio ( double ) ( default = 120 )
	
	maxThreshold: la soglia minima sopra la quale il pixel è considerato "bad" per il calcolo dell'exp-ratio ( double ) ( default = 140 )

	squareSize: la dimensione in pixel del lato della regione (quadrato) su cui si calcola l'exp-ratio ( int ) ( default = 10 )

### Esempio di utilizzo

	./bin/AG_expratio log.txt ../../mappetest/exp.exp 45 30 false true d 140 d

### Output

	1) L'outuput di ExpRatioEvaluator -> https://github.com/Leofaber/ExpRatioEvaluator
	2) Il file <outfile> che riporta il valore exp-ratio
	
### Dipendenze:

	ExpRatioEvaluator https://github.com/Leofaber/ExpRatioEvaluator
	
