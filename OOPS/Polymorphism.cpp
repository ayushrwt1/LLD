#include <iostream>
#include <string>
using namespace std;

// ========================================
// METHOD OVERLOADING (Compile-time Polymorphism)
// ========================================
// Same method name with different parameters
class Calculator {
public:
    // Overload 1: Add two integers
    int add(int a, int b) {
        cout << "Adding two integers: " << a << " + " << b << endl;
        return a + b;
    }
    
    // Overload 2: Add three integers
    int add(int a, int b, int c) {
        cout << "Adding three integers: " << a << " + " << b << " + " << c << endl;
        return a + b + c;
    }
    
    // Overload 3: Add two doubles
    double add(double a, double b) {
        cout << "Adding two doubles: " << a << " + " << b << endl;
        return a + b;
    }
    
    // Overload 4: Add integer and double
    double add(int a, double b) {
        cout << "Adding integer and double: " << a << " + " << b << endl;
        return a + b;
    }
};

// ========================================
// METHOD OVERRIDING (Runtime Polymorphism)
// ========================================
// Same method signature with virtual keyword in base class
class Animal {
public:
    // Virtual function to be overridden
    virtual void sound() {
        cout << "Animal makes some sound" << endl;
    }
    
    virtual void eat() {
        cout << "Animal eats food" << endl;
    }
    
    virtual ~Animal() {
        cout << "Animal destructor called" << endl;
    }
};

class Dog : public Animal {
public:
    // Override the sound method
    void sound() override {
        cout << "Dog barks: Woof! Woof!" << endl;
    }
    
    void eat() override {
        cout << "Dog eats bones and meat" << endl;
    }
    
    ~Dog() {
        cout << "Dog destructor called" << endl;
    }
};

class Cat : public Animal {
public:
    // Override the sound method
    void sound() override {
        cout << "Cat meows: Meow! Meow!" << endl;
    }
    
    void eat() override {
        cout << "Cat eats fish and meat" << endl;
    }
    
    ~Cat() {
        cout << "Cat destructor called" << endl;
    }
};

class Cow : public Animal {
public:
    // Override the sound method
    void sound() override {
        cout << "Cow moos: Moo! Moo!" << endl;
    }
    
    void eat() override {
        cout << "Cow eats grass" << endl;
    }
    
    ~Cow() {
        cout << "Cow destructor called" << endl;
    }
};

// ========================================
// COMBINATION OF BOTH (Advanced)
// ========================================
class Shape {
public:
    // Method overloading in base class
    virtual void calculateArea(int side) {
        cout << "Calculating area with 1 parameter" << endl;
    }
    
    virtual void calculateArea(int length, int width) {
        cout << "Calculating area with 2 parameters" << endl;
    }
    
    virtual ~Shape() {}
};

class Square : public Shape {
public:
    // Override with single parameter
    void calculateArea(int side) override {
        cout << "Square area = " << side * side << endl;
    }
};

class Rectangle : public Shape {
public:
    // Override with two parameters
    void calculateArea(int length, int width) override {
        cout << "Rectangle area = " << length * width << endl;
    }
};

// ========================================
// MAIN FUNCTION - DEMONSTRATIONS
// ========================================
int main() {
    cout << "========== METHOD OVERLOADING (Compile-time) ==========" << endl;
    
    Calculator calc;
    
    // Calling different overloaded methods
    cout << "Result: " << calc.add(5, 10) << endl;
    cout << "Result: " << calc.add(5, 10, 15) << endl;
    cout << "Result: " << calc.add(5.5, 10.5) << endl;
    cout << "Result: " << calc.add(5, 10.5) << endl;
    
    cout << "\n========== METHOD OVERRIDING (Runtime Polymorphism) ==========" << endl;
    
    // Create pointers to base class pointing to derived objects
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();
    Animal* animal3 = new Cow();
    
    // Call overridden methods - behavior depends on object type at runtime
    cout << "\n--- Calling sound() method ---" << endl;
    animal1->sound();
    animal2->sound();
    animal3->sound();
    
    cout << "\n--- Calling eat() method ---" << endl;
    animal1->eat();
    animal2->eat();
    animal3->eat();
    
    // Clean up
    delete animal1;
    delete animal2;
    delete animal3;
    
    cout << "\n========== COMBINATION: Overloading + Overriding ==========" << endl;
    
    Shape* shape1 = new Square();
    Shape* shape2 = new Rectangle();
    
    shape1->calculateArea(5);          // Calls Square's overridden method
    shape2->calculateArea(4, 6);       // Calls Rectangle's overridden method
    
    delete shape1;
    delete shape2;
    
    cout << "\n========== KEY DIFFERENCES ==========" << endl;
    cout << "Method Overloading:   Same name, different parameters (Compile-time)" << endl;
    cout << "Method Overriding:    Same name, same parameters in derived class (Runtime)" << endl;
    cout << "Overriding requires:  virtual keyword in base class and override in derived" << endl;
    
    return 0;
}

/*
DETAILED EXPLANATION:

1. METHOD OVERLOADING (Compile-time Polymorphism):
   - Same method name with different parameters
   - Resolved at COMPILE TIME
   - Can differ by:
     * Number of parameters: add(int, int) vs add(int, int, int)
     * Type of parameters: add(int, int) vs add(double, double)
     * Order of parameters: add(int, double) vs add(double, int)
   - Increases readability and usability

2. METHOD OVERRIDING (Runtime Polymorphism):
   - Derived class provides specific implementation of base class method
   - Resolved at RUNTIME (late binding)
   - Requirements:
     * Base class method must be virtual
     * Same method signature in derived class
     * Use 'override' keyword (C++11) for safety
   - Enables loose coupling and extensibility

3. BENEFITS:
   - Overloading: Single interface for similar operations
   - Overriding: Flexible behavior based on object type
   - Together: Powerful abstraction mechanisms for OOP design
*/
