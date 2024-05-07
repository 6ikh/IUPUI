#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//This line begins the definition of a new struct called TreeNode
struct TreeNode {
//This line declares an integer variable named value within the TreeNode struct
    int value;
//This line declares a pointer to another TreeNode struct named left. This pointer is used to point to the left child node of the current node
    TreeNode* left;
//This line declares a pointer to another TreeNode struct named right. Similar to the left pointer, this one is used to point to the right child node of the current node.
    TreeNode* right;
//This is the constructor for the TreeNode struct. It takes an integer x as an argument. The left and right pointers are also initialized to nullptr, indicating that the new node initially has no left or right children
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};
// This line builds a balanced BST from a sorted vector of integers. Int start represents the start of the vector index. Int end is for the vector subrange
TreeNode* BalancedBST(vector<int>& numbers, int start, int end) {
//This if statement will check if the start index is greater than the end index
    if (start > end) {
//If it is true, this means the subrange of the vector is empty and returns a nullptr. 
        return nullptr;
    }
//This line calculates the middle index (mid) of the current subrange of the vector by taking the average of start and end
    int mid = start + (end - start) / 2;
//A new TreeNode object is created called newNode. The val of this new node is set to the value at the middle index nums[mid]. This node represents the root of the current subtree
    TreeNode* newNode = new TreeNode(numbers[mid]);
//The left subtree is constructed by calling BalancedBST with the subrange from start to mid-1
    newNode->left = BalancedBST(numbers, start, mid - 1);
//The right subtree is constructed by calling BalancedBST with the subrange from mid + 1 to end
    newNode->right = BalancedBST(numbers, mid + 1, end);
//The function returns a pointer to the newNode, which represents the root of the current subtree
    return newNode;
}
//This line defines an int function named findKthSmallest that takes two parameters: TreeNode* root, a pointer to the root, and int& k, a reference to int k representing the k-th smallest element to find in the BST
int findKthSmallest(TreeNode* root, int k, int& count) {
//If statement checks if the root pointer is equal to nullptr, which means the tree is empty
    if (root == nullptr) {
 // Return -1 if the tree is empty. 
        return -1; 
    }
//This line calls the findKthSmallest function on the left subtree of the current root node. It assigns the result to leftResult, which represents the k-th smallest element found in the left subtree
    int leftResult = findKthSmallest(root->left, k, count);
//If statement checks if count is equal to k. If they are equal, it means that the k-th smallest element has been found in the left subtree. 
    if (count == k) {
//The function returns leftResult, which holds the k-th smallest element in the left subtree.
        return leftResult; 
    }
//This line increments the count variable, which keeps track of the number of elements encountered during the traversal.
    count++;
//If count reaches k, k-th smallest element has been found at the current root node. In this case, the function returns root->val, which is the value of the k-th smallest element at the current node.
    if (count == k) {
//The function returns root->val, which is the value of the k-th smallest element at the current node.
        return root->value; 
    }
//If the k-th smallest element hasn't been found in the left subtree or at the current node, the function searches for it in the right subtree by calling itself with the root pointer set to root->right. This recursive search continues until the k-th smallest element is found.
    return findKthSmallest(root->right, k, count); 
}
//This line defines a function named printBST that takes the parameter TreeNode* root which is a pointer to the root of BST
void printBST(TreeNode* root) {
//If statement that checks if the root pointer is nullptr, indicating that the current subtree is empty
    if (root == nullptr) {
//If the root is nullptr, the function returns, terminating further execution
        return;
    }
//This line prints the elements of the left subtree, performing an in-order traversal of the BST, where elements are printed in ascending order.
    printBST(root->left);
//This line prints the value of the current root node to the standard output and adds a space after printing the value to separate it from the next value that will be printed during the traversal.
    cout << root->value << " ";
//This line is a recursive call to the printBST function on the right subtree of the current root node. It prints the elements of the right subtree in the same in-order manner.
    printBST(root->right);
}
//This line defines the main function.
int main() {
// Given a set of integers in an array
    vector<int> nums = {6, 17, 20, 41, 45, 52, 57, 65, 71, 76, 79, 87, 92, 95, 99};
//This line sorts the elements in the nums vector in ascending order using the std::sort function. 
    sort(nums.begin(), nums.end());
//This line calls the BalancedBST function to construct a BST from the sorted nums vector. The 0 and nums.size() - 1 parameters specify the range of elements in the vector to use for building the tree.
    TreeNode* root = BalancedBST(nums, 0, nums.size() - 1);
//: This line declares an integer variable named k to store the user's input, which will represent the "k-th smallest" element to find in the BST.
    int k;
//This line outputs a prompt to the console, asking the user to enter the value of k.
    cout << "Enter the value of k: ";
//This line reads the user's input from the console and stores it in the k variable.
    cin >> k;
//This line initializes an integer variable named count to 1. This variable is used to keep track of the number of elements encountered during the traversal of the BST.
    int count = 1; 
//This line calls the findKthSmallest function to find the k-th smallest element in the BST. It passes the root of the tree, the value of k entered by the user, and the count variable used for tracking.
    int result = findKthSmallest(root, k, count);
//These lines of code are responsible for displaying the result of the k-th smallest element search. If result is not equal to -1 (indicating a valid result), it prints the k-th smallest element along with a message. 
    if (result != -1) {
        cout << "The " << k << "th smallest element is: " << result << endl;
//If the result is -1, it means that the tree doesn't have at least k elements, and it prints an appropriate message.
    } else {
        cout << "The tree doesn't have at least " << k << " elements." << endl;
    }
//These lines print the elements of the balanced BST in an in-order traversal, which results in the elements being printed in ascending order. It starts with "Balanced BST (in-order traversal):" and then calls the printBST function to display the elements of the BST.
    cout << "Balanced BST (in-order traversal): ";
    printBST(root);
    cout << endl;
//Return 0 for program end
    return 0;
}
