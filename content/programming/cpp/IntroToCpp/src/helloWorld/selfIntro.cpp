#include <iostream>
#include <string>
#include <ctime>
using namespace std;
int main(int argc , char* argv[])
{
//  cout<<"Hello I am Malika"<<endl;
//  cout<<"Im from Sri Lanka"<<endl;
//  cout<<"Whaz up Homies"<<endl;

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

/*

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

string countries[]={"USA","usa","Japan","japan","UK","uk"};
string count="";
cout<<"Type your country"<<endl;
cin>>count;
bool cas=false;

int len=sizeof(countries);

for (int i=0;i<=len;i++)
{
    if(count==countries[i])
    {
        cas=true;
    }

    
    
}

if(cas)
{
 cout<<"You are excepted"<<endl;
}

else
{
cout<<"You are not excepted"<<endl;

}

return 0; 
}