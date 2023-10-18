project : main.cpp class_vessel.o class_input.o player.o
	g++ main.cpp class_vessel.o class_input.o player.o -o project -Wfatal-errors -lsfml-graphics -lsfml-window -lsfml-system

class_vessel.o : class_vessel.cpp class_vessel.h
	g++ -c class_vessel.cpp -Wfatal-errors

class_input.o : class_input.cpp class_input.h
	g++ -c class_input.cpp -Wfatal-errors

player.o : player.cpp player.h
	g++ -c player.cpp -Wfatal-errors

