#include<iostream>

using std::cout;
using std::endl;
// to use std::endl
    // for new line

int main ()
{
   // int slices = 5; // declaration and initialization

    // can also be written as 
    int slices;
    slices = 10;
    cout << slices << endl;
    //or 
   
    cout << slices << std::endl;

    int children = slices;
    cout << children << '\n';
    slices = 100;
    cout <<"You have "<< slices << " slices of pizzas" << endl;

    // printf also works
   // printf("%i", slices);
    
    
}