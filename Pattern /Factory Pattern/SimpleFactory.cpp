#include<iostream>
using namespace std;
class Burger {
    public:
        virtual void prepare() = 0;
};

class VeggieBurger : public Burger {
    public:
        void prepare() override{
            cout << "Preparing Veggie Burger." << endl;
        }
};


class ChickenBurger : public Burger {
    public:
        void prepare() override{
            cout << "Preparing Chicken Burger." << endl;
        }
};

class PremiumBurger : public Burger {
    public:
        void prepare() override{
            cout << "Preparing Premium Burger." << endl;
        }
};

class BurgerFactory {
    public:

    //return Burger type of object
    Burger* createBurger(string& type){
        if(type == "veggie"){
            return new VeggieBurger();
        } else if(type == "chicken"){
            return new ChickenBurger();
        } else if(type == "premium"){
            return new PremiumBurger();
        }else{
            cout << "Invalid burger type: " << type << endl;
            return nullptr;
        }
    }
};


int main  () {
    string type = "veggie";
    BurgerFactory* factory = new BurgerFactory();
    Burger* burger = factory -> createBurger(type);

    burger->prepare();

    return 0;
}
