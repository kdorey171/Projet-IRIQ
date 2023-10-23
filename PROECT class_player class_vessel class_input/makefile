project : main.cpp class_vessel.o class_input.o player.o
	g++ main.cpp class_vessel.o class_input.o player.o -I"include" -o project -Wfatal-errors -lsfml-graphics -lsfml-window -lsfml-system

class_vessel.o : source/class_vessel.cpp include/class_vessel.h
	g++ -c source/class_vessel.cpp -I"include" -Wfatal-errors

class_input.o : source/class_input.cpp include/class_input.h
	g++ -c source/class_input.cpp -I"include" -Wfatal-errors

player.o : source/player.cpp include/player.h
	g++ -c source/player.cpp -I"include" -Wfatal-errors

