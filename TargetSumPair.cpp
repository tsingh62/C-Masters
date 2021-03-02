
#include<iostream>
using namespace std;


int TargetSumPair(int arr[], int n, int target)
{
   int count=0;
   int left=0;
   int right=n-1;
    // sum of array pair
   // two pointer
   while(left<right)
   {
       if(arr[left]+arr[right]>target)
       {
           right--;
       }
       else if(arr[left]+arr[right]<target)
       {
           left++;
       }
       else
       {
           count++;
           left++;
           right--;
       }
   }
  
   return count;
}



int main()
{
   int arr[]={10,12,3,4,5,6};
   int n=6;
   int target=15;
    
   cout << TargetSumPair(arr, n, target) << endl;
   return 0;
   
} 