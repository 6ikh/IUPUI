/*
TITLE: script.js
AUTHOR: Parmindar Singh (PS)
CREATE DATE: 03 Mar 2024
PURPOSE: Gas Station Pump for customers to choose which fuel grade and check out, the functionality
LAST MODIFIED ON: 09 Mar 2024
LAST MODIFIED BY: Parmindar Singh (PS)
MODIFICATION HISTORY:
03 Mar 2024: Initial creation of the javascript file. (PS)
09 Mar 2024: Transfered everything from personal vscode (PS)
*/

//Theme: This theme will be for a gas station were customers can check out food and purchase gas, currently I have created the gas part but will add more on -->

//Requirement #4: Create and use an array
// Prefixes added to variable names
let arrTransactionHistory = []; // Array to store transaction history

// Requirement #7: Create and use an object that has properties and methods.
// Requirement #11: Initialize your object with values, call each of the methods, and output the modified values.
let objFuelPrices = {
  fltRegular: 2.50,
  fltPremium: 3.00,
  fltDiesel: 2.75,
  fltE85: 1.85,
  calculateTotalCost: function(fuelType, fuelAmount) {
    // Requirement #12: Demonstrate the use of an if/else construct or switch statement with at least three case values and a default code block. 
    let fltTotalCost = 0;
    //Requirement #5: Use at least two arithmetic operators.
    switch (fuelType) {
      case 'regular':
        //Requirement #10: Use the keyword this.
        fltTotalCost = this.fltRegular * fuelAmount;
        break;
      case 'premium':
        fltTotalCost = this.fltPremium * fuelAmount;
        break;
      case 'diesel':
        fltTotalCost = this.fltDiesel * fuelAmount;
        break;
      case 'e85':
        fltTotalCost = this.fltE85 * fuelAmount;
        break;
      default:
        fltTotalCost = 0;
    }
    //Requirement #8: Use a Math Object method.
    return Math.round(fltTotalCost);
  }
};

// Requirement #3: Create and use a function that has parameters and either returns a value or sends output to a page element.
// Function to add transaction details to transaction history list
function addToTransactionHistory(fuelType, fuelAmount, fltTotalCost) {
  //Requirement #6: Use at least one string method.
  const strTransactionDetails = `${fuelType}: ${fuelAmount} gallons - Total Cost: $${fltTotalCost} - Transaction Time: ${new Date().toLocaleString()}`; // Requirement #9: Use a Date Object method.
  arrTransactionHistory.push(strTransactionDetails);
  displayTransactionHistory(); // Update transaction history UI
}


// Requirement #32: Demonstrate a mutation event that produces visible results on the page.
document.getElementById('fuelPump').addEventListener('DOMNodeInserted', function(event) {
    if (event.target.tagName === 'BUTTON') {
      // Create a new button
      const newButton = document.createElement('button');
      newButton.textContent = 'New Button';
      // Append the new button to the fuelPump element
      event.target.parentNode.appendChild(newButton);
    }
  });

// Function to update transaction history list in the UI
function displayTransactionHistory() {
    const elTransactionList = document.getElementById('transactionList');
    if (!elTransactionList) {
      console.log("Transaction list element not found.");
      return;
    }
    
    elTransactionList.innerHTML = ''; // Requirement #19 Use innerHTML to change a page element or add a new one.
    
    // Check if arrTransactionHistory is defined and not empty
    if (!Array.isArray(arrTransactionHistory) || arrTransactionHistory.length === 0) {
      console.log("Transaction history is empty.");
      return;
    }
    
    //Requirement #4: Create and use an array & Requirement #16 Use a loop
    arrTransactionHistory.forEach(transaction => {
      const elListItem = document.createElement('li');
      elListItem.textContent = transaction;
      elTransactionList.appendChild(elListItem);
    });
  }
  

