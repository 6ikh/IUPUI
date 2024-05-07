//Import the Serializable class from the java.io package
import java.io.Serializable;
//Import the Scanner class from the java.util package
import java.util.Scanner;
//Create an abstract class called Pet that implements the Serializable interface
public abstract class Pet implements Serializable {
//Create a protected variable called name of type String
    protected String name;
//Create a protected variable called age of type int
    protected int age;
//Create a protected variable called hunger of type Hunger
    protected Hunger hunger;
//Create a protected variable called happiness of type Happiness
    protected Happiness happiness;
//Create a constructor with parameters name and age
    public Pet(String name, int age) {
//Set the value of name to the instance variable this.name
        this.name = name;
//Set the value of age to the instance variable this.age
        this.age = age;
//Create a new Hunger object and set it to the instance variable this.hunger
        this.hunger = new Hunger();
//Create a new Happiness object and set it to the instance variable this.happiness
        this.happiness = new Happiness();
    }
//Create an abstract method called play
    public abstract void play();
//Create an abstract method called feed
    public abstract void feed();
//Create a method called sleep
    public void sleep() {
    }
//Create a method called rename with a parameter newName of type String
    public void rename(String newName) {
//Set the value of newName to the instance variable this.name
        this.name = newName;
    }
//Create a method called getName that returns the value of the instance variable name
    public String getName() {
//Return the value of variable name 
        return name;
    }
//Create a method called gethunger that returns the value of the instance variable hunger 
    public Hunger gethunger() {
//Return the value of variable hunger 
        return hunger;
    }
//Create a method called gethappiness that returns the value of the instance variable happiness
    public Happiness gethappiness() {
//Return the value of variable happiness
        return happiness;
    }
//Create a method called getAge that returns the value of the instance variable age
    public int getAge() {
//Return the value of variable age 
        return age;
    }
//Create a method called displayMenu
    public void displayMenu() {
//Print the text "Pet Menu:"
        System.out.println("Pet Menu:");
//Print the text "Name Of Pet:" followed by the value of the instance variable name
        System.out.println("Name Of Pet: " + getName());
//Print the text "Pet Age:" followed by the value of the instance variable age
        System.out.println("Pet Age: " + getAge());
//Print the text "Hunger Level:" followed by the value of the getCurrentLevel method of the instance variable hunger
        System.out.println("Hunger Level : " + gethunger().getCurrentLevel());
//Print the text "Happiness Level:" followed by the value of the getHappyLevel method of the instance variable happiness
        System.out.println("Happiness Level: " + gethappiness().getHappyLevel());
    }
}

