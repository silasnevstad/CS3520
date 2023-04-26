// Debug T-2
// Function template finds biggest of two or three objects. The function works on any data type which has greater than operator defined.

#include <iostream>
#include <string>
using namespace std;

// Function template to find the largest of two objects
template <class T>
void findBiggest(T a, T b)
{
   T large = a;
   if (b > large)
      large = b;
   cout << "The larger of " << a << " " << b << " is " << large << endl;
}

// Function template to find the largest of three objects
template <class T>
void findBiggest(T a, T b, T c)
{
   T large = a;
   if (b > large)
      large = b;
   if (c > large)
      large = c;
   cout << "The largest of " << a << " " << b << " " << c << " is " << large << endl;
}

class BankAccount
{
   friend ostream &operator<<(ostream &, const BankAccount &);

private:
   string name;
   int amount;

public:
   BankAccount(const string &name, const int amount);
   bool operator>(const BankAccount &);
};

// Constructor for BankAccount class
BankAccount::BankAccount(const string &n, const int a)
{
   name = n;
   amount = a;
}

// Overload the '<<' operator to output a BankAccount object
ostream &operator<<(ostream &out, const BankAccount &bh)
{
   out << "Name: " << bh.name << " Amount: " << bh.amount;
   return out;
}

// Overload the '>' operator to compare two BankAccount objects
bool BankAccount::operator>(const BankAccount &bh)
{
   return amount > bh.amount;
}

int main()
{
   BankAccount bAA("A", 800);
   BankAccount bAB("B", 120);
   BankAccount bAC("C", 500);
   findBiggest(bAA, bAB);
   findBiggest(bAB, bAC);
   findBiggest(bAC, bAA);
   findBiggest(bAA, bAB, bAC);
   return 0;
}

// 1. Changed the second parameter of the 'findBiggest' function with three arguments from 'int' to 'T'.
// 2. Fixed the logic for finding the largest object in the 'findBiggest' function with three arguments.
// 3. Changed the output of the 'findBiggest' function with three arguments to show the largest object, not 'a'.
// 4. Changed the '==' operator to '>' in the 'findBiggest' function with two arguments.
// 5. Changed the variable name 'larger' to 'large' in the 'findBiggest' function with two arguments.
// 6. Fixed the constructor signature in the BankAccount class.
// 7. Fixed the constructor implementation in the BankAccount class to initialize member variables correctly.
// 8. Fixed the output stream operator for the BankAccount class by removing an extra '<<' and correcting the output format.
// 9. Fixed the initialization of the 'flag' variable in the '>' operator overload of the BankAccount class.