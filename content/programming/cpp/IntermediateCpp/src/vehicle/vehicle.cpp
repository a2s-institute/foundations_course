#include "vehicle.h"
#include <iostream>

using namespace std;

/*
=================================================
Define all the methods from the Vehicle class
=================================================
*/

Vehicle::Vehicle()
{
    isOn_ = false;
    currPos_ = 0;
    name_ = "Vehicle Name Not Set!";
    type_ = "Vehicle Type Not Set!";
}

Vehicle::Vehicle(int spawnPos, std::string type, std::string name)
{
    isOn_ = false;
    currPos_ = spawnPos;
    name_ = name;
    type_ = type;
}

Vehicle::~Vehicle()
{
    cout << "Vehicle of type " << type_ << " and named " << name_
         << " was destroyed" << endl;
}

/*
=================================================
Define all the methods from the WheeledVehicle class
=================================================
*/

WheeledVehicle::WheeledVehicle(int numOfWheels, float wheelDiameter)
{
    numOfWheels_ = numOfWheels;
    wheelDiameter_ = wheelDiameter;
}

/*
=================================================
Define all the methods from the FlyingVehicle class
=================================================
*/

FlyingVehicle::FlyingVehicle(bool hasWings, bool hasRotorBlades, bool canHover)
{
    hasWings_ = hasWings;
    hasRotorBlades_ = hasRotorBlades;
    canHover_ = canHover_;
}
