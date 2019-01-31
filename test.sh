./main < testFiles/square.txt > testFiles/outputSquare.txt
diff testFiles/outputSquare.txt testFiles/squareOutput.txt
error=$?
if [ $error -eq 0 ]
then
echo "sqare test passed"
elif [ $error -eq 1 ]
then
echo "square test failed"
exit 1
else
echo "square test didn't run properly"
exit 1
fi
./main < testFiles/rectangle.txt > testFiles/outputRectangle.txt
diff testFiles/outputRectangle.txt testFiles/rectangleOutput.txt
error=$?
if [ $error -eq 0 ]
then
echo "rectangle test passed"
elif [ $error -eq 1 ]
then
echo "rectangle test failed"
exit 1
else
echo "rectangle test didn't run properly"
exit 1
fi
./main < testFiles/trapezoid.txt > testFiles/outputTrapezoid.txt
diff testFiles/outputTrapezoid.txt testFiles/trapezoidOutput.txt
error=$?
if [ $error -eq 0 ]
then
echo "trapezoid test passed"
elif [ $error -eq 1 ]
then
echo "trapezoid test failed"
exit 1
else
echo "trapezoid test didn't run properly"
exit 1
fi
./main < testFiles/kite.txt > testFiles/outputKite.txt
diff testFiles/outputKite.txt testFiles/kiteOutput.txt
error=$?
if [ $error -eq 0 ]
then
echo "kite test passed"
elif [ $error -eq 1 ]
then
echo "kite test failed"
exit 1
else
echo "kite test didn't run properly"
exit 1
fi
./main < testFiles/parallelogram.txt > testFiles/outputParallelogram.txt
diff testFiles/outputParallelogram.txt testFiles/ParallelogramOutput.txt
error=$?
if [ $error -eq 0 ]
then
echo "parallelogram test passed"
elif [ $error -eq 1 ]
then
echo "parallelogram test failed"
exit 1
else
echo "parallelogram test didn't run properly"
exit 1
fi
./main < testFiles/rhombus.txt > testFiles/outputRhombus.txt
diff testFiles/outputRhombus.txt testFiles/rhombusOutput.txt
error=$?
if [ $error -eq 0 ]
then
echo "rhombus test passed"
elif [ $error -eq 1 ]
then
echo "rhombus test failed"
exit 1
else
echo "rhombus test didn't run properly"
exit 1
fi
./main < testFiles/quadrilateral.txt > testFiles/outputQuadrilateral.txt
diff testFiles/outputQuadrilateral.txt testFiles/quadrilateralOutput.txt
error=$?
if [ $error -eq 0 ]
then
echo "quadrilateral test passed"
elif [ $error -eq 1 ]
then
echo "quadrilateral test failed"
exit 1
else
echo "quadrilateral test didn't run properly"
exit 1
fi
./main < testFiles/error1.txt > testFiles/outputError1.txt
diff testFiles/outputError1.txt testFiles/error1Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "error1 test passed"
elif [ $error -eq 1 ]
then
echo "error1 test failed"
exit 1
else
echo "error1 test didn't run properly"
exit 1
fi
./main < testFiles/error2.txt > testFiles/outputError2.txt
diff testFiles/outputError2.txt testFiles/error2Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "error2 test passed"
elif [ $error -eq 1 ]
then
echo "error2 test failed"
exit 1
else
echo "error2 test didn't run properly"
exit 1
fi
./main < testFiles/error3.txt > testFiles/outputError3.txt
diff testFiles/outputError3.txt testFiles/error3Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "error3 test passed"
elif [ $error -eq 1 ]
then
echo "error3 test failed"
exit 1
else
echo "error3 test didn't run properly"
exit 1
fi
./main < testFiles/error4.txt > testFiles/outputError4.txt
diff testFiles/outputError4.txt testFiles/error4Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "error4 test passed"
elif [ $error -eq 1 ]
then
echo "error4 test failed"
exit 1
else
echo "error4 test didn't run properly"
exit 1
fi
./main < testFiles/error5.txt > testFiles/outputError5.txt
diff testFiles/outputError5.txt testFiles/error5Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "error5 test passed"
elif [ $error -eq 1 ]
then
echo "error5 test failed"
exit 1
else
echo "error5 test didn't run properly"
exit 1
fi
./main < testFiles/error6.txt > testFiles/outputError6.txt
diff testFiles/outputError6.txt testFiles/error6Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "error6 test passed"
elif [ $error -eq 1 ]
then
echo "error6 test failed"
exit 1
else
echo "error6 test didn't run properly"
exit 1
fi
#./main < testFiles/error7.txt > testFiles/outputError7.txt
#diff testFiles/outputError7.txt testFiles/error7Output.txt
#error=$?
#if [ $error -eq 0 ]
#then
#echo "error7 test passed"
#elif [ $error -eq 1 ]
#then
#echo "error7 test failed"
#exit 1
#else
#echo "error7 test didn't run properly"
#exit 1
#fi
#./main < testFiles/error8.txt > testFiles/outputError8.txt
#diff testFiles/outputError8.txt testFiles/error8Output.txt
#error=$?
#if [ $error -eq 0 ]
#then
#echo "error8 test passed"
#elif [ $error -eq 1 ]
#then
#echo "error8 test failed"
#exit 1
#else
#echo "error8 test didn't run properly"
#exit 1
#fi
#./main < testFiles/error9.txt > testFiles/outputError9.txt
#diff testFiles/outputError9.txt testFiles/error9Output.txt
#error=$?
#if [ $error -eq 0 ]
#then
#echo "error9 test passed"
#elif [ $error -eq 1 ]
#then
#echo "error9 test failed"
#exit 1
#else
#echo "error9 test didn't run properly"
#exit 1
#fi
./main < testFiles/error10.txt > testFiles/outputError10.txt
diff testFiles/outputError10.txt testFiles/error10Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "error10 test passed"
elif [ $error -eq 1 ]
then
echo "error10 test failed"
exit 1
else
echo "error10 test didn't run properly"
exit 1
fi
./main < testFiles/error11.txt > testFiles/outputError11.txt
diff testFiles/outputError11.txt testFiles/error11Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "error11 test passed"
elif [ $error -eq 1 ]
then
echo "error11 test failed"
exit 1
else
echo "error11 test didn't run properly"
exit 1
fi
./main < testFiles/error12.txt > testFiles/outputError12.txt
diff testFiles/outputError12.txt testFiles/error12Output.txt
error=$?
if [ $error -eq 0 ]
then
echo "error12 test passed"
elif [ $error -eq 1 ]
then
echo "error12 test failed"
exit 1
else
echo "error12 test didn't run properly"
exit 1
fi
