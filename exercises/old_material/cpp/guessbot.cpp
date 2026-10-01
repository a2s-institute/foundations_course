//The guessing bot game

//Library imports
#include <iostream>
#include <string>




//Namespace declations
using namespace std;

//Global Variabls & functions declarations

void mode1();
void mode2();
void mode3();

int main()
{

int gmode=0; //Game mode
string name; // Player name
cout<<"Hello what is your name? \n"<<endl;
getline(cin,name);

cout<<"\nWelcome "+name+" to the Guess Bot Game: Please select your game mode"<<endl;
cout<<"1. You guess the number "<<endl;
cout<<"2. Dumb bot guess the number  "<<endl;
cout<<"3. Smart Bot guess the number(Beat you in 7 moves or less) "<<endl;
cout<<"Enter game mode "<<endl;


cin>>gmode;

    if(gmode==1)
    {
         mode1();
    }
       
    else if (gmode==2)
    {
        mode2();
    }
    else if(gmode==3)
    {
        mode3();
    }
    else
    {
        cout<<"Wrong mode selected"<<endl;
    }
    

    




return 0;
}

void mode1()
{
    cout<<"Hello you entered game mode 1"<<endl;
    cout<<"The bot will think of a number between 1 and 100 , your have to guess that number \n"<<endl;
    int random_number= rand()%100;
    int guess;
    int count=0;
    cout<<"Enter you guess"<<endl;
    cin>>guess;
    
    while((guess!=random_number)&&count<20)
    {
        if(guess>random_number)
        {

            cout<<"Wrong guess again, the number is Lower than what you guessed"<<endl;
        }

        else
        {
            cout<<"Wrong guess again, the number is Higer than what you guessed"<<endl;
        }
        
        count++;
        cout<<"Enter you guess"<<endl;
        cin>>guess;
        

    }
    
    if(guess==random_number)
    {
        cout<<"\n Congradulations you guessed in "<<count<<" tries"<<endl;
    }
    
    else
    {
        cout<<"\n Sorry you could'nt guess in 20 tries"<<endl;
    }
    



}

//This mode the player guess the number 
void mode2()
{
    cout<<"Hello you entered game mode 2"<<endl;
    cout<<"You will have to think of a number between 1 and 100 , dumb bot will have to guess that number"<<endl;
    cout<<"If the bot guessed right enter 'r' "<<endl;
    cout<<"If the bot guessed wrong and if the actual number is higher enter 'h' "<<endl;
    cout<<"If the bot guessed wrong and if the actual number is lower enter 'l' \n "<<endl;

    cout<<"Think of a number, the game starts now \n "<<endl;

    int guess= rand()%100;;
    
    string user_response="w";
    int count=0;
    

    while ((user_response!="r")&&count<20)
    {
         
         
         cout<<"The bot guessed "<<guess<<" ,Is the guess correct?"<<endl;
         cin>>user_response;

         if(user_response=="h")
         {
            guess= guess+(rand()%(101-guess));
         }

         else if(user_response=="l")
         {
             guess= guess-(rand()%(guess));
         }

         else if(user_response=="r")
         {
            break;
         }

         else
         {
             
            cout<<"You entered a wrong input \n"<<endl;
            cout<<"If the bot guessed right enter 'r' "<<endl;
            cout<<"If the bot guessed wrong and if the actual number is higher enter 'h' "<<endl;
            cout<<"If the bot guessed wrong and if the actual number is lower enter 'l' "<<endl;


         }
         count++;

    }
    
    if(user_response=="r")
    {
        cout<<"Sorry the bot guessed your number in "<<count<<" tries"<<endl;
    }
    
    else
    {
        cout<<"Congradulations the comptuer could'nt guess your number in 20 tries"<<endl;
    }


}

//This is game mode three the smart gusser which uses a binar filter search alogorithm
void mode3()
{
    cout<<"Hello you entered game mode 3"<<endl;
    cout<<"You will have to think of a number between 1 and 100 , smart bot will have to guess that number"<<endl;
    cout<<"If the bot guessed right enter 'r' "<<endl;
    cout<<"If the bot guessed wrong and if the actual number is higher enter 'h' "<<endl;
    cout<<"If the bot guessed wrong and if the actual number is lower enter 'l' "<<endl;

    int guess= 50;
    
    string user_response="w";
    int count=0;
    

    while ((user_response!="r")&&count<7)
    {



        count++;
    }


    if(user_response=="r")
    {
        cout<<"Sorry the bot guessed your number in "<<count<<" tries"<<endl;
    }
    
    else
    {
        cout<<"Congradulations the smart bot could'nt guess your number in 7 tries"<<endl;
    }

}