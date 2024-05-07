//Define a public class named "atm"
public class atm {
//Define a private instance variable named "accountNumber" of type String
    private String accountNumber;
//Define a private instance variable named "pin" of type int
    private int pin;
//Define a private instance variable named "isAdmin" of type boolean
    private boolean isAdmin;
//Define a private instance variable named "checkingAccount" of type "checking"
    private checking checkingAccount;
//Define a private instance variable named "savingsAccount" of type "saving"
    private saving savingsAccount;
//Define a constructor that takes in parameters of type String, int, boolean, "checking", and "saving"
    public atm(String accountNumber, int pin, boolean isAdmin, checking checkingAccount, saving savingsAccount) {
//Set the value of the instance variable "accountNumber" to the value of the "accountNumber" parameter
        this.accountNumber = accountNumber;
//Set the value of the instance variable "pin" to the value of the "pin" parameter
        this.pin = pin;
//Set the value of the instance variable "isAdmin" to the value of the "isAdmin" parameter
        this.isAdmin = isAdmin;
//Set the value of the instance variable "checkingAccount" to the value of the "checkingAccount" parameter
        this.checkingAccount = checkingAccount;
//Set the value of the instance variable "savingsAccount" to the value of the "savingsAccount" parameter
        this.savingsAccount = savingsAccount;
    }
//Define a method named "getAccountNumber" that returns a value of type String
    public String getAccountNumber() {
//Return the current value of "accountNumber"
        return accountNumber; }
//Define a method named "setAccountNumber" that takes in a parameter of type String named "accountNumber"
    public void setAccountNumber(String accountNumber) {
//Set the value of the instance variable "accountNumber" to the value of the "accountNumber" parameter
        this.accountNumber = accountNumber; }
//Define a method named "getPin" that returns a value of type int
    public int getPin() {
//Return the current value of "pin"
        return pin; }
//Define a method named "setPin" that takes in a parameter of type int named "pin"
    public void setPin(int pin) {
//Define a method named "setPin" that takes in a parameter of type int named "pin"
        this.pin = pin; }
//Define a method named "isAdmin" that returns a value of type boolean
    public boolean isAdmin() {
//Return the current value of "isAdmin"
        return isAdmin; }
//Define a method named "setAdmin" that takes in a parameter of type boolean named "isAdmin"
    public void setAdmin(boolean isAdmin) {
//Set the value of the instance variable "isAdmin" to the value of the "isAdmin" parameter
        this.isAdmin = isAdmin; }
//Define a method named "getCheckingAccount" that returns an object of type "checking"
    public checking getCheckingAccount() {
// Return the current value of "checkingAccount"
        return checkingAccount; }
//Define a method named "setCheckingAccount" that takes in a parameter of type "checking" named "checkingAccount"
    public void setCheckingAccount(checking checkingAccount) {
//Set the value of the instance variable "checkingAccount" to the value of the "checkingAccount
        this.checkingAccount = checkingAccount; }
//Define a method named "getSavingsAccount" that returns an object of type "saving"
    public saving getSavingsAccount() {
//Return the current value of "savingsAccount"
        return savingsAccount; }
//Define a method named "setSavingsAccount" that takes in a parameter of type "saving" named "savingsAccount"
    public void setSavingsAccount(saving savingsAccount) {
//Set the value of the instance variable "savingsAccount" to the value of the "savingsAccount" parameter
	 this.savingsAccount = savingsAccount; }

//Define a method named "toString" that returns a value of type String
    public String toString() {
//Return a string representation of the object's state, including the values of all instance variables
        return "User{" +
                "accountNumber='" + accountNumber + '\'' +
                ", pin=" + pin +
                ", isAdmin=" + isAdmin +
                ", checkingAccount=" + checkingAccount +
                ", savingsAccount=" + savingsAccount +
                '}';
    }
}

