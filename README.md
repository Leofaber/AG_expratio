# AG_expratio 1.0.2

Il software calcola il valore exp-ratio su di una mappa exposure data la coppia (l,b) della posizione del blob.
Per maggiori informazioni consultare: https://github.com/Leofaber/ExpRatioEvaluator

### Input:
	
	imagePath: il percorso alla mappa di esposizone (.exp o .exp.gz) ( const char * )
	outfile: il file di output (è possibile specificare anche il percorso) ( const char * )
	onNormalizedMap: se il valore è "true", la valutazione exp-ratio viene effettuata sulla mappa normalizzata. Inoltre la mappa exp-ratio viene creata a partire dalla mappa normalizzata. Altrimenti si utilizza l'immagine in input. ( true/false )
	l: longitudine galattica ( double )
	b: latitudine galattica ( double )
	
	(OPZIONALI) -> è possibile specificare "d" per usare il valore di default
	minThreshold: la soglia minima sotto la quale il pixel è considerato "bad" per il calcolo dell'exp-ratio ( double ) ( default = 120 )
	maxThreshold: la soglia minima sotto la quale il pixel è considerato "bad" per il calcolo dell'exp-ratio ( double ) ( default = 140 )
	squareSize: la dimensione in pixel del lato della regione (quadrato) su cui si calcola l'exp-ratio ( int ) ( default = 10 )

### Outputs

	1) L'outuput di ExpRatioEvaluator -> https://github.com/Leofaber/ExpRatioEvaluator
	2) Il file <outfile> che riporta il valore exp-ratio
	
### Dipendenze:

	ExpRatioEvaluator https://github.com/Leofaber/ExpRatioEvaluator

### Esempio di utilizzo:

	./bin/ExpRatioEvaluator mappetest/exp.exp log.txt true 45 30 d 140 5
