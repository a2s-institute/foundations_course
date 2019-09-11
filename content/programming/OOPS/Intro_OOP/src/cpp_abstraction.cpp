#include <iostream>
#include <string>
using namespace std;

class Car{
    private:
    int car_number;
    string car_model;
    public:
    void register_ar(int number, string model){
        car_number = number
        car_model = model;
    }
    void get_details(){
        cout<<"Car number is: "<<car_number<<endl;
        cout<<"Car model is: "<< car_model<<endl;
    }
};

int main(){
    Car opel;
    opel.register _car(124, "Astra");
    opel.get_details();
}