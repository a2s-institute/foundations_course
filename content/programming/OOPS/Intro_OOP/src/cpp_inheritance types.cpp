#include <iostream>
#include <string>
using namespace std;

class Animal
{
    int number_of_legs;
    string special_ability;
    public:
        void eat(){
            cout<<"Eating..[Animal class]"<<endl;
        }
};

// Single Inhertiance (Animal-->Carnivorous)
class Carnivorous : public Animal
{
    public:
        void characteristic(){
            cout<<"Carnivorous have canine tooth..[Carnivorous class]"<<endl;
        }
};

// Multi level Inheritance (Animal-->Carnivorous-->Cheetah)
class Cheetah : public Carnivorous
{
    public:
        void run(){
            cout<<"Cheetah outruns Ussain Bolt..[Cheetah class]"<<endl;
        }
};

// Heirarchical Inheritance (Animal-->Carnivorous,Herbivorous)
class Herbivorous : public Animal
{
    public:
        void quality(){
            cout<<"Herbivorous have stubby teeth..[Herbivorous class]"<<endl;
        }
};

// Multiple Inheritance (Carnivorous,Herbivorous-->Humans)
class Human : public Herbivorous, public Carnivorous
{
    public:
        void think(){
            cout<<"Humans are able to think at complex level..[Human class]"<<endl;
        }
};

// Hybrid Inheritance (Animal-->Carnivorous,Herbivorous-->Humans)

int main(void) {
// Single Inheritance (A wolf object have property of Animal and it special property of having canine tooth)
    Carnivorous wolf;
    cout<<""<<endl;
    wolf.characteristic();
    wolf.eat();
    cout<<""<<endl;
// Multi-level Inheritance (A cheetah have property of Animal, Carnivorous and have special property of running faster)
    Cheetah C;   
    C.run();
    C.eat();
    C.characteristic();
    cout<<""<<endl;

// Heirachical Inhertiance (A Gazelle and Wolf can have animal properties)
    wolf.eat();
    Herbivorous gazelle;
    gazelle.eat();
    gazelle.quality();
    cout<<""<<endl;
// Multiple Inheritance (A human can have its own ability along with carnivorous and herbivorous abilities)
    Human h;
    h.think();
    h.quality();
    h.characteristic();
    cout<<""<<endl;
// Hybrid Inheritance (Carnivorous and Herbivorous are derived from Animal so Human is also derived from Animal)
    //h.eat();
    cout<<""<<endl;
    return 0;
}