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

    /*
    The for loop consists of three parts:
        1. The initializer: creates any variables that may be necessary. Executed once at the start of the first iteration.
        2. The loop condition: This is evaluated at the START of each iteration
        3. The update: This section is executed AFTER each iteration.

    All the three parts are optional but the semicolons are a must.
    An infinite loop can be written as for ( ; ; )
    */
    for(int naturalNum = 1; naturalNum <= n; naturalNum++)
    {
        sum = sum + naturalNum;
    }

    cout << "The sum of first " << n << " natural numbers = " << sum << endl;

    return 0;
}
