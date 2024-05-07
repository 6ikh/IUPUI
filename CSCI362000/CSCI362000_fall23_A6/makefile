make: main.o
	g++ main.o -o make	
main.o: main.cpp
	g++ -c main.cpp 	
clean: 
	rm *.o
debug: make
	gdb ./make

run: make
	./make
