//Create a class called Owl that extends the Pet class
public class Owl extends Pet {
//Declare a private instance variable "color" of type String    
    private String color;
//Define a constructor method for the Owl class that takes in "name", "age", and "color" as parameters
    public Owl(String name, int age, String color){
//Call the constructor of the parent "Pet" class and pass in "name" and "age" as arguments
        super(name,age);
//Initialize the "color" instance variable with the value passed in as the "color" parameter
        this.color = color;
    }
//Define a public method "getColor" that returns the value of the "color" instance variable
    public String getColor(){
//Return the "color" instance variable
        return color;
    }  
//Define a public method "sing" 
    public void sing(){
//Print a message that the owl is singing loudly with its name
        System.out.println(this.getName() + "sings loudly!");
//Increase the hunger level of the owl by 10
        gethunger().setCurrentLevel(gethunger().getCurrentLevel() + 10);
//Increase the happiness level of the owl by 10
        gethappiness().setHappyLevel(gethappiness().getHappyLevel() + 10);
    }
//Define a public method "feed"
    public void feed() {
//Decrease the hunger level of the owl by 10
        gethunger().decreaseLevel(10);
//Increase the happiness level of the owl by 10
        gethappiness().increaseHappyLevel(10);
    }
//Define a public method "play"   
    public void play() {
// Increase the hunger level of the owl by 10
        gethunger().increaseLevel(10);
//Increase the happiness level of the owl by 10
        gethappiness().increaseHappyLevel(10);
    }
//Define a public method "sleep"     
    public void sleep() {
//Increase the hunger level of the owl by 10
        gethunger().increaseLevel(10);
//Increase the happiness level of the owl by 10
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



