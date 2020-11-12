#include<iostream>
using namespace std;

void rev(int arr[], int si, int n)
{
    if(si == n)
    {
        return;
    }
    rev(arr, si+1, n);

    cout << arr[si] << " ";


}
int main()
{
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(int);
    rev(arr, 0, n);
}