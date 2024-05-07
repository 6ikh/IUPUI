// Include the input/output stream library
#include <iostream>
// Include the file stream library for reading and writing files
#include <fstream>
// Include the vector library for dynamic array storage.
#include <vector>
// Include the unordered_map library for key-value pair storage
#include <unordered_map>
// Include the algorithm library for algorithms and functions 
#include <algorithm>
// Include the string library for string manipulation
#include <string>
// Include the header file "TimeInterval.h" for the TimeInterval class
#include "TimeInterval.h"
// Include the limits library for limits of integral types
#include <limits>
//Define a custom hash function that takes a constant reference to a string as its parameter
size_t customHash(const std::string& s) {
// Initialize a variable 'hash' to store the computed hash value
    size_t hash = 0;
//Iterate through each character in the input string.
    for (char c : s) {
// Update the hash value using the simple hash algorithm and times it by 31 + the ASCII value of the character 
        hash = (hash * 31) + static_cast<size_t>(c);
    }
//The size_t value is then returned as the hash for the input string
    return hash;
}
//Define a function 'loadDictionary' that takes a constant reference to a string //representing a filename and returns an unordered map of size_t keys to string values
std::unordered_map<size_t, std::string> loadDictionary(const std::string& filename) {
//Create an empty unordered map to store the dictionary data 
    std::unordered_map<size_t, std::string> dictionary;
//Open a file stream using the provided filename
    std::ifstream file(filename);
//Check if the file was successfully opened
    if (!file.is_open()) {
//If not, print an error message and exit the program
        std::cerr << "Error: Unable to open dictionary file." << std::endl;
        exit(1);
    }
//Declare a string variable 'word' to store each word read from the file
    std::string word;
//Read each word from the file using the input stream.
    while (file >> word) {
//Calculate the hash value for the current word using the custom hash function
        size_t hash = customHash(word);
//Insert the word into the dictionary with its hash value as the key
        dictionary[hash] = word;
    }
//Close the file stream
    file.close();
//Return the dictionary
    return dictionary;

}
// Define a function 'levenshteinDistance' that takes two constant references to strings ('word1' and 'word2') and returns an integer representing the Levenshtein distance between the two words.
int levenshteinDistance(const std::string& word1, const std::string& word2) {
// Get the lengths of the two input words and store them in variables 'm' and 'n'.
    const int m = word1.length();
    const int n = word2.length();
// Create a 2D vector 'dp' representing the dynamic programming table with dimensions (m+1) x (n+1) and initialize it with zeros
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
// Populate the dynamic programming table using a nested loop
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
// If 'i' is 0, set the value in the table to 'j'. This handles the base case for the first word being empty
            if (i == 0) {
                dp[i][j] = j;
//If 'j' is 0, set the value in the table to 'i'. This handles the base case for the second word being empty
            } else if (j == 0) {
                dp[i][j] = i;
//If the current characters in both words are the same, take the value from the diagonal in the table
            } else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
// If the characters are different, update the table entry by taking the minimum of the three adjacent values and adding 1
            } else {
                dp[i][j] = 1 + std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
            }
        }
    }
