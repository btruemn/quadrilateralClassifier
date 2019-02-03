#!/bin/bash

clang++ -fprofile-instr-generate -fcoverage-mapping main.cpp -o main

#RANDOM INTS
for i in `seq 1 100`;
do
    LLVM_PROFILE_FILE="profraw/$i.profraw" ./main < quadrilateralFizzer/testFiles/randomInt/$i.txt > quadrilateralFizzer/testFiles/randomInt/output$i.txti.txt
done

#RANDOM ASCII
for i in `seq 1 100`;
do
    LLVM_PROFILE_FILE="profraw/ascii$i.profraw" ./main < quadrilateralFizzer/testFiles/randomASCII/$i.txt > quadrilateralFizzer/testFiles/randomASCII/output$i.txti.txt
done

LLVM_PROFILE_FILE="profraw/square.profraw" ./main < quadrilateralFizzer/testFiles/shapes/testSquares.txt > quadrilateralFizzer/testFiles/shapes/outputSquares.txt
LLVM_PROFILE_FILE="profraw/rectangle.profraw" ./main < quadrilateralFizzer/testFiles/shapes/testRectangles.txt > quadrilateralFizzer/testFiles/shapes/outputRectangles.txt


str=""
for i in `seq 1 100`;
do
    str+="profraw/$i.profraw "
done

for i in `seq 1 100`;
do
    str+="profraw/ascii$i.profraw "
done

str+="profraw/square.profraw "
str+="profraw/rectangle.profraw"

llvm-profdata merge -sparse $str -o coverage.profdata
# llvm-cov show ./main -instr-profile=coverage.profdata
llvm-cov show ./main -instr-profile=coverage.profdata


# for i in 'seq 1 800';
# do
    # rm -f profraw/*
# done
#
# rm -f profraw/kite.profraw
# rm -f profraw/square.profraw
# rm -f profraw/rectangle.profraw
