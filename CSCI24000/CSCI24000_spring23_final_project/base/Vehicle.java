// Declare an abstract class named "Vehicle"
public abstract class Vehicle {
// Declare private instance variables "make", "model", "price", and "sold"
    private String make;
    private String model;
    private double price;
    private boolean sold;
// Declare a constructor that takes in parameters "make", "model", and "price"
// Set the values of "make", "model", "price", and "sold" to the values of the corresponding parameters and false, respectively
    public Vehicle(String make, String model, double price) {
        this.make = make;
        this.model = model;
        this.price = price;
        this.sold = false;
    }
// Declare a method "getMake" that returns the value of "make"
    public String getMake() {
        return make;
    }
// Declare a method "getModel" that returns the value of "model"
    public String getModel() {
        return model;
    }
// Declare a method "getPrice" that returns the value of "price"
    public double getPrice() {
        return price;
    }
// Declare a method "isSold" that returns the value of "sold"
    public boolean isSold() {
        return sold;
    }
// Declare a method "sell" that sets the value of "sold" to true
    public void sell() {
        this.sold = true;
    }
// Declare a method "getMakeandModel" that concatenates the values of "make" and "model" separated by a space and returns the result
    public String getMakeandModel() {
        return make + " " + model;
    }
}



