// Automatic dialing machine
// Delivers a sales message
/* Needs to print all possible combinations of areacode and exchangecode with the last 4 digits
Example : If areacode = 617, exchange = 424
Output : 
"I am calling to tell you to buy a subscription to Dogs Monthly Magazine!"
617-424-0001
617-424-0002
617-424-0003
...
617-424-9998
617-424-9999
*/

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

// Errors and fixes:
// 1. The variable 'exchange' and 'areaCode' should be switched when used in cin statement.
// 2. The second for loop should start with digit2 = 0 and increment by 1, it should be for(digit2 = 0; digit2 <= 9; ++digit2)
// 3. The while loop condition is incorrect, it should be looping through digit3, and digit4
// 4. The cout statement inside the while loop is incorrect, it should be cout<< areaCode<<"-"<< exchange<<"-"<< digit1<<digit2<<digit3<<digit4<<std::endl;
// 5. The cout statement for the message should be outside the for loops
// 6. The return statement is missing a value, it should be return 0;
// 7. There is a missing quotation mark in the first cout statement, it should be std::cout<< "Enter a three-digit area code: ";

#include<iostream>
  
int main(){
    int digit1, digit2, digit3, digit4;
    int areaCode, exchange;
    std::cout<< "Hello, I am a telemarketing calling making program."<<std::endl;
    std::cout<< "Enter a three-digit area code: ";
    std::cin>>areaCode;
    std::cout<<"Enter a three-digit exchange to call: ";
    std::cin>>exchange;
    for(digit1 = 0; digit1 <= 9; ++digit1) {
        for(digit2 = 0; digit2 <= 9; ++digit2) {
            for(digit3 = 0; digit3 <= 9; ++digit3) {
                for(digit4 = 0; digit4 <= 9; ++digit4) {
                    std::cout<< "Dialing ("<< areaCode<<") "<< exchange<<" - ";
                    std::cout<<digit1<<digit2<<digit3<<digit4<<std::endl;
                }
            }
        }
    }

    std::cout<< "I am calling to tell you to buy a subscription to Dogs Monthly Magazine!"<<std::endl;
    std::cout<< "Calls completed"<<std::endl;
    return 0;
}