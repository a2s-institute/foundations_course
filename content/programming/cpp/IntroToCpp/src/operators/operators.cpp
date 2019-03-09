#include <iostream>
#include <string>

using namespace std;

int main()
{
    int integer1 = 10;
    int integer2 = 25;
    int integer3 = 10;

    // Modulo operator
    int modulo = integer2 % integer1;
    cout << integer2  << " modulo " << integer1 << " = " << modulo << endl;

    // increment operator
    integer1++;
    cout << "After incrementing the integer1 variable, it changed to " << integer1 << endl;

    // decrement operator
    integer1--;
    cout << "After decrementing the integer1 variable, it changed back to " << integer1 << endl;

    // Equality operator
    bool int1EqualsInt2 = integer1 == integer2;
    bool int1EqualsInt3 = integer1 == integer3;

    cout << "Result of comparing integer1 and integer2 = " << int1EqualsInt2 << endl;
    cout << "Result of comparing integer1 and integer3 = " << int1EqualsInt3 << endl;

    string str1 = "xyz";
    string str2 = "abc";
    string str3 = "xyz";

    // You can compare strings too! 
    // Notice that we do not use an additional variable to store the results here.
    cout << "Result of comparing two strings " << str1 << " and " << str2 << " = " << (str1 == str2) << endl;
    cout << "Result of comparing two strings " << str1 << " and " << str3 << " = " << (str1 == str3) << endl;


    // Logical operators
    bool X = true;
    bool Y = false;
    bool Z = true;

    // AND
    cout << X << " AND " << Y << " = " << (X && Y) << endl;
    cout << X << " AND " << Z << " = " << (X && Z) << endl;

    // OR
    cout << X << " OR " << Y << " = " << (X || Y) << endl;

    // NOT
    cout << "Negation of " << X << " is " << (!X) << endl;

    return 0;
}