// Return the final Levenshtein distance, which is stored in the bottom-right corner of the table
    return dp[m][n];
}
// Define a function 'findRecommendedWord' that takes a constant reference to a string //('word') and an unordered map ('dictionary') mapping hash values to words. 
// The function returns a string representing the recommended word from the dictionary //based on Levenshtein distance.
std::string findRecommendedWord(const std::string& word, const std::unordered_map<size_t, std::string>& dictionary) {
// Declare a string variable 'recommendedWord' to store the recommended word
    std::string recommendedWord;
// Declare an integer variable 'minDistance' and initialize it with the maximum possible integer value
    int minDistance = std::numeric_limits<int>::max();
// Iterate through each entry in the provided dictionary
    for (const auto& entry : dictionary) {
//Retrieve the word from the dictionary entry
        const std::string& dictWord = entry.second;
//Check if the length of the dictionary word is at least 2 characters and the first characters of 'word' and 'dictWord' match
        if (dictWord.size() >= 2 && word[0] == dictWord[0]) {
//Calculate the Levenshtein distance between 'word' and the current dictionary word
            int distance = levenshteinDistance(word, dictWord);
//Update the minimum distance and recommended word if the calculated distance is less than the current minimum distance
            if (distance < minDistance) {
                minDistance = distance;
                recommendedWord = dictWord;
            }
        }
    }
//Return the final recommended word.
    return recommendedWord;
}
// Define a function 'findWordsWithSameInitialLetters' that takes a constant reference to //a string ('word') and an unordered map ('dictionary') mapping hash values to words 
// The function returns a vector of strings representing words from the dictionary with //the same first two letters as the input word
std::vector<std::string> findWordsWithSameInitialLetters(const std::string& word, const 
// Declare a vector of strings 'suggestions' to store the words with the same initial letters as the input word
std::unordered_map<size_t, std::string>& dictionary) {
    std::vector<std::string> suggestions;
// Iterate through each entry in the provided dictionary
    for (const auto& entry : dictionary) {
//Retrieve the word from the dictionary entry
        const std::string& dictWord = entry.second;
//Check if the length of the dictionary word is at least 2 characters and if the first two letters of 'word' and 'dictWord' match
        if (dictWord.size() >= 2 && word.substr(0, 2) == dictWord.substr(0, 2)) {
//If the condition is met, add the dictionary word to the 'suggestions' vector
            suggestions.push_back(dictWord);
        }
    }
// Return the vector of words with the same initial letters as the input word
    return suggestions;
}
// Define the main function for the program
int main() {
//Specify the filename of the dictionary file.
    std::string dictionaryFile = "Dictionary.txt";
//Load the dictionary from the specified file into an unordered map using custom hashing function
    std::unordered_map<size_t, std::string> dictionary = loadDictionary(dictionaryFile);
//Start a while loop for user interaction
    while (true) {
//Declare a string variable 'userInput' to store user-entered words.
        std::string userInput;
// Prompt the user to enter a word. and give the user the option to exit the program
        std::cout << "Enter a word (Enter 0 to exit): ";
        std::cin >> userInput;
//If statement that takes in userinput and if it is equal to 0
        if (userInput == "0") {
//Ouput a message to the user that the program is exiting
            std::cout << "Exiting program" << std::endl;
            break;
        }
//Compute the hash value for the user input using a custom hash function
        size_t userHash = customHash(userInput);
//Search for the user-entered word in the dictionary based on its hash value
        auto it = dictionary.find(userHash);
//Check if the word exists in the dictionary.
        if (it != dictionary.end()) {
//Print "True" to indicate the word's existence.
            std::cout << "True" << std::endl;
//Measure the time interval for processing using a TimeInterval object.
            TimeInterval timer;
            timer.start();
//Find words in the dictionary with the same initial letters as the user-entered word
            std::vector<std::string> suggestions = findWordsWithSameInitialLetters(userInput, dictionary);
//Stop the timer after processing.
            timer.stop();
//Display the suggestions and the processing time.
            for (const std::string& suggestion : suggestions) {
                std::cout << suggestion << std::endl;
            }
            std::cout << timer.GetInterval() << " micro-sec" << std::endl;
//Else the word doesn't exist in the dictionary
        } else {
//Find a recommended word based on Levenshtein distance

            std::string recommendedWord = findRecommendedWord(userInput, dictionary);
//Check if a recommended word is found
            if (!recommendedWord.empty()) {
//Prompt the user to confirm the recommended word
                std::cout << "Do you mean '" << recommendedWord << "'? (yes/no): ";
                std::string userResponse;
                std::cin >> userResponse;
//Check user response for confirmation.
                if (userResponse == "yes") {
//Print "True" to indicate the word's existence
                    std::cout << "True" << std::endl;
//Measure the time interval for processing using a TimeInterval object
                    TimeInterval timer;
                    timer.start();
//Find words in the dictionary with the same initial letters as the recommended word
                    std::vector<std::string> suggestions = findWordsWithSameInitialLetters(recommendedWord, dictionary);
//Stop the timer after processing.
                    timer.stop();
//Display the suggestions and the processing time
                    for (const std::string& suggestion : suggestions) {
                        std::cout << suggestion << std::endl;
                    }
                    std::cout << timer.GetInterval() << " micro-sec" << std::endl;
//The user does not confirm the recommended word
                } else {
//Print "False" to indicate that the user did not confirm the recommended word
                    std::cout << "False" << std::endl;
                }
//Else the recommended word is not found
            } else {
//Print false to indicate that the user input did not have any resemblance 
                std::cout << "False." << std::endl;
            }
        }
    }
//Return 0 to show successful program execution
    return 0;
}
