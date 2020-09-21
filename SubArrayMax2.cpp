
#include<iostream>
using namespace std;

// With reduced complexity 
// one forloop less 
// see SubArrayMAX.cpp
// for reference
int main()
{
    int arr[]={1,2,4,5,7};
    int n=5;
    int maxsum=0;
   
    // 1st row of pair
    for(int i=0; i<n; i++)
    {
         int sum = 0;
        // pair values to ith row
        for(int j=i; j<n; j++)
        {   // adding the pairs
                sum  +=arr[j];
            }
          //  cout << "Sum is " << sum << endl;
             if(sum>maxsum)
                {
                    maxsum=sum;
                }
        }
    cout << "Max sum is " << maxsum << endl;
    return 0;
}