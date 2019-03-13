#include "flyingVehicle.h"
#include <iostream>

using namespace std;

/*
=================================================
Define all the methods from the Airplane class
=================================================
*/

Airplane::Airplane(string modelName, string airlines)
    : Vehicle(0, "Airplane", modelName), FlyingVehicle(true, false, false)
{
    airlines_ = airlines;
    cout << "Created a " << modelName << " Airplane for " << airlines << endl;
}

void Airplane::start()
{
    if (!isOn_) {
        cout << "All Jet Engine's started" << endl;
        isOn_ = true;
    }
    else
        cout << "Airplane is already ON" << endl;
}

void Airplane::stop()
{
    if (isOn_) {
        cout << "All Jet Engine's stopped" << endl;
        isOn_ = false;
    }
    else
        cout << "Airplane is already OFF" << endl;
}

bool Airplane::move(int newPos)
{
    if (!canHover_ && (newPos == currPos_)) {
        cout << "Airplane cannot hover!!" << endl;
        return false;
    }
    if (newPos < 10000) {
        cout << airlines_ << "'s airplane " << name_ << " flew from "
             << currPos_ << " to " << newPos << endl;
        currPos_ = newPos;
        return true;
    }
    else {
        cout << "Cannot move airplane as fuel is over!" << endl;
        return false;
    }
}

/*
=================================================
Define all the methods from the Helicopter class
=================================================
*/

Helicopter::Helicopter(string modelName, string owner)
    : Vehicle(0, "Airplane", modelName), FlyingVehicle(false, true, true)
{
    owner_ = owner;
    cout << "Created a " << modelName << " Helicopter for " << owner << endl;
}

void Helicopter::start()
{
    if (!isOn_) {
        cout << "Chopper Engine started" << endl;
        isOn_ = true;
    }
    else
        cout << "Chopper is already ON" << endl;
}

void Helicopter::stop()
{
    if (isOn_) {
        cout << "Chopper Engine stopped" << endl;
        isOn_ = false;
    }
    else
        cout << "Chopper is already OFF" << endl;
}

bool Helicopter::move(int newPos)
{
    if (newPos < 500) {
        cout << owner_ << "'s chopper " << name_ << " flew from " << currPos_
             << " to " << newPos << endl;
        currPos_ = newPos;
        return true;
    }
    else {
        cout << "Cannot move chopper as fuel is over!" << endl;
        return false;
    }
}
