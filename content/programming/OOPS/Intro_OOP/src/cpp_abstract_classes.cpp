#include <iostream>
#include <string>
using namespace std;
// Abstract Class
class Animal{
    public:
    virtual void eat()=0;
    void ability(){
        cout<<"All animals either run or fly..[Animal Class]"<<endl;
    }
};

class Carnivorous: public Animal{
    public:
    void eat(){
        cout<<"Carnivorous only eat meat..[Carnivorous Class]"<<endl;
    }
};

class Human: public Animal{
    public:
    void think(){
        cout<<"Humans can think at complex level..[Human Class]"<<endl;
    }
    void eat(){
        
    }
};
int main(){
    // Cannot make object to abstract class.
    // Every abstract method must be implemented in every child class.
    Carnivorous wolf;
    wolf.eat();
    Human h;
    h.think();
}