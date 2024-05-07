//Declare a class named "BankAccount"
public class BankAccount {
//Declare a private static variable "balance" and initialize it to 0
    private static double balance = 0;
//Declare a static method "getBalance" that returns the value of "balance"
    public static double getBalance() {
        return balance;
    }
//Declare a static method "deposit" that takes in a parameter "amount" and adds it to the "balance" variable
    public static void deposit(double amount) {
        balance += amount;
    }
//Declare a static method "withdraw" that takes in a parameter "amount" and checks if there is enough balance to withdraw that amount
    public static boolean withdraw(double amount) {
// If there isn't enough balance, return false; else, subtract the "amount" from "balance" and return true
        if (balance < amount) {
            return false;
        }
        balance -= amount;
        return true;
    }
}



