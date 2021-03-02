#include<iostream>
using namespace std;
#include<list>
int main()
{
    int arr[]={1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    list <int> l;

    for(int i=0; i<n; i++)
    {
        if(i < n-1)
        {
            l.push_back(arr[i]);
        }
        else
        {
            l.push_front(arr[i]);
        }
        
       
    }

    for(int val : l)
    {
        cout << val << " ";
    }

}

/************************/

/*
void func(int arr[], int n)
{
    cout << arr[n-1] << " ";

    for(int i=0; i<n-1; i++)
    {
        cout << arr[i] << " ";
       
    }
}
int main()
{
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    func(arr, n);
}
*/