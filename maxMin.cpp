
#include<iostream>
using namespace std;

int main()
{
    int arr[6]={2,12,1,3,5,6};
    int n=6;
    int min=arr[0];

    for(int i=0; i<=n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    cout << min << endl;
}