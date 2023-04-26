//This program allocated memory for an NxM integer array dynamicaly 
//The program then prints the 2D array in a matrix form using a combination of * and [] operators
//Note: You can't use ** or [][] for printing the values (use a combination of * and [] only.

// 1. Changed for(i=0; i< N, i++) to for (i = 0; i < N; i++).
// 2. Changed d_array[i] = (int*) malloc(M * sizeof(int*) ); to d_array[i] = (int*) malloc(M * sizeof(int));.
// 3. Changed printf("Initializing array values!\n"); to cout << "Initializing array values!\n";.
// 4. Changed *(d_array+i+j) = i+j to d_array[i][j] = i + j.
// 5. Changed *(d_array[i] + j) to *(*(d_array + i) + j).
// 6. Added a return statement at the end of main().

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int N = 3, M = 5;
    int i, j; 
    int** d_array = (int**) malloc(N * sizeof(int*)); // change sizeof(int) to sizeof(int*)
    for (i = 0; i < N; i++) {
        d_array[i] = (int*) malloc(M * sizeof(int)); // remove the extra * in sizeof(int*)
    }
    //Initializing 2D array using [ ][ ] notation
    cout << "Initializing array values!\n"; // change printf to cout
    for (i = 0; i < N; i++) {			 
        for (j = 0; j < M; j++) {
            d_array[i][j] = i + j; // change *(d_array+i+j) to d_array[i][j]
        }
    }
    //Accessing 2D array using a combination of * and [] notation
    cout << "\n";
    for (i = 0; i < N; i++) {			 
        for (j = 0; j < M; j++) {
            cout << *(*(d_array + i) + j); // change *(d_array[i] + j) to *(*(d_array + i) + j)
        }
        cout << "\n";
    }
    //Deallocating 2D array
    for (i = 0; i < N; i++) {			 
        free(d_array[i]);
    }
    free(d_array);
    return 0; // add a return statement
}

