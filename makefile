main: main.o CopyFast.o
	g++ main.o CopyFast.o -o cf
	rm *.o

main.o: main.cpp
	g++ main.cpp -c -o main.o	

CopyFast.o: CopyFast.cpp
	g++ CopyFast.cpp -c -o CopyFast.o