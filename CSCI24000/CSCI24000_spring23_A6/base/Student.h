#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Address.h"
#include "Date.h"
// Declare a class called Student 
class Student {
//Declare a public section for the Address class
public:
//define constructor for Address class that takes 2 string, 4 integer, and 1 double parameters 
    Student(const std::string& firstName, const std::string& lastName, const Address& address, const Date& birthDate, const Date& completionDate, double gpa, int creditHours);
//Define all functions methods
//this is meant to return first name of student as std::string 
    std::string getFirstName() const;
// this is meant to return last name of student as std:string
    std::string getLastName() const;
// returns the gpa of studetnt as a double 
    double getGpa() const;
// returns the address of student as an address object 
    Address getAddress() const;
// returns the DOB of the student as a date object 
    Date getDateOfBirth() const;
// returns the credit hours completed as an int
    int getCreditHoursCompleted() const;
// returns the date of completion of student as a date object 
    Date getDateOfCompletion() const;

// Declare a private section for the Student class
private:
// stores the first name of the student
    std::string firstName;
// stores the last name of the student
    std::string lastName;
// stores the address of the student 
    Address address;
// stores the dob of the student 
    Date dateOfBirth;
    Date completionDate;
    double gpa;
    int creditHours;
};

#endif // STUDENT_H

