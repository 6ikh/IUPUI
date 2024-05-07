//Import class package used to write character files 
import java.io.PrintWriter;
//Import class package used to handle input and output errors
import java.io.IOException;
//Import class package used to store dynamically sized collection of elements
import java.util.ArrayList;
//Import class package used to iterate over a collection elements 
import java.util.Iterator;
//Import class package used to read input from the user 
import java.util.Scanner;

//Declare public class called main
public class main{
//Declare public main method that takes an array of strings as a parameter named para 
    public static void main(String[] args) throws IOException {
//Created an 'ArrayList' object called 'userlist' of type 'atm' to store information
        ArrayList<atm> userlist = new ArrayList<>();
//Created a 'Scanner' object called userinput to read input from the standard input stream
        Scanner userinput = new Scanner(System.in);
///Declare a variable 'input' of type 'String' No value of the variable is initialized yet and will be used to store user input later 
        String input;
//New 'atm' object object to 'userlist' arraylist with the id, pin, isAdmin,starting balance and stating balance along with starting interest rate
        userlist.add(new atm("00000", 12345, true, new checking(0),new saving(0, 2)));
//New 'atm' object object to 'userlist' arraylist with the id, pin, isAdmin,starting balance and stating balance along with starting interest rate
        userlist.add(new atm("1234", 1234, false, new checking(0), new saving(0, 2)));
//New 'atm' object object to 'userlist' arraylist with the id, pin, isAdmin,starting balance and stating balance along with starting interest rate
        userlist.add(new atm("4321", 4321, false, new checking(0), new saving(0, 2)));
//New 'atm' object object to 'userlist' arraylist with the id, pin, isAdmin,starting balance and stating balance along with starting interest rate
        userlist.add(new atm("0731", 0731, false, new checking(0), new saving(0, 2)));
//Start with a do while loop
        do {
//Display a message to prompt the user to enter their account number
            System.out.print("enter your account #: ");
//Read the user's account number and store it in a String variable called account1
            String account1 = userinput.next();
//Display a message to prompt the user to enter their password
System.out.print("enter your password: ");
//Read the user's password and store it in an integer variable called password
            int password = userinput.nextInt();
 //declare integer point to 0
            int point = 0;
 //Begin a for loop that will iterate through each element of the userlist ArrayList
            for (int i = 0; i < userlist.size(); i++) {
 //If the current element's account number matches account1 and its pin matches password, do the following
                if (userlist.get(i).getAccountNumber().equals(account1)
                        && userlist.get(i).getPin() == password) {
//Set the variable point to 1
                    point = 1;
//Check if the current user is an admin 
                    if (userlist.get(i).isAdmin()) {
//Declare an integer called input2
                        int input2;
//Begin a do-while loop
                        do {
//Display all of the menu options 
                            System.out.println("(1) Add a user\n" + "(2) Delete a user ( the account must be empty)\n" + "(3) List all users\r\n" + "(4) Apply interest to all saving accounts\n" + "(5) Exit");
//Display a message to the user to choose a option from the menu 
                            System.out.print("Please select option: ");
//Read the user's input and store it in the input2 variable 
                            input2 = userinput.nextInt();
//Begin a switch-case statement based on the value of input2 variable. switch used to compare it with constant values until it matches with the first case 
                            switch (input2) {
//If input2 is 1, execute the code in this case 
                                case 1:
//Display a message to the user to enter an account number
                                    System.out.print("enter account #: ");
//Read the user's input for the account number and store it in the accountnumber variable
                                    String accountnumber = userinput.next();
//Display a message to the user to enter a password
                                    System.out.print("enter password: ");
//Read the user's input for the password and store it in the userpassword variable
                                    int userpassword = userinput.nextInt();
//Display a message to the user to enter a balance for the account
                                    System.out.print("Enter a balance for the checking account: ");
//Read the user's input for the checking account balance and store it in the balance variable
                                    int balance = userinput.nextInt();
//Display a message to the user to enter a balance for the saving account
                                    System.out.print("Enter a balance for the saving account: ");
//Read the user's input for the saving account balance and store it in the balance2 variable
                                    float balance2 = userinput.nextFloat();
//Display a message to the user to enter an interest rate
                                    System.out.print("Enter interest rate: ");
//Read the user's input for the interest rate and store it in the interest variable.
                                    float interest = userinput.nextFloat();
//Create a new atm object with the user's input and add it to the userlist array
                                    userlist.add(new atm(accountnumber, userpassword, false,
//Checking object representing the user's checking account and it take one argument which is the balance
                                            new checking(balance),
//Saving object representing the user's saving account which takes two arguments which is the balance and the interest
                                            new saving(balance2, interest)));
//End the case statement
                                    break;
//If input2 is 2, execute the code in this case
                                case 2:
//Display a message to the user to enter the account number to delete 
                                    System.out.print("Enter account # to delete: ");
//Get user input for account number and store it in a string variable
                                    String accountnumber2 = userinput.next();
//set integer point1 to value 0
                                    int point1 = 0;
//Create an iterator for the userlist
                                    Iterator<atm> it = userlist.iterator();
//Loop through the iterator while it has a next element
                                    while (it.hasNext()) {
//Check if the current element's account number matches the user input
                                        if (it.next().getAccountNumber().equals(accountnumber2)){
//Set variable point1 to value 1 
                                                point1 = 1;
//Remove the current element from the userlist
                                                it.remove();
                                                }
                                        }
//If the variable point1 is equal to value 1 
                                        if (point1 == 1){
//display a message to the user that the user was removed successfully 
                                                System.out.println("user removed");
                                        }
                                        else{
//Display a message to the user that the user with account number was not found 
                                                System.out.println("User " + accountnumber2 + " not found!");
                                        }
                                        break;
//If he input2 is 3, execute the code in this case 
                                case 3:
//Use a for loop to iterate through the userlist
                                        for (int l = 0; l < userlist.size(); l++){
//Display a message to the user the account number 
                                                System.out.println("user " + userlist.get(l).getAccountNumber());
                                        }
//End the case statement
                                        break;
//if the input2 is 4, then execute the code in case 4 
                                case 4:
//Apply interest of 6% on all savings accounts for the selected user
                                        for (int k = 0; k < userlist.size(); k++){
                                                userlist.get(k).getSavingsAccount().applyInterest(6);
                                        }
//End the case statement
                                        break;
//If the input2 is 5, execute the code 
                                case 5:
//Display the message to the user that they have been logged out 
                                        System.out.println("you have been logged out!");
                                        break;
//Handle default case for invalid user input
                                        default:
//Display a message to the user that the option is not right
                                                System.out.println("Invalid choice!!");
                                                break;
                                        }
//The loop continues to execute until the value of input2 is not equal to 5.
                                        } while (input2 != 5);
                                        }
                                        else
                                        {
//If the previous condition is not met, create a variable called "input2" this loop continues to execute until the value of input2 is not equal to 5.
                                        int input2;
                                        do{
//Display a message to the user for the menu options 
                                                System.out.println("\n1. Get checking balance\n"+ "(2) Deposit into checking\n" + "(3) Withdraw from checking\n" + "(4) Get savings balance\n"     + "(5) Deposit into savings\n" + "(6) Withdraw from savings\n" + "(7) Exit");
//Display a message to the user to pick a option 
                                                System.out.print("Please select any option: ");
//Get user input for the menu option selected
                                                input2 = userinput.nextInt();
//Handle user input using switch case
                                        switch (input2){
//Display the balance of the checking account
                                                case 1:
//Display the checking balance amount 
                                                        System.out.println("Checking balance: " + userlist.get(i).getCheckingAccount().getBalance());
                                                        break;
//Display a message to the user to enter the desired amount to deposit 
                                                case 2:
                                                        System.out.print("Enter amount to deposit: ");
//declare a new variable called amount of type float and assign it the value entered by the user
                                                        float amount = userinput.nextFloat();
//update the balance of the user's checking account by adding the deposited amount
                                                        userlist.get(i).getCheckingAccount().deposit(amount);
                                                        break;
//Display a message to the user to enter the desired amount to withdraw 
                                                case 3:
                                                        System.out.print("Enter amount to withdraw: ");
//declare a new variable called amount1 of type float and assign it the value entered by the user
                                                        float amount1 = userinput.nextFloat();
//update the balance of the user's checking account by withdrawing the withdraw amount
                                                        userlist.get(i).getCheckingAccount().withdraw(amount1);
                                                        break;
//Display a message to the user that their saving account balance is the current savings account balance
                                                case 4:
                                                        System.out.print("You savings account balance is: " + userlist.get(i).getSavingsAccount().getBalance());
                                                        break;
//Display a message to the user how much money they want to add to their savings account 
                                                case 5:
                                                        System.out.print("Enter amount to deposit: ");
//declare a new variable called amount3 of type float and assign it the value entered by the user
                                                        float amount3 = userinput.nextFloat();
//update the balance of the user's savings account by adding the deposited amount

                                                        userlist.get(i).getSavingsAccount().deposit(amount3);
                                                        break;
//Display a message to the user to enter the amount to withdraw 
                                                case 6:
                                                        System.out.print("Enter amount to withdraw: ");
//declare a new variable called amount4 of type float and assign it the value entered by the user
                                                        float amount4 = userinput.nextFloat();
//update the balance of the user's savings account by withdrawing the withdraw amount
                                                        userlist.get(i).getSavingsAccount().withdraw(amount4);
                                                        break;
//Display a message to the user that they are logged out 
                                                case 7:
                                                        System.out.println("Thank you for visiting!");
                                                        break;
//For any other option, display "incorrect option!! Try again"
                                                default:
                                                        System.out.println("incorrect option!! Try again\n");
//End the case statement
                                                        break;
                                                        }
//This do-while loop executes the statements inside the block until the input value of input2 is not equal to 7
                                                } while (input2 != 7);
                                        }
                                }
                        }
//this conditional statement checks whether the value of the point variable is equal to zero
        if (point == 0){
//This line outputs "user unknown" message to the console when the variable equals 0
                System.out.println("user unknown");
        }
//Display a message to the user if they want to continue or not
                System.out.println("Do you want to continue yes or no");
// read the input value from the user and assign it to the input variable.
                input = userinput.next();}
//This do-while loop executes the statements inside the block until the user enters "no" (ignoring the case) when prompted to continue or not
        while (!input.equalsIgnoreCase("no"));
//creates a new PrintWriter object named fw that writes to a file named "users.txt"
PrintWriter fw = new PrintWriter("users.txt");
//declare an integer variable size and initialize it with the size of the userlist list
int size = userlist.size();
//start a for loop that iterates from 0 to the size of userlist list - 1
for (int i = 0; i < size; i++) {
//get the accountNumber attribute of the ‘i’ th element of the userlist list and assign it to the account variable.
    String account = userlist.get(i).getAccountNumber();
//get the pin attribute of the ‘i’ th element of the userlist list, convert it to a string and assign it to the password variable.
    String password = Integer.toString(userlist.get(i).getPin());
//get the balance attribute of the CheckingAccount object of the ‘i’ th element of the userlist list, convert it to a string and assign it to the Checking variable.
    String Checking = Double.toString(userlist.get(i).getCheckingAccount().getBalance());
//get the balance attribute of the SavingsAccount object of the ith element of the userlist list, convert it to a string and assign it to the Savings variable.
    String Savings = Double.toString(userlist.get(i).getSavingsAccount().getBalance());
//create a string acc by combining the account and password variables 
    String acc = "Account Number: " + account + " password: " + password;
//create a string chec by combining the Checking and Savings variables 
    String chec = " CheckingAccount Balance: " + Checking + " Savings Account Balance: " + Savings;
//create a string data by combining the acc and chec variables with a newline character at the end
    String data = acc + chec + "\n";
//write the string data to the file using the fw PrintWriter object.
    fw.write(data);
}
// close the printwriter object
fw.close();
}
}


