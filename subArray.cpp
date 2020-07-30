
#include<iostream>
using namespace std;


int main()
{
    int arr[]={1,2,4,5,7};
    int n=5;

    // 1st row of pair
    for(int i=0; i<n; i++)
    {
        // pair values to ith row
        for(int j=i; j<n; j++)
        {
            // printing the pair values
            for(int k=i; k<=j; k++)
            {
                cout << arr[k] << " "; 
            }
        cout << endl;
        }
        
    }
    return 0;
}