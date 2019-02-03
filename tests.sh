#!/bin/bash

clang++ -fsanitize=address -fprofile-instr-generate -fcoverage-mapping main.cpp -o main
errorCounter=0;

#RANDOM INTS
for i in `seq 1 100`;
do
    ./main < "quadrilateralFizzer/testFiles/randomInt/$i.txt" > "quadrilateralFizzer/testFiles/randomInt/output$i.txt"
done

#RANDOM ASCII
for i in `seq 1 100`;
do
    ./main < "quadrilateralFizzer/testFiles/randomASCII/$i.txt" > "quadrilateralFizzer/testFiles/randomASCII/output$i.txt"
done

#RANDOM LARGE INT
for i in `seq 1 100`;
do
    ./main < "quadrilateralFizzer/testFiles/randomLargeInt/$i.txt" > "quadrilateralFizzer/testFiles/randomLargeInt/output$i.txt"
done


#SQUARE
./main < quadrilateralFizzer/testFiles/shapes/testSquares.txt > quadrilateralFizzer/testFiles/shapes/outputSquares.txt
diff quadrilateralFizzer/testFiles/shapes/outputSquares.txt quadrilateralFizzer/testFiles/shapes/squareKey.txt
error=$?
if [ $error -eq 1 ]
then
errorCounter+=1
fi

#RECTANGLE
./main < quadrilateralFizzer/testFiles/shapes/testRectangles.txt > quadrilateralFizzer/testFiles/shapes/outputRectangles.txt
diff quadrilateralFizzer/testFiles/shapes/outputRectangles.txt quadrilateralFizzer/testFiles/shapes/rectangleKey.txt
error=$?
if [ $error -eq 1 ]
then
errorCounter+=1
fi

#PARALLELOGRAM
./main < quadrilateralFizzer/testFiles/shapes/testParallelograms.txt > quadrilateralFizzer/testFiles/shapes/outputParallelograms.txt
diff quadrilateralFizzer/testFiles/shapes/outputParallelograms.txt quadrilateralFizzer/testFiles/shapes/parallelogramKey.txt
error=$?
if [ $error -eq 1 ]
then
errorCounter+=1
fi


if [ $errorCounter \> 0 ]
then
echo "ERROR"
exit 1
elif [ $errorCounter -eq 0 ]
then
echo "OK"
fi
