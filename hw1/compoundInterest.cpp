/* CS3520 - Silas Nevstad
   1/22/2023
   This program will show the different amounts of money that the depositor would have gotten if
   they had deposited $24.00 in the year 1626 and kept it on deposit until now (year 2023) with
   different interest rates, ranging from 2% to 12. It will show the year, the interest rate
   and the amount on deposit for each year, this way one can compare the amounts each year.
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double amount; // amount on deposit at end of each year
    double principal = 24.0; // initial amount before interest
    double rate; // interest rate

    // display headers
    cout << "Interest Rate" << setw(21) << "Amount on deposit after 397 years" << endl;

    // set floating-point number format
    cout << fixed << setprecision(2);

    for (unsigned int interest_rate = 2; interest_rate <= 12; ++interest_rate) {
        rate = interest_rate/100.0;
        // calculate new amount for specified year
        amount = principal * pow(1.0 + rate, 397);

        // display the interest rate and the amount
        cout << setw(4) << rate*100 << setw(25) << amount << endl;
    }

    return 0;
}
