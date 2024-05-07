#ifndef DATE_H
#define DATE_H

#include <string>

// Declare a class called Date
class Date {
//Declare a public section for the Date class
public:
// define all the methods and functions, declare default constructor  
    Date();
// Declare the constructor Date with three integer parameters 
    Date(int month, int day, int year);
// Declare constructor that takes string parameter of the date
    Date(std::string date);
// three methods that return month day and year, const because the methods do not modigy the date object 
    int getMonth() const;
    int getDay() const;
    int getYear() const;
// three methods that set the month day and year 
    void setMonth(int month);
    void setDay(int day);
    void setYear(int year);
// Declare method that returns the string representation of the date object in mm/dd/yyy format 
    std::string toString() const;
// Declare private section for Date class
private:
// Declare private variables. only accessible within the class and cannot be modifed from outside the class
    int month_;
    int day_;
    int year_;
};

#endif // DATE_H

