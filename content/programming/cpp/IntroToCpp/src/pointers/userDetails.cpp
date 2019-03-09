#include<iostream>
#include<string>
using namespace std;

// This is an example of passing by pointer to get multiple return values from a function
void getUserData(string* name, int* yearOfBirth, string* nationality)
{
    cout << "Enter your first name: ";
    cin >> *name;

    cout << "Enter your year of birth: ";
    cin >> *yearOfBirth;

    cout << "Enter your nationality: ";
    cin >> *nationality;
}

void printUserData(string name, int age, string nationality)
{
    cout << name << " is a " << age << " year old person from " << nationality << "\n" << endl;
}

// Notice that we use a default value for the parameter currentYear.
// Therefore passing a value for the paramater currentYear is optional.
// If no value is passed, then the parameter assumes the default value of 2019.
int computeAge(int yearOfBirth, int currentYear = 2019)
{
    return currentYear - yearOfBirth;
}

int main()
{
    string name = "";
    int yearOfBirth = 0;
    string nationality = "";

    for (int itr = 0; itr < 10; itr++)
    {
        getUserData(&name, &yearOfBirth, &nationality);

        // Notice that we do not pass a value for currentYear when calling the function computeAge
        printUserData(name, computeAge(yearOfBirth), nationality);
    }

    return 0;
}
