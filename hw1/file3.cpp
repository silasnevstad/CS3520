/*  This program should determine if a number is a prime or composite number 
    The program should ask user for a number 'num'
    If 'num' is 0 or 1, print "num is not prime or composite"
    For any value > 1, print "num is a prime number" or "num is a composite number" depending on the number */

// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include<iostream>

int main(){
    int num,i;
    bool factor_found = false;
    std::cout<<"Enter Number:\n";
    std::cin>>num;
    if(num == 0 || num == 1) {
        std::cout<<num<<" is not prime or composite"<<std::endl;
        return 0;
    }   
    for (i = 2; i<num; i++){
        if(num%i == 0){
            factor_found = true;
            break;
        }
    }
    if (not factor_found) {
        std::cout<<num<<" is a prime number\n";
    }
    else {
        std::cout<<num<<" is a composite number\n";
    }

    return 0;
}