main: main.o
	g++ main.o -o main	
main.o: main.cpp
	g++ -c main.cpp 	
clean: 
	rm *.o
	rm ./main
debug: main
	gdb ./main

run: main
	./main
