// Function to update date and time
function updateDateTime() {
    var now = new Date();
    var datetimeElement = document.getElementById('datetime');
    datetimeElement.innerHTML = now.toLocaleString();
}
// Update date and time every second
setInterval(updateDateTime, 1000);
// Initial call to display date and time
updateDateTime();