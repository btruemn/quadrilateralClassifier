all: classifier

classifier: main.o functions.o
	clang++ main.o functions.o -o classifier

main.o: main.cpp
	clang++ -c main.cpp

functions.o: functions.cpp
	clang++ -c functions.cpp

test:
	./test.sh

clean:
	rm -f main
