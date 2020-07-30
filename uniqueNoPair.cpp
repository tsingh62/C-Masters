
#include<iostream>
using namespace std;

void findPair(int arr[], int n)
{
    int xorPair=0;
    for(int i=0; i<n; i++)
    {
        xorPair = xorPair ^ arr[i];
    }

    int element=xorPair;
    int pos=0;

    while(element>0)
    {
        int temp = element&1;
        if(temp)
        {
            break;
        }
        pos++;
        element = element >>1;
    }
    int categoryWithOne =0;
    for(int i=0; i<n; i++)
    {
        int val =arr[i];
        int check = val >>pos;
        if(check&1)
        {
            categoryWithOne = categoryWithOne ^ arr[i];
        }
    }
    cout << categoryWithOne << endl;
    int categoryWithZero = categoryWithOne ^ xorPair;
    cout << categoryWithZero << endl; 
}
int main()
{
    int arr[] = {1,2,3,4,5,9,1,2,3,4};
    int n = sizeof(arr)/sizeof(int);
    findPair(arr,n);

    return 0;

}