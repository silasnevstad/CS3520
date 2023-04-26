//This program should read any string (including spaces) from the user and print it using a character pointer
//The program is setup to use pointer offset notation to get each character of the string

// BUGS FIXED:
// 1. Changed #include <stdio> to #include <iostream> to use cout and cin
// 2. Added #include <string> to use the string type and related functions
// 3. Changed void main(void) to int main()
// 4. Changed char cPtr; to char *cPtr; to declare cPtr as a pointer to a char rather than just a char
// 5. Changed while (cPtr-- == '\0') to while (*cPtr != '\0') to check the value of the pointer
// 6. Changed cout << cPtr++; to cout << *cPtr; cPtr++; to dereference the pointer and increment it
// 7. Added endl to move to the next line and added a semicolon at the end
// 8. Added return 0; at the end of main()


#include <iostream> // change #include <stdio> to #include <iostream>
#include <string> // include the <string> header for string-related functions

using namespace std;

int main() { // change void to int in the function declaration
    char s[20];
    char *cPtr; // change cPtr to a pointer to a char
    cin >> s;
    cPtr = s;
    while (*cPtr != '\0') { // change the while loop condition to check the value of the pointer
        cout << *cPtr; // dereference the pointer to print the character
        cPtr++; // increment the pointer to point to the next character
    }
    cout << endl; // use endl to move to the next line and add a semicolon at the end
    return 0;
}

