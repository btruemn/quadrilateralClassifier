all: classifier

classifier: main.o
  clang++ main.o -o classifier

main.o: main.cpp
  clang++ -c main.cpp functions.cpp

test:
  ./test.sh
