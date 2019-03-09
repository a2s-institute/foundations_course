#include <iostream>

// Include the string header to store strings of characters
#include <string>

using namespace std;

int main()
{
    // Define a string variable to store the user's name. 
    // Set the dafault value as an empty name.
    string username = "";

    // We define two variables to store the users input. Let us set the default
    // value of these variables to 0. Otherwise the value assigned to this
    // memory will be any random number and is called garbage value.
    int num1 = 0;
    int num2 = 0;

    // We define one more variable to store the sum of the two numbers.
    int sum = 0;

    // Ask the user to enter his first name
    cout << "Please enter your first name (no spaces please): ";

    /*
    cin is also from the iostream header and is used to get user inputs from the
    user. The user input is stored into the username variable.
    This will replace the default value of an empty name by the users input
    */
    cin >> username;

    // Ask the user to enter first integer
    cout << "Enter the first integer: ";
    // Store the first number in the num1 variable
    cin >> num1;

    // Ask the user to enter second integer
    cout << "Enter the second integer: ";
    // Store the second number in the num2 variable
    cin >> num2;

    /*
    Use the + operator to compute the sum.
    The = operator will replace the default value of zero assigned to the sum
    variable with the newly computed sum of the two input numbers
    */
    sum = num1 + num2;

    /*
    Print the Sum of two number.
    Also demonstrates how we can print the variables with standard datatypes to
    the console
    */
    cout << username  << ", the sum of " << num1 << " and " << num2 << " is: " << sum << endl;

    return 0;
}
