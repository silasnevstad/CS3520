// This program includes a struct called car that is used to store information
// about a given car The program should ask the user for information about their
// car and initialize a car structure with the given information The program
// should also print the information using a pointer to the initialized struct
// The information printed using the struct and the pointer should be the same

// BUGS:
// 1. added 'using namespace std;' to use 'cout' and 'cin' directly
// 2. Changed 'char *name' to 'char name[20]'
// 3. Change 'cout >> a' to 'cin >> a'
// 4. Changed 'cin << w' to 'cin >> w' to read the input
// 5. Changed 'c.speed = speed' to 'c.speed == w'
// 6. Changed name = n to strcpy(c.name, n) to copy the input string
// 7. Changed cPtr.name to cPtr->name to access the struct's name field
// 8. Changed car.modelYear to cPtr->modelYear to access the struct's modelYear
// 9. Changed w to cPtr->speed


#include <iostream>
#include <string>
#include <cstring>

using namespace std; // add this line to be able to use cout and cin directly

struct car {
  char name[20]; // use an array instead of a pointer to store the car's name
  int modelYear;
  float speed;
};

int main(void) {
  char n[20];
  int a;
  float w;

  struct car c;
  car *cPtr = &c;

  cout << "What is your favorite car's name: ";
  cin >> n;
  strcpy(c.name, n); // use strcpy to copy the input string into the struct's name field

  cout << "When was it launched : ";
  cin >> a; // use cin to read the input integer
  c.modelYear = a;

  cout << "How much speed does it give : ";
  cin >> w;
  c.speed = w; // assign the input float to the struct's speed field

  cout << "Car's name is " << c.name << ", and should be the same as " << cPtr->name
       << ".\n"; // use -> to access fields of the struct through the pointer

  cout << "Car's model year is " << c.modelYear << ", and should be the same as "
       << cPtr->modelYear << ".\n";

  cout << "Car's speed is " << c.speed << ", and should be the same as "
       << cPtr->speed << ".\n"; // access the speed field using the pointer
}
