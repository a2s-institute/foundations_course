#include <iostream>
#include "flyingVehicle.h"
#include "groundVehicle.h"

using namespace std;

Vehicle* createVehicle(int type, string model, string owner)
{
    Vehicle* vehicle = NULL;
    switch (type)
    {
        case 1:
            vehicle = new HorseCart(model, owner);
            break;
        case 2:
            vehicle = new Car(model, owner);
            break;
        case 3:
            vehicle = new Helicopter(model, owner);
            break;
        case 4:
            vehicle = new Airplane(model, owner);
            break;
        default:
            cout << "Cannot create a vehicle. INVALID vehicle type!" << endl;
            break;
    }

    return vehicle;
}

void testRunVehicle(Vehicle* vehicle, int pos = 100)
{
    if (vehicle != NULL)
    {
        cout << endl;
        vehicle->start();
        vehicle->move(pos);
        vehicle->stop();
    }
    else
    {
        cout << "Cannot test vehicle. Invalid vehicle pointer!" << endl;
    }
    
}

int main()
{
    Vehicle* v1 = createVehicle(1, "The Grand Gala Berlin", "Ferdinand III");
    Vehicle* v2 = createVehicle(2, "Tesla", "Elon Musk");
    Vehicle* v3 = createVehicle(3, "Eurocopter EC 175", "Bill gates");
    Vehicle* v4 = createVehicle(4, "Boeing 777", "Lufthansa");

    testRunVehicle(v1, 45);
    testRunVehicle(v2, 80);
    testRunVehicle(v3);
    testRunVehicle(v4);

    delete v1;
    delete v2;
    delete v3;
    delete v4;

    return 0;
}
