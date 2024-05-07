#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//This line defines a function named isQueenSafe that takes in 4 parameters. 
//The first parameter is &chessboard which is a reference to a 2D vector representing the chessboard
//The second parameter is for the row to check if it's safe to place a queen
//The third parameter is for the column to check if it's safe to place a queen.
//The fourth parameter is for N, size of the chessboard 
bool isQueenSafe(vector<vector<int>>& chessboard, int row, int col, int N) {
//This line initializes a for loop that iterates through the columns to the left of the current column
//It starts from i = 0 and continues as long as i is less than col.
    for (int i = 0; i < col; i++) {
//inside the loop, this line checks if there's already a queen (1) in the same row but in a column to the left (i)
        if (chessboard[row][i] == 1) {
//If there is a queen in the same row to the left, it's not safe to place another queen in the current position
//and it will return the value false
            return false;
        }
    }
//This for loop iterates over the upper-left diagonal of the current position (row, col) on the chessboard
//i starts at row and j starts at col, representing the current position
//The loop continues as long as both i and j are greater than or equal to 0 
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
//This checks if there's a queen (1) in the current cell of the upper-left diagonal
        if (chessboard[i][j] == 1) {
//If a queen is found in this diagonal, the function immediately returns false
            return false;
        }
    }
//This for loop iterates over the lower-left diagonal of the current position (row, col) on the chessboard
//i starts at row and j starts at col, representing the current position.
//The loop continues as long as i is less than N  and j is greater than or equal to 0 
//Inside the loop, it checks if there's a queen (represented by 1) in the current cell of the lower-left diagonal
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
//This checks if there's a queen ( 1) in the current cell of the lower-left diagonal
        if (chessboard[i][j] == 1) {
//If a queen is found in this diagonal, the function immediately returns false
            return false;
        }
    }
//The function returns true if neither of the loops detects a queen in the diagonals
    return true;
}
//This line defines a function named printChessboard, which takes a reference to a 2D vector chessboard as its parameter
void printChessboard(vector<vector<int>>& chessboard) {
//This line calculates the size of the chessboard so N represents the number of rows and columns in the board
    int N = chessboard.size();
//This line prints a space to the console and this space will be used to align the column numbers
    cout << " ";
//This for loop iterates over the column indices from 0 to N - 1 
    for (int i = 0; i < N; i++) {
//This line prints each column number (increased by 1) with a space before it which will be for labeling the columns of the chessboard
        cout << " " << i + 1;
    }
//This line moves to the next line after printing the column numbers
    cout << endl;
//This line prints the current row number (increased by 1) before printing the contents of each cell in the row
    for (int i = 0; i < N; i++) {
        cout << i + 1;
//This nested for loop iterates over the columns in the current row
        for (int j = 0; j < N; j++) {
//This line checks the value of the cell at position (i, j) in the chessboard 
//If the value is 1, it prints " Q" to represent a queen in that cell
            if (chessboard[i][j] == 1) {
                cout << " Q"; 
//If the value is not 1, it prints " -" to represent an empty cell
            } else {
                cout << " -"; 
            }
        }
//This line moves to the next line after printing all cells in the current row,  starting a new line for the next row
        cout << endl;
    }
}
//This line defines a function named solveNQueens, which takes an integer N as its parameter
void solveNQueens(int N) {
//This line initializes the vector called chessboard representing the N x N chessboard 
//The N is initialized to 0 meaning there are no queens on the board 
    vector<vector<int>> chessboard(N, vector<int>(N, 0));
//This line creates a stack called columnStack which will keep track of the columns where queens have been placed
    stack<int> columnStack;
//This line initializes an integer variable Column to 0
    int Column = 0;
//This line starts an infinite loop
    while (true) {
//This if condition checks if all queens have been successfully placed on the board. 
//If the current column being considered (Column) is equal to N, it means that queens have been successfully placed in all N columns
        if (Column == N) {
//If all queens are placed, this code prints a message for the position & calls the printChessboard function to print the chessboard with the queen positions.
            cout << "Queen positions {row, column}:" << endl;
            printChessboard(chessboard);
//After printing the solution, the program breaks out of the infinite loop, ending the execution
            break;
        }
//This line initializes a boolean variable queenPlaced to false. It will be used to track whether a queen was successfully placed in the current column.
        bool queenPlaced = false;
//This line starts a loop that iterates through each row of the current column, attempting to place a queen in each row.
        for (int row = 0; row < N; row++) {
//Inside the loop, this code calls the isQueenSafe function to check if it's safe to place a queen in the current row of the current column. 
//It passes the chessboard, the current row (row), the current column (Column), and the size of the chessboard (N) as arguments
            if (isQueenSafe(chessboard, row, Column, N)) {
//If it's safe to place a queen in the current row, this line updates the chessboard to indicate that a queen is placed in the current row and column by setting the corresponding element to 1.
                chessboard[row][Column] = 1;
//This pushes the current column onto the columnStack, keeping track of the columns where queens have been placed.
                columnStack.push(Column);
//The program increments Column to move on to the next column.
                Column++;
//The queenPlaced flag is set to true to indicate that a queen was successfully placed in the current column.
                queenPlaced = true;
//If a queen is successfully placed in the current column, the program prints the chessboard after 
//placing the queen and then breaks out of the inner loop to move on to the next column
                cout << "Board after placing queen at {" << Column << ", " << row + 1 << "}:" << endl;
                printChessboard(chessboard);
                cout << endl;

                break;
            }
        }
//This line checks if queenPlaced is false, which means that no queen was successfully placed in the current column during the previous iteration
        if (!queenPlaced) {
//This checks if the columnStack (which keeps track of the columns where queens have been placed) is empty. 
//If it's empty, it means that there are no more columns to backtrack to
            if (columnStack.empty()) {
//If there are no columns left to backtrack to, this prints a message indicating that no solution was found for the given value of N
                cout << "No solution found for N = " << N << endl;
//The break statement exits the while loop since no solution is possible, and there's no need to continue searching for solutions.
                break;
            }
//If columnStack is not empty this line retrieves the most recently placed column from the top of the stack and assigns it to the Column variable   
            Column = columnStack.top();
//This removes the top element (the last column) from the columnStack, as the program is moving back to that column
            columnStack.pop();
//This for loop iterates through the rows of the column where backtracking is happening 
            for (int i = 0; i < N; i++) {
//This checks if a queen is placed in the current row of the column being backtracked (Column) by examining the chessboard matrix
                if (chessboard[i][Column] == 1) {
//If a queen is found in the current row of the column, it removes the queen
//by setting the corresponding element in the chessboard to 0
                    chessboard[i][Column] = 0;
//After removing the queen from the current row, the loop breaks, and the program moves on to the next step
                    break;
                }
            }
//Finally, the program increments Column to move on to the next column, allowing it to continue searching for a solution or backtrack further if necessary
            Column++;
        }
    }
}

//This line starts the main function
int main() {
//This line delcares the integer N
    int N;
//This line outputs a message to the user to enter a N value higher than 3
    cout << "Enter the value of N (N > 3): ";
//This line will take in the input from the user for N
    cin >> N;
//This line checks if N is less than or equal to 3 and, if so, prints an error message and exits
    if (N <= 3) {
        cout << "N must be greater than 3." << endl;
        return 1;
    }
// the program calls the solveNQueens function to solve the N-Queens puzzle for the given N
    solveNQueens(N);
    return 0;
}
