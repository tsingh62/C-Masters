#include<iostream>
using std::cout;
// we need to add - using string to define string values
using std::string;
using std::endl;

int main()
{
    // we need to add - using string to define string values
    string greet = "Hello welcome";
    string greet2 = "back";
    string greet3 = greet + greet2; // concatination 

    greet2 += "!"; // append

    cout << greet.append(" ") << greet3 << greet2.length()  << endl;
    // .append() also works

}