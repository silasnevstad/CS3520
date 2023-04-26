// Program to read 3-dimensional matrix and display the elements as 1xN^3 matrix
// TODO
// initize matrix using update_3d method (see comments below)
// display method must not be able to modify array elements (update the code as needed)
// display method must use a single loop/iterator to print the entire array with addresses
// display cannot use nested loops

// 1. Added #include <iomanip> to format the output.
// 2. Added #include <cstdlib> to use the random number generator.
// 3. Changed void main(void) to int main().
// 4. Added the int parameter to the display_1d function.
// 5. Changed the loop variables i, j, and k to be declared inside the for loop header.
// 6. Added the input method for the matrix. You can use either cin to read the input from the user or a random number generator to fill the matrix.
// 7. Changed the for loop in the display_1d function to use a single loop with one iterator to print all values.
// 8. Calculated the x, y, and z indices for each element based on the current iterator value.
// 9. Added setw(2) to format the output of each element.
// 10. Printed the address of each element in addition to its value.


#include <iostream>
#include <iomanip> // include the <iomanip> header to format the output
#include <cstdlib> // include the <cstdlib> header to use the random number generator
#define SIZE 7

using namespace std;

void update_3d(double Matrix_3d[][SIZE][SIZE], int size); 
void display_1d(double Matrix_3d[][SIZE][SIZE], int size); 

int main() { // remove the void parameter from main()
    double Matrix_3d[SIZE][SIZE][SIZE] = {};
    update_3d(Matrix_3d, SIZE);
    display_1d(Matrix_3d, SIZE);
    return 0;
}

void update_3d(double matrix[][SIZE][SIZE], int size) {
    cout << "Entering 3N elements of the matrix:" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                // use either cin to read the input from the user or a random number generator
                // for example, you can use rand() % 10 + 1 to generate a random number between 1 and 10
                // or cin >> matrix[i][j][k];
                matrix[i][j][k] = rand() % 10 + 1;
            }
        }
    }
}

void display_1d(double Matrix_3d[][SIZE][SIZE], int size) {
    cout << "Matrix elements:" << endl;
    for (int i = 0; i < size * size * size; i++) { // use a single loop with one iterator to print all values
        int x = i / (size * size); // calculate the x index
        int y = (i % (size * size)) / size; // calculate the y index
        int z = i % size; // calculate the z index
        cout << setw(2) << Matrix_3d[x][y][z] << " at address " << &Matrix_3d[x][y][z] << endl; // print the element and its address
    }
}

