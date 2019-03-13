#include <iostream>
#include <string>

using namespace std;

// An example to demonstrate function overloading
class Adder {
  public:
    Adder() {}
    ~Adder() {}

    // The add function takes many forms.
    int add(int a, int b) { return a + b; }

    // Overloading can be done by having different number of parameters
    int add(int a, int b, int c) { return a + b + c; }

    // Overloading can be done by having same number of parameters nut different
    // types (even different order of same types is allowed)
    string add(string a, string b) { return a + b; }
};

int main()
{
    Adder *adder = new Adder();

    int num1 = 10;
    int num2 = 20;
    int num3 = 100;

    string str1 = "Lemon";
    string str2 = "Grass";

    cout << num1 << " + " << num2 << " = " << adder->add(num1, num2) << endl;
    cout << num1 << " + " << num2 << " + " << num3 << " = "
         << adder->add(num1, num2, num3) << endl;
    cout << str1 << " + " << str2 << " = " << adder->add(str1, str2) << endl;

    return 0;
}
