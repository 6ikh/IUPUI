
Project Summary 
Begin with a summary of the project. You'll need to include a brief summary as well as a few specific goals and clarifications.

Proposed project title
Golden State Motors  
Longer description of project
This project is a Java-based system for managing a car dealership's inventory and sales operations. The system will allow users to browse, buy, and sell vehicles, as well as trade in their own car for one that is listed. The car dealership will automatically have 5-10 cars that will be removed when bought or traded. I will have system where it will save the user pin and password so the trade in amount is stored 
Intended user	
The intended users of this system are customers of the car dealership.
What problem is the project trying to solve?
The project is trying to solve the problem of managing a car dealership's inventory and sales operations efficiently and effectively. 
Which technologies will you need (files, databases, GUIs?)
The project will require a database to store vehicle and customer information.
I could implement a GUI System if I would like to make it a bit more harder for me but with the lack of knowledge about GUI systems, I would rather have that as a backup option

Data Design
Every program is really about some kind of data. Thinking well about the data is the key to creating a decent program. Try to answer the following questions:

What data is your program really about?
The program is primarily about vehicle and customer data. The vehicle data will just be the price and a few pieces of information will be given like the make, model, mileage, color, and year. Customer data will just be the user pin and the balance they have. 
What is the best way to represent that data? (database, object, arrays)
The best way to represent the data would be through objects, specifically vehicle and User objects.
Will the data need to be persistent? How will you make that happen?
Yes, the data will need to be persistent, and this will be accomplished by using a database to store the information.
Will the data need to be aggregated into a larger structure? How
Yes, the data will need to be aggregated into a larger structure, specifically the dealership's inventory.

Algorithm
Once you've done the previous steps, you should be ready to start putting together your algorithm. Remember, an algorithm is simply a list of instructions written in English that are so detailed that they can be translated to programming code.

Most projects will benefit from an OOP design. Identify the main objects needed in your program. Generally each data element will be a class, and each screen of a GUI will be a class. For each class in your project:



Define the data members - what are the key data elements of the class?
The key data elements of the Vehicle class include make, model, year, mileage, and price. The User object will be one with admin and customer. Admin and Customer will have the pin and password. Admin will be able to see the user pin a password, similar to last week's assignment. 
Describe the initializer - Initializers always create and populate the data members.
The initializer for the Vehicle class will read in parameters for make, model, year, mileage, and price. The initializer for the User class will read in parameters for pin and password. 
Will you read in parameters? Have default values? Both?
It will read in parameters related to the code such as string values for the car 
Describe any other housekeeping that may need to happen in the initializer
The current initializer creates Car objects directly in the code for the viewCurrentInventory method. The isValidUser method currently always returns true, meaning that any user number and password combination will be accepted. 
Define access methods for all data members. Build appropriate getters and setters
The Vehicle class will have getters and setters for make, model, year, mileage, price, and availability. The User class will have getters and setters pin and password.
Define any properties or virtual properties you class may need
There will be no properties or visual properties my class is going to need.
Identify any methods your class will need beyond access modifiers
I do not have any methods that will need beyond access modifiers. Everything is under a method.
Flesh out each method just like the function analysis below
isValidUser(String userNumber, String password): This method takes in a user number and password as arguments and returns a boolean value indicating whether the user number and password are valid or not. In the current implementation, the method always returns true, which means that any user number and password combination will be considered valid. In a real application, this method would typically check the user number and password against a database or other form of authentication system to determine whether they are valid.
viewCurrentInventory(): This method prints out the current inventory of vehicles at Golden State Motors. It first creates Car objects for each vehicle in the inventory, and then stores them in an array of Vehicle objects. The method then loops through the array and prints out information about each vehicle, including its make and model and price.
viewVehicleDescription(): This method allows the user to view the description of a specific vehicle in the inventory. It first prompts the user to enter the vehicle number, and then reads the input using a Scanner object. The method then creates an array of Vehicle objects for the inventory and uses the user's input to select the appropriate vehicle from the array. Finally, the method prints out a description of the selected vehicle, including its make and model, horsepower, top speed, and acceleration.
depositMoney(): This method allows the user to deposit money into their account. It prompts the user to enter the amount of money they want to deposit, reads the input using a Scanner object, and then adds the deposited amount to the user's balance. The method then prints out a message indicating that the deposit was successful and displays the user's updated balance.
withdrawMoney(): This method allows the user to withdraw money from their account. It prompts the user to enter the amount of money they want to withdraw, reads the input using a Scanner object, and then subtracts the withdrawn amount from the user's balance. The method first checks if the user has sufficient funds before proceeding with the withdrawal. If the user's balance is not sufficient, the method prints out an error message and does not perform the withdrawal. If the withdrawal is successful, the method prints out a message indicating that the withdrawal was successful and displays the user's updated balance.
checkBalance(): This method allows the user to check their account balance. It simply prints out the user's current balance.
purchaseVehicle(): This method allows the user to purchase a vehicle from the inventory. It first prompts the user to enter the vehicle number, reads the input using a Scanner object, and then creates an array of Vehicle objects for the inventory. The method then uses the user's input to select the appropriate vehicle from the array and calculates the total cost of the vehicle, including taxes and fees. If the user has sufficient funds to purchase the vehicle, the method subtracts the total cost from the user's balance and prints out a message indicating that the purchase was successful. If the user's balance is not sufficient, the method prints out an error message and does not perform the purchase.


