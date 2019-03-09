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

    // Check if user is allowed to vote.
    // Can you use a switch here?
    if (userAge > minAgeToVote)
    {
        // Assume every party is identified using an integer starting at 1.
        // Also assume there are 5 parties named A, B, C, D and E.
        int partyID = 0;
        cout << "Please enter a party ID between 1 to 5 to cast your vote: ";
        cin >> partyID;

        // Example of using a switch to make the decision instead of if-else
        switch (partyID)
        {
            case 1:
                cout << "You cast your vote to Party - A" << endl;
                break;
            case 2:
                cout << "You cast your vote to Party - B" << endl;
                break;
            case 3:
                cout << "You cast your vote to Party - C" << endl;
                break;
            case 4:
                cout << "You cast your vote to Party - D" << endl;
                break;
            case 5:
                cout << "You cast your vote to Party - E" << endl;
                break;
            default:
                // This block will be executed if partyId is not equal to any of
                // the above values
                cout << "You entered a wrong partyID!!" << endl;
                break;
        }
    }
    else
    {
        cout << "Please wait for " << (minAgeToVote - userAge) << " years before you can vote." << endl; 
    }

    return 0;
}
