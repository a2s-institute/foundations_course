// This is a single line comment. everything after the // will be commented out
// in that line

/*
This is a multi line comment
Everything between the opening and closing combination of /* will be commented
out.
*/

/*
The below line is a header include.
Headers usually define many standard utitlty functions which are often used. For
example writing something to the console is done using the iostream header here.
*/
#include <iostream>

/*
We will not cover namespaces today. But you can find more info at
https://www.tutorialspoint.com/cplusplus/cpp_namespaces.htm
*/
using namespace std;

// This is where the program will begin its execution. The main() function.
int main()
{
    /*
    The below line will print the text "Hello world" to the console.
    The cout and endl are utilities defined in the header iostream. That is why
    we had to include it.

    cout prints whatever follows the << operator on the
    console.

    endl will add a new line after we have finished priniting the
    content.
    */
    cout << "Hello World!" << endl;

    /*
    This will return the value of zero to the calling program indicating the
    completion of the execution of the program
    */
    return 0;
}
