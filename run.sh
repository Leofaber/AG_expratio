#!/bin/sh
module load agile-B24-r5
export PFILES=/home/student/PARFILES
cp ../ExpRatioEvaluator/include/ExpRatioEvaluator.h include/ExpRatioEvaluator.h
cp ../ExpRatioEvaluator/src/ExpRatioEvaluator.cpp src/ExpRatioEvaluator.cpp

make


./bin/AG_expratio log.txt exp_120_140_20_exp_norm.exp.gz no 45 30
