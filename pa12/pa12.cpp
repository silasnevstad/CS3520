#include <iostream>
#include <string>
#include <memory>

using namespace std;

class MyString {
    shared_ptr<string> str;
public:
    MyString() { // Default Constructor
        str = make_shared<string>("");
    };

    MyString(const string& val) { // Constructor with 1 argument
        str = make_shared<string>(val);
        cout << "The given string is: " << *str << endl;
    }

    MyString(const MyString& source) { // Copy Constructor
        str = source.str;
    }

    // The move constructor is not needed for pre-C++11 compatibility

    // Destructor is not needed, as std::shared_ptr takes care of memory deallocation
};

int main(void) {
    cout << "Start!" << endl;
    MyString a;
    MyString b("Hello");
    MyString c(a);
    MyString d(MyString("World"));
    cout << "Bye" << endl;
}

