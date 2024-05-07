#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
// Declare a class called Address
class Address {

//Declare a public section for the Address class
public
	Address();
// Declare a parameterized constructor for the Address class that takes in 5 const std::string& arguments
	Address(const std::string& line1, const std::string& line2, const std::string& city, const std::string& state, const std::string& zip);
// Declare a public member function that returns the first line of the address 
	std::string getAddressLine1() const;
//Declare a public member function that returns the second line of the address 
	std::string getAddressLine2() const;
// Declare a public member function that returns the city of the address
	std::string getCity() const;
//Declare a public member function that returns the state of the address
	std::string getState() const;
//Declare a public member function that returns the zip code of the address
	std::string getZipCode() const;
//Define a function called setAddressLine1 that takes a constant reference to a string called line1  
	void setAddressLine1(const std::string& line1);
//Define a function called setAddressLine2 that takes a constant reference to a string called line2
	void setAddressLine2(const std::string& line2);
//Define a function called setCity that takes a constant reference to a string called city
	void setCity(const std::string& city);
//Define a function called setState that takes a constant reference to a string called state 
	void setState(const std::string& state);
//Define a function called setZipCode that takes a constant reference to a string called zip
	void setZipCode(const std::string& zip);

// define private section of the address class that contains 5 private member variables that are std::string types  
private:
// represents address line 1 details 
	std::string line1_;
// represents address line 2 details 
	std::string line2_;
// represents city details
	std::string city_;
// represents state details
	std::string state_;
// represents zipcode details 
	std::string zip_;

};
// The #endif statement marks the end of the header file and ensures that the content in the file is included only once.
#endif



