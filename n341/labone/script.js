/**************************************
TITLE: Lab 1 - Expressions, Functions and Objects
AUTHOR: Parmindar Singh PS
CREATE DATE: 25 Jan 2024
PURPOSE: Javascript code for functionality of a Barber Shop
LAST MODIFIED ON: 28 Jan 2024 
LAST MODIFIED BY: Parmindar Singh PS
MODIFICATION HISTORY:(3)
<list the dates of each modification, explain each and give the initials of the programmer who made each modification>
25 Jan 2024 - Created the File PS
28 Jan 2024 - Transfered code from VSCode and tested everything PS
**************************************/




var cart = [];

// Declare variables with appropriate prefixes Req 3
var strServiceName = "Classic Haircut"; //Declare a string variable. Use the str prefix and initialize it to a string value. 4
var intServicePrice = 20; // Declare an integer variable. Use the int prefix and initialize it to an integer value. Req 5)
var bolServiceAvailable = true; // Declare a Boolean variable. Use the bol prefix and initialize it to a Boolean value. Req 6) 

function clearCart() {
    cart = []; // Empty the cart array
    updateCart(); // Update the cart display
}

function addToCart(serviceId) {
    var selectedService = document.querySelector(`[data-service-id="${serviceId}"]`);
    
    // Check if selectedService is null
    if (!selectedService) {
        console.log(`No service found with id: ${serviceId}`);
        return;
    }
    
    var serviceName = selectedService.querySelector('h2').innerText;
    var servicePrice = parseFloat(selectedService.querySelector('p').innerText.replace('$', ''));

    cart.push({ id: serviceId, name: serviceName, price: servicePrice });

    updateCart();
}

function updateCart() {
    var cartList = document.getElementById('cart-list');
    var totalElement = document.getElementById('total');

    // Clear the cart list
    while (cartList.firstChild) {
        cartList.removeChild(cartList.firstChild);
    }

    // Update the cart list
    cart.forEach(function (item) {
        var listItem = document.createElement('li');
        listItem.innerHTML = item.name + ' - $' + item.price.toFixed(2);
        cartList.appendChild(listItem);
    });

    // Calculate and display the total
    var total = cart.reduce(function (sum, item) {
        return sum + item.price;
    }, 0);
    totalElement.innerHTML = 'Total: $' + total.toFixed(2);

    // Output the additional variables with appropriate prefixes (Req 8)
    sendOutput("elOutput1", "Service Name", strServiceName);
    sendOutput("elOutput2", "Service Price", intServicePrice);
    sendOutput("elOutput3", "Service Availability", bolServiceAvailable ? "Available" : "Not Available");

    // Create an array of strings and integers (Req 9 & Req 10)
    var stringArray = ["Shampoo", "Beard Trim", "Hot Towel Shave", "Hair Coloring", "Style Consultation"];
    var intArray = [25, 15, 30, 40, 10];

    // Use the function from step 7 to output the values of both arrays to different page elements.(Req 11)
    sendOutput("elOutput4", "All Services Offered Today", stringArray.join(', '));
    sendOutput("elOutput5", "Cost", intArray.join(', '));

    // Use three different arithmetic operators to change each value in the array of integers (Req 12)
    intArray = intArray.map(function (value) {
        return value * 2; // Double each value
    });

    // Use two different string methods to change each value in the array of strings (Req 13)
    stringArray = stringArray.map(function (value) {
        return value.toUpperCase(); // Convert each string to uppercase
    });

    // Use the function to output the modified array of integers and strings (Req 14 & Req 15 )
    sendOutput("elOutput6", "Waiting Time", intArray.join(', '));
    sendOutput("elOutput7", "", stringArray.join(', '));


    // Create an object with relevant barber shop theme properties and methods (Req 16 & Req 17)
    var barberObject = {
        barberName: "Barber Joe",
        shopLocation: "123 Main Street",
        calculateHaircutCost: function () {
            return this.barberName.length * 5; // Cost based on the length of the barber's name
        },
        outputProperties: function () {
            sendOutput("elOutput8", "Barber Name", this.barberName);
            sendOutput("elOutput9", "Shop Location", this.shopLocation);
        },
        useMathMethod: function () {
            var randomNum = Math.floor(Math.random() * 10) + 1; // Get a random number between 1 and 10
            sendOutput("elOutput10", "Spots Available", randomNum);
        },
        useDateMethod: function () {
            var currentDate = new Date();
            sendOutput("elOutput11", "Current Date", currentDate.toDateString());
        },
        updateProperty: function () {
            this.barberName = "Barber Joe"; // Change the barber's name
            sendOutput("elOutput12", "Owner", this.barberName);
        }
    };

    // Output the initial properties of the object (Req 18)
    barberObject.outputProperties();

    // Call the object's method that uses the Math Object (Req 19)
    barberObject.useMathMethod();

    // Call the object's method that uses the Date Object (Req 20)
    barberObject.useDateMethod();

    // Use dot notation inside a method to update one of the object's properties (R eq21)
    barberObject.updateProperty();

    // After modifying the properties, use the object's output method to send the updated values to a different page element (Req 22)
    barberObject.outputProperties();
}

// Function to send output to the page element (7)
function sendOutput(el, label, value) {
    var elOutput = document.getElementById(el);
    
    // Clear the existing content
    elOutput.innerHTML = '';
    
    // Append the new output
    elOutput.innerHTML += '<p>' + label + ': ' + value + '</p>';
}


// Call the addToCart function three times with different serviceIds
addToCart(1);
addToCart(2);
addToCart(3);
addToCart(4);

