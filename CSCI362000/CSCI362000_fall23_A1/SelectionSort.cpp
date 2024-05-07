//Include the iostream library for input and output
#include <iostream>
//Include the string library for input
#include <string> 
//Use the standard namespace
using namespace std;
//Define a function for selection sort that takes an array and its size as parameters
void selectionSort(int array[], int N) {
//iterate through the array
    for (int i = 0; i < N - 1; ++i) {
//The current element is the minimum
        int minimum = i;
// Find the minimum element in the unsorted part of the array
        for (int j = i + 1; j < N; ++j) {
//Compare elements to find the minimum
            if (array[j] < array[minimum]) {
//Update the index of the minimum element
                minimum = j;
//Swap the minimum element with the current element
                std::swap(array[i], array[minimum]);
            }
        }
    }
}
//Define the main function
int main() {
//Declare a variable to store the length of the array
    int N;
//Prompt the user to enter the length of the array
    std::cout << "Enter the length of the array: ";
//Read the length of the array from the user
    std::cin >> N;
//Check if the entered array length is valid
    if (N <= 0) {
//Display an error message and exit
        std::cout << "Invalid array length." << std::endl;
        return 0;
    }
//Declare an array to store integers    
    int arr[N];
//Prompt the user to enter N integers
    std::cout << "Enter " << N << " integers:" << std::endl;
//Read N integers from the user
    for (int i = 0; i < N; ++i) {
//Declare a string variable for input
        std::string input; 
//Read the input as a string       
        std::cin >> input;
// Convert the input string to an integer
        int num;
//Use try-catch to handle invalid input
        try {
            num = std::stoi(input);
        } catch (std::invalid_argument&) {
//Display an error message for invalid input
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
	    return 0;
        }
//Store the integer in the array      
        arr[i] = num;
    }
//Sort the array using the selectionSort function
    selectionSort(arr, N);
//Display the sorted array in ascending order
    std::cout << "Sorted array in ascending order:" << std::endl;
    for (int i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
//Print a newline character to end the output
    std::cout << std::endl;
//Return 0 to indicate successful execution
    return 0;
}





