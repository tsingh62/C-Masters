#include<iostream>

// using math function
#include<cmath>
using std::endl;
using std::cin;
using std::cout;


int main ()

{ 
    int x,y;
    cout << "Enter the values : " << endl;
    cin >>  x;
    cin >>  y;
    double power = pow(x,y);
    cout << power << endl;
    return 0;


}