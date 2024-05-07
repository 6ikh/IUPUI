Goals - What is the goal of the program or function?
The goal of the program is to simulate a horse race with 5 horses. Each horse has a chance to advance forward in the race each round and the race continues until one horse reaches the end of the race. A coin flip system is used to decide if the horse will go forward or not. The program also prints out the current state of the race, showing the position of each horse. The user is prompted to enter a random seed, which is used to initialize the random number generator for copied results.
Input - What (if any) input does the function or program accept?  Are there specific data types or ranges?
The program accepts the seed value 700 for the program to output the same race. 
Output - What (if any) output does the function or program return
The program returns the output of a horse race simulation that is displayed in the console. The output shows the progress of the horses in the race and the number of the horse, and at the end of the race it prints the winner of the race.
Steps - What are the steps (written in English) necessary to solve this problem.  This should NOT be programming code, but each line should be specific enough to be translated to a line or two of code in your target language.
Steps for “Horse.cpp” 
Include the standard I/O library, standard library, and the header file "Horse.h".
Initialize a HorseRace object, "race".
Call the "advance()" method of "race" in a loop for the desired number of iterations to simulate the horse race.
Call the "getPosition(int horseNumber)" method of "race" to get the position of the horse with horseNumber.
Display the final positions of all horses.
Steps for “Horse.h” 
Define HORSES gets value 5
Implement the constructor "HorseRace()" to initialize all elements of "horses" to 0. It should be private
Implement the "advance()" method to simulate the advancing of horses in a race by randomly increasing the position of each horse. This should be public as well as below. 
Implement the "getPosition(int horseNumber)" method to return the position of the horse with the given horse number
Steps for “Race.cpp” 
Implement the constructor "Race()" to initialize the private member "raceKeepGoing" to true.
Implement the "number()" method to display the current positions of all horses in the race.
Implement the "checkWinner()" method to check if any horse has crossed the finish line and declare the winner if any.
Implement the "runRace()" method to simulate the horse race by calling the "advance()" method of the "horseRace" object and calling the "number()" and "checkWinner()" methods repeatedly until the winner is declared.
Steps for “Race.h” 
Include the "HorseRace" header file.
Implement the constructor "Race()" to initialize the private member "raceKeepGoing" to true.
Implement the "number()" method to display the current positions of all horses in the race.
Implement the "checkWinner()" method to check if any horse has crossed the finish line and declare the winner if any.
Implement the "runRace()" method to simulate the horse race by calling the "advance()" method of the "horseRace" object and calling the "number()" and "checkWinner()" methods repeatedly until the winner is declared.
Steps for “Main.cpp”
Include the "Race.h" header file.
Create an object "race" of class "Race".
Call the "runRace()" method on the "race" object.
Return 0 to indicate successful termination of the program.


