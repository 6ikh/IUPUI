//Define a public class named "checking"
public class checking {
//Define a private instance variable named "balance" of type float
    private float balance;
//Define a private instance variable named "accountNumber" of type int
    private int accountNumber;

//Define a constructor that takes in a parameter of type int named "accountNumber"
    public checking(int accountNumber) {
//Set the value of the instance variable "accountNumber" to the value of the "accountNumber" parameter
      	this.accountNumber = accountNumber;
//Set the value of the instance variable "balance" to 0
	this.balance = 0;
    }

//Define a method named "deposit" that takes in a parameter of type float named "amount"
    public void deposit(float amount) {
//Add the value of "amount" to the current value of "balance"
	 balance += amount;
    }

//Define a method named "withdraw" that takes in a parameter of type float named "amount"
    public void withdraw(float amount) {
//Check if the current value of "balance" is greater than or equal to the value of "amount"
        if (balance >= amount) {
//If so, subtract the value of "amount" from the current value of "balance"
            balance -= amount;
        } else {
//Otherwise, print "Insufficient funds!"
            System.out.println("Insufficient funds!");
        }
    }

//Define a method named "getBalance" that returns a value of type float
    public float getBalance() {
//Return the current value of "balance"
        return balance;
    }
}

