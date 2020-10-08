#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function declaration

int add(int a,int b)
{
return (a+b);

}

int sub(int a,int b)
{
    return (a-b);
    
}

int mul(int a,int b)
{
    return (a*b);
}

float divi(int a,int b)
{
    float res=(float)a/b;

    return res;
}

int main()
{
int num1,num2;
string action;

    cout<<"Enter first Number"<<endl;
    cin>>num1;
    cout<<""<<endl;

    cout<<"Enter Second Number"<<endl;
    cin>>num2;
    cout<<""<<endl;

    cout<<"Whats the function you want to do. add,sub,mul,divi"<<endl;
    cin>>action;
    transform(action.begin(),action.end(),action.begin(),::tolower);
    cout<<""<<endl;

    if(action=="add")
    {
        cout<<add(num1,num2)<<endl;
    }

    if(action=="sub")
    {
        cout<<sub(num1,num2)<<endl;
    }


    if(action=="mul")
    {
        cout<<mul(num1,num2)<<endl;
    }


    if(action=="divi")
    {
        cout<<divi(num1,num2)<<endl;
    }




    
}