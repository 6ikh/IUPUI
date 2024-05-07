import java.io.Serializable;
//Declare a public class called "happiness" that implements the Serializable interface
public class Happiness implements Serializable {
//Declare a private integer variable called "happyLevel" to represent the happiness level
     private int happyLevel;
//Define a constructor for the "happiness" class
    public Happiness() {
//Set the default happiness level to 100
        this.happyLevel = 100; 
    }
//Define a getter method called "getHappyLevel"
    public int getHappyLevel() {
//Return the current happiness level
        return happyLevel;
    }
//Define a setter method called "setHappyLevel"
    public void setHappyLevel(int happyLevel) {
//Set the current happiness level to the specified value
        this.happyLevel = happyLevel;
    }
//Define a method called "reduceHappyLevel"    
    public void reduceHappyLevel(int value) {
//Subtract the specified value from the current happiness level
        this.happyLevel -= value;
//If the current happiness level is less than 0, set it to 0
        if (this.happyLevel < 0) {
            this.happyLevel = 0;
        }
    }
//Define a method called "increaseHappyLevel"
    public void increaseHappyLevel(int value) {
//Add the specified value to the current happiness level.
        this.happyLevel += value;
//If the current happiness level is greater than 100, set it to 100
        if (this.happyLevel > 100) {
            this.happyLevel = 100;
        }
    }
}





