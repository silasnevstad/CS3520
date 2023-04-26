// Program to check if the user-provided number is a palindrome
// Number of errors/bugs = 25

//TODO: Fix the bugs and make sure the program runs as expected.
//Provide a brief comment identifying each bug fixed.

// 1. Added using namespace std; to be able to use cout and cin directly
// 2. Changed void func(char x); to bool isPalindrome(int n);
// 3. Added parameter names to the function declaration.
// 4. Declared a new function void printResult(bool result); to print the result.
// 5. Changed void main() to int main()
// 6. added semicolons afer 'couts', 'return', 'float given_number', 'n/10'
// 7. Changed returned_val to result and func2 to isPalindrome
// 8. dded double quotes around "It is not a palindrome" to make it a string
// 9. Changed n = 0 to n != 0 in the while loop condition.
// 10. Changed temp * 10 + remainder; to temp = temp * 10 + remainder; to update temp correctly.
// 11. Changed if (n == temp) to if (n == reversed) to check the correct variable.
// 12. Added an else keyword to make the if-else statement complete

#include<iostream>

using namespace std;

bool isPalindrome(int n); // change the return type of the function to bool and add parameter names to the function declaration
void printResult(bool result); // declare a new function to print the result

int main() { // change the return type of main to int and add parentheses
    int input;
    cout << "Enter an integer please: ";
    cin >> input; // use cin to read the input integer
    bool result = isPalindrome(input);
    printResult(result); // call the new function to print the result
    return 0; // add a semicolon and return 0 at the end of main
}

bool isPalindrome(int n) {
    int temp = n; // assign n to temp
    int reversed = 0;
    while (temp != 0) { // use != instead of = in the while loop condition
        int remainder = temp % 10;
        reversed = reversed * 10 + remainder;
        temp = temp / 10; // update temp by dividing it by 10
    }
    if (n == reversed) { // return true if n is equal to reversed, false otherwise
        return true;
    }
    else {
        return false;
    }
}

void printResult(bool result) {
    if (result) {
        cout << "It is a palindrome" << endl;
    }
    else {
        cout << "It is not a palindrome" << endl;
    }
}

