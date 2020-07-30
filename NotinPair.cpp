#include<iostream>
using namespace std;

// unique no 
// find the number which does not have a pair
int main()
{
    int arr[]={1,2,4,2,3,1,4};
    int n= 7;
    
    int find={0};

    for(int i=0; i<n; i++)
    {
        find = find ^ arr[i];
    }
    cout << find << endl;
}