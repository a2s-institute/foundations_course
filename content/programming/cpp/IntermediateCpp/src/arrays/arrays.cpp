#include <iostream>

using namespace std;

/*
    This program demonstrates a simple example of creating arrays of a few basic
   datatypes
*/
int main()
{
    // Set the number of elements needed in the array
    const int NUM_OF_ITEMS = 5;

    /*
        Create and initialize an interger array.

        This way of initialization is not a very good way since changing it will
        require modifying code.

        Assume the length of the array was 1000, and started from 0-999.
        If you want to change this array to the range 1000-1999, you will have
        to change a 1000 numbers by hand!!
    */
    int intArray[NUM_OF_ITEMS] = {1, 2, 3, 4, 5};

    // Create a float array that will be initialized later
    float floatArray[NUM_OF_ITEMS];

    // This is a good way to initialize the array.
    // You can write any logic inside the loop to initialize the array as per
    // any given rule. Here we assume we want increments of 0.1 starting at 100
    for (int i = 0; i < NUM_OF_ITEMS; i++) {
        floatArray[i] = 100 + (i * 0.1);
    }

    // Create a char array that will be initialized later
    char charArray[NUM_OF_ITEMS];

    // Initialize just the first element of the array.
    // Notice that the indexs start at 0 for any array.
    charArray[0] = 'A';

    // Initialize all the subsequent elements of the array as the next character
    // in the C++ character encoding set.
    // Notice that the start index of this loop is 1 and not 0 as earlier. Why?
    for (int i = 1; i < NUM_OF_ITEMS; i++) {
        // We make use of the previous element in the array to determine the
        // value of the new element
        charArray[i] = charArray[i - 1] + 1;
    }

    // Print all the arrays
    cout << "Printing integer array elements..." << endl;
    for (int i = 0; i < NUM_OF_ITEMS; i++) {
        cout << intArray[i] << endl;
    }

    cout << "\nPrinting float array elements..." << endl;
    for (int i = 0; i < NUM_OF_ITEMS; i++) {
        cout << floatArray[i] << endl;
    }

    cout << "\nPrinting char array elements..." << endl;
    for (int i = 0; i < NUM_OF_ITEMS; i++) {
        cout << charArray[i] << endl;
    }
}
