#include <iostream>
#include <string>

using namespace std;

// This is the base class for all the living creatures
class LivingCreature {
  public:
    LivingCreature(string type, int avgLifeSpan)
    {
        type_ = type;
        avgLifeSpan_ = avgLifeSpan;
    }

    ~LivingCreature()
    {
        cout << "\nLiving Creature of type " << type_ << " died" << endl;
    }

    // These are the common functions that every living creature must posses
    string getType() { return type_; }
    int getAvgLifeSpan() { return avgLifeSpan_; }
    


  protected:
    // These are the common features of every living creature
    string type_;
    int avgLifeSpan_;


  private:
    friend void frienship(){cout<<"This is a friendship"<<endl;}
};

// The Animal class inherits all the properties and methods of the Living
// creature here. In addition it has its own set of properties and methods.

class Animal : public LivingCreature {
  public:
    /*
    The constructor of the derived class has an additional responsibility of
    calling its base class constructor to initialize the properties of the base
    class.

    This is done using the initializer list (arguments that follow the :
    operator).

    The new properties introduced in the derived class can be initialized in the
    initializer list or in within the constructor body. However it is preferred
    to be done in the initializer list.
    */
    Animal(string type, int avgLifeSpan, int numOfLegs)
        : LivingCreature(type, avgLifeSpan), numOfLegs_(numOfLegs)
    {
        cout << "Created an animal of type " << type << " with " << numOfLegs_
             << " legs." << endl;
    }

    // Define some additional methods that are specific to the Animal class and
    // not relevant for other living creatures.
    int getNumOfLegs() { return numOfLegs_; }

    void run()
    {
        if (numOfLegs_ > 0) {
            cout << type_ << " is running." << endl;
        }
        else {
            cout << type_ << " has no legs. It can only crawl." << endl;
        }
    }

  protected:
    // Define some additional properties that are specific to the Animal class
    // and not relevant for other living creatures.
    int numOfLegs_;
};

// Similarly define a new bird class that inherits from the LivingCreature class
// Notice that this class has different additional properties as compared to the
// Animal class
class Bird : public LivingCreature {
  public:
    Bird(string type, int avgLifeSpan, bool canFly)
        : LivingCreature(type, avgLifeSpan), canFly_(canFly)
    {
        if (canFly) {
            cout << "Created a bird of type " << type << " which can fly."
                 << endl;
        }
        else {
            cout << "Created a bird of type " << type << " which cannot fly."
                 << endl;
        }
    }

    bool canFly() { return canFly_; }

    void fly()
    {
        if (canFly_) {
            cout << type_ << " is flying." << endl;
        }
        else {
            cout << type_ << " cannot fly." << endl;
        }
    }

  protected:
    bool canFly_;
};

int main()
{
    // Create a few living creatures.
    // It is suggested to dynamically create objects using the new operator
    Animal *animal1 = new Animal("Cheetah", 12, 4);
    Animal *animal2 = new Animal("Snake", 18, 0);
    Bird *bird1 = new Bird("Eagle", 20, true);
    Bird *bird2 = new Bird("Little Penguin", 6, false);

    // Test the motions of the created living creatures

    // Notice that although the getType() method was not defined in the Animal
    // class we can still use it as it is inhertited from the LivingCreature


    // cout << "\nTesting animal motion of " << animal1->getType() << endl;
    // animal1->run();
    

    // cout << "\nTesting animal motion of " << animal2->getType() << endl;
    // animal2->run();

    // cout << "\nTesting bird motion of " << bird1->getType() << endl;
    // bird1->fly();

    // cout << "\nTesting bird motion of " << bird2->getType() << endl;
    // bird2->fly();


    //Friendship

    LivingCreature *living_animal = new LivingCreature("Alive",20); 
    living_animal->getAvgLifeSpan();








    // Delete the living creatures
    delete animal1;
    delete animal2;
    delete bird1;
    delete bird2;
}
