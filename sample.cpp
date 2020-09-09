#include<iostream>
using namespace std;

int x = 40;

int main()
{
    int x = 5;
    cout << "Outside" << endl;
    cout << "x -> " << x << endl;

    if(true)
    {
        cout << " Inside block : " << endl;
        int x = 10;
        cout << x << endl;
        cout << "Global -> " << ::x  << endl; // globals
    }
    cout << "Outside -> " << x << endl;
    cout << "Global -> " << ::x << endl;

    return 0;
}