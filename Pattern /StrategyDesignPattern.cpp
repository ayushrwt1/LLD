#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Walkable
{
public:
    virtual void walk() = 0;
};

class NormalWalk : public Walkable
{
public:
    void walk() override
    {
        cout << "Walking normally." << endl;
    }
};
class SneakingWalk : public Walkable
{
public:
    void walk() override
    {
        cout << "Walking sneakily." << endl;
    }
};

class Talkable
{
public:
    virtual void talk() = 0;
};

class Normaltalk : public Talkable
{
public:
    void talk() override
    {
        cout << "Talking normally." << endl;
    }
};
class WhisperTalk : public Talkable
{
public:
    void talk() override
    {
        cout << "Whispering." << endl;
    }
};

class Flyable
{
public:
    virtual void fly() = 0;
};

class NormalFly : public Flyable
{
public:
    void fly() override
    {
        cout << "Flying normally." << endl;
    }
};

class SuperFly : public Flyable
{
public:
    void fly() override
    {
        cout << "Flying super fast." << endl;
    }
};

class Robot
{
public:
    Talkable *T;
    Walkable *W;
    Flyable *F; 

public:
    Robot(Talkable *T , Walkable *W , Flyable *F)
    {
        this->T = T;
        this->W = W;
        this->F = F;
    }

    void walk(){
        W->walk();
    }
    void talk(){
        T->talk();
    }
    void fly(){
        F->fly();
    }

    virtual void projection() = 0;
};


// The Robot(T,W,F){} is a member initializer list that calls the parent class constructor. Here's why we need it:

// What's happening:

// CompanionRobot inherits from Robot
// Robot has member variables (T, W, F) that need to be initialized
// When we create a CompanionRobot object, we must initialize the parent class first


class CompanionRobot : public Robot{
    public:
    CompanionRobot(Talkable *T , Walkable *W , Flyable *F) : Robot(T,W,F){}

    void projection() override{
        cout << "Companion Robot Projection" << endl;
    }

};

class WorkableRobot : public Robot{
    public:
    WorkableRobot(Talkable *T , Walkable *W , Flyable *F) : Robot(T,W,F){}

    void projection() override{
        cout << "Workable Robot Projection" << endl;
    }

};

int main(){

    Robot* companionRobot = new CompanionRobot(new Normaltalk(), new NormalWalk(), new NormalFly());
    companionRobot->talk();
    companionRobot->walk();
    companionRobot->fly();
    companionRobot->projection();
    
    cout << "------------------------" << endl;

    Robot* workRobot = new WorkableRobot(new WhisperTalk(), new SneakingWalk(), new SuperFly());
    workRobot->talk();
    workRobot->walk();
    workRobot->fly();
    workRobot->projection();


    return 0;
}


