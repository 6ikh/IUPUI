/**************************************
TITLE: Lab 3 - Javascript Events
AUTHOR: Parmindar Singh PS
CREATE DATE: 22 Feb 2024
PURPOSE: Javascript code for functionality of a Barber Shop
LAST MODIFIED ON: 25 Feb 2024 
LAST MODIFIED BY: Parmindar Singh PS
MODIFICATION HISTORY:(3)
<list the dates of each modification, explain each and give the initials of the programmer who made each modification>
22 Feb 2024 - Created the File PS
22 Feb 2024 - Transfered code from VSCode and tested everything PS
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



// Req 3: Demonstrate if/else construct
if (cart.length > 0) {
    console.log("Cart is not empty");
} else {
    console.log("Cart is empty");
}

// Req 4: Demonstrate the use of at least two comparison operators
if (intServicePrice == 20) {
    console.log("Service price is 20");
}

if (intServicePrice !== 30) {
    console.log("Service price is not 30");
}

// Req 5: Demonstrate the use of at least two logical operators
if (intServicePrice > 10 && intServicePrice < 30) {
    console.log("Service price is between 10 and 30");
}

if (intServicePrice < 10 || intServicePrice > 30) {
    console.log("Service price is not between 10 and 30");
}

// Req 6: Demonstrate the use of the switch statement
switch (strServiceName) {
    case "Classic Haircut":
        console.log("The service is Classic Haircut");
        break;
    case "Beard Trim":
        console.log("The service is Beard Trim");
        break;
    case "Hot Towel Shave":
        console.log("The service is Hot Towel Shave");
        break;
    default:
        console.log("Unknown service");
}

// Req 7: Use parseInt() to demonstrate the difference between adding two digits stored as strings and adding the same two digits stored as integers
var firstServiceDuration = "30"; // Duration of the first service in minutes
var secondServiceDuration = "45"; // Duration of the second service in minutes

// Adding durations stored as strings linking them together
console.log("Total duration when stored as strings: " + firstServiceDuration + secondServiceDuration + " minutes");

// Using parseInt() to convert strings to integers before adding them
console.log("Total duration when stored as integers: " + (parseInt(firstServiceDuration) + parseInt(secondServiceDuration)) + " minutes");


// Req 8: Demonstrate the difference between == and ===
if (intServicePrice == "20") {
    console.log("Service price is '20' (loose equality)"); // This will be logged
}

if (intServicePrice === "20") {
    console.log("Service price is '20' (strict equality)"); // This will not be logged
}

// Req 9: Use a loop to output the contents of an array to the page
var services = ["Classic Haircut", "Beard Trim", "Hot Towel Shave", "Facial Grooming"];
for (var i = 0; i < services.length; i++) {
    console.log(services[i]);
}

// Req 10: Use a Truthy value in a condition without an operator
if (strServiceName) {
    console.log("Service name is truthy");
}

// Req 11: Use a Falsy value in a condition
if (!bolServiceAvailable) {
    console.log("Service is not available");
}

// Req 12: Select a single page element and change the textContent
var header = document.querySelector('header h1');
header.textContent = "Barber Haven, Downtown Indy";

// Req 13: Select at least three page elements by their class attribute or tag name and use innerHTML to change the formatting as well as the content.
var services = document.querySelectorAll('.service h2');
for (var i = 0; i < services.length; i++) {
    services[i].innerHTML = "<strong>" + services[i].textContent + "</strong>";
}

// Req 14: Loop through the selection from step 13 and add a new class attribute to each one. This change must show visible results on the page.
for (var i = 0; i < services.length; i++) {
    services[i].classList.add('highlight');
}

// Req 15: Use innerHTML to change the formatting as well as the content of a page element.
var firstService = document.querySelector('.service');
if (firstService) {
    firstService.innerHTML = "<h2><em>Updated Service</em></h2><p>$25.00</p><button onclick='addToCart(5)'>Add to Cart</button>";
} else {
    console.log("Element with class 'service' not found.");
}


// Req 16: Add a page element with content to the page.
var container = document.querySelector('.container');
if (container) {
    var newService = document.createElement('div');
    newService.innerHTML = "<h2>New Service</h2><p>$30.00</p><button onclick='addToCart(6)'>Add to Cart</button>";
    container.appendChild(newService);
} else {
    console.log("Element with class 'container' not found.");
}



// Req 17: Select a page element based on its ID or class attribute value.
var cart = document.getElementById('cart');

// Req 18: Change the value of the ID or class that was selected in step 17. Changing the attribute value must show visible results on the page.
var cart = document.getElementById('cart');
if (cart) {
    cart.id = 'newCart';
} else {
    console.log("Element with ID 'cart' not found.");
}


// Req 19: Remove a page element.
var lastService = document.querySelector('.service:last-child');
if (lastService) {
    lastService.parentNode.removeChild(lastService);
} else {
    console.log("No matching element found.");
}

// Check if the button element exists before adding the event listener
const submitButton = document.querySelector("button[type='submit']");
if (submitButton) {
    // Req 3: Use an event listener without parameters to produce visible results on the page when the user clicks a page element
    submitButton.addEventListener("click", function() {
        alert("Thank you for your message!");
    });
} else {
    console.log("Button element not found!");
}


document.addEventListener("DOMContentLoaded", function() {
    // Check if the element with id "contactForm" exists
    const contactForm = document.getElementById("contactForm");
    if (contactForm) {
        // Req 4: Use an event listener with parameters to produce visible results on the page when the user clicks a page element
        // Add event listener only if the element exists
        contactForm.addEventListener("submit", function(event) {
            event.preventDefault();
            const formData = new FormData(event.target);
            console.log("Form submitted with data:", formData);
        });
    } else {
        console.log("Element with id 'contactForm' not found.");
    }
});


document.addEventListener("DOMContentLoaded", function() {
    const contactElement = document.getElementById("contact");
    if (contactElement) {
        // Req 5: Demonstrate Event Bubbling with nested HTML elements that have events bound to them
        // Event listener with event bubbling for nested HTML elements
        contactElement.addEventListener("click", function(event) {
            //Req 6: Use the Event Object to create an event that responds by displaying the ID or class attribute of the page element that was clicked.
            alert("Clicked on: " + event.target.id);
            event.stopPropagation();
        });
    } else {
        console.log("Element with id 'contact' not found.");
    }
});

function nestedElementClickHandler(event) {
    alert("Clicked on nested element: " + event.target.id);
}

function stopBubblingEventHandler(event) {
    // Req 7: Use a method to stop the Event Bubbling. This event must be separate from requirement 5.
    event.stopPropagation();
    alert("Event bubbling stopped at: " + event.currentTarget.id);
}

function stopBubbling(event) {
    // Req 7: Use a method to stop the Event Bubbling. This event must be separate from requirement 5.
    event.stopPropagation();
    alert("Event bubbling stopped at: " + event.currentTarget.id);
}


document.addEventListener("DOMContentLoaded", function() {
    const nameElement = document.getElementById("name");
    if (nameElement) {
 //Req 8: In JavaScript, create two focus/blur or focusin/focusout events that produce visible results on the page.
        // Focus event listener
        nameElement.addEventListener("focus", function() {
            nameElement.style.backgroundColor = "lightblue";
        });
    } else {
        console.log("Element with id 'name' not found.");
    }
});

document.addEventListener("DOMContentLoaded", function() {
    const nameElement = document.getElementById("name");
    if (nameElement) {
        //Req 8: In JavaScript, create two focus/blur or focusin/focusout events that produce visible results on the page.
        // Blur event listener
        nameElement.addEventListener("blur", function() {
            nameElement.style.backgroundColor = "";
        });
    } else {
        console.log("Element with id 'name' not found.");
    }
});


document.addEventListener("DOMContentLoaded", function() {
    const messageElement = document.getElementById("message");
    if (messageElement) {
        // Req 9: In JavaScript, create at least three different mouse events that produce visible results on the page.
        messageElement.addEventListener("mouseenter", function() {
            messageElement.style.border = "2px solid green";
        });
        //Req 9: In JavaScript, create at least three different mouse events that produce visible results on the page.
        messageElement.addEventListener("mouseleave", function() {
            messageElement.style.border = "";
        });
        //Req 9: In JavaScript, create at least three different mouse events that produce visible results on the page.
        messageElement.addEventListener("click", function() {
            messageElement.style.color = "blue";
        });
    } else {
        console.log("Element with id 'message' not found.");
    }
});


document.addEventListener("DOMContentLoaded", function() {
    const emailElement = document.getElementById("email");
    if (emailElement) {
        // Req 10: In JavaScript, create at least two different keyboard events that produce visible results on the page.
        emailElement.addEventListener("keydown", function(event) {
            if (event.key === "Enter") {
                alert("You pressed Enter in the email field.");
            }
        });
    
        // Req 10: In JavaScript, create at least two different keyboard events that produce visible results on the page.
        emailElement.addEventListener("keyup", function(event) {
            if (event.key === "Shift") {
                alert("Shift key released in the email field.");
            }
        });
    } else {
        console.log("Element with id 'email' not found.");
    }
});
    


document.addEventListener("DOMContentLoaded", function() {
    const emailElement = document.getElementById("email");
    if (emailElement) {
        // Req 9: In JavaScript, create two different form events that produce visible results on the page
        emailElement.addEventListener("input", function() {
            console.log("Email input value changed:", emailElement.value);
        });
    } else {
        console.log("Element with id 'email' not found.");
    }
    // Req 11: In JavaScript, create two different form events that produce visible results on the page.
    const contactFormElement = document.getElementById("contactForm");
    if (contactFormElement) {
        // Reset event for the form
        contactFormElement.addEventListener("reset", function() {
            alert("Form has been reset.");
        });

        // Change event for the form
        contactFormElement.addEventListener("change", function() {
            alert("Form has been changed.");
        });
    } else {
        console.log("Element with id 'contactForm' not found.");
    }
});


document.addEventListener("DOMContentLoaded", function() {
    const contactForm = document.getElementById("contactForm");
    if (contactForm) {
        //Req 12: In JavaScript, demonstrate a mutation event that produces visible results on the page
        contactForm.addEventListener("submit", function(event) {
            event.preventDefault(); // Prevent the default form submission
            // Display a thank you message. This text will change
            const thankYouMessage = document.createElement("p");
            thankYouMessage.textContent = "Thank you for your message!";
            contactForm.appendChild(thankYouMessage);
        });
    } else {
        console.log("Contact form not found.");
    }
});

// Req 13: In JavaScript, create an event that alerts the user before leaving the page. This event must use beforeunload in JavaScript. While other methods work, they will not receive credit.
window.addEventListener("beforeunload", function(event) {
    event.returnValue = "Are you sure you want to leave?";
});



