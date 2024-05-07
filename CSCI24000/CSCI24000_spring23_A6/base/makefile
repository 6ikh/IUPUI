Main: main.o Student.o Date.o Address.o 
	g++ main.o Student.o Date.o Address.o  -o Main	
main.o: main.cpp Student.h Date.h Address.h
	g++ -c main.cpp 
student.o: Student.cpp Student.h Address.h Date.h 
	g++ -c Student.cpp	
date.o: Date.cpp Date.h 
	g++ -c Date.cpp
address.o: Address.cpp Address.h Date.h 
	g++ -c Address.cpp
clean: 
	rm -rf *.o
	rm -rf Main
	rm -rf fullReport.txt
	rm -rf shortReport.txt 
debug: Main
	gdb ./Main
valgrind: Main 
	valgrind --tool=memcheck  --leak-check=yes  --show-reachable=yes --num-callers=20 --track-fds=yes  ./Main
run: Main
	./Main
