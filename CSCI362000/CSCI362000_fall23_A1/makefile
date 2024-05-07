make: SelectionSort.o
	g++ SelectionSort.o -o make	
SelectionSort.o: SelectionSort.cpp
	g++ -c SelectionSort.cpp 	
clean: 
	rm *.o
	rm make
debug: make
	gdb ./make

run: make
	./make
