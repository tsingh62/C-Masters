

#include<iostream>
using namespace std;

int main()
{
    int arr[] = {12,13,10,9,5,20};
    int n = sizeof(arr)/sizeof(int);
    int key=9;
    int pos=1;
    for(int i=0; i<n; i++)
    {
        pos++;
        if(arr[i]==key)
        {
            
            cout << arr[i] << endl;
            cout << pos; 
            break;
        }
    
    }
    cout << endl;
}