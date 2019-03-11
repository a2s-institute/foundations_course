#include <iostream>

using namespace std;

/*
    This program demonstrates an example of how to use arrays with functions.
*/

// To pass an array to function as a pointer.
void printArray(int* array, int numOfElements)
{
    for (int i = 0; i < numOfElements; i++) {
        cout << array[i] << endl;
    }
}

int main()
{
    // Set the number of elements needed in the array
    const int NUM_OF_ITEMS = 5;

    int intArray[NUM_OF_ITEMS];

    // Print the garbage values created in the array
    cout << "\nArray elements without initialization:" << endl;
    printArray(intArray, NUM_OF_ITEMS);

    // Initialize the array as multiples of two.
    for(int i = 0; i < NUM_OF_ITEMS; i++)
    {
        intArray[i] = 2 * (i+1);
    }

    // Print the initialized values in the array
    cout << "\nArray elements after initialization:" << endl;
    printArray(intArray, NUM_OF_ITEMS);

    return 0;
}
