#include "Person.h"
#include <iostream>

using namespace std;


int main()
{

    //Default contructor    
    Person p1;


    
    p1.SetFirstName("Jerry");
    std::cout << p1.GetFirstName() << std::endl;

    // this line will output an invalid age message due to the 
    // validation check in the SetAge() function
    //instesad of
    
    // p1.SetAge(-5);

    p1.SetAge(10);

    // this line will not work because firstName is private
    // p.firstName = "Jerry";

    // Other constructors

    Person p2("Tom","Hanks");
    std::cout << p2.GetFirstName() << std::endl;


    Person p3("Charlie","Chaplin",101);
    std::cout << p3.GetFirstName() << std::endl;
    std::cout << p3.GetAge() << std::endl;
    










    Person *pointer_class = new Person;
    pointer_class->SetFirstName("Malika");

    delete pointer_class;


    return 0;
}