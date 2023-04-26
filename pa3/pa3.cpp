#include <iostream>

class Test {
    private:
        static int static_private_var;
        int non_static_private_var;

    public:
        static int static_public_var;
        int non_static_public_var;

        // Setter function for non_static_private_var
        void set_non_static_private_var(int val) {
            non_static_private_var = val;
        }

        // Getter function for non_static_private_var
        int get_non_static_private_var() {
            return non_static_private_var;
        }

        // Setter function for static_private_var
        static void set_static_private_var(int val) {
            static_private_var = val;
        }

        // Getter function for static_private_var
        static int get_static_private_var() {
            return static_private_var;
        }

        // Function to display all member variables
        void display() {
            std::cout << "Static Private Variable: " << static_private_var << " (Memory Address: " << &static_private_var << ")" << std::endl;
            std::cout << "Non-Static Private Variable: " << non_static_private_var << " (Memory Address: " << &non_static_private_var << ")" << std::endl;
            std::cout << "Static Public Variable: " << static_public_var << " (Memory Address: " << &static_public_var << ")" << std::endl;
            std::cout << "Non-Static Public Variable: " << non_static_public_var << " (Memory Address: " << &non_static_public_var << ")" << std::endl;
        }
};

// Initializing static member variables
int Test::static_private_var = 0;
int Test::static_public_var = 0;

int main() {
    Test obj1, obj2;

    std::cout << "Object 1 Memory Address: " << &obj1 << std::endl;
    std::cout << "Object 2 Memory Address: " << &obj2 << std::endl;

    // Setting values for all member variables
    obj1.set_non_static_private_var(5);
    obj1.non_static_public_var = 10;
    Test::set_static_private_var(15);
    Test::static_public_var = 20;

    // Displaying values and memory addresses of all member variables for object 1
    std::cout << "\nObject 1:" << std::endl;
    obj1.display();

    // Setting values for all member variables
    obj2.set_non_static_private_var(25);
    obj2.non_static_public_var = 30;
    Test::set_static_private_var(35);
    Test::static_public_var = 40;

    // Displaying values and memory addresses of all member variables for object 2
    std::cout << "\nObject 2:" << std::endl;
    obj2.display();

    return 0;
}


// From the program output, we can observe that:

// - The memory addresses of the static private and public member variables are the same for both
//   objects. This is because static member variables are shared among all objects of a class, and
//   there is only one copy of them in memory.
// - The memory addresses of the non-static private and public member variables are different for
//   both objects. This is because non-static member variables are unique to each object, and each
//   object has its own copy of them in memory.

// This means that static member variables can be accessed directly from the class, without the need
// for an object, and are shared among all objects. Non-static member variables, on the other hand, 
// can only be accessed through an object and are unique to each object.

// Therefore, static member variables are useful when you need to store information that is common
// to all objects of a class, while non-static member variables are useful when you need to store
// information that is unique to each object.