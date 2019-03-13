#ifndef FLYING_VEHICLE_H
#define FLYING_VEHICLE_H

#include "vehicle.h"

class Airplane : public Vehicle, public FlyingVehicle {
  public:
    Airplane(std::string modelName, std::string airlines);

    // The destructor has to be virtual
    virtual ~Airplane() {}

    // Implement the pure virtual functions from vehicle class
    virtual void start();
    virtual void stop();

    // Implement the pure virtual functions from the FlyingVehicle class
    virtual bool move(int newPos);

    std::string getAirlines() { return airlines_; }

  protected:
    std::string airlines_;
};

class Helicopter : public Vehicle, public FlyingVehicle {
  public:
    Helicopter(std::string modelName, std::string owner);

    // The destructor has to be virtual
    virtual ~Helicopter() {}

    // Implement the pure virtual functions from vehicle class
    virtual void start();
    virtual void stop();

    // Implement the pure virtual functions from the WheeledVehicle class
    virtual bool move(int newPos);

    std::string getOwner() { return owner_; }

  protected:
    std::string owner_;
};

#endif
