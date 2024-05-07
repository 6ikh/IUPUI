// Import the Scanner class for user input
import java.util.Scanner;
//Import the Input/Output classes for file manipulation
import java.io.*;
//Import ArrayList class for storing Pet objects
import java.util.ArrayList;
//Define the PetMain class
public class PetMain {
//Define the main method
    public static void main(String[] args) {
//Create an ArrayList of Pet objects
        ArrayList<Pet> myPets = new ArrayList<Pet>();
//Create a Scanner object to get user input
        Scanner scanner = new Scanner(System.in);
//Initialize a Pet object
        Pet pet = null;
//Print a welcome message
        System.out.println("Welcome To The Pet Creator!");
//Start an infinite while loop
        while (true) {
//Print the menu options
            System.out.println("_________________________");
//Print a message to create a new pet 
            System.out.println("(1) Create a new pet");
//Print a message to interact with your pet 
            System.out.println("(2) Interact with your pet");
//Print a message to save the pet to a file 
            System.out.println("(3) Save your pet to a file");
//Print a message to load the pet from a file
            System.out.println("(4) Load your pet from a file");
//Print a message to exit the program
            System.out.println("(5) Exit");
//Prompt the user to select an option
            System.out.println("What would you like to do?");
//Print out a line 
            System.out.println("_________________________");
// Read user's choice
            int choice = scanner.nextInt();
//If choice is to create a new pet
            if (choice == 1) {
//Print out a line
                System.out.println("_________________________");
//Print out a message for the user to choose the type of pet they want to create 
                System.out.println("What type of pet would you like to create?");
//Print out a message for the user for selection 1 
                System.out.println("(1) Panda");
//Print out a message for the user for selection 2
                System.out.println("(2) Lizard");
//Print out a message for the user for selection 3
                System.out.println("(3) Owl");
//Print out a line 
                System.out.println("_________________________");
//Read user's pet choice
                int petChoice = scanner.nextInt();
// If user wants to create a Panda
                if (petChoice == 1) {
//Print out a line
                    System.out.println("_________________________");
// Print a message to enter the Panda's name
                    System.out.println("\nWhat would you like to name your Panda?");
//Print out a line 
                    System.out.println("_________________________");
//// Read the Panda's name
                    String name = scanner.next();
//Print out a line 
                    System.out.println("_________________________");
// Print a message to enter the Panda's age
                    System.out.println("\nWhat is your Panda's age?");
//Print out a line 
                    System.out.println("_________________________");
//Read the Panda's age
                    int age = scanner.nextInt();
//Create a new Panda object with the entered name and age
                    pet = new Panda(name, age);
// Add the created pet to the ArrayList
                    myPets.add(pet);
//If user wants to create a Lizard
                } else {
                    if (petChoice == 2) {
//Print out a line
                        System.out.println("_________________________");
//Print a message to enter the Lizard's name
                        System.out.println("\nWhat would you like to name your Lizard?");
//Read the Lizard's name
                        String name = scanner.next();
//Print out a line 
                        System.out.println("_________________________");
//Print a message to enter the Lizard's age
                        System.out.println("\nWhat is your Lizard's age?");
//Print out a line 
                        System.out.println("_________________________");
//Read the Lizard's age
                        int age = scanner.nextInt();
//Create a new Lizard object with the entered name and age
                        pet = new Lizard(name, age);
//Add the created pet to the ArrayList
                        myPets.add(pet);
//If user wants to create an Owl
                    } else {
                        if (petChoice == 3) {
//Print out a line
                            System.out.println("_________________________");
//Print a message to enter the Owl's name
                            System.out.println("\nWhat would you like to name your Owl?");
//Read the Owl's name
                            String name = scanner.next();
//Print out a Line
                            System.out.println("_________________________");
//Ask the user what age their owl is 
                            System.out.println("\nWhat is your Owl's age?");
//Print out a Line
                            System.out.println("_________________________");
//Read the Owl’s age
                            int age = scanner.nextInt();
//Print out a line
                            System.out.println("_________________________");
//Ask user what color their Owl is 
                            System.out.println("\nWhat color is your Owl?");
//Print out a Line
                            System.out.println("_________________________");
//Read the Owl’s color
                            String color = scanner.next();
//Create a new Owl object with the entered name and age
                            pet = new Owl(name, age, color);
//Add the created pet to the ArrayList
                            myPets.add(pet);
//Else statement if one of the options wasn’t selected, print a line
                        } else {
                            System.out.println("_________________________");
//Display a message saying the choice is invalid 
                            System.out.println("\nInvalid choice.");
                        }
                    }
                }
//If the user chooses number 2 
            } else {
                if (choice == 2) {
//If the myPets object is empty
                    if (myPets.isEmpty()) {
//Print out a line 
                        System.out.println("_________________________");
//Print out a message that there is no pet created yet 
                        System.out.println("\nYou don't have a pet yet!");
//Start else statement 
                    } else {
//Interact with the scanner and myPets object 
                        interactWithPet(scanner, myPets);
                    }
//Start the else statement if the choice of the user is 3
                } else {
                    if (choice == 3) {
//If the myPets object is empty
                        if (myPets.isEmpty()) {
//Print out a line
                            System.out.println("_________________________");
//Print out a message saying there is no pet to save 
                            System.out.println("\nYou don't have a pet to save!");
//Start else statement ;
                        } else {
//Try statement for the output files 
                            try {
//Create a new FileOutputStream object with the file name "pet.ser"
                                FileOutputStream fileOut = new FileOutputStream("pet.ser");
//Any object written to the "out" stream will be serialized and written to the file "pet.ser"
                                ObjectOutputStream out = new ObjectOutputStream(fileOut);
//Call the "writeObject" method on the "out" object and pass "myPets" as an argument to write it to the file
                                out.writeObject(myPets);
//Call the "close" method on the "out" object to close the ObjectOutputStream
                                out.close();
//Close the FileOutputStream object fileOut, which was used to create the ObjectOutputStream object out
                                fileOut.close();
//Print out a line 
                                System.out.println("_________________________");
//Print out a message to the user that the object has been serialized 
                                System.out.println("\nPet object has been serialized to pet.ser");
//Catch an IOException exception and assign it to the variable i.
                            } catch (IOException i) {
//Print the stack trace of the caught IOException exception.
                                i.printStackTrace();
                            }
                        }
//If the user selects option 4 
                    } else {
                        if (choice == 4) {
//start the try statement 
                            try {
//Create a new FileInputStream object with the filename pet.ser.
                                FileInputStream fileIn = new FileInputStream("pet.ser");
//Create a new ObjectInputStream object with the FileInputStream object.
                                ObjectInputStream in = new ObjectInputStream(fileIn);
//Read an object from the ObjectInputStream object and assign it to the variable object.
                                Object object = in.readObject();
//Suppress warnings about unchecked type casting.
                                @SuppressWarnings("unchecked")
//Cast the object to an ArrayList of Pet objects and assign it to the variable newMyPets.
                                ArrayList<Pet> newMyPets = (ArrayList<Pet>) object;
//Close the ObjectInputStream object.
                                in.close();
//Close the FileInputStream object.
                                fileIn.close();
//Print a message indicating that the object has been deserialized from the file.
                                System.out.println("\nPet object has been deserialized from pet.ser");
//Assign the newMyPets object to the myPets object.
                                myPets = newMyPets;
//Catch an IOException exception and assign it to the variable i.
                            } catch (IOException i) {
//Print the stack trace of the caught IOException exception.
                                i.printStackTrace();
//Print a return statement and exit the method 
                                return;
//Print the classnotfound to indicate that the class being requested for loading is not found in the classpath
                            } catch (ClassNotFoundException c) {
//Print a message for the user that the pet class is not found 
                                System.out.println("\nPet class not found");
//When an error occurs, printstacktrace which line error occurred
                                c.printStackTrace();
//Print a return statement and exit the method 
                                return;
                            }
//Print an else statement for choice 5 
                        } else {
//If the user choice is 5, exit the program 
                            if (choice == 5) {
                                System.out.println("\nExiting the program.");
                                return;
//If anything else then print a invalid choice message
                            } else {
                                System.out.println("\nInvalid choice.");
                            }
                        }
                    }
                }
            }
        }
    }
//Declare a method named interactWithPet that takes two parameters of Scanner and ArrayList<Pet> types.
        private static void interactWithPet(Scanner scanner, ArrayList<Pet> pets) {
//Use a for loop to iterate over each Pet in the ArrayList.
            for (int i = 0; i < pets.size(); i++) {
//Print out the index of the Pet plus one.
                System.out.println((i + 1) + ".");
//Call the displayMenu() method for the current Pet object.
                pets.get(i).displayMenu();
//Print an empty line.
                System.out.println();
            }
//Ask the user to select which pet they would like to interact with
            System.out.println("What pet would you like to interact with?");
//Read the user's input as an integer and subtract one to get the corresponding index in the ArrayList.
            int choice = scanner.nextInt() - 1;
//Ask the user what they would like to do with their selected pet.
            System.out.println("\nWhat would you like to do?");
//Print a message to the user for option to feed the pet 
            System.out.println("(1) Feed your pet");
//Print a message to the user for option to play with the pet 
            System.out.println("(2) Play with your pet");
//Print a message to the user for option to put the pet to sleep
            System.out.println("(3) Make your pet sleep");
//
            Pet pet = pets.get(choice);
//Print a message to the user for option to rename the pet
            System.out.println("(4) Rename your pet");
//If the pet is an instance of the Owl class, print out an additional option to let the owl sing.
            if (pet instanceof Owl) {
//Print a message to the user for option to let the owl sing 
                System.out.println("(5) Let your Owl sing");
            }
//Read the user's choice as an integer
            choice = scanner.nextInt();
//If the users choice is number 1 
            if (choice == 1) {
//call the feed() method for the selected Pet object
                pet.feed();
//Print a message to the user that the pet has been fed 
                System.out.println("\nYou fed your pet.");
//If the choice of the user is number 2 
            } else if (choice == 2) {
//call the play() method for the selected Pet object
                pet.play();
//Print a message to the user that the pet has been played with 
                System.out.println("\nYou played with your pet.");
//If the choice of the user is 3 
            } else if (choice == 3) {
//Call the sleep() method for the selected Pet object
                pet.sleep();
//Print a message to the user that they put the pet to sleep 
                System.out.println("\nYou put your pet to sleep.");
//If the choice of the user is 4 
            } else if (choice == 4) {
//Ask the user what name they want the pet to have 
                System.out.print("What new name would you like for your pet? ");
//read the user's input from the scanner as a string and assigns it to the variable newName
                String newName = scanner.next();
//Store the new name in the variable newName
                pet.rename(newName);
//Print out a message to the user that the pet has been rename whatever they chose it to be
                System.out.println("Your pet has been renamed '" + pet.getName() + "'");
//If number 5 is chosen, call the sing() method for the selected Pet object and print out a confirmation message.
            } else if (choice == 5 && pet instanceof Owl) {
                ((Owl) pet).sing();
//Else statement for the invalid choice 
            } else {
//Print out a error message that the choice is invalid 
                System.out.println("\nInvalid choice.");
            }
        }
}


