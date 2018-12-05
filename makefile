all: main

main: ./MAIN/main.cpp
	g++ -Wall -o programme  ./MAIN/main.cpp
