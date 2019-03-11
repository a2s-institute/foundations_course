#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

// This is an abstract class due to presence of pure virtual functions.
// Therefore no object of this class can be constructed.
class Vehicle {
  public:
    // This is the deafult constructor
    Vehicle();

    // This is a parameterized constructor
    Vehicle(int spawnPos, std::string type, std::string name);

    // This is a destructor. All destructor's dont have a return type and also
    // do not take any parameters.
    virtual ~Vehicle();

    // These are pure virtual functions.
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual bool move(int pos) = 0;

    // These functions are common to any vehicle and therefore can be declared
    // here. Also these functions are called getters. It is common to define
    // them in the header itself.
    std::string getName() { return name_; }
    std::string getType() { return type_; }
    int getPosition() { return currPos_; }
    bool isOn() { return isOn_; }

  protected:
    // Define the common properties associated with all type of vehicles
    bool isOn_;
    int currPos_;
    std::string type_;
    std::string name_;
};

class WheeledVehicle {
  public:
    // This class only has a parameterized constructor,
    // therefore we force the user of this class to always pass the numOfWheels
    // and wheelDiameter
    WheeledVehicle(int numOfWheels, float wheelDiameter);
    virtual ~WheeledVehicle() {}

    int getNumOfWheels() { return numOfWheels_; }
    float getWheelDiameter() { return wheelDiameter_; }

  protected:
    int numOfWheels_;
    float wheelDiameter_;
};

class FlyingVehicle {
  public:
    // Again, this class only has a parameterized constructor,
    // therefore we force the user of this class to always pass some parameters
    FlyingVehicle(bool hasWings, bool hasRotorBlades, bool canHover);
    virtual ~FlyingVehicle() {}

    bool hasWings() { return hasWings_; }
    bool hasRotorBlades() { return hasRotorBlades_; }
    bool canHover() { return canHover_; }

  protected:
    bool hasWings_;
    bool hasRotorBlades_;
    bool canHover_;
};

#endif
