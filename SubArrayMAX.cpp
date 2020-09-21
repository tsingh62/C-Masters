
#include<iostream>
using namespace std;


int main()
{
    int arr[]={1,2,-4,5,7};
    int n=5;
    int maxsum=0;
   
    // 1st row of pair
    for(int i=0; i<n; i++)
    {
        // pair values to ith row
        for(int j=i; j<n; j++)
        {
            // for every j values
            // sum =0
            int sum = 0;
            // printing the pair values
            for(int k=i; k<=j; k++)
            {
               cout << arr[k] << " ";
                // adding the pairs
                sum  +=arr[k];
            // cout << arr[k] << " ";
            }

          //  cout << "Sum is " << sum << endl;
             if(sum>maxsum)
                {
                    maxsum=sum;
                }
       // cout << "Max sum is " << maxsum << endl;
       cout << endl;
        }
        
    }
    cout << "Max sum is " << maxsum << endl;
    return 0;
}