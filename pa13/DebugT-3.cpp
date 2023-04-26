// Debug T-3
// A container class for displaying a comma-separated list.
// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

#include <iostream>
#include <string>
using namespace std;

// Container class for displaying a comma-separated list
template <class T>
class CommaSeparatedList
{
private:
   T *data;
   int size;

public:
   CommaSeparatedList(T *d, int s);
   void printList();
};

// Constructor for CommaSeparatedList class
template <class T>
CommaSeparatedList<T>::CommaSeparatedList(T *d, int s)
{
   data = d;
   size = s;
}

// Print the comma-separated list
template <class T>
void CommaSeparatedList<T>::printList()
{
   cout << "Comma separated list:" << endl;
   for (int x = 0; x < size; ++x)
   {
      cout << data[x];
      if (x != size - 1)
         cout << ", ";
   }
   cout << endl
        << endl;
}

class Book
{
   friend ostream &operator<<(ostream &, const Book &);

private:
   string title;
   int year;

public:
   void setBook(string, int);
};

void Book::setBook(string Title, int yr)
{
   title = Title;
   year = yr;
}

ostream &operator<<(ostream &out, const Book &b)
{
   out << b.title << " was published in " << b.year;
   return out;
}

class Customer
{
   friend ostream &operator<<(ostream &, const Customer &);

private:
   string name;
   double balDue;

public:
   void setCustomer(string, double);
};

void Customer::setCustomer(string CustomerName, double pr)
{
   name = CustomerName;
   balDue = pr;
}

ostream &operator<<(ostream &out, const Customer &aCustomer)
{
   out << aCustomer.name << " owes  $" << aCustomer.balDue;
   return out;
}

int main()
{
   int CommaSeparatedListSize;
   // Declare and assign values to four kinds of CommaSeparatedLists
   int someInts[] = {12, 34, 55, 77, 99};
   double someDoubles[] = {11.11, 23.44, 44.55, 123.66};
   Book someBooks[2];
   someBooks[0].setBook("Wizard of Oz", 1986);
   someBooks[1].setBook("Harry Potter", 2000);
   Customer someCustomers[6];
   someCustomers[0].setCustomer("Zaps", 23.55);
   someCustomers[1].setCustomer("Martin", 155.77);
   someCustomers[2].setCustomer("Fine", 333.88);
   someCustomers[3].setCustomer("Torrence", 123.99);
   someCustomers[4].setCustomer("Richard", 20.06);
   someCustomers[5].setCustomer("Curtin", 56999.19);
   // Calculate size and create CommaSeparatedList objects
   CommaSeparatedListSize = sizeof(someInts) / sizeof(someInts[0]);
   CommaSeparatedList<int> CommaSeparatedListOfIntegers(someInts, CommaSeparatedListSize);
   CommaSeparatedListSize = sizeof(someDoubles) / sizeof(someDoubles[0]);
   CommaSeparatedList<double> CommaSeparatedListOfDoubles(someDoubles, CommaSeparatedListSize);
   CommaSeparatedListSize = sizeof(someBooks) / sizeof(someBooks[0]);
   CommaSeparatedList<Book> CommaSeparatedListOfBooks(someBooks, CommaSeparatedListSize);
   CommaSeparatedListSize = sizeof(someCustomers) / sizeof(someCustomers[0]);
   CommaSeparatedList<Customer> CommaSeparatedListOfCustomers(someCustomers, CommaSeparatedListSize);

   // Use printList() with each CommaSeparatedList
   CommaSeparatedListOfIntegers.printList();
   CommaSeparatedListOfDoubles.printList();
   CommaSeparatedListOfBooks.printList();
   CommaSeparatedListOfCustomers.printList();

   return 0;
}

// 1. Fixed the template syntax error in `CommaSeparatedList<T>::printList()` method.
// 2. Changed the output redirection operator (>>) to the output stream operator (<<) in `CommaSeparatedList<T>::printList()` method.
// 3. Fixed the variable name typo in the loop of `CommaSeparatedList<T>::printList()` method (changed `y` to `x`).
// 4. Added a missing semicolon after the `cout` statement in the `CommaSeparatedList<T>::printList()` method.
// 5. Fixed the constructor signature for the `CommaSeparatedList` class template by changing the first parameter from `T` to `T*`.
// 6. Corrected the misspelled `sizeof` keyword in the main function when calculating the `CommaSeparatedListSize` for books.
// 7. Corrected the method name `prinList()` to `printList()` when calling it for the `CommaSeparatedListOfBooks` object.
// 8. Added comments to make the code more readable.