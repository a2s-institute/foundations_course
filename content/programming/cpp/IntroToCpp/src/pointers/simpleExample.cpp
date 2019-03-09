#include <iostream>
using namespace std;

int main()
{
    int num1 = 10;

    // Initialise the pointer with the address of num1 variable.
    int* num1Ptr1 = &num1; // The & operator will fetch the address at which the variable num1 is stored.
    cout << "Address of num1 variable is: " << num1Ptr1 << endl;
    cout << "Data stored at this address is : " << *num1Ptr1 << endl;

    // de-reference the pointer to update the value store at the address.
    *num1Ptr1 = 20;
    cout << "Value of the variable num1 after changing the value using num1Ptr1 = " << num1 << endl;

    // Create and initialize a new pointer using the pointer created previously
    int* num1Ptr2 = num1Ptr1; // You can create multiple copies of this pointer. All of them will change the same memory location.

    // Update the num1 variable by de-referencing the newly created pointer
    *num1Ptr2 = 30;
    cout << "Value of the variable num1 after changing the value using num1Ptr2 = " << num1 << endl;

    return 0;
}
