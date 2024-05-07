/*
TITLE: labfive.js
AUTHOR: Parmindar Singh (PS)
PURPOSE: JavaScript Functionality For Lab Five
ORIGINALLY CREATED ON: 13 April 2024 (PS)
LAST MODIFIED ON: 14 April 2024 (PS)
LAST MODIFIED BY: Parmindar Singh (PS)
MODIFICATION HISTORY: 
13 Apr 2024 - Creation Date (PS)
14 Apr 2024 - Transfered everything from personal VsCode (PS)
*/


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

//datepicker jQuery
$("datepicker").datepicker();

// Requirement #11: Use jQuery to validate at least one input field with a regular expression. Also use the placeholder attribute in the same field to show an example of valid input for the user.
$( "#phone" ).focus(function() { // Requirement #12: Use at least one form method listed in Chapter 13 of the text to add functionality to your form .focus() 
	$(this).attr("placeholder", "e.g. 123-456-7890");
  });
// Requirement #9: When the user submits the form, all form data should echo to the output area with labels. For example:
$("#myForm").on("submit", function(event) {
	event.preventDefault();
	var formData = $(this).serializeArray();
	var dateSelected = $("#datepicker").datepicker("getDate");
	var output = "";
	$.each(formData, function(index, field) {
		output += "<p style='font-weight: bold;'>" + field.name + ":</p>";
		output += "<p>" + field.value + "</p>";
	});
	$("#outputArea").html(output);
});

// Requirement #13: Use the jQuery .on() method with at least one form event listed in Chapter 13 of the text to add functionality to your form [ blur focus change input keydown keypress].
$("#name, #email, #phone, #comments").on("focus", function() {
// Requirement #10: Data can be extracted from the form using JavaScript value, checked or selected properties as appropriate or jQuery .val() method, :checked filter or :selected filter.
    if ($("#selectmenu option:selected").val() !== "") {
        console.log("A service is selected.");
    } else {
        console.log("No service is selected.");
    }
});



