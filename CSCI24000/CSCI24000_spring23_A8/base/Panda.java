//Create a class called Panda that extends the Pet class
public class Panda extends Pet {
//Create a constructor with parameters name and age
    public Panda(String name, int age) {
//Call the constructor of the parent class with the parameters name and age
        super(name, age);
    }
//Create a method called feed
    public void feed() {
//Call the private method decreaseLevel with the parameter 10
        gethunger().decreaseLevel(10);
//Call the private method increaseHappyLevel with the parameter 10
        gethappiness().increaseHappyLevel(10);
    }
//Create a method called play   
    public void play() {
//Call the private method increaseLevel with the parameter 10
        gethunger().increaseLevel(10);
//Call the private method increaseHappyLevel with the parameter 10
        gethappiness().increaseHappyLevel(10);
    }
//Create a method called sleep   
    public void sleep() {
//Call the private method increaseLevel with the parameter 10
        gethunger().increaseLevel(10);
//Call the private method increaseHappyLevel with the parameter 10
        gethappiness().increaseHappyLevel(10);
    }
//Create a private method called increaseHappinessLevel with a parameter amount of type int 
    private void increaseHappinessLevel(int amount) {
//Set the value of the level variable in the happiness instance variable to its current value plus the amount parameter
        gethappiness().setHappyLevel(gethappiness().getHappyLevel() + amount);
    }
//Create a private method called decreaseHungerLevel with a parameter amount of type int
    private void decreaseHungerLevel(int amount) {
//Set the value of the level variable in the hunger instance variable to its current value minus the amount parameter
        gethunger().setCurrentLevel(gethunger().getCurrentLevel() - amount);
    }
}
    
 
























