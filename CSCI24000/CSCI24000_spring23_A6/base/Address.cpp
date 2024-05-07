// Include the required library for input output  
#include <iostream>
// Include the required library for reading to a new file 
#include <fstream>
#include "Address.h"
// define default constuctor for Address class that takes no parameters and just makes a new instance
Address::Address() {}
// define constructor for Address class that takes five string parameters 
Address::Address(const std::string& line1, const std::string& line2, const std::string& city, const std::string& state, const std::string& zip)
// initalizing the member variables of object Address class using the parameters passed in the constructor 
       	: line1_(line1), line2_(line2), city_(city), state_(state), zip_(zip)
{}
// define a method called getAddressLine1 for the Address class 
std::string Address::getAddressLine1() const{
// return the value of private member variable line1_ 
    return line1_;}
// define a method called getAddressLine2 for the Address class
std::string Address::getAddressLine2() const{
// return the value of private member variable line2_
    return line2_;}
// define a method called getCity for the Address class
std::string Address::getCity() const{
// return the value of private member variable city_
    return city_;}
// define a method called getState for the Address class
std::string Address::getState() const{
// return the value of private member variable state_
    return state_;}
// define a method called getZipCode for the Address class
std::string Address::getZipCode() const{
// return the value of private member variable zip_
    return zip_;}
// define a function called setAddressLine1 for Address class that takes constant reference to string object line1 as its parameter
void Address::setAddressLine1(const std::string& line1){
// assign the value of line1 parameter to the private member variable line1_ 
    line1_ = line1;}
// define a function called setAddressLine2 for Address class that takes constant reference to string object line2 as its parameter
void Address::setAddressLine2(const std::string& line2){
// assign the value of line2 parameter to the private member variable line2_
    line2_ = line2;}
// define a function called setCity for Address class that takes constant reference to string object city as its parameter
void Address::setCity(const std::string& city){
// assign the value of city parameter to the private member variable city_
    city_ = city;}
// define a function called setState for Address class that takes constant reference to string object state as its parameter
void Address::setState(const std::string& state){
//assign the value of state parameter to the private member variable state_
    state_ = state;}
// define a function called setZipCode for Address class that takes constant reference to string object zip as its parameter
void Address::setZipCode(const std::string& zip){
//assign the value of zip parameter to the private member variable zip_
    zip_ = zip;}

