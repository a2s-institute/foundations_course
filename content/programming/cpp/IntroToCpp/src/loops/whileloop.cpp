#include<iostream>
#include<string>
using namespace std;

// This code will compute the sum of first 'n' natural numbers.
int main()
{
    int n;
    int sum = 0; // initializing this variable to 0 is very important

    cout << "Enter the value of n: ";
    cin >> n;

    // Define a control variable to update the current natural number to be added to the sum.
    int naturalNum = 1;

    /*
    A while does not take care of the initialization of the control variable or its update.
    It simply checks if the control condition is true to decide if it should start the iteration.
    The condition is checked at the START of each iteraion.
    The developer is responsible for correctly updating the control variable.
    An infinite loop can be written using while (true) since the control statement will never evaluate to false.
    */
    while (naturalNum <= n)
    {
        sum = sum + naturalNum;

        // Update the control variable
        naturalNum++;
    }

    cout << "The sum of first " << n << " natural numbers = " << sum << endl;

    return 0;
}
