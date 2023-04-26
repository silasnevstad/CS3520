// [ --- Part 1 --- ]

// a) planet_record.planet_number
// b) planet_ptr->planet_number
// c) planet_record.planet_name
// d) planet_ptr->planet_name
// e) planet_record.personal.age
// f) planet_ptr->personal_ptr->age
// g) planet_record.personal.origin
// h) planet_ptr->personal_ptr->origin


// [ --- Part 2 --- ]
#include <iostream>
#include <cstring>

using namespace std;

struct planet {
    unsigned int planet_number;
    char* planet_name;
    struct {
        char origin[10];
        int age;
    } personal, *personal_ptr = &personal;
} planet_record, *planet_ptr = &planet_record, all_records[5];

int main() {
    // Initialize members of planet_record
    planet_record.planet_number = 1;
    planet_record.planet_name = new char[20];
    strcpy(planet_record.planet_name, "Earth");
    strcpy(planet_record.personal.origin, "Solar System");
    planet_record.personal.age = 19;

    // Access and print structure members using expressions
    cout << "planet_number of structure planet_record: " << planet_record.planet_number << endl;
    cout << "planet_number of the structure pointed to by planet_ptr: " << planet_ptr->planet_number << endl;
    cout << "planet_name of structure planet_record: " << planet_record.planet_name << endl;
    cout << "planet_name of member structure pointed to by planet_ptr: " << planet_ptr->planet_name << endl;
    cout << "age of the structure member personal of structure planet_record: " << planet_record.personal.age << endl;
    cout << "age of member pointed to by personal_ptr of the structure pointed to by planet_ptr: " << planet_ptr->personal_ptr->age << endl;
    cout << "origin of the structure member personal of structure planet_record: " << planet_record.personal.origin << endl;
    cout << "origin of member pointed to by personal_ptr of the structure pointed to by planet_ptr: " << planet_ptr->personal_ptr->origin << endl;

    // Deallocate dynamically allocated memory
    delete[] planet_record.planet_name;
    planet_record.planet_name = nullptr;

    // Part 2 --> I had no syntax errors in my code


    // [ --- Part 3 ---]
    // Initialize members of all planets stored in all_records
    all_records[0].planet_number = 1;
    all_records[0].planet_name = new char[20];
    strcpy(all_records[0].planet_name, "Mercury");
    strcpy(all_records[0].personal.origin, "Solar Sys");
    all_records[0].personal.age = 45;

    all_records[1].planet_number = 2;
    all_records[1].planet_name = new char[20];
    strcpy(all_records[1].planet_name, "Venus");
    strcpy(all_records[1].personal.origin, "Solar Sys");
    all_records[1].personal.age = 45;

    all_records[2].planet_number = 3;
    all_records[2].planet_name = new char[20];
    strcpy(all_records[2].planet_name, "Earth");
    strcpy(all_records[2].personal.origin, "Solar Sys");
    all_records[2].personal.age = 45;

    all_records[3].planet_number = 4;
    all_records[3].planet_name = new char[20];
    strcpy(all_records[3].planet_name, "Mars");
    strcpy(all_records[3].personal.origin, "Solar Sys");
    all_records[3].personal.age = 46;

    all_records[4].planet_number = 5;
    all_records[4].planet_name = new char[20];
    strcpy(all_records[4].planet_name, "Jupiter");
    strcpy(all_records[4].personal.origin, "Solar Sys");
    all_records[4].personal.age = 45;

    // Print all planets stored in all_records
    cout << "All planets stored in all_records: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Planet " << i + 1 << ": " << endl;
        cout << "Planet number: " << all_records[i].planet_number << endl;
        cout << "Planet name: " << all_records[i].planet_name << endl;
        cout << "Planet personal origin: " << all_records[i].personal.origin << endl;
        cout << "Planet personal age: " << all_records[i].personal.age << endl;
    }

    // Initialize members of all planets stored in all_records_ptr
    planet* all_records_ptr = new planet[5];
    all_records_ptr[0].planet_number = 1;
    all_records_ptr[0].planet_name = new char[20];
    strcpy(all_records_ptr[0].planet_name, "Mercury");
    strcpy(all_records_ptr[0].personal.origin, "Solar Sys");
    all_records_ptr[0].personal.age = 45;

    all_records_ptr[1].planet_number = 2;
    all_records_ptr[1].planet_name = new char[20];
    strcpy(all_records_ptr[1].planet_name, "Venus");
    strcpy(all_records_ptr[1].personal.origin, "Solar Sys");
    all_records_ptr[1].personal.age = 45;

    all_records_ptr[2].planet_number = 3;
    all_records_ptr[2].planet_name = new char[20];
    strcpy(all_records_ptr[2].planet_name, "Earth");
    strcpy(all_records_ptr[2].personal.origin, "Solar Sys");
    all_records_ptr[2].personal.age = 45;

    all_records_ptr[3].planet_number = 4;
    all_records_ptr[3].planet_name = new char[20];
    strcpy(all_records_ptr[3].planet_name, "Mars");
    strcpy(all_records_ptr[3].personal.origin, "Solar Sys");
    all_records_ptr[3].personal.age = 46;

    all_records_ptr[4].planet_number = 5;
    all_records_ptr[4].planet_name = new char[20];
    strcpy(all_records_ptr[4].planet_name, "Jupiter");
    strcpy(all_records_ptr[4].personal.origin, "Solar Sys");
    all_records_ptr[4].personal.age = 45;

    // Print all planets stored in all_records_ptr
    cout << "All planets stored in all_records_ptr: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Planet " << i + 1 << ": " << endl;
        cout << "Planet number: " << all_records_ptr[i].planet_number << endl;
        cout << "Planet name: " << all_records_ptr[i].planet_name << endl;
        cout << "Planet personal origin: " << all_records_ptr[i].personal.origin << endl;
        cout << "Planet personal age: " << all_records_ptr[i].personal.age << endl;
    }

    // Deallocate dynamically allocated memory
    for (int i = 0; i < 5; i++) {
        delete[] all_records[i].planet_name;
        all_records[i].planet_name = nullptr;

        delete[] all_records_ptr[i].planet_name;
        all_records_ptr[i].planet_name = nullptr;
    }
    delete[] all_records_ptr;

    return 0;
}