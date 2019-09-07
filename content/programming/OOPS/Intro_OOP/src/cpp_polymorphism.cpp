#include <iostream>
#include <string>
using namespace std;

class Animal
{
    int stomach_capacity;
    public:
    // Function Overloading
    void eat(){
        cout<<"Animal Eats for survival..[Animal Class]"<<endl;
        stomach_capacity = 1;
    }
    int eat(string food){
        if (stomach_capacity == 1)
        {
            cout<<"Animal Stomach is full..[Animal Class]"<<endl;
            return 1;
        }
        else
        {
            cout<<"Animal is Eating"<<food<<"..[Animal Class]"<<endl;
            return 0;
        }
    }
    // Virtual Functions
    virtual void kill(){
        cout<<"Typically,animals kill for survival..[Animal Class]"<<endl;
    }
};

class Carnivorous : public Animal
{
    public:
    // Function Overriding
    void eat(){
        cout<<"Carnivorous animal eats meat..[Carnivorous Class]"<<endl;
    }
    void kill(){
        cout<<"Some Carnivorous kill for pleasure..[Carnivorous Class]"<<endl;
    }
};

int main(){
    int stomach_status;
    Animal X;
    Carnivorous Wolf;
    Wolf.eat();
    X.eat();
    stomach_status = X.eat("fish");

    //Vitual Functions
    Animal *a;
    Carnivorous human;
    a = &human;
    cout<<""<<endl;
    // Usig a parent class pointer to call virtual and normal function
    a->kill();
    a->eat();
}