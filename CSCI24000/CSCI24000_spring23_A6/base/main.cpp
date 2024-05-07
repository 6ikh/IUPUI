// Include the required library for input output  
#include <iostream>
// Include the required library for reading to a new file 
#include <fstream>
// Include the required library for strings
#include <string>
// Include the respected h files which contain the class definitions for the Student, Address, and Date classes. 
#include "Student.h"
#include "Address.h"
#include "Date.h"
// Include the stringstream and standard c library
#include <sstream>
#include <cstdlib>

// Define the main function
int main() {
// Declare an input file stream object inputFile to read data from the file student.dat
    std::ifstream inputFile("students.dat");
// Declare two output file stream objects outputFile and shortReportOutputFile to write data to two separate files 
    std::ofstream outputFile("fullReport.txt");
    std::ofstream shortReportOutputFile("shortReport.txt");
//Declare variables to store the student's information 
    std::string firstName, lastName, addressLine1, addressLine2, city, state, zipCode, temp, dob, completionDate, GPA, creditHours;
    int monthOfBirth, dayOfBirth, yearOfBirth, monthOfCompletion, dayOfCompletion, yearOfCompletion;
    int creditHoursCompleted;

//While loop that reads each line of the input file and assigns it to the variable temp
    while (std::getline(inputFile, temp)) {
//Creates an array called parts that can hold up to eleven strings,stores the comma-separated values from each line of the input file.
        std::string parts[11];
//stringstream object called ss that is initialized with the current line of the input file temp
        std::stringstream ss(temp);
//the variable i is declared and initialized to zero
        int i = 0;
//While loop that reads each comma-separated value from the stringstream object ss and assigns it to the parts array at the current index i
        while (getline(ss, parts[i], ',')) {
//increment the value of the variable i after each comma-separated value is read 
            i++;
        }
//Assign the value at index zero of the parts array to the variable lastName
        lastName = parts[0];
//Assign the value at index one of the parts array to the variable firstName
        firstName = parts[1];
//Assign the value at index two of the parts array to the variable addressLine1
        addressLine1 = parts[2];
//Assign the value at index three of the parts array to the variable addressLine2
        addressLine2 = parts[3];
//Assign the value at index four of the parts array to the variable city
        city = parts[4];
//Assign the value at index five of the parts array to the variable state
        state = parts[5];
//Assign the value at index six of the parts array to the variable zipCode
        zipCode = parts[6];
//Assign the value at index seven of the parts array to the variable dob
        dob = parts[7];
//Assign the value at index eight of the parts array to the variable completionDate.
        completionDate = parts[8];
//Assign the value at index nine of the parts array to the variable GPA.
        GPA = parts[9];
//Assign the value at index ten of the parts array to the variable creditHours.
        creditHours = parts[10];
// Create an Address object using the address information 
        Address address(addressLine1, addressLine2, city, state, zipCode);
// Create Date object using the date of birth information 
        Date date(dob);
// Create one more date object using the completion date information 
        Date compDate(completionDate);
// Create a Student object using the student's information, including the Address and Date objects. atof is for: string to a double float and atoi is for: string to int. 
        Student student(firstName, lastName, address, date, compDate, atof(GPA.c_str()), atoi(creditHours.c_str()));
//Output the student's first name to the outputFile
        outputFile << "First Name: " << student.getFirstName() << "\n";
//Output the student's last name to the outputFile.
        outputFile << "Last Name: "<< student.getLastName() << "\n";
//Output the student's last name followed by a comma and then their first name to the shortReportOutputFile
        shortReportOutputFile << student.getLastName() << ", " << student.getFirstName() << "\n";
//Output the student's address line 1 to the outputFile
  	outputFile << "Address line 1: " << student.getAddress().getAddressLine1() << "\n";
//Output the student's address line 2 to the outputFile
  	outputFile << "Address line 2: " << student.getAddress().getAddressLine2() << "\n";
//Output the student's city to the outputFile
  	outputFile << "City: " << student.getAddress().getCity() << "\n";
//Output the student's state to the outputFile
  	outputFile << "State: " << student.getAddress().getState() << "\n";
//Output the student's zip code to the outputFile
  	outputFile << "Zip Code: " << student.getAddress().getZipCode() << "\n";
//Output the student's date of birth month to the outputFile
  	outputFile << "Date of birth month: " << student.getDateOfBirth().getMonth() << "\n";
//Output the student's date of birth day to the outputFile
  	outputFile << "Date of birth day: " << student.getDateOfBirth().getDay() << "\n";
//Output the student's date of birth year to the outputFile
	outputFile << "Date of birth year: " << student.getDateOfBirth().getYear() << "\n";
//Output the student's date of completion month to the outputFile
  	outputFile << "Date of completion month: " << student.getDateOfCompletion().getMonth() << "\n";
//Output the student's date of completion day to the outputFile
  	outputFile << "Date of completion day: " << student.getDateOfCompletion().getDay() << "\n";
//Output the student's date of completion year to the outputFile
	outputFile << "Date of completion year: " << student.getDateOfCompletion().getYear() << "\n";
//Output the student's GPA to the outputFile
	outputFile << "GPA: " << student.getGpa() << "\n";
//Output the student's credit hours completed to the outputFile
  	outputFile << "Credit hours completed: " << student.getCreditHoursCompleted() << "\n\n";
//Output a line of underscores to the outputFile 
  	outputFile << "________________________________" << "\n";
    }
// Close the Inputfile student.dat
    inputFile.close();
// Close the OutputFile fullReport.txt
    outputFile.close();
// Close the OutputFile shortReport.txt
    shortReportOutputFile.close();
// End the program by returning zero 
    return 0;
}

