#include <iostream>
#include <cstdint>        // for uintptr_t (used in reinterpret_cast)
using namespace std;
 
// ---------- Classes for dynamic_cast (real-life: vehicles) ----------
class Vehicle {
public:
    virtual void start() {                 // virtual function makes the class "polymorphic"
        cout << "  Vehicle is starting" << endl;
    }
    virtual ~Vehicle() {}
};
 
class Car : public Vehicle {
public:
    void start() {
        cout << "  Car is starting" << endl;
    }
    void openTrunk() {                     // only Car has this function
        cout << "  Car trunk opened" << endl;
    }
};
 
class Bike : public Vehicle {
public:
    void start() {
        cout << "  Bike is starting" << endl;
    }
};
 
// Tries to treat a Vehicle as a Car using dynamic_cast
void tryOpenTrunk(Vehicle *v) {
    Car *c = dynamic_cast<Car*>(v);        // gives nullptr if v is not really a Car
    if (c != nullptr) {
        c->openTrunk();
    } else {
        cout << "  This vehicle is not a car, no trunk" << endl;
    }
}
 
// Calculates average marks (shows why type casting is needed)
double findAverage(int total, int count) {
    if (count == 0) {                      // boundary case: avoid divide by zero
        cout << "  Error: count is zero" << endl;
        return 0;
    }
    return static_cast<double>(total) / count;
}
 
int main() {
    // ===== 1. Implicit type casting (done automatically by the compiler) =====
    cout << "===== 1. Implicit type casting =====" << endl;
    int a = 10;
    double d = a;                          // int -> double
    cout << "  int 10 to double      : " << d << endl;
    char ch = 'A';
    int code = ch;                         // char -> int (ASCII value)
    cout << "  char 'A' to int       : " << code << endl;
    double price = 9.99;
    int rounded = price;                   // double -> int (decimal part is lost)
    cout << "  double 9.99 to int    : " << rounded << endl;
 
    // ===== 2. Explicit type casting (C-style) =====
    cout << "\n===== 2. Explicit casting (C-style) =====" << endl;
    int total = 7, count = 2;
    cout << "  7 / 2 without cast    : " << total / count << endl;
    cout << "  7 / 2 with (double)   : " << (double)total / count << endl;
 
    // ===== 3. static_cast =====
    cout << "\n===== 3. static_cast =====" << endl;
    cout << "  Average of 7 and 2    : " << findAverage(7, 2) << endl;
    cout << "  Average when count is 0:" << endl;
    double avg = findAverage(7, 0);
    cout << "  Value returned        : " << avg << endl;
    cout << "  static_cast<int>(-7.8): " << static_cast<int>(-7.8) << endl;
    cout << "  static_cast<int>(0.5) : " << static_cast<int>(0.5) << endl;
    cout << "  static_cast<char>(66) : " << static_cast<char>(66) << endl;
    cout << "  static_cast<int>('z') : " << static_cast<int>('z') << endl;
 
    // ===== 4. const_cast =====
    cout << "\n===== 4. const_cast =====" << endl;
    int x = 10;
    const int *cp = &x;                    // pointer that cannot change the value
    int *p = const_cast<int*>(cp);         // remove the const
    *p = 20;                               // now we can change x through p
    cout << "  Value of x after change: " << x << endl;
 
    // ===== 5. reinterpret_cast =====
    cout << "\n===== 5. reinterpret_cast =====" << endl;
    int num = 65;
    int *ptr = &num;
    uintptr_t address = reinterpret_cast<uintptr_t>(ptr);   // pointer -> integer
    int *back = reinterpret_cast<int*>(address);            // integer -> pointer
    cout << "  Value read back through the pointer: " << *back << endl;
 
    // ===== 6. dynamic_cast =====
    cout << "\n===== 6. dynamic_cast =====" << endl;
    Car myCar;
    Bike myBike;
    Vehicle *v1 = &myCar;                  // upcasting (Car -> Vehicle) is automatic
    Vehicle *v2 = &myBike;
    cout << "  Vehicle 1 (a car):" << endl;
    v1->start();
    tryOpenTrunk(v1);
    cout << "  Vehicle 2 (a bike):" << endl;
    v2->start();
    tryOpenTrunk(v2);
 
    cout << "\nProgram finished successfully." << endl;
    return 0;
}

