#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
//This line defines a constant integer variable MIN_KEYS and initializes it with the value 1. It's used to specify the minimum number of keys a node in a B-tree must have
const int MIN_KEYS = 1;
//This line defines a constant integer variable MAX_KEYS and initializes it with the value 5. It's used to specify the maximum number of keys a node in a B-tree must have
const int MAX_KEYS = 5;
//This code defines a C++ struct called BTreeNode. It's used to represent a node in the B-tree data structure
struct BTreeNode {
//A boolean flag indicating whether the node is a leaf node or an internal node in the B-tree
    bool isLeaf;
//A vector that holds integer keys, representing the values associated with this node
    std::vector<int> keys;
//A vector of pointers to other BTreeNode structs, representing child nodes of this node
    std::vector<BTreeNode*> children;
};
//This line defines a function named createBTreeNode that returns a pointer to a BTreeNode. It's used to create a new B-tree node 
BTreeNode* createBTreeNode() {
//This line creates a new BTreeNode on the heap and assigns its memory address to the newNode pointer. This new node will represent the node to be created
    BTreeNode* newNode = new BTreeNode();
//This line sets the isLeaf member of the newly created node to true, indicating that this node is a leaf node in the B-tree
    newNode->isLeaf = true;
//This line returns a pointer to the newly created and initialized BTreeNode
    return newNode;
}
//This line defines a function named insertInNode, which is used to insert an integer key into a given B-tree node represented by the node parameter
void insertInNode(BTreeNode* node, int key) {
//This line initializes int i to 0 that will find the correct position to insert the key while ensuring that the keys in the node remain in sorted order. 
    int i = 0;
//This line starts a while loop that continues as long as i is less than the number of keys in the node and the key to insert is greater than the current key at index i    
    while (i < node->keys.size() && key > node->keys[i]) {
//Inside the loop, i is incremented for each iteration to move through the keys in the node until the correct position for the new key is found
        i++;
    }
//This line inserts the key at the position within the keys vector of the node. It maintains the sorted order by using the insert method with the calculated index i
    node->keys.insert(node->keys.begin() + i, key);
}
//This line defines a function named splitNode, which is used to split a node in a B-tree, specifically the child node at the given childIndex, 
//and returns a pointer to the parent node
BTreeNode* splitNode(BTreeNode* parentNode, int childIndex) {
//This line retrieves the child node to be split from the parentNode at the specified childIndex 
    BTreeNode* nodeToSplit = parentNode->children[childIndex];
//This creates a new node called newRightNode using the createBTreeNode function, which will be the right node after the split
    BTreeNode* newRightNode = createBTreeNode(); 
//This line calculates the median key as the key at index MAX_KEYS / 2 and uses the insertInNode function to insert this median key into the parentNode.
    int median = nodeToSplit->keys[MAX_KEYS / 2];
    insertInNode(parentNode, median);
//This line creates a vector of keys in the newRightNode by copying the keys from the nodeToSplit starting from the position MAX_KEYS / 2 + 1 to the end of the keys vector
    newRightNode->keys = std::vector<int>(
        nodeToSplit->keys.begin() + MAX_KEYS / 2 + 1,
        nodeToSplit->keys.end()
    );
//This line resizes the nodeToSplit to have only the first half of its keys, removing the keys that were moved to the newRightNode
    nodeToSplit->keys.resize(MAX_KEYS / 2);
//This condition checks if the nodeToSplit is not a leaf node
    if (!nodeToSplit->isLeaf) {
//If the nodeToSplit is not a leaf node, this line sets the isLeaf property of the newRightNode to false, indicating that it's an internal node
        newRightNode->isLeaf = false;
//This line creates a vector of child nodes in the newRightNode by copying the children from the nodeToSplit starting from the position MAX_KEYS / 2 + 1 to the end of the children vector
        newRightNode->children = std::vector<BTreeNode*>(
            nodeToSplit->children.begin() + MAX_KEYS / 2 + 1,
            nodeToSplit->children.end()
        );
//If the nodeToSplit is not a leaf node, this code resizes the nodeToSplit to have only the first half of its children, removing the children that were moved to the newRightNode
        nodeToSplit->children.resize(MAX_KEYS / 2 + 1);
    }
//This line inserts the newRightNode into the parentNode immediately to the right of the childIndex position
    parentNode->children.insert(parentNode->children.begin() + childIndex + 1, newRightNode);
//Finally, the function returns a pointer to the parentNode after the split
    return parentNode;
}
//This line defines a function named insertBTree, which is used to insert a key into a B-tree starting from the given root node 
//It returns a pointer to the root of the modified tree
BTreeNode* insertBTree(BTreeNode* root, int key) {
//This condition checks whether the root node is full, indicating that it has reached the maximum allowed number of keys
    if (root->keys.size() == MAX_KEYS) {
//If the root is full, a new root node (newRoot) is created
        BTreeNode* newRoot = createBTreeNode();
//This new root is marked as not a leaf node (isLeaf = false) because it will have children
        newRoot->isLeaf = false;
//The original root node is added as the first child of the new root. This step creates a new level in the B-tree
        newRoot->children.push_back(root);
//The splitNode function is called to split the newly created root node (with the original root as its child). The result of this split becomes the new root node
        root = splitNode(newRoot, 0);
    }
//The code continues by initializing a currentNode pointer to the root, which is where the insertion process begins
    BTreeNode* currentNode = root;
//This loop iterates while the currentNode is not a leaf node, indicating that we haven't reached the level where the key should be inserted
    while (!currentNode->isLeaf) {
//index i is initialized to zero to find the correct position for key insertion within the currentNode
        int i = 0;
//This loop increments i until it finds the correct position for inserting the key within the currentNode
        while (i < currentNode->keys.size() && key > currentNode->keys[i]) {
            i++;
        }
//The nextNode is set to the child node at index i, which is the next node to be traversed in the B-tree
        BTreeNode* nextNode = currentNode->children[i];
//This condition checks whether the child node (nextNode) is full, indicating the need for a split
        if (nextNode->keys.size() == MAX_KEYS) {
//If the child node is full, the splitNode function is called to split it, and the result becomes the new currentNode
            currentNode = splitNode(currentNode, i);
//After splitting, if the key to be inserted is greater than the median key in the currentNode, i is incremented to move to the right side of the split
            if (key > currentNode->keys[i]) {
                i++;
            }
        }
//The loop continues by moving to the next level of the B-tree, specifically to the child node at index i
        currentNode = currentNode->children[i];
    }
//Finally, the key is inserted into the leaf node (currentNode) using the insertInNode function
    insertInNode(currentNode, key);
//The function returns a pointer to the root node of the modified B-tree.
    return root;
}
//This line defines a function named searchBTree, which is used to search for keys within a B-tree node, given a range defined by low and high 
//The matching keys are collected in the result vector
void searchBTree(BTreeNode* node, int low, int high, std::vector<int>& result) {
//This condition checks whether the node is a valid node. If it's not, the function returns, as there's nothing to search in an empty or non-existent node
    if (!node) {
        return;
    }
//An integer i is initialized to zero, which will be used to go through the keys in the node
    int i = 0;
//This loop moves i through the keys in the node until it finds the first key that is greater than or equal to low
    while (i < node->keys.size() && low > node->keys[i]) {
        i++;
    }
//This loop continues iterating through the keys while they are less than or equal to high,ensureing that it will stop searching when keys exceed the specified range
    while (i < node->keys.size() && node->keys[i] <= high) {
//Within this loop, if the current key falls within the range (greater than or equal to low and within high), it is added to the result vector
        if (low <= node->keys[i]) {
            result.push_back(node->keys[i]);
        }
        i++;
    }
//This condition checks if the node is not a leaf node, indicating that it has children nodes
    if (!node->isLeaf) {
//If the node is not a leaf, it enters a loop to recursively search within the child nodes, it calls the searchBTree function on each child node
        for (i = 0; i < node->children.size(); i++) {
            searchBTree(node->children[i], low, high, result);
        }
    }
}
//This line defines a function named printBTreeInOrder, which is used to print the keys in a B-tree node in sorted order
void printBTreeInOrder(BTreeNode* node) {
//This condition checks whether the node is valid. If it's not, the function returns, as there are no keys to print
    if (!node) {
        return;
    }
//This condition checks if the node is not a leaf node, indicating that it has children nodes
    if (!node->isLeaf) {
//If the node is not a leaf, this loop iterates through the child nodes and calls the printBTreeInOrder function on each of them. 
        for (int i = 0; i < node->children.size(); i++) {
            printBTreeInOrder(node->children[i]);
//Within this loop, it prints the keys in the current node in sorted order (in-order traversal), it checks that i is within the range of valid keys before printing
            if (i < node->keys.size()) {
                std::cout << node->keys[i] << " ";
            }
        }
//If the node is a leaf node, this code block is executed
    } else {
//In this block of code, it directly prints the keys in the leaf node in sorted order, as there are no child nodes to consider
        for (int i = 0; i < node->keys.size(); i++) {
            std::cout << node->keys[i] << " ";
        }
    }
}
//This line defines the main function
int main() {
//Declares an integer variable N to store the user's input value
    int N;
//Displays a prompt asking the user to enter a value for N
    std::cout << "Enter the value of N (N >= 400): ";
//Reads the user's input value for N from the standard input
    std::cin >> N;
//Checks if the value of N is less than 400
    if (N < 400) {
//If N is less than 400, this line prints a message indicating that N must be greater than or equal to 400
        std::cout << "N must be greater than or equal to 400." << std::endl;
//Exits the program with a return code of -1, indicating an error
        return -1;
    }
//Seeds the random number generator with the current time to ensure different random sequences each time the program is run.
    std::srand(static_cast<unsigned>(std::time(NULL)));
//Create a new B-tree node (root) and sets it as a leaf node
    BTreeNode* root = createBTreeNode();
    root->isLeaf = true;
//Starts a loop that will run N times.
    for (int i = 0; i < N; i++) {
//Generates a random integer key in the range from 0 to 3*N (inclusive) using the std::rand function
        int key = std::rand() % (3 * N + 1);
//Calls the insertBTree function to insert the generated key into the B-tree rooted at root
        root = insertBTree(root, key);
    }
//Declares an integer variable low and initializes it with the value of N
    int low = N;
//Declares an integer variable high and initializes it with twice the value of N
    int high = 2 * N;
//Declares a vector keysFound to store the keys that are found within the specified range.
    std::vector<int> keysFound;
//Calls the searchBTree function to search for keys in the B-tree root within the range defined by low and high, and the results are stored in the keysFound vector
    searchBTree(root, low, high, keysFound);
//This line of code prints the message to the user "(a) the tree:"
    std::cout << "(a) the tree:" << std::endl;
//Calls the printBTreeInOrder function to print the keys in the B-tree in sorted order. This displays the B-tree structure as well
    printBTreeInOrder(root);
//Outputs a newline character to separate the B-tree structure from the next output
    std::cout << std::endl;
//Printed statement to the user that prints the keys found during the search. 
    // Print the keys found
    std::cout << "(b) array of keys found: ";
//Checks if the keysFound vector is empty, meaning no keys were found within the specified range
    if (keysFound.empty()) {
//If keysFound is empty, this message is displayed to indicate that no keys were found within the range
        std::cout << "(empty array or null for no keys found)";
//If keysFound is not empty (meaning keys were found), the following block of code is executed
    } else {
//Iterates through the keysFound vector and prints each key separated by spaces
        for (int key : keysFound)
            std::cout << key << " ";
    }
//Outputs a newline character to separate the keys found output from the return statement.
    std::cout << std::endl;
//Exits the program with a return code of 0
    return 0;
}