// Requirement #24: Use an event listener with parameters to produce visible results on the page when the user clicks a page element. Requirement #25: Demonstrate Event Bubbling.
document.getElementById('fuelPump').addEventListener('click', function(event) { // Requirement #27 Use the Event Object in a function or method.
  event.stopPropagation(); // Requirement #26 Stop Event Bubbling
  // Requirement #13: Demonstrate the use of at least two comparison operators:
  if (event.target.tagName === 'BUTTON') {
    const strFuelType = event.target.id.replace('Btn', '');
    // Requirement #15: Use parseInt() to convert a string to an integer.
    const intFuelAmount = parseInt(prompt(`Enter fuel amount for ${strFuelType}:`));
    // Requirement #14: Demonstrate the use of at least one logical operators: & Requirement #17: Use a Truthy or a Falsy value in a condition without a comparison operator
    if (!isNaN(intFuelAmount) && intFuelAmount > 0) {
      const fltTotalCost = objFuelPrices.calculateTotalCost(strFuelType, intFuelAmount);
      //Requirement #18: Use textContent to change the value of a page element's content. Requirement #21: Select a page element by id.
      document.getElementById('fuelType').textContent = `Fuel Type: ${strFuelType}`;
      document.getElementById('fuelAmount').textContent = `Fuel Amount: ${intFuelAmount} gallons`;
      document.getElementById('totalCost').textContent = `Total Cost: $${fltTotalCost}`;
      
      // Add transaction to history
      addToTransactionHistory(strFuelType, intFuelAmount, fltTotalCost);
    } else {
      alert('Please enter a valid fuel amount.');
    }
  }
});


// Requirement #23: Add a class to an existing page element
document.getElementById('fuelPump').classList.add('highlight');

// Requirement #20: Select page elements by class name
let elsFuelButtons = document.getElementsByClassName('fuelButton');


// Requirement #33 Create an event that alerts the user before leaving the page.
window.addEventListener('beforeunload', function(event) {
    event.preventDefault();
    event.returnValue = 'Are you sure you want to leave?';
});

// Requirement #22 Remove a page element
let elTransactionList = document.getElementById('transactionList');
if (elTransactionList) {
  elTransactionList.parentNode.removeChild(elTransactionList);
} else {
    console.log("No matching element found.");
}

// Requirement #29: Create at least two different mouse events that produce visible results on the page.
document.getElementById('fuelPump').addEventListener('mouseover', function(event) {
  if (event.target.tagName === 'BUTTON') {
    event.target.style.backgroundColor = 'rgba(0,0,0,0.5)';
  }
});

document.getElementById('fuelPump').addEventListener('mouseout', function(event) {
  // Requirement #13: Demonstrate the use of at least two comparison operators:
  if (event.target.tagName === 'BUTTON') {
    event.target.style.backgroundColor = '';
  }
});


// Requirement #28: Create two focus/blur or focusin/focusout events that produce visible results on the page.
document.getElementById('fuelPump').addEventListener('focus', function(event) {
  event.target.style.backgroundColor = 'rgba(0,0,0,0.5)';
}, true); 

document.getElementById('fuelPump').addEventListener('blur', function(event) {
  event.target.style.backgroundColor = '';
}, true); 

// Requirement #30: Create at least one keyboard event that produces visible results on the page
document.addEventListener('keydown', function(event) {
  // 
  if (event.key === 'Escape') {
    console.log('Escape key pressed!');
  }
//Requirement #31
document.addEventListener('DOMContentLoaded', function() {
  // Listen for form submission
  const feedbackForm = document.getElementById('feedback');
  feedbackForm.addEventListener('submit', function(event) {
    event.preventDefault(); // Prevent form submission

    // Get the feedback input value
    const feedbackInput = document.getElementById('feedbackInput').value;

    // Display the submitted feedback on the page
    const displayFeedback = document.getElementById('displayFeedback');
    displayFeedback.textContent = `Feedback: ${feedbackInput}`;

    // Clear the form input
    feedbackForm.reset();
  });
});
});
