#ifndef GROUND_VEHICLE_H
#define GROUND_VEHICLE_H

#include "vehicle.h"

class Car : public Vehicle, public WheeledVehicle {
  public:
    Car(std::string modelName, std::string owner);

    // The destructor has to be virtual
    virtual ~Car() {}

    // Implement the pure virtual functions from vehicle class
    virtual void start();
    virtual void stop();

    // Implement the pure virtual functions from the WheeledVehicle class
    virtual bool move(int newPos);

  protected:
    std::string owner_;
};

class HorseCart : public Vehicle, public WheeledVehicle {
  public:
    HorseCart(std::string modelName, std::string owner);

    // The destructor has to be virtual
    virtual ~HorseCart() {}

    // Implement the pure virtual functions from vehicle class

    // Since there is nothing to do to start or stop a horse cart give empty
    // definitions to these functions
    virtual void start() {}
    virtual void stop() {}

    // Implement the pure virtual functions from the WheeledVehicle class
    virtual bool move(int newPos);

  protected:
    std::string owner_;
};

#endif
