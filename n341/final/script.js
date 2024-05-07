/*
TITLE: script.js
AUTHOR: Parmindar Singh (PS)
CREATE DATE: 20 April 2024
PURPOSE: Gas Station Pump for customers to choose which fuel grade and check out, the functionality
LAST MODIFIED ON: 27 April 2024
LAST MODIFIED BY: Parmindar Singh (PS)
MODIFICATION HISTORY:
20 April 2024: Initial creation of the HTML file. (PS)
27 April 2024: Transfered everything from personal vscode (PS)
*/

//Theme: This theme will be for a gas station were customers can check out food and purchase gas, currently I have created the gas part but will add more on -->

$( "#accordion" ).accordion();

var availableTags = [
	"ActionScript",
	"AppleScript",
	"Asp",
	"BASIC",
	"C",
	"C++",
	"Clojure",
	"COBOL",
	"ColdFusion",
	"Erlang",
	"Fortran",
	"Groovy",
	"Haskell",
	"Java",
	"JavaScript",
	"Lisp",
	"Perl",
	"PHP",
	"Python",
	"Ruby",
	"Scala",
	"Scheme"
];
$( "#autocomplete" ).autocomplete({
	source: availableTags
});

$( "#button" ).button();
$( "#button-icon" ).button({
	icon: "ui-icon-gear",
	showLabel: false
});

$( "#radioset" ).buttonset();

$( "#controlgroup" ).controlgroup();

$( "#tabs" ).tabs();

$( "#dialog" ).dialog({
	autoOpen: false,
	width: 400,
	buttons: [
		{
			text: "Ok",
			click: function() {
				$( this ).dialog( "close" );
			}
		},
		{
			text: "Cancel",
			click: function() {
				$( this ).dialog( "close" );
			}
		}
	]
});

// Link to open the dialog
$( "#dialog-link" ).click(function( event ) {
	$( "#dialog" ).dialog( "open" );
	event.preventDefault();
});

$( "#datepicker" ).datepicker({
	inline: true
});

$( "#slider" ).slider({
	range: true,
	values: [ 17, 67 ]
});

$( "#progressbar" ).progressbar({
	value: 20
});

$( "#spinner" ).spinner();

$( "#menu" ).menu();

$( "#tooltip" ).tooltip();

$( "#selectmenu" ).selectmenu();

// Hover states on the static widgets
$( "#dialog-link, #icons li" ).hover(
	function() {
		$( this ).addClass( "ui-state-hover" );
	},
	function() {
		$( this ).removeClass( "ui-state-hover" );
	}
);

// Requirement #16: Use a Date Object method.
$("datepicker").datepicker();


