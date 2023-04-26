/* Print the sum of products of odd and even numbers from 1 to 10
*  Print alternate characters from 'A' to 'Z' in the reverse order starting with 'Z'
*  Ouput of the program should look like:
    The value of limit is 10
    The Sum = 4785
    Z X V T R P N L J H F D B
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

// Errors and fixes:
// 1. 'cout' was not declared, you need to include 'std::' before 'cout' to use it
// 2. 'i' was not declared, it should be declared as an int variable
// 3. The for loop condition is incorrect, it should be i <= limit instead of i <= 0
// 4. The for loop increment operator is incorrect, it should be ++i instead of : i
// 5. The if condition for even numbers is incorrect, it should be i % 2 == 0 instead of i / 2 = 0
// 6. The if condition for odd numbers is incorrect, it should be i % 2 == 1 instead of i ** 2 == 1
// 7. The sum should be incremented inside the loop instead of being assigned a value
// 8. The second for loop should start with 'Z' and decrement by 2, it should be for(c = 'Z'; c >= 'A'; c-=2)
// 9. The output of the sum is incorrect, it should be cout<<"The Sum = "<< sum<<endl;
// 10. The output of characters should be cout<<c<<" "; instead of cout<<" "<< i;
// 11. limit variable should be initialized with a value, like 10, in order to get a proper output

#include <iostream>

int main() {
    int limit = 10, sum = 0;
    int evenSum = 1, oddSum = 1;
    char c;

    // Print the limit value
    std::cout << "The value of limit is " << limit << std::endl;

    // Calculate the sum of products of odd and even numbers from 1 to 10
    for (int i = 1; i <= limit; ++i) {
        // Check if the number is even
        if (i % 2 == 0) {
            // Calculate the sum of products of even numbers
            evenSum *= i;
        } else {
            // Calculate the sum of products of odd numbers
            oddSum *= i;
        }
    }

    // Calculate the sum of products of odd and even numbers
    sum = evenSum + oddSum;

    // Print the sum
    std::cout << "The Sum = " << sum << std::endl;

    // Print alternate characters from 'A' to 'Z' in reverse order starting with 'Z'
    for (c = 'Z'; c >= 'A'; c -= 2) {
        std::cout << c << " ";
    }

    return 0;
}

