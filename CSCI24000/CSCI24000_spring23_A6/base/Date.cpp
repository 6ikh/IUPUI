// include the header file Date.h which contains the declaration of the Date class and its member functions.
#include "Date.h"
// include the standard C library header file 
#include <cstdlib>
// include the standard C++ header file sstream. it provides classes and functions for working with input and output streams
#include <sstream>

// initialize a new Date object with default values for the month, day, and year.
Date::Date(): month_(0), day_(0), year_(0) {}
// initialize a new Date object with the given month, day, and year.
Date::Date(int month, int day, int year): month_(month), day_(day), year_(year) {}

// Start the Date::Date constructor with a single string parameter date
Date::Date(std::string date) {
// Declare an array parts of 3 strings to hold the month, day and year components of the date string
    std::string parts[3];
// Declare a std::stringstream object ss initialized with the input date string
    std::stringstream ss(date);

// Declare an integer i and initialize it to 0 
        int i = 0;
// Check the streams state. The while loop continues to iterate while there are still characters in std::stringstream.
    while (ss.good()) {
//Declare a string variable substr.it is declared to store the substrings that are extracted from the input string date using the std::getline() function
        std::string substr;
//Use getline() function to extract characters from ss until a delimiter ('/') is encountered and store it in substr.
        std::getline(ss, substr, '/');
//Store the value of substr in the array named parts at index i.
        parts[i] = substr;
//Increment the value of i by 1.
        i++;
    }
//Convert the string value in parts[0] to an integer using atoi function and store the result in the month_ variable
        month_ = atoi(parts[0].c_str());
//Convert the string value in parts[1] to an integer using atoi function and store the result in the day_ variable
  	day_ = atoi(parts[1].c_str());
//Convert the string value in parts[2] to an integer using atoi function and store the result in the year_ variable 
	year_ = atoi(parts[2].c_str());
}
//define a member function called getMonth() that returns an integer value representing the month of the date object
int Date::getMonth() const {

// return the private variable month_
return month_;}

// define a member function called getDay() for the Date class, which returns the day value of a Date object
int Date::getDay() const {

// return the private variable day_
return day_;}

//define a member function called getYear() for the Date class, which returns the value of the year value of the Date object
int Date::getYear() const {

// return the private variable year_
return year_;}

//define a member function called setMonth that takes an integer parameter month
void Date::setMonth(int month) {

//sets the value of the month_ variable to the value of month
month_ = month;}

//define a member function called setDay that takes an integer parameter day
void Date::setDay(int day) {

//sets the value of the day_ variable to the value of day
day_ = day;}

//define a member function called setYear that takes an integer parameter year
void Date::setYear(int year) {

//sets the value of the year_ variable to the value of year
year_ = year;}

//define a member function called toString() 
std::string Date::toString() const {

//Create an object convertMonth of type ostringstream which is used to convert month to string
        std::ostringstream convertMonth;
// Create an object convertDay of type ostringstream which is used to convert day to string
        std::ostringstream convertDay;
//Create an object convertYear of type ostringstream which is used to convert year to string 
        std::ostringstream convertYear;
//Convert the integer value of month_ to a string and store it in the object convertMonth 
        convertMonth << month_;
//Convert the integer value of day_ to a string and store it in the object convertDay.
        convertDay << day_;
// Convert the integer value of year_ to a string and store it in the object convertYear.
        convertYear << year_;

//Declare a string variable month and initialize it to the string value returned by the str() method of the convertMonth object
        std::string month = convertMonth.str();
//Declare a string variable day and initialize it to the string value returned by the str() method of the convertDay object
        std::string day = convertDay.str();
//Declare a string variable year and initialize it to the string value returned by the str() method of the convertYear object.
        std::string year = convertYear.str();
// Return month variable, day, and year seperated by "/"
        return month + "/" + day + "/" + year;
}

