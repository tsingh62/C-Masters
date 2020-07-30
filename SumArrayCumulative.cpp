
#include<iostream>
using namespace std;

int main()
{
    int arr[]={-4,1,3,-2,6,2,-1,-4,-7};
    int n=9;
    int maxSum =0;
    // for printing the sub arrays
    int left = -1;
    int right = -1;

     // Generating sub array 
    // iterating value for i
    for(int i=0; i<n; i++)
    {
        // iteraing value of j as the pair for i
        for(int j=i; j<n;j++)
        {
            int currentSum=0; // everytime we print the value sum is set to 0 
            // printing the value of i and j as pair
            for(int k=i; k<=j; k++)
            {
                currentSum +=arr[k];
            }
            if(currentSum > maxSum)
            {
                maxSum = currentSum;
                left=i;
                right=j;
            }
        }
    }
    cout << maxSum << endl;
    // printing sub arrays
    for(int k=left; k<=right; k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;

}