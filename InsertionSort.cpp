

#include<iostream>
using namespace std;

int main()
{
    int arr[]={3,2,1,4,5};
    int n=5;
    int divider = 1;

    while(divider < n)
    {
    for(int i=divider; i>0; i--)
    {
        if(arr[i]<arr[i-1])
        {
            swap(arr[i], arr[i-1]);
        }
        else
        {
            break;
        }
        
    }
    divider++;
    }
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;

}