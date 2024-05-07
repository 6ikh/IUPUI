// Define a public class named "saving"
public class saving {
//Define a private instance variable named "balance" of type float
    private float balance;

//Define a private instance variable named "interestRate" of type float
    private float interestRate;

//Define a constructor that takes in two parameters of type float, balance and interestRate
    public saving(float balance, float interestRate) {
//Set the value of the instance variable "balance" to the value of the "balance" parameter
        this.balance = balance;
//Set the value of the instance variable "interestRate" to the value of the "interestRate" parameter
  	this.interestRate = interestRate;
    }

//Define a method named "deposit" that takes in a parameter of type float named "amount"
    public void deposit(float amount) {
//Add the value of "amount" to the current value of "balance"
      	 balance += amount;
    }
//Define a method named "withdraw" that takes in a parameter of type float named "amount"
    public void withdraw(float amount) {
//Check if the current value of "balance" is less than the value of "amount"
  	  if (balance < amount) {
//If so, print "Insufficient funds!"
            System.out.println("Insufficient funds!");
        } else {
//Otherwise, subtract the value of "amount" from the current value of "balance"
            balance -= amount;
	}
    }

//Define a method named "getInterestRate" that returns a value of type float
    public float getInterestRate() {
//Set the value of the instance variable "interestRate" to the value of the "interestRate" parameter
        return interestRate;
    }

//Define a method named "setInterestRate" that takes in a parameter of type float named "interestRate"
    public void setInterestRate(float interestRate) {
//Set the value of the instance variable "interestRate" to the value of the "interestRate" parameter
        this.interestRate = interestRate;
    }

//Define a method named "getBalance" that returns a value of type float
    public float getBalance() {
//Return the current value of "balance"
        return balance;
    }

//Define a method named "setBalance" that takes in a parameter of type float named "balance"
    public void setBalance(float balance) {
//Set the value of the instance variable "balance" to the value of the "balance" parameter
	 this.balance = balance;
    }


//Define a method named "applyInterest" that takes in a parameter of type int named "month"
    public void applyInterest(int month) {
//Add the value of "interestPaid(month)" to the current value of "balance"
	    this.balance = this.balance + interestPaid(month);
    }

//Define a method named "interestPaid" that takes in a parameter of type int named "month" and returns a value of type float
    public float interestPaid(int month){ 
//Compute the interest using the formula, and store the value in a variable named "interest"
        float interest = this.balance * (1 + interestRate * month / 12) - this.balance;
//Return the value of "interest"
        return interest;
    }
}

