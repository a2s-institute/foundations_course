#include <iostream>
using namespace std;

// We use pass by reference here!
int swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int num1 = 10, num2 = 20;
    swap(num1, num2);
    cout << "Numbers after swap: " << num1 << " " << num2 << endl;
    return 0;
}
