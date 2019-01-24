all: classifier

classifier: main.o
	clang++ main.o functions.o -o classifier

# main.o: main.cpp
# 	clang++ -c main.cpp
#
# functions.o: functions.cpp functions.h
# 	clang++ -c functions.cpp

test:
	./test.sh'

clean:
	rm -f main
