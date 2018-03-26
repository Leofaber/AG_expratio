#!/bin/sh
module load agile-B24-r5
export PFILES=/home/student/PARFILES

# ExpRatioEvaluator
cp ../AG_utils/include/ExpRatioEvaluator.h include/ExpRatioEvaluator.h
cp ../AG_utils/src/ExpRatioEvaluator.cpp src/ExpRatioEvaluator.cpp

# MapConverter
cp ../AG_utils/include/MapConverter.h include/MapConverter.h
cp ../AG_utils/src/MapConverter.cpp src/MapConverter.cpp


make clean
make


#./bin/AG_expratio logg.txt map/exp.exp no 45 30 no no -1 -1 -1 
./bin/AG_expratio log.txt map/mappa.exp no 45 30
