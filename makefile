edClust: main.o common.o edlib.o
	g++ -fopenmp -g -O3 -o edClust main.o common.o edlib.o
main.o: main.cpp common.h edlib.h
	g++ -fopenmp -g -O3 -c main.cpp
common.o: common.cpp common.h edlib.h
	g++ -fopenmp -g -O3 -c common.cpp
edlib.o: edlib.cpp edlib.h
	g++ -fopenmp -g -O3 -c edlib.cpp
clean:
	rm *.o edClust
