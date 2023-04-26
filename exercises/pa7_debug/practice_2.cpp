// Program to read integers into a 3X3 matrix and display them
// Todo: Fix bugs and makesure program works as intended.
// for each bug fix, add a comments specifying what you fixed.

// 1. Added using namespace std; to be able to use cout and cin directly.
// 2. Changed void display(double Matrix[3][3], int size); to void display(int Matrix[3][3], int size); to change the type of the Matrix array and the second parameter of the function to int.
// 3. Removed void from main().
// 4. Declared size as a const int to use it to declare the Matrix array.
// 5. Changed int Matrix[size + 1][size + 1]; to int Matrix[size][size]; to declare the Matrix array with the correct size.
// 6. Changed cin<<"Enter 9 elements of the matrix:"<<endl; to cout << "Enter 9 elements of the matrix:" << endl; to use cout.
// 7. Added int i = 0; to initialize i in the loop.
// 8. Changed for (; j < size; j++) to for (int j = 0; j < size; j++) to declare the loop variable j.
// 9. Changed display(&Matrix,3); to display(Matrix, size); to pass the correct arguments to the display function.
// 10. Changed for (int i = 0; i < size , i++) to for (int i = 0; i < size; i++) to use the correct syntax for the for loop
// 11. Added a semicolon after the cout statement.

#include <iostream>
using namespace std;

void display(int Matrix[3][3], int size); // change the second parameter to int instead of float

int main() { // remove the void parameter from main()
    const int size = 3; // declare size as a const int to use it to declare the Matrix array
    int Matrix[size][size]; // use size to declare the Matrix array
    cout << "Enter 9 elements of the matrix:" << endl;
    for (int i = 0; i < size; i++) { // declare i in the for loop header
        for (int j = 0; j < size; j++) { // declare j in the for loop header
            cin >> Matrix[i][j];
        }
    }
    display(Matrix, size); // pass the Matrix array and size to the display function
    return 0;
}

void display(int Matrix[3][3], int size) { // change the second parameter to int instead of float
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << Matrix[i][j] << ", ";
        }
        cout << endl; // add a semicolon after the cout statement
    }
}

