
// Abstraction --

// Abstraction is the process of hiding the implementation details and showing only the functionality to the user.
// Abstraction can be achieved using abstract classes and interfaces.
#include <iostream>
#include<string>
using namespace std;

// abstact class is a class that cannot be instantiated and is used as a base class for other classes. 
// It can contain pure virtual functions, which are functions that are declared in the base class but must 
// be overridden in the derived class.
class car
{
public:
    // virtual function is a function that is declared in the base class and
    // overridden in the derived class.
    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void shiftGears() = 0;

    virtual ~car() {}
};

class SportsCar : public car {
    public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

    //constructor
    SportsCar(string brand, string model){
        this->brand= brand;
        this->model= model;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    void startEngine() override {
        isEngineOn = true;
        cout << "Engine Started" << endl;
    }

    void shiftGears() override {
        if(isEngineOn){
            currentGear++;
            cout << "Shifted to gear " << currentGear << endl;
        } else {
            cout << "Start the engine first" << endl;
        }
    }
    void accelerate() override {
        if(isEngineOn){
            currentSpeed += 10;
            cout << "Accelerating... Current speed: " << currentSpeed << " km/h" << endl;
        } else {
            cout << "Start the engine first" << endl;
        }
    }
    void brake() override {
        if(isEngineOn){
            currentSpeed -= 10;
            cout << "Braking... Current speed: " << currentSpeed << " km/h" << endl;
        } else {
            cout << "Start the engine first" << endl;
        }
    }

    void stopEngine() override {
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
        cout << "Engine Stopped" << endl;
    }
};

int main (){

    SportsCar* Sc=  new SportsCar("KIA" , "Seltos");
    Sc->startEngine();

    Sc->shiftGears();

    Sc->accelerate();

    Sc->shiftGears();
    Sc->accelerate();
    Sc->brake();

    Sc->stopEngine();

    return 0;
}