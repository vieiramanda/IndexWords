FLAGS = -Wall -pedantic -std=c++11

all: main.o metodos.o
	g++ $(FLAGS) $^ 
main.o: main.cpp Classes.h
	g++ $(FLAGS) -c main.cpp
metodos.o: metodos.cpp
	g++ $(FLAGS) -c metodos.cpp
clean:
	rm *.o
