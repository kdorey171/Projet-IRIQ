all :
	make project
	rm *.o 2>/dev/null || echo "rien a clean"

project : main.cpp class_vessel.o class_vessel_ressource.o class_vessel_unite.o class_vessel_tower.o class_unite.o class_input.o player.o load_textures.o
	g++ main.cpp class_vessel.o class_vessel_ressource.o class_vessel_unite.o class_vessel_tower.o class_unite.o class_input.o player.o load_textures.o -I"include" -o project -Wfatal-errors -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lpthread


class_vessel.o : source/class_vessel.cpp include/class_vessel.h
	g++ -c source/class_vessel.cpp -I"include" -Wfatal-errors

class_vessel_ressource.o : source/class_vessel_ressource.cpp include/class_vessel_ressource.h
	g++ -c source/class_vessel_ressource.cpp -I"include" -Wfatal-errors

class_vessel_unite.o : source/class_vessel_unite.cpp include/class_vessel_unite.h
	g++ -c source/class_vessel_unite.cpp -I"include" -Wfatal-errors

class_vessel_tower.o : source/class_vessel_tower.cpp include/class_vessel_tower.h
	g++ -c source/class_vessel_tower.cpp -I"include" -Wfatal-errors

class_unite.o : source/class_unite.cpp include/class_unite.h
	g++ -c source/class_unite.cpp -I"include" -Wfatal-errors

class_input.o : source/class_input.cpp include/class_input.h
	g++ -c source/class_input.cpp -I"include" -Wfatal-errors

player.o : source/player.cpp include/player.h
	g++ -c source/player.cpp -I"include" -Wfatal-errors

load_textures.o : source/load_textures.cpp include/load_textures.h
	g++ -c source/load_textures.cpp -I"include" -Wfatal-errors

