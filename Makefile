lab9: main.o PrecondViolatedExcep.o BinomialQueue.o
	g++ -std=c++11 -g -Wall main.o PrecondViolatedExcep.o BinomialQueue.o -o lab9

main.o: QNode.h QNode.hpp Queue.h Queue.hpp main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -std=c++11 -g -Wall -c PrecondViolatedExcep.cpp
    
BinomialQueue.o: BinomialQueue.h BinomialQueue.cpp
	g++ -std=c++11 -g -Wall -c BinomialQueue.cpp

clean:
	rm *.o lab9
	echo clean done