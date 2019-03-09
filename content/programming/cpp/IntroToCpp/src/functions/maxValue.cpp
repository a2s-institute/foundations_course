#include <iostream>
using namespace std;

// function returning the max between two numbers
int max(int num1, int num2)
{
    // local variable declaration
    int result;

    if (num1 > num2)
        result = num1;
    else
        result = num2;

    return result;
}

// function returning the max between three numbers
int max(int num1, int num2, int num3)
{
    if (num1 > num2)
    {
        return max(num1, num3);
    }
    else
    {
        return max(num2, num3);
    }

    // Or in a single line as:
    // return max(max(num1, num2), num3);
}

int main()
{
    // local variable declaration:
    int a = 100;
    int b = 200;
    int c = 300;
    int maxValue;

    // calling a function to get max value.
    maxValue = max(a, b);
    cout << "Max value among " << a << " and " << b << " is : " << maxValue << endl;

    // calling a function to get max value.
    maxValue = max(a, b, c);
    cout << "Max value among " << a << ", " << b << " and " << c << " is : " << maxValue << endl;

    return 0;
}
