#include <iostream>

using namespace std;

class test_class
{
    public:

    void name()
    {
    cout<<"Pointer class"<<endl;
    }
};
// function that takes value as parameter
void func_value(int numVal) {
    numVal+=1;
}
// function that takes reference as parameter
void func_ref(int &numRef) {
    numRef+=1;
}
// function that takes pointer as parameter
void func_point(int *numPoint)
{
    *numPoint+=1;
}
int main(int argc , char **argv)
{
    int age =19;   
    int *pAge=&age;
    cout<<"The value of age is "<<age<<endl;
    cout<<"The address of age is "<<&age<<endl;
    cout<<"The output of pAge is "<<pAge<<endl;
    cout<<"The output of *pAge is "<<*pAge<<" \n \n"<<endl;   
    int pass_val=3;
    int pass_ref=3;
    cout<<"Pass by value before "<<pass_val<<endl;
    cout<<"Pass by reference before "<<pass_ref<<endl;
    func_value(pass_val);
    func_ref(pass_ref);
    cout<<"\n Pass by value after "<<pass_val<<endl;
    cout<<"Pass by reference after "<<pass_ref<<endl;
    cout<<"\n\nPass by pointer before "<<*pAge<<endl;
    func_point(pAge);
    cout<<"Pass by pointer after "<<*pAge<<endl;
return 0; 
}