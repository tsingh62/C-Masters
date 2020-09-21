#include<iostream>
using namespace std;

int main()
{
  int arr[] = {-1,2,5,-11,6};
//    int arr[]={-1,2,3-11,6};
   int n = 5;
   
    
    int maxSum = arr[0];
    int currSum = arr[0];

    for(int i=1; i<n ; i++)
    {
        int continuewithSubArray = currSum + arr[i];
        int startNewSubArray = arr[i];


        currSum = max(startNewSubArray,continuewithSubArray);

        if(currSum>maxSum)
        {
            maxSum = currSum;

        }
    }
cout << "Max Sum is " << maxSum << endl;
return 0;
}