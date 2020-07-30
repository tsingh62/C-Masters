#include<iostream>
using std::cout;
using std::endl;

int main()
{
   // int guesses [10] = {12,43,23,43,25}; // will print 12,23,43,23,43,0,0,0,0,0
                                            // since we have also defined 10 with it
    int guesses [] = {12,43,23,43,25};
    // this will print 20
    // which is the bit size of the array 
    int size1 = sizeof(guesses);
    cout << size1 << endl;
    // in order to get the size of the array
    // we need to divide it by the size of a single element
    int size = sizeof(guesses) / sizeof(guesses[0]);
    cout << size << endl;

    for(int i=0; i<size; i++)
    {
        cout << guesses[i] << endl;
    }
    
    return 0;
}