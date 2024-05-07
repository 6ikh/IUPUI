HorseRace: main.o Race.o Horse.o
	g++ main.o Race.o Horse.o -o HorseRace
main.o: main.cpp Race.h Horse.h 
	g++ -c main.cpp
Race.o: Race.cpp Race.h Horse.h 
	g++ -c Race.cpp
Horse.o: Horse.cpp Horse.h
	g++ -c Horse.cpp
clean: 
	rm *.o
	rm HorseRace
run: HorseRace
	./HorseRace
