all: main

main: main.cpp
	clang++ -std=c++11 main.cpp -o main

test: main
	./test.sh

clean:
	rm -f main
	rm -f testFiles/outputSquare.txt
	rm -f testFiles/outputRhomus.txt
	rm -f testFiles/outputErrror1.txt
	rm -f testFiles/outputErrror2.txt
	rm -f testFiles/outputErrror3.txt
	rm -f testFiles/outputErrror4.txt
	rm -f testFiles/outputErrror5.txt
	rm -f testFiles/outputErrror6.txt
	rm -f testFiles/outputErrror7.txt
	rm -f testFiles/outputErrror8.txt
	rm -f testFiles/outputErrror9.txt
	rm -f testFiles/outputError10.txt
	rm -f testFiles/outputError11.txt
	rm -f testFiles/outputError12.txt
	rm -f testFiles/expectedOutput.txt

fuzzer:
	clang++ -std=c++11 main.cpp -o main
	chmod +x shapes.py
	./shapes.py
	chmod +x fuzz

cover:
	clang++ -fprofile-instr-generate -fcoverage-mapping main.cpp -o main
	LLVM_PROFILE_FILE="profraw/square.profraw" ./main < testFiles/square.txt > testFiles/outputSquare.txt
	LLVM_PROFILE_FILE="profraw/rhombus.profraw" ./main < testFiles/rhombus.txt > testFiles/outputRhombus.txt
	-LLVM_PROFILE_FILE="profraw/error1.profraw" ./main < testFiles/error1.txt > testFiles/outputError1.txt
	-LLVM_PROFILE_FILE="profraw/error2.profraw" ./main < testFiles/error2.txt > testFiles/outputError2.txt
	-LLVM_PROFILE_FILE="profraw/error3.profraw" ./main < testFiles/error3.txt > testFiles/outputError3.txt
	-LLVM_PROFILE_FILE="profraw/error4.profraw" ./main < testFiles/error4.txt > testFiles/outputError4.txt
	-LLVM_PROFILE_FILE="profraw/error5.profraw" ./main < testFiles/error5.txt > testFiles/outputError5.txt
	-LLVM_PROFILE_FILE="profraw/error6.profraw" ./main < testFiles/error6.txt > testFiles/outputError6.txt
	-LLVM_PROFILE_FILE="profraw/error7.profraw" ./main < testFiles/error7.txt > testFiles/outputError7.txt
	-LLVM_PROFILE_FILE="profraw/error8.profraw" ./main < testFiles/error8.txt > testFiles/outputError8.txt
	-LLVM_PROFILE_FILE="profraw/error9.profraw" ./main < testFiles/error9.txt > testFiles/outputError9.txt
	-LLVM_PROFILE_FILE="profraw/error10.profraw" ./main < testFiles/error10.txt > testFiles/outputError10.txt
	-LLVM_PROFILE_FILE="profraw/error11.profraw" ./main < testFiles/error11.txt > testFiles/outputError11.txt
	-LLVM_PROFILE_FILE="profraw/error12.profraw" ./main < testFiles/error12.txt > testFiles/outputError12.txt
	-LLVM_PROFILE_FILE="profraw/input.profraw" ./main < testFiles/input.txt  > testFiles/expectedOutput.txt
	llvm-profdata merge -sparse  profraw/rhombus.profraw profraw/error1.profraw profraw/error2.profraw profraw/error3.profraw profraw/error4.profraw profraw/error5.profraw profraw/error6.profraw profraw/error7.profraw profraw/error8.profraw profraw/error9.profraw profraw/error10.profraw profraw/error11.profraw profraw/error12.profraw profraw/input.profraw profraw/square.profraw -o main.profdata #profraw/error7.profraw profraw/error8.profraw profraw/error9.profraw # profraw/square.profraw profraw/rectangle.profraw profraw/trapezoid.profraw profraw/kite.profraw profraw/parallelogram.profraw profraw/quadrilateral.profraw
	llvm-cov show ./main -instr-profile=main.profdata
