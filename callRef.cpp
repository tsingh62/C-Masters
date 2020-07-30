
#include<iostream>
using namespace std;

void check(int* k)
{
    *k = *k+1;

    cout << &k << endl;
    cout << *k << endl;
}

int main()
{
    int a = 10;
    check(&a);

    cout << a << endl;
    cout << &a << endl;

}