#include <iostream>
#include <string>
#include <ctime>
#include<algorithm>

using namespace std;

int main(int argc , char* argv[])
{
//  cout<<"Hello I am Malika"<<endl;
//  cout<<"Im from Sri Lanka"<<endl;
//  cout<<"Whaz up Homies"<<endl;
/*
int birth=0;
string first_name="";
string last_name="";

cout<<"Type your first name"<<endl;
cin>>first_name;
cout<<"Enter last name"<<endl;
cin>>last_name;
cout<<"Enter Birth Year"<<endl;
cin>>birth;

//Using ctime lib to get the current year
time_t t = time(NULL);
tm *tPtr = localtime(&t);
int age=(tPtr->tm_year)-birth+1900;



cout<<"You are"<<endl;
cout<<age<<endl;
cout<<" yearss old"<<endl;



int p=1;
int q=1;

int result1=(p++)*3;
int result2=(++q)*3;

cout<<"p++"<<endl;
cout<<result1<<endl;

cout<<"++p"<<endl;
cout<<result2<<endl;


*/

string countries[]={"usa","japan","uk"};
string count="";
int len=sizeof(countries);

 cout<<"Type your country"<<endl;
 cin>>count;
 transform(count.begin(),count.end(),count.begin(),::tolower); // convert to lower case inclded algorith
while (count!="END")
{
     bool allowed=false;



        for (int i=0;i<=len;i++)
        {
            if(count==countries[i])
            {
                allowed=true;
            }        
            
        }


    if(allowed)
    {
    cout<<"You are exempted"<<endl;
    cout<<""<<endl;
    }

    else
    {
    cout<<"You are not exempted"<<endl;
    cout<<""<<endl;

    }

 cout<<"Type your country"<<endl;
 cin>>count;
 transform(count.begin(),count.end(),count.begin(),::tolower); // convert to lower case inclded algorith
 
}



 return 0; 
}


   
   