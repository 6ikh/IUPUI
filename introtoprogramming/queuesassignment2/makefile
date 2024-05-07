queues: queues.o
	g++ queues.o -o queues	
queues.o: queues.cpp
	g++ -c queues.cpp 	
clean: 
	rm *.o
debug: queues
	gdb ./queues
valgrind: queues 
	valgrind --tool=memcheck  --leak-check=yes  --show-reachable=yes --num-callers=20 --track-fds=yes  ./queues
run: queues
	./queues
