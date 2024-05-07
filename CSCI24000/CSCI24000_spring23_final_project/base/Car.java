// Declare a public class named "Car" that extends the abstract class "Vehicle"
public class Car extends Vehicle {
// Declare private instance variables "make", "model", "horsepower", "topSpeed", and "acceleration"
    private String make;
    private String model;
    private int horsepower;
    private int topSpeed;
    private double acceleration;
// Declare a constructor that takes in parameters "make", "model", "horsepower", "topSpeed", and "acceleration"
    public Car(String make, String model, int horsepower, int topSpeed, double acceleration) {
// Call the constructor of the parent class with "make", "model", and 100000.00 as parameters
        super(make, model, 100000.00);
// Set the values of "make", "model", "horsepower", "topSpeed", and "acceleration" to the corresponding parameters
        this.make = make;
        this.model = model;
        this.horsepower = horsepower;
        this.topSpeed = topSpeed;
        this.acceleration = acceleration;
    }
// Declare a method "getMake" that returns the value of "make"
    public String getMake() {
        return make;
    }
// Declare a method "setMake" that takes in a parameter "make" and sets the value of "make" to the corresponding parameter
    public void setMake(String make) {
        this.make = make;
    }
// Declare a method "getModel" that returns the value of "model"
    public String getModel() {
        return model;
    }
// Declare a method "setModel" that takes in a parameter "model" and sets the value of "model" to the corresponding parameter
    public void setModel(String model) {
        this.model = model;
    }
// Declare a method "getHorsepower" that returns the value of "horsepower"
    public int getHorsepower() {
        return horsepower;
    }
// Declare a method "setHorsepower" that takes in a parameter "horsepower" and sets the value of "horsepower" to the corresponding parameter
    public void setHorsepower(int horsepower) {
        this.horsepower = horsepower;
    }
// Declare a method "getTopSpeed" that returns the value of "topSpeed"
    public int getTopSpeed() {
        return topSpeed;
    }
// Declare a method "setTopSpeed" that takes in a parameter "topSpeed" and sets the value of "topSpeed" to the corresponding parameter
    public void setTopSpeed(int topSpeed) {
        this.topSpeed = topSpeed;
    }
// Declare a method "getAcceleration" that returns the value of "acceleration"
    public double getAcceleration() {
        return acceleration;
    }
// Declare a method "setAcceleration" that takes in a parameter "acceleration" and sets the value of "acceleration" to the corresponding parameter
    public void setAcceleration(double acceleration) {
        this.acceleration = acceleration;
    }
// Override the toString method to return the make, model, horsepower, top speed, and acceleration of the car in a formatted string
    @Override
    public String toString() {
        return make + " " + model + " - " + horsepower + "HP " + topSpeed + "mph " + acceleration + "s 0-60";
    }
}


