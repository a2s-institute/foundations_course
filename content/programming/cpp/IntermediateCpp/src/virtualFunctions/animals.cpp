#include <iostream>
#include <string>

using namespace std;

// This is the base class for all the living creatures
class LivingCreature {
  public:
    LivingCreature(string type) : type_(type) {}
    virtual ~LivingCreature() {}

    /*
        These functions are called pure virtual because these functions are
       needed by every living creature, but everyone has a different way of
       doing this. There is no default way to these functions.

        Any class which has one or more pure virtual functions are called
       abstract class and it is not possible to create an object of these
       classes. Only object of derived classes which implement these functions
       are possible.
    */
    virtual void move() = 0;
    virtual void procreate() = 0;
    

    // This function is defined as virtual here, because we want to override it
    // later. Any function you believe has the possibility to be overriden in
    // derived classes must be defined as virtual.
    virtual void die()
    {
        cout << "A living creature of type " << type_ << " died." << endl;
    }

    void non_virtual(){cout<<"This is Living Creature class"<<endl;}

    // We do not expect this function to be changed in the derived class.
    // Therefore it is not virtual.
    string getType() { return type_; }

  protected:
    string type_;
};

class Mammal : public LivingCreature {
  public:
    Mammal(string type) : LivingCreature(type) {}
    virtual ~Mammal() {}

    // This is where we define the move method of the pure virtual function
    // from the base class
    virtual void move()
    {
        cout << "Mammal of type " << type_ << " moves on land." << endl;
    }

    virtual void procreate()
    {
        cout << "Mammal of type " << type_ << " gives birth to offsprings."
             << endl;
    }


    void non_virtual(){cout<<"This is Mammal class"<<endl;}
};

class Bird : public LivingCreature {
  public:
    Bird(string type) : LivingCreature(type) {}
    virtual ~Bird() {}

    // This is where we define the move method of the pure virtual function
    // from the base class
    virtual void move()
    {
        cout << "Bird of type " << type_ << " flies in the air." << endl;
    }

    virtual void procreate()
    {
        cout << "Bird of type " << type_ << " lays Eggs." << endl;
    }


    void non_virtual(){cout<<"This is Bird class"<<endl;}

};

class Phoenix : public Bird {
  public:
    Phoenix(string type) : Bird(type) {}
    virtual ~Phoenix() {}

    virtual void die()
    {
        cout << "A Phoenix died, but came back to life from its Ashes!" << endl;
    }

    void non_virtual(){cout<<"This is Phoneix class"<<endl;}

};

int main()
{
    

    // Run a non virtual class 

    Mammal *dog = new Mammal("Hund");

    dog->non_virtual();

    LivingCreature *dog2 = new Mammal("Hund2");

    dog2->non_virtual();


    /*
    The below line is commented because we cannot create a generic living
    creature now since the class LivingCreature is abstract

    Try uncommenting out the line to see what happens.
     */

    // LivingCreature *genericCreature = new LivingCreature("Generic Creature");

    // Lets assume we wish to create three living creatures. We will now use an
    // array of the base class pointer's to represent all the different types of
    // living creatures.

    // const int NUM_OF_CREATURES = 4;
    // LivingCreature *creatures[NUM_OF_CREATURES];

    // // Use the base class pointer to represent objects of the derived classes
    // creatures[0] = new Mammal("Cheetah");
    // creatures[1] = new Bird("Eagle");
    // creatures[2] = new Phoenix("Phoenix");
    // creatures[3] = new Mammal("Dog");





    //   for (int i = 0; i < NUM_OF_CREATURES; i++) {
    //     creatures[i]->non_virtual();
    // }

    // // Try moving the creatures
    // for (int i = 0; i < NUM_OF_CREATURES; i++) {
    //     creatures[i]->move();
    // }

    // //Try procreating the creatures
    // for (int i = 0; i < NUM_OF_CREATURES; i++) {
    //     creatures[i]->procreate();
    // }

    // //Try killing the creatures
    // for (int i = 0; i < NUM_OF_CREATURES; i++) {
    //     creatures[i]->die();
    // }

    // //delete the creatures
    // for (int i = 0; i < NUM_OF_CREATURES; i++) {
    //     delete creatures[i];
    // }

    return 0;
}
