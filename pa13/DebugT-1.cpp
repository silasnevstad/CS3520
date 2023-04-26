// Debug T-1
// Function template subtracts objects from each other. The function works on any object which has '-' opertor defined.
// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <iostream>
#include <string>
using namespace std;

// Function template to subtract two objects of any type
// Requires that the type T has the '-' operator defined
template <class T>
T subtract(T x, T y)
{
   T difference;
   difference = x - y;
   return difference;
}

class Person
{
   friend ostream &operator<<(ostream &, const Person &);

private:
   string lastName;
   string firstName;
   int age;

public:
   void setValues(string, string, int);
   Person operator-(const Person &);
};

// Overload the '<<' operator to output a Person object
ostream &operator<<(ostream &out, const Person &per)
{
   out << per.firstName << " " << per.lastName << " " << per.age << " years old";
   return out;
}

void Person::setValues(string last, string first, int a)
{
   lastName = last;
   firstName = first;
   age = a;
}

// Overload the '-' operator to subtract two Person objects
Person Person::operator-(const Person &p)
{
   Person temp;
   temp.lastName = "of Age";
   temp.firstName = "Difference";
   temp.age = age - p.age;
   return temp;
}

int main()
{
   int a = 7, b = 26, c;
   double d = 39.25, e = 2.01, f;
   Person g, h, i;
   g.setValues("Mitchell", "Donald", 40);
   h.setValues("Clayton", "Rita", 35);
   c = subtract(a, b);
   f = subtract(d, e);
   i = subtract(g, h);
   cout << c << endl;
   cout << f << endl;
   cout << i << endl;
   return 0;
}

// 1. Changed function name from 'add' to 'subtract'.
// 2. Changed the function signature to include the template parameter for the second argument 'y'.
// 3. Fixed the type of the 'sum' variable to match the template type 'T'.
// 4. Replaced the '+' operator with the '-' operator in the function and the Person class.
// 5. Fixed the parameter type for the 'operator+' function in the Person class to be 'const Person &'.
// 6. Changed the 'operator+' function to 'operator-'.
// 7. Changed 'Person operator+(person);' to 'Person operator-(const Person &);'.
// 8. Fixed the output stream operator to return the 'out' object.
// 9. Fixed the age calculation in the 'operator-' function for the Person class.


