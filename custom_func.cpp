
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;

double power(double base, int exponent)
{
    double result = 1;
    for(int i =0; i<exponent; i++)
    {
        result = result * base;
    }
    return result;
}

int main()
{
    double base;
    int exponent;
    cout <<"Enter the 1st value : " <<endl;
    cin >> base;
    cout <<"Eneter the 2nd value : "<<endl;
    cin >> exponent;
    double myPower = power(base, exponent);
    cout << myPower << endl;
}