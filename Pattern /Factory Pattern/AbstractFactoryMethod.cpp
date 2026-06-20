#include <iostream>
using namespace std;
class Burger
{
public:
    virtual void prepare() = 0;
};

class VeggieBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Veggie Burger." << endl;
    }
};

class ChickenBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Chicken Burger." << endl;
    }
};

class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Burger." << endl;
    }
};

class PremiumWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Wheat Burger." << endl;
    }
};
class ChickenWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Chicken Wheat Burger." << endl;
    }
};

// Garlic Bread classes

class GarlicBread
{
public:
    virtual void prepare() = 0;
};

class NormalGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing Normal Garlic Bread." << endl;
    }
};

class ChickenGarlicBread : public GarlicBread 
{
public:
    void prepare() override
    {
        cout << "Preparing Chicken Garlic Bread." << endl;
    }
};

class PremiumGarlicBread  : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Garlic Bread." << endl;
    }
};


class NormalWheatGarlicBread : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing Normal Wheat Garlic Bread." << endl;
    }
};

class ChickenWheatGarlicBread : public GarlicBread 
{
public:
    void prepare() override
    {
        cout << "Preparing Chicken Wheat Garlic Bread." << endl;
    }
};

class PremiumWheatGarlicBread  : public GarlicBread
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Wheat Garlic Bread." << endl;
    }
};





class BurgerFactory
{
public:
    virtual Burger *createBurger(string &type) = 0;
    virtual GarlicBread* createBread(string& type) = 0;
};

class BurgerSingh : public BurgerFactory
{
public:
    Burger *createBurger(string &type) override
    {
        if (type == "veggie")
        {
            return new VeggieBurger();
        }
        else if (type == "chicken")
        {
            return new ChickenBurger();
        }
        else if (type == "premium")
        {
            return new PremiumBurger();
        }
        else
        {
            cout << "Invalid burger type: " << type << endl;
            return nullptr;
        }
    }

    GarlicBread* createBread(string& type) override{
        if (type == "normal"){
            return new NormalGarlicBread();
        } else if(type == "chicken"){
            return new ChickenGarlicBread();
        } else if(type == "premium"){
            return new PremiumGarlicBread();
        } else {
            cout << "Invalid bread type: " << type << endl;
            return nullptr;
        }
    }
};

class BurgerKing : public BurgerFactory
{
public:
    Burger *createBurger(string &type) override
    {
        if (type == "premium")
        {
            return new PremiumWheatBurger();
        }
        else if (type == "chicken")
        {
            return new ChickenWheatBurger();
        }
        else
        {
            cout << "Invalid burger type: " << type << endl;
            return nullptr;
        }
    }

    GarlicBread* createBread(string& type) override{
        if (type == "normal"){
            return new NormalWheatGarlicBread();
        } else if(type == "chicken"){
            return new ChickenWheatGarlicBread();
        } else if(type == "premium"){
            return new PremiumWheatGarlicBread();
        } else {
            cout << "Invalid bread type: " << type << endl;
            return nullptr;
        }
    }
};

int main()
{
    string type = "premium";

    // Burger Singh Factory
    BurgerFactory *burgerSingh = new BurgerSingh();

    burgerSingh->createBurger(type)->prepare();
    burgerSingh->createBread(type)->prepare();

    // Burger King Factory
    BurgerFactory *burgerKing = new BurgerKing();
    burgerKing->createBurger(type)->prepare();
    burgerKing->createBread(type)->prepare();

    return 0;
}
