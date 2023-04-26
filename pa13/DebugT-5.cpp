// The goal of this debug execrice is to understand the concept of object slicing.
// Check for possible compiler errors, logical errors and rectify them
// Re-factor the code by adding few comments (make it readable) and
// provide list of most important fixes (in comments)

// Expected output -
// Name: tesla model Year: 2019
// Name: Hyundai model Year: 2020 Mileage: 23
// Name: Ford model Year: 2012 Miles driven: 20000
// Name: Ford model Year: 2017 Miles driven: 10000

#include <iostream>

using namespace std;

class Car
{
protected: // Changed to protected to make it accessible in derived classes
    string name;
    int modelYear;
    void assign(const Car &c)
    {
        name = c.name;
        modelYear = c.modelYear;
    }

public:
    Car(const string &n, const int my) : name(n), modelYear(my) {}

    virtual void print() const
    {
        cout << "Name: " << name << " model Year: " << modelYear << endl;
    }

    virtual const Car &operator=(const Car &c)
    {
        name = c.name;
        modelYear = c.modelYear;
        return *this;
    }

};

class Sedan : public Car
{
private:
    int mileage;

public:
    Sedan(const string &n, const int my, const int m) : Car(n, my), mileage(m) {}

    virtual void print() const
    {
        cout << "Name: " << name << " model Year: " << modelYear << " Mileage: " << mileage << endl;
    }

};

class SUV : public Car
{
private: // Added private access modifier
    int miles;

public:
    SUV(const string &n, const int my, const int m) : Car(n, my), miles(m) {} // Added initialization of base class

    virtual void print() const
    {
        cout << "Name: " << name << " model Year: " << modelYear << " Miles driven: " << miles << endl;
    }

    virtual const SUV &operator=(const Car &c)
    {
        if (const SUV *b = dynamic_cast<const SUV *>(&c))
        {
            assign(*b);
        }
        return *this;
    }

protected:
    void assign(const SUV &c)
    {
        Car::assign(c);
        miles = c.miles;
    }
};

void printCarInfo(const Car &c) // Changed to pass by reference
{
    c.print();
}

int main()
{
    Car tesla = Car("tesla", 2019);
    Sedan hyundai = Sedan("Hyundai", 2020, 23);
    SUV ford = SUV("Ford", 2012, 20000);

    printCarInfo(tesla);
    printCarInfo(hyundai);

    Car &ref = ford;
    printCarInfo(ref);
    SUV ford2 = SUV("Ford", 2017, 10000);
    ref = ford2;
    printCarInfo(ref);
    return 0;
}

// 1. Changed the access modifier of name and modelYear to protected in the Car class to make them accessible in derived classes.
// 2. Added initialization of the base class in the constructor of SUV.
// 3. Added private access modifier for the miles variable in the SUV class.
// 4. Changed the printCarInfo function to pass the Car object by reference to avoid object slicing.
// 5. Fixed the operator=() method in the SUV class to receive a reference to the Car class.