// Requirement #17: Create and use an object that has properties and methods.
let objFuelPrices = {
    fltRegular: 2.50,
    fltPremium: 3.00,
    fltDiesel: 2.75,
    fltE85: 1.85,
    calculateTotalCost: function(fuelType, fuelAmount) {
      let fltTotalCost = 0;
      // Requirement #5: Demonstrate the use of an if/else construct or a switch/case construct.
      switch (fuelType) {
        case 'regular':
          //Requirement #18: Use the keyword this in at least one of your object's methods.
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
      //Requirement #15: Use a Math Object method.
      return Math.round(fltTotalCost);
    }
  };

  // Requirement #4: Create and use an array.
  let arrTransactionHistory = [];
  

  // Function to add transaction details to transaction history list
  function addToTransactionHistory(fuelType, fuelAmount, fltTotalCost) {
    const strTransactionDetails = `${fuelType}: ${fuelAmount} gallons - Total Cost: $${fltTotalCost}`; 
    arrTransactionHistory.push(strTransactionDetails);
    displayTransactionHistory(); // Update transaction history UI
  }
  
  
  $('#fuelPump').on('DOMNodeInserted', 'button', function(event) {
      // Create a new button
      const newButton = $('<button>New Button</button>');
      // Append the new button to the fuelPump element
      $(this).parent().append(newButton);
  });
  
  // Function to update transaction history list in the UI
  function displayTransactionHistory() {
      const elTransactionList = $('#transactionList');
      if (!elTransactionList.length) {
        console.log("Transaction list element not found.");
        return;
      }
      
      elTransactionList.html('');  
      
      // Check if arrTransactionHistory is defined and not empty
      if (!Array.isArray(arrTransactionHistory) || arrTransactionHistory.length === 0) {
        console.log("Transaction history is empty.");
        return;
      }

      arrTransactionHistory.forEach(transaction => {
        const elListItem = $('<li></li>').text(transaction);
        elTransactionList.append(elListItem);
      });
    }

  //Requirement #14: Demonstrate jQuery chaining.
  $('li.highlight')
    .css({
        'color': 'blue',
        'font-weight': 'bold',
        'text-decoration': 'underline'
    })
    // Chain to add a click event handler
    .on('click', function() {
        $(this).toggleClass('clicked');
    });

    
  $('#fuelPump').on('click', 'button', function(event) { 
    event.stopPropagation(); 
    // Requirement #13: Demonstrate the use of at least two comparison operators:
    if ($(this).is('button')) {
      const strFuelType = this.id.replace('Btn', '');
      // Requirement #8: Use parseInt() to convert a string to an integer.
      const intFuelAmount = parseInt(prompt(`Enter fuel amount for ${strFuelType}:`));
      // Requirement #7: Demonstrate the use of logical operators 
      if (!isNaN(intFuelAmount) && intFuelAmount > 0) {
        const fltTotalCost = objFuelPrices.calculateTotalCost(strFuelType, intFuelAmount);
        //Requirement #11: A jQuery method to change a page element's content. 
        $('#fuelType').text(`Fuel Type: ${strFuelType}`);
        $('#fuelAmount').text(`Fuel Amount: ${intFuelAmount} gallons`);
        $('#totalCost').text(`Total Cost: $${fltTotalCost}`);
        
        // Add transaction to history
        addToTransactionHistory(strFuelType, intFuelAmount, fltTotalCost);
      } else {
        alert('Please enter a valid fuel amount.');
      }
    }
  });
  
  
  // Requirement #10: Use jQuery to add a class to an existing page element.
  $('#fuelPump').addClass('highlight');

  let elsFuelButtons = $('.fuelButton');
  
  
  $(window).on('beforeunload', function(event) {
      event.preventDefault();
      event.returnValue = 'Are you sure you want to leave?';
  });
  //Requirement #9: Use jQuery to remove or hide a page element
  let elTransactionList = $('#transactionList');
  if (elTransactionList.length) {
    elTransactionList.remove();
  } else {
      console.log("No matching element found.");
  }
  // Requirement #12: Use a jQuery event to produce visible results on the page when the user triggers the event.
  $('#fuelPump').on('mouseover', 'button', function(event) {
    if ($(this).is('button')) {
      $(this).css('background-color', 'rgba(0,0,0,0.5)');
    }
  });
  
  
  // Requirement #6: Demonstrate the use of comparison operators.
  $('#fuelPump').on('mouseout', 'button', function(event) {
    // Check if the background color of the button is not equal to red
    if ($(this).css('background-color') !== 'red') {
        // Change the background color of the button to green
        $(this).css('background-color', 'green');
    }
  });

  // Requirement #13: Use a jQuery animation method.
   $('#fuelPump').on('click', function() {
    // Select the element to animate
    let element = $('#feedback');
    
    // Perform the animation
    element.animate({
        opacity: 0.25,
        left: '+=50',
        height: 'toggle'
    }, 1000, function() {
        // Animation complete.
    });
   });

   // Requirement #25: Use the jQuery .on() method with at least one form event listed in Chapter 13 of the text to add functionality to your form [ blur focus change input keydown keypress].
    $("#name, #email, #phone, #comments").on("focus", function() {
        if ($("#selectmenu option:selected").val() !== "") {
            console.log("A service is selected.");
        } else {
            console.log("No service is selected.");
        }
    });

    // Requirement #23: Use jQuery to validate at least one input field with a regular expression. Also use the placeholder attribute in the same field to show an example of valid input for the user.
    $( "#phone" ).focus(function() { // Requirement #24: Use at least one form method listed in Chapter 13 of the text to add functionality to your form .focus() 
	    $(this).attr("placeholder", "e.g. 123-456-7890");
    });

    // Requirement #22: Create a labeled output area for form output. Form field values must display to the output area with labels on submit.
    $("#myForm").on("submit", function(event) {
        event.preventDefault();
	    var formData = $(this).serializeArray();
	    var output = "";
        // Requirement #19: Use the jQuery .each() method to process a jQuery selection that contains multiple page elements.: 
        $.each(formData, function(index, field) { 
		output += "<p style='font-weight: bold;'>" + field.name + ":</p>";
		output += "<p>" + field.value + "</p>";
    });
    $("#outputArea").html(output);
    });
    
  // Requirement #20: Use the Event Object in a jQuery method or an object method.
  $('#fuelPump').on('focus', 'button', function(event) {
    $(this).css('background-color', 'rgba(0,0,0,0.5)');
  }); 
  
  $('#fuelPump').on('blur', 'button', function(event) {
    $(this).css('background-color', '');
  }); 
  
  $(document).on('keydown', function(event) {
    // Requirement #6: Demonstrate the use of comparison operators.
    if (event.key === 'Escape') {  
      console.log('Escape key pressed!');
    }
    });
    // Requirement #26: Submit button should be disabled until at least one form field is filled
    $(document).ready(function() {
        var form = $('#myForm'); // The form
        var submit = $('#button'); // Submit button
        var submitted = false; // Has form been submitted?
    
        submit.prop('disabled', true); // Disable submit button
        submit.addClass('disabled'); // Style submit button
    
        // Function to check if at least one form field is filled
        function checkFormFields() {
            var formFields = form.find("input[type='text'], input[type='email'], input[type='tel'], textarea, select");
            var isAnyFieldFilled = false;
    
            formFields.each(function() {
                if ($(this).val().trim() !== "") {
                    isAnyFieldFilled = true;
                    return false; // Exit the loop if any field is filled
                }
            });
            return isAnyFieldFilled;
        }
    
        // Enable/disable submit button based on form field inputs
        form.on('input', function() {
            if (checkFormFields()) {
                submit.prop('disabled', false);
                submit.removeClass('disabled').addClass('enabled');
            } else {
                submit.prop('disabled', true);
                submit.removeClass('enabled').addClass('disabled');
            }
        });
    
        // On submit
        form.on('submit', function(e) {
            if (submit.prop('disabled') || submitted) {
                e.preventDefault(); // Stop form submission
                return;
            }
    
            submit.prop('disabled', true); // Disable submit button
            submitted = true; 
            submit.addClass('disabled'); 
        });
    });
