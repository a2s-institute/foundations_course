#include <iostream>

using namespace std;

int *createArrayUsingDMA(int size)
{
    int *newArray = new int[size];
    cout << "Created Array of Size " << size << endl;
    return newArray;
}

void deleteArray(int *array)
{
    delete[] array;
    cout << "Deleted Array" << endl;
}

int main()
{
    // Allocate large chunks of memory in each allocation
    const int NUM_OF_ITEMS = 50000000;

    // Infinite loop to create arrays on heap without deleting them
    while (true) {
        int *intArray = createArrayUsingDMA(NUM_OF_ITEMS);
        // deleteArray(intArray);
    }

    return 0;
}
