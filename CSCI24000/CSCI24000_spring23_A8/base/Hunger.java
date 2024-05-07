import java.io.Serializable;
//Declare a public class called "hunger" that implements the Serializable interface
public class Hunger implements Serializable{
//Declare a private integer variable called "currentLevel" to represent the current hunger level    
    private int currentLevel;
//Define a constructor for the "hunger" class that sets the default current hunger level to 100
    public Hunger() {
        this.currentLevel = 100;
    }
//Define a getter method called "getCurrentLevel" that returns the current hunger level
    public int getCurrentLevel() {
        return currentLevel;
    }
//Define a setter method called "setCurrentLevel" that sets the current hunger level to the specified value
    public void setCurrentLevel(int level) {
        this.currentLevel = level;
    }
//Define a method called "decreaseLevel"" 
    public void decreaseLevel(int value) {
//Subtract the specified value from the current hunger level
        this.currentLevel -= value;
//If the current hunger level is less than 0, set it to 0
        if (this.currentLevel < 0) {
            this.currentLevel = 0;
        }
    }
//Define a method called "increaseLevel"
    public void increaseLevel(int value) {
//add the specified value to the current hunger level
        this.currentLevel += value;
//If the current hunger level is greater than 100, set it to 100
        if (this.currentLevel > 100) {
            this.currentLevel = 100;
        }
    }
}

