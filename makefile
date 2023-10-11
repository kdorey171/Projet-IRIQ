projet : main.o
	g++ main.o -o projet -lsfml-graphics -lsfml-window -lsfml-system

main.o : main.cpp
	g++ -c main.cpp
