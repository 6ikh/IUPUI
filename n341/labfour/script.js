/*
TITLE: script.js
AUTHOR: Parmindar Singh PS
CREATE DATE: 24 Mar 2024
PURPOSE: Functionality of the webpage
LAST MODIFIED ON: 31 Mar 2024
LAST MODIFIED BY: Parmindar Singh PS
MODIFICATION HISTORY:
- 27 Mar 2024: Create date
- 31 Mar 2024: Transfered everything from personal vscode
*/
// Requirement 3: Encapsulate your code using a function to ensure that the DOM has loaded before your code runs.  The textbook suggests using $(document).ready but it is depricated.
$(function(){
    // Requirement 5: Demonstrate a jQuery selection of multiple page elements by tag name or class name with a single jQuery selection.
    $("content").css(function(){
        $(this).addClass("highlight");
    });

    // Requirement 6: jQuery selection of a single page element by ID
    $("#newsletter").css("border", "2px solid #000");

    // Requirement 7: Filtered jQuery selection and change content
    $("#services li:even").css("color", "blue");

    // Requirement 8: For each of the selections in requirements 5-7, use a jQuery method to change the content of the selection. 
    // Change formatting (add class) for .content elements
    $(".content").addClass("highlight");

    // Change formatting (border) for #newsletter element
    $("#newsletter").css("border", "2px solid red");

    // Change formatting (color) for even-indexed li elements within #services section
    $("#services li:even").css("color", "red");

    // Requirement 9: Use the .each() method to loop through a jQuery selection of multiple page elements.
    $('.content').each(function() {
        //Requirement 10: Use $(this) inside the .each() loop with a jQuery method to create visible results on the page.
        $(this).append(' - Services at Barber Haven');
    });

    // Requirement 11: Use jQuery chaining to perform at least three methods on a single jQuery selection.
    $('.content')
        .css('color', 'red')   
        .addClass('title')      
        .fadeOut(1000);

    // Requirement 12: Using .html() method to change content
    $("#footer").html("<p>&copy; 2024 Barber Shop. We care for your style!</p>");
 
    // Requirement 13: Using .text() method to change content
    $(".message").text("Stop In today!");

    // Requirement 14: Adding an element using .after()
    $("#newsletterForm").after("<p>Subscribe to get the latest updates!</p>");

    // Requirement 15: Use two jQuery methods [ .attr() .removeAttr() .addClass() .removeClass() ] to change the attribute values of at least two different page elements.
    $("header h1").attr("id", "shopTitle");
    $("button").attr("disabled", true);

    // Requirement 16: Using .css() method to change color
    $("#footer").css("background-color", "#f4f4f4");

    // Requirement 17: Using .on() method to register events
    $('#button').on('click', function(){
        $('h1').css('color', '#FFFFFF');
    });

    // Requirement 18: Use the Event Object with a jQuery event registration to create an event that responds differently depending on which page element was clicked.
    $('#services li').on('click', function(event) {
        $(this).toggleClass('selected');
        console.log("Clicked on service: " + $(this).find('h3').text());
    });

    // Requirement 19: Use at least three jQuery Effects methods to enhance your page with transitions and movement.
    $("#services").hide().fadeIn(2000);
    $("footer").fadeOut(3000).fadeIn(3000);

    // Requirement 20: Use at least two jQuery methods to traverse the DOM to access a parent or sibling node of a previous selection
    $("label").closest("section").css("border", "2px solid red");
    $('#services ul').parent().css('background-color', 'lightgray');

    // Requirement 21: Create at least two jQuery selections that use form element selectors.
    $("input[type='email']").on("blur", function() {
        console.log("Blur event triggered");
        $("#output").text("Email input value: " + $(this).val());
    });

    $("#newsletterForm").on("submit", function(event) {
        console.log("Form submit event triggered");
        event.preventDefault();
        var email = $("#email").val();
        alert("Thank you for subscribing with email: " + email);
        $("#email").val("");
    });

    // Requirement 22: Removing an element from the page
    $("#footer").remove(); 

});
