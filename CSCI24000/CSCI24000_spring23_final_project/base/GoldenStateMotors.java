//import Scanner library
import java.util.Scanner;
//import Arrays library
import java.util.Arrays;
//import ArrayList library
import java.util.ArrayList;
//create a class called GoldenStateMotors
public class GoldenStateMotors {
//create the main function
    public static void main(String[] args) {
//create a new scanner object
        Scanner scanner = new Scanner(System.in);
//create a variable for user number
        String userNumber;
//create a variable for password
        String password;
//print out the welcome message
        System.out.println("Welcome to Golden State Motors!");
//print out the prompt to enter login information
        System.out.println("Please Enter Your Login Information:");
//print out the prompt to enter user number
        System.out.print("User #: ");
//store the user number input in a variable
        userNumber = scanner.next();
//print out the prompt to enter password
        System.out.print("Password: ");
//store the password input in a variable
        password = scanner.next();
//if the user number and password are valid, continue to menu
        if (isValidUser(userNumber, password)) {
//create a variable for the user's menu selection
            int option;
//create a loop for the menu
            do {
//print out the menu options
                System.out.println("How Can We Serve You Today?");
                System.out.println("(1) View Current Inventory");
                System.out.println("(2) View Vehicle Description");
                System.out.println("(3) Deposit Money");
                System.out.println("(4) Withdraw Money");
                System.out.println("(5) Check Balance");
                System.out.println("(6) Purchase a Vehicle");
                System.out.println("(7) Logout");
//print out the prompt to enter menu selection

                System.out.print("Enter your choice (1-7): ");
//store the menu selection in a variable
                option = scanner.nextInt();
//perform an action based on the menu selection
                switch (option) {
//if option 1 is selected, view current inventory
                    case 1:
                        viewCurrentInventory();
                        break;
//if option 2 is selected, view vehicle description
                    case 2:
                        viewVehicleDescription();
                        break;
//if option 3 is selected, deposit money
                    case 3:
                        depositMoney();
                        break;
//if option 4 is selected, withdraw money
                    case 4:
                        withdrawMoney();
                        break;
//if option 5 is selected, check balance
                    case 5:
                        checkBalance();
                        break;
//if option 6 is selected, purchase a vehicle
                    case 6:
                        purchaseVehicle();
                        break;
//if option 7 is selected, log out
                    case 7:
                        System.out.println("Logged out successfully!");
                        break;
//if an invalid option is selected, prompt to try again
                    default:
                        System.out.println("Invalid option, please try again.");
                }
//While option is not equal to 7
            } while (option != 7);
//Anything else, print out a invalid user number or password 
        } else {
            System.out.println("Invalid user number or password, please try again.");
        }
    }
//create a function to check if the user number and password are valid
    private static boolean isValidUser(String userNumber, String password) {
        return true;
    }

//create a function to view the current inventory
    private static void viewCurrentInventory() {
//print out the current inventory header
        System.out.println("Current Inventory:");
////create car objects for the current inventory
        Car car1 = new Car("Dodge", "Hellcat", 717, 199, 3.6);
        Car car2 = new Car("Porsche", "911 GT3", 502, 197, 3.2);
        Car car3 = new Car("Mercedes", "E63s", 603, 186, 3.3);
        Car car4 = new Car("BMW", "X5M", 617, 177, 3.8);
        Car car5 = new Car("Mercedes", "G63", 577, 149, 4.4);
//create an array of Vehicles objects for the current inventory
        Vehicle[] vehicles = {car1, car2, car3, car4, car5};
//loop through the current inventory array and print out each car's information
        for (int i = 0; i < vehicles.length; i++) {
//For each iteration, print the vehicle number, make and model, and price 
            System.out.println((i+1) + ". " + vehicles[i].getMakeandModel() + ": " + "$" + vehicles[i].getPrice());
        }
    }
//Implement the viewVehicleDescription method.
    private static void viewVehicleDescription() {
//Initialize a Scanner object to read input from the user input
    Scanner scanner = new Scanner(System.in);
//Prompt the user to enter the vehicle number.
    System.out.print("Enter the vehicle number: ");
//Read the vehicle number from the user 
    int vehicleNumber = scanner.nextInt();
//Create an array of Vehicle objects, containing various car models.
    Vehicle[] vehicles = {
            new Car("Dodge", "Hellcat", 717, 199, 3.6),
            new Car("Porsche", "911 GT3", 502, 197, 3.2),
            new Car("Mercedes", "E63s", 603, 186, 3.3),
            new Car("BMW", "X5M", 617, 177, 3.8),
            new Car("Mercedes", "G63", 577, 149, 4.4)
    };
//If the vehicle number entered is within the valid range, print the vehicle description 
    if (vehicleNumber >= 1 && vehicleNumber <= vehicles.length) {
        System.out.println("Vehicle Description:");
//Print the string representation of the Vehicle object at the specified index in the array "vehicles".
        System.out.println(vehicles[vehicleNumber-1].toString());
    } else {
//Otherwise, print an error message indicating that the vehicle number is invalid.
        System.out.println("Invalid vehicle number, please try again.");
    }
}
//Implement the depositMoney method.
private static void depositMoney() {
//Initialize a Scanner object to read input from the user 
    Scanner scanner = new Scanner(System.in);
//Prompt the user to enter the amount to deposit
    System.out.print("Enter the amount to deposit: ");
//Read the amount to deposit from the user 
    double amount = scanner.nextDouble();
//Call the "deposit" method of the "BankAccount" object, passing in the amount to deposit
    BankAccount.deposit(amount);
//Print a success message to the user, along with the current balance of the account
    System.out.println("Deposit successful! Current balance: " + "$" + BankAccount.getBalance());
}
//Implement the withdrawMoney method
private static void withdrawMoney() {
//Initialize a Scanner object to read input from the user 
    Scanner scanner = new Scanner(System.in);
//Prompt the user to enter the amount to withdraw
    System.out.print("Enter the amount to withdraw: ");
//Read the amount to withdraw from the user 
    double amount = scanner.nextDouble();
//Call the "withdraw" method of the "BankAccount" object, passing in the amount to withdraw
    boolean success = BankAccount.withdraw(amount);
//If the withdrawal is successful, print a success message to the console, along with the current balance of the account
    if (success) {
        System.out.println("Withdrawal successful! Current balance: " + "$" + BankAccount.getBalance());
//If the withdrawal fails due to insufficient funds, print an error message to the user 
    } else {
        System.out.println("Withdrawal failed, insufficient balance.");
    }
}
//Implement the checkBalance method
private static void checkBalance() {
//Print the current balance of the account to the user 
    System.out.println("Current balance: " + "$" +BankAccount.getBalance());
}
//Implement the purchaseVehicle method 
private static void purchaseVehicle() {
//Initialize a Scanner object to read input from the user 
    Scanner scanner = new Scanner(System.in);
//Prompt the user to enter the vehicle number
    System.out.print("Enter the vehicle number: ");
//Read the vehicle number from the user 
    int vehicleNumber = scanner.nextInt();
//Create an array of Vehicle objects representing the inventory
    Vehicle[] vehicles = {
        new Car("Dodge", "Hellcat", 717, 199, 3.6),
        new Car("Porsche", "911 GT3", 502, 197, 3.2),
        new Car("Mercedes", "E63s", 603, 186, 3.3),
        new Car("BMW", "X5M", 617, 177, 3.8),
        new Car("Mercedes", "G63", 577, 149, 4.4)
    };
//Check if the vehicle number entered is within the valid range of options
    if (vehicleNumber >= 1 && vehicleNumber <= vehicles.length) {
//If the vehicle number is valid, retrieve the corresponding Vehicle object from the array
        Vehicle vehicle = vehicles[vehicleNumber-1];
//Get the price of the selected vehicle
        double price = vehicle.getPrice();
//Check if the balance of the account is sufficient to purchase the selected vehicle
        if (BankAccount.getBalance() >= price) {
//If the balance is sufficient, withdraw the price of the vehicle from the account
            BankAccount.withdraw(price);
//Print a success message to the console, indicating the make and model of the purchased vehicle and its price
            System.out.println("Purchase successful! You bought a " + vehicle.getMakeandModel() + " for " + "$" + price);
// Remove the purchased vehicle from the inventory
            vehicles = removeVehicleFromInventory(vehicles, vehicleNumber-1);
//If the balance is insufficient, print an error message to the console
        } else {
            System.out.println("Purchase failed, insufficient funds.");
        }
//If the vehicle number is invalid, print an error message to the console


    } else {
        System.out.println("Invalid vehicle number, please try again.");
    }
}
//Create a method called removeVehicleFromInventory that takes in an array of Vehicle objects and an integer index as parameters
private static Vehicle[] removeVehicleFromInventory(Vehicle[] vehicles, int index) {
//Create a new Vehicle array called newVehicles with a length of one less than the length of the input vehicles array
    Vehicle[] newVehicles = new Vehicle[vehicles.length - 1];
//Initialize an integer variable newIndex to 0
    int newIndex = 0;
//Use a for loop to iterate through the vehicles array
    for (int i = 0; i < vehicles.length; i++) {
//If the current index i is not equal to the input index
        if (i != index) {
//Set newVehicles[newIndex] equal to vehicles[i].Increment newIndex by 1.
            newVehicles[newIndex] = vehicles[i];
            newIndex++;
        }
    }
//Return the newVehicles array
    return newVehicles;
}
}




