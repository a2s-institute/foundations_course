#include<iostream>
#include<string>
using namespace std;

// This code will compute the sum of first 'n' natural numbers.
// Assume that we need to set the sum to the first natural number if user enters n = 0;
int main()
{
    int n;
    int sum = 0; // initializing this variable to 0 is very important

    cout << "Enter the value of n: ";
    cin >> n;

    // Define a control variable to update the current natural number to be added to the sum.
    int naturalNum = 1;

    /*
    A do-while loop is similar to the while loop, except that the control condition is checked AFTER each iteration.
    This mean the loop's code will be executed atleast once irrespective of the control condition.
    */
    do
    {
        sum = sum + naturalNum;

        // Update the control variable
        naturalNum++;
    } while (naturalNum <= n); // we need a semi-colon here for a do-while loop

    cout << "The sum of first " << n << " natural numbers = " << sum << endl;

    return 0;
}
