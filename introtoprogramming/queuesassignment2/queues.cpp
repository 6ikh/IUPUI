//Include the input-output stream library for console I/O.
#include <iostream>
//This allows the use of standard C++ library components without prefixing them with std::
using namespace std;  
//Defined a C++ class called "Queue"
class Queue { 
//Defined an inner struct called "Node" to represent elements in the queue
    struct Node {
//Defined variable data to store the int data of each element in the queue
        int data;
//Define member variable "next" of type pointer to Node. It will point to the next element in the queue
        Node* next;
    };
//Point to the top element of the queue
    Node* top; 
//Point to the bottom element of the queue
    Node* bottom;   
public:
//Constructor for the Queue class, initializes top and bottom pointers as NULL indicating an empty queue
    Queue() : top(NULL), bottom(NULL) { 
//Output a message to indicate the queue has been created
        cout << "Parm's queue is ready!" << endl; 
    }
//This is the destructor for the Queue class and is called when an instance of the class is destroyed
    ~Queue() { 
//Outputs a message to indicate the queue is being destroyed
        cout << "Bye queue!" << endl;
//This line starts a while loop that continues until the isEmpty() function returns true
//Dequeues all elements in the queue before the object is destroyed.
        while (!isEmpty()) {
//Remove and deallocate the top element of the queue in each iteration.
            dequeue();
        }
    }
//Function enqueue with parameter int num to add an element to the bottom of the queue
    void enqueue(int num) { 
//Create a new Node to hold the data and allocates memory for a new node using the new operator
        Node* newNode = new Node;
//Assign the integer value num to the data member of the new node, setting the data for this element
        newNode->data = num;
//Set the next pointer of the new node to NULL, indicating that this node is currently the last element in the queue
        newNode->next = NULL;
//New if condiion that checks if the queue is empty by calling the isEmpty() method.
        if (isEmpty()) {
//If the queue is empty, both top and bottom pointers point to the new node, as it is the only element in the queue
            top = bottom = newNode;
//Else condition if the queue is not empty:
        } else {
//The next pointer of the current bottom element points to the new node, linking it to the end of the queue
            bottom->next = newNode; 
//The bottom pointer now points to the new node, making it the newn bottom element of the queue
            bottom = newNode;
        }
    }
//Dequeue method to remove the top element from the queue
    void dequeue() {
//If condition that checks if the queue is empty
        if (isEmpty()) {
//If the queue is empty, the program wil ouput an error message 
            cout << "Trying to dequeue from an empty queue" << endl; 
//Returns without performing a dequeue operation since there are no elements to dequeue.
            return;
        }
//If the queue is not empty, the function proceeds to dequeue the front element:
//Create a temporary pointer temp to the front node of the queue
        Node* temp = top;
//The top pointer is moved to the next node in the queue
        top = top->next;
//Delete the old front node to free memory and prevent memory leaks
        delete temp;
    }
//This function checks if the queue is empty and returns a boolean value 
    bool isEmpty() const {
//Returns true if the top pointer is NULL indicating an empty queue
        return top == NULL;
    }
//This function prints the elements in the queue. 
    void printQueue() const {
//If condition to check if the queue is empty by calling the isEmpty() method
        if (isEmpty()) {
//If the queue is empty, print a message indicating that the queue is empty and returns
            cout << "Queue is empty" << endl; 
            return;
        }
//If the queue is not empty, the function proceeds to print its elements:
//Initialize a temporary pointer temp to the top element of the queue
        Node* temp = top;
//Print a message to the user fod the queue contents
        cout << "Queue contents:" << endl;
//Enter a while loop that iterates through the queue until temp becomes NULL printing each element
        while (temp != NULL) {
//Print the data of the current node pointed to by temp.
            cout << temp->data << endl; 
//Move temp to the next node in the queue for the next iteration
            temp = temp->next;
        }
    }
};
//Main function of the program
int main() { 
//Outputs a "Hello World!" message to the user
    cout << "Hello World!" << endl; 
//Create an instance of the Queue class called "q."
    Queue q;
//Call the printQueue method to print the initially empty queue
    q.printQueue();
//This is a for loop that iterates from 1 to 5
    for (int i = 1; i <= 5; i++) {
//Add the numbers 1 through 5 to the end of the queue using the enqueue method
        q.enqueue(i);
    }
//Print the queue after enqueuing
    q.printQueue();
//Dequeue 3 numbers
    for (int i = 0; i < 3; i++) {
//Remove the front three elements
        q.dequeue();
    }
//Print the queue after dequeuing
    q.printQueue();
//Dequeue 3 more numbers and show an appropriate error message if the queue is empty
    for (int i = 0; i < 3; i++) {
        q.dequeue();
    }
//Print the empty queue
    q.printQueue();
//Program has been successfully executed
    return 0; 
}
