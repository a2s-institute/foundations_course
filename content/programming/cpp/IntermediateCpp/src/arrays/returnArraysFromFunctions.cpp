#include <iostream>

using namespace std;

// A function to print an integer array of a given size
void printArray(int* array, int numOfElements)
{
    for (int i = 0; i < numOfElements; i++) {
        cout << array[i] << endl;
    }
}

// Write a function that creates an array and returns it
int* createArray(int size)
{
    int newArray[size];
    for(int i = 0; i < size; i++)
    {
        newArray[i] = i;
    }

    printArray(newArray, size);

    return newArray;
}

int main()
{
    // Set the number of elements needed in the array
    const int NUM_OF_ITEMS = 5;

    // Get the array using the function
    int* intArray = createArray(NUM_OF_ITEMS);

    // Print the newly created array.
    printArray(intArray, NUM_OF_ITEMS);

    return 0;
}
