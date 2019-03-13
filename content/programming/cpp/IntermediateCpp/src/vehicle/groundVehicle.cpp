#include "groundVehicle.h"
#include <iostream>

using namespace std;

/*
=================================================
Define all the methods from the Car class
=================================================
*/

Car::Car(string modelName, string owner)
    : Vehicle(0, "MotorCar", modelName), WheeledVehicle(4, 10)
{
    owner_ = owner;
    cout << "Created a " << modelName << " Car for " << owner << endl;
}

void Car::start()
{
    if (!isOn_)
    {
        cout << "Car Engine started" << endl;
        isOn_ = true;
    }
    else
        cout << "Car is already ON" << endl;
}

void Car::stop()
{
    if (isOn_)
    {
        cout << "Car Engine stopped" << endl;
        isOn_ = false;
    }
    else
        cout << "Car is already OFF" << endl;
}

bool Car::move(int newPos)
{
    if (newPos < 100) {
        cout << owner_ << "'s car " << name_ << " moved from " << currPos_
             << " to " << newPos << endl;
        currPos_ = newPos;
        return true;
    }
    else {
        cout << "Cannot move as fuel is over!" << endl;
        return false;
    }
}

/*
=================================================
Define all the methods from the HorseCart class
=================================================
*/

HorseCart::HorseCart(string modelName, string owner)
    : Vehicle(0, "HorseCart", modelName), WheeledVehicle(4, 8)
{
    owner_ = owner;
    cout << "Created a " << modelName << " horseCart for " << owner << endl;
}

bool HorseCart::move(int newPos)
{
    if (newPos < 50) {
        cout << owner_ << "'s horse cart " << name_ << " moved from "
             << currPos_ << " to " << newPos << endl;
        currPos_ = newPos;
        return true;
    }
    else {
        cout << "Cannot move as horses are tired!" << endl;
        return false;
    }
}
