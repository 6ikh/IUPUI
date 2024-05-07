Goals - What is the goal of the program or function?
The goal of the program is to simulate a horse race with 5 horses. Each horse has a chance to advance forward in the race each round and the race continues until one horse reaches the end of the race. A coin flip system is used to decide if the horse will go forward or not. The program also prints out the current state of the race, showing the position of each horse. The user is prompted to enter a random seed, which is used to initialize the random number generator for copied results.
Input - What (if any) input does the function or program accept?  Are there specific data types or ranges?
The program accepts the seed value 700 for the program to output the same race. 
Output - What (if any) output does the function or program return
The program returns the output of a horse race simulation that is displayed in the console. The output shows the progress of the horses in the race and the number of the horse, and at the end of the race it prints the winner of the race.
Steps - What are the steps (written in English) necessary to solve this problem.  This should NOT be programming code, but each line should be specific enough to be translated to a line or two of code in your target language.
Steps for “void advance()” 
Create a for loop and first Initialize a variable "i" to 0
While i is less than the total number of horses
Generate a random number between 0 and 1 by using the "rand()" function and taking the remainder when divided by 2.
If the generated number is equal to 0, increment the "horses[i]" by 1.
Increment the variable "i" by 1
Repeat step 2 - 5 until "i" is equal to the total number of horses.
Steps for “void number()”
Create a nested for loop
Initialize variables i and j to 0
Iterate over the array 'horses' starting from i=0, going until i is less than 'HORSES'
Within the first for loop, iterate from j=0 to j less than the value at index i of array 'horses'
Inside the second for loop, output a '.' to the console
After the second for loop, output the horse number (i)
Iterate from j = value at index i of array 'horses' to j is less than 'TRACK'
Within the third for loop, output a '.' to the console
After the third for loop, output a newline
Output one final newline
End the function
Steps for “void checkwinner()”
Initialize a variable "winner" to 0
Create a for loop
Loop through all the horses (from 0 to HORSES)
For each horse, compare the position of the current horse with the position of the horse at the index "winner"
If the current horse is ahead of the horse at index "winner", set the variable "winner" to the current horse's index
After the loop, check if the horse at index "winner" has reached or exceeded the TRACK length
If true, announce the winner by printing "Horse [winner+1] wins!" and set the variable "raceKeepGoing" to false
If false, do nothing and continue the race.
Steps for “int main”
Initialize an integer variable "seed"
Prompt the user to enter a random seed and store the input in the "seed" variable
Use the "srand()" function to seed the random number generator with the value of "seed"
Create a loop that continues as long as "raceKeepGoing" is true
Inside the loop, call the "advance()" function to advance the race
Call the "number()" function to generate a random number
Call the "checkwinner()" function to check if there is a winner
Repeat steps 5-7 until "raceKeepGoing" is false
Exit the loop and return 0 to indicate successful execution of the program.

