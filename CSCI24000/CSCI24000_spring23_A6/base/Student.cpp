#include <iostream>
#include <fstream>
#include "Student.h"
// define constructor for Address class that takes 2 string, 4 integer, and 1 double parameters 
Student::Student(const std::string& firstName, const std::string& lastName, const Address& address, const Date& birthDate, const Date& completionDate, double gpa, int creditHours)
//initialize the member variables of object Student class using the parameters passed in the constructor 
       	: firstName(firstName), lastName(lastName), address(address), dateOfBirth(birthDate), completionDate(completionDate), gpa(gpa), creditHours(creditHours)
{}
// define a method called getFirstName for the Student class
std::string Student::getFirstName() const{
//return the value of variable firstName
    return firstName;}
// define a method called getLastName for the Student class
std::string Student::getLastName() const{
//return the value of variable lastName
    return lastName;}
// define a method called getGPA for the student class 
double Student::getGpa() const{
// return the value of gpa which will be a double 
      return gpa;}
// define a method called getAddress 
Address Student::getAddress() const{
// return the value of address 
    return address;}
// define a method called getDateOfBirth 
Date Student::getDateOfBirth() const{
// return the value of dateOfBirth 
    return dateOfBirth;}
// define the function getCredit.. that is a member of studen class. it will return type int 
int Student::getCreditHoursCompleted() const{
// return the value of creditHours
    return creditHours;}
// define a method of student class called getDate.. 
Date Student::getDateOfCompletion() const{
// return the value of completionDate
    return completionDate;}

