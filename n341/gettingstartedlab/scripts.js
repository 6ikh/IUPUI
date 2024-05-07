/***********************************************
TITLE: Getting Started Lab
AUTHOR: Parmindar Singh (PM)
CREATE DATE: 12 Jan 2024
PURPOSE: Using JavaScript to add functionality to my HTML page  
LAST MODIFIED ON: 13 Jan 2024
LAST MODIFIED BY: Parmindar Singh (PM)
MODIFICATION HISTORY:
12 Jan 2024 - Added the header of the file (PM)
12 Jan 2024 - Added the main JS function code (PM)
12 Jan 2024 - Added comments to each line of code (PM)
13 Jan 2024 - Changed the function as I used alert but was required to use textContent (PM)
*************************************************/

/**************************************
NAME:  showCookieMessage
PURPOSE:  Displays an alert message indicating that there are no cookies left
PARAMETERS:  None
RETURN VALUE:  None
**************************************/
function showCookieMessage() {  //Declaring function showCookieMessage() with no parameters 
    var outputElement = document.getElementById("parm");    //Variable outputElement gets assigned the retrieved HTML Element "parm"
    outputElement.textContent = "There is none left, check back later!";    //The variable accesses the text content of the element and the id "parm" is set to the text content in quotes
}
