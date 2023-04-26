// [--- Part 1 ---]
// Open an input file and output file
// Loop through each line from the input file and store numbers in a vector
// Calculate the total number of elements in the vector and their sum
// Create a 2D array from the vector of numbers, that minimizes the number of empty cells
// Create a 3D array from the 2D array, that minimizes the number of empty cells
// Print the total sum of numbers in the vector
// Print the elements of the 2D array
// Print the elements of the 3D array
// Close the input file and output file.

// [--- Part 2 ---]
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    ifstream inFile("input.txt"); // input file stream object
    ofstream outFile("output.txt"); // output file stream object
    vector<double> numbers; // vector to store the numbers from the input file
    int total_numbers = 0; // total number of numbers in the input file
    double total_sum = 0.0; // total sum of numbers in the input file

    // loop through each line in the input file
    for (string line; getline(inFile, line);) {
        // create a string stream object
        istringstream iss(line);
        // loop through each number in the line
        for (double number; iss >> number;) {
            total_numbers++;
            total_sum += number;
            numbers.push_back(number);
        }
    }

    int  num_rows = ceil(sqrt(total_numbers)); // square root of the total number = number of rows
    int num_cols = ceil((double)total_numbers / num_rows); // number of columns in the 2d array
    // create a 2d array with the calculated number of rows and columns
    double** array = new double*[num_rows];
    for (int i = 0; i < num_rows; i++) {
        array[i] = new double[num_cols]; // create a 1d array for each row
        for (int j = 0; j < num_cols; j++) {
            // fill the array with the numbers from the vector if the number exists
            if (i * num_cols + j < total_numbers) {
                array[i][j] = numbers[i * num_cols + j];
            } else {
                array[i][j] = 0;
            }
        }
    }

    // convert the 2d array to a 3d array
    int num_pages = ceil(cbrt(total_numbers)); // cube root of the total numbers = number of pages
    int nums_per_page = ceil((double)total_numbers / num_pages); // number of numbers per page
    int num_rows_3d = ceil(sqrt(nums_per_page)); // number of rows per page
    int num_cols_3d = ceil((double)nums_per_page / num_rows_3d); // number of columns per page
    double*** array_3d = new double**[num_rows_3d];
    for (int page = 0; page < num_pages; page++) {
        array_3d[page] = new double*[num_rows_3d]; // create a 2d array for each page
        for (int row = 0; row < num_rows_3d; row++) {
            array_3d[page][row] = new double[num_cols_3d]; // create a 1d array for each row
            for (int col = 0; col < num_cols_3d; col++) {
                // fills the array with the numbers from the vector if the number exists
                if (page * num_rows_3d * num_cols_3d + row * num_cols_3d + col < total_numbers) {
                    array_3d[page][row][col] = numbers[page * num_rows_3d * num_cols_3d + row * num_cols_3d + col];
                } else {
                    array_3d[page][row][col] = 0;
                }
            }
        }
    }

    // print the total numbers and total sum
    outFile << "The total sum is " << (double) total_sum << endl;

    outFile << endl; // prints a blank line

    // print the 2d array
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            outFile << array[i][j] << " ";
        }
        outFile << endl;
    }

    outFile << endl; // prints a blank line

    // print the 3d array
    for (int page = 0; page < num_pages; page++) { // loop through each page 
        for (int row = 0; row < num_rows_3d; row++) { // loop through each row 
            for (int col = 0; col < num_cols_3d; col++) { // loop through each column
                outFile << array_3d[page][row][col] << " ";
            }
            outFile << endl;
        }
        outFile << endl; // prints a blank line
    }

    // close the input file and output file
    inFile.close();
    outFile.close();
}
