#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

int main()
{
    string one = "apple";
    string two = "beans";

    cout << one << endl << two << endl;

    one.swap(two);


    cout << one << endl << two << endl;

}
