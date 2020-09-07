#include<iostream>
using namespace std;


int main()
{
    int size;
    int *ptr;

    cout << "Enter no of values u want to store (size of array) : " << endl;
    cin >> size;

    /* --- Create an array of that size 
           using a pointer --- */

  //  ptr = new  int [size];
    // or
    ptr = (int*) malloc(size *sizeof(int));
    // allocating memory

    cout << "Enter values to be stored in the array : " << endl;
    for(int i=0; i<size; i++)
    {
        cin >> ptr[i];
    }
    cout << " Values in the array are : " << endl;

    for(int i=0; i<size; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;



    // *********** Double pointer ************ //

    int  **a;
    int n =3;
    int m=5;

    a = (int**) malloc( n *sizeof(int*));
   
    for(int i=0; i<n; i++)
    {
        a[i] = (int*) malloc(m *sizeof(int));
        for(int j=0; j<m; j++)
        {
            a[i][j]= i+j;
        }
    }

    //----------//
     for(int i=0; i<n; i++)
    { 
        for(int j=0; j<m; j++)
        {
           cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}
// For 1st example
// Input
// Enter no of values u want to store (size of array) : 
// 6

// Enter values to be stored in the array : 
// 1 2 3 4 5 6

//  Values in the array are : 
// 1 2 3 4 5 6 