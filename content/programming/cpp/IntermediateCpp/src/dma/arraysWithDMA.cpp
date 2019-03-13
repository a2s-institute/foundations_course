#include <iostream>

using namespace std;

// A function to print an integer array of a given size
void printArray(int *array, int numOfElements)
{
    for (int i = 0; i < numOfElements; i++) {
        cout << array[i] << endl;
    }
}

// Write a function that creates an array using DMA and returns it
int *createArrayUsingDMA(int size)
{
    /*
    Allocate the memory on Heap using the new operator.

    You can pass the size of the memory needed using the [] operator.

    The new opertaor always returns a pointer to the first element in the
    alllocated memory.
    */
    int *newArray = new int[size];

    // You can access the memory in the ssame way as accessing an array
    for (int i = 0; i < size; i++) {
        newArray[i] = i;
    }

    cout << "Arrays contents being returned from the function" << endl;
    printArray(newArray, size);

    return newArray;
}

int main()
{
    // Set the number of elements needed in the array
    const int NUM_OF_ITEMS = 5;

    // Get the array using the function
    int *intArray = createArrayUsingDMA(NUM_OF_ITEMS);

    // Print the newly created array.
    cout << "\nArrays contents being received from the function" << endl;
    printArray(intArray, NUM_OF_ITEMS);

    // Deallocate the allocated memory
    // Since it is an array, we need to use delete[] instead of simply delete.
    delete[] intArray;

    return 0;
}
