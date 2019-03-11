#include <iostream>
#include <string>

using namespace std;

// This is the base class for all the living creatures
class LivingCreature {
  public:
    LivingCreature() {}
    ~LivingCreature() {}

    // This function needs to be overridden in the derived classes to specify
    // the right mode of movement.
    void move()
    {
        cout << "Living Creature is moving. But mode of movement is unknown!"
             << endl;
    }
};

class Animal : public LivingCreature {
  public:
    Animal() : LivingCreature() {}
    ~Animal() {}

    // Here we override the move method which is inherted from the
    // LivingCreature class
    void move() { cout << "Animal moves by running." << endl; }
};

class Bird : public LivingCreature {
  public:
    Bird() : LivingCreature() {}
    ~Bird() {}

    // Here we override the move method which is inherted from the
    // LivingCreature class
    void move() { cout << "Bird moves by flying." << endl; }
};

int main()
{
    // Create a few living creatures.
    // It is suggested to dynamically create objects using the new operator
    LivingCreature *genericCreature = new LivingCreature();
    Animal *animal1 = new Animal();
    Bird *bird1 = new Bird();

    // Test the motions of the created living creatures
    cout << "\nTesting generic creature motion" << endl;
    genericCreature->move();

    // Test of the move function behaves differently than in the LivingCreature
    cout << "\nTesting animal motion" << endl;
    animal1->move();

    // Test of the move function behaves differently than in the LivingCreature
    cout << "\nTesting bird motion" << endl;
    bird1->move();

    // Delete the living creatures
    delete genericCreature;
    delete animal1;
    delete bird1;

    return 0;
}
