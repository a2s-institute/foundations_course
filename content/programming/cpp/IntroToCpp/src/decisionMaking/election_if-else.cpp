#include <iostream>
#include <string>

using namespace std;

int main()
{
    string username = "";
    int userYearOfBirth = 0;

    cout << "Enter your name: ";
    cin >> username;

    cout << "Enter your year of birth: ";
    cin >> userYearOfBirth;

    // Assuming elections are in 2019, compute user's age
    int userAge = 2019 - userYearOfBirth;

    // Set the minimum voting age.
    // Notice the use of the const keyword. It will not allow the value of the
    // variable to be modified after it has been initialized.
    const int minAgeToVote = 18;

    // Check if user is allowed to vote
    if (userAge > minAgeToVote)
    {
        // Assume every party is identified using an integer starting at 1.
        // Also assume there are 5 parties named A, B, C, D and E.
        int partyID = 0;
        cout << "Please enter a party ID between 1 to 5 to cast your vote: ";
        cin >> partyID;

        if (partyID == 1)
        {
            cout << "You cast your vote to Party - A" << endl;
        }
        else if (partyID == 2)
        {
            cout << "You cast your vote to Party - B" << endl;
        }
        else if (partyID == 3)
        {
            cout << "You cast your vote to Party - C" << endl;
        }
        else if (partyID == 4)
        {
            cout << "You cast your vote to Party - D" << endl;
        }
        else if (partyID == 5)
        {
            cout << "You cast your vote to Party - E" << endl;
        }
        else 
        {
            // Handle incorrect inputs for partyID.
            cout << "You entered a wrong partyID!!" << endl;
        }
    }
    else
    {
        cout << "Please wait for " << (minAgeToVote - userAge) << " years before you can vote." << endl; 
    }

    return 0;
}
