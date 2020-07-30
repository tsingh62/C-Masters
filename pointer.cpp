
#include<iostream>
using namespace std;

int main()
{
    int x = 10;
    int* xptr = &x;

    cout << x << endl; // 10
    cout << *xptr<< endl; // 10

    cout << &x << endl; // address
    cout << xptr << endl; // address

    cout << *(&x) << endl; // 10
    cout << *(xptr) << endl; // 10

    cout << *(&xptr)<< endl; // address
    cout << &(*xptr)<< endl; // address

}