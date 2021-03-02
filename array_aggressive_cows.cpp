/*
Farmer John has built a new long barn, 
with N (2 <= N <= 100,000) stalls. 
The stalls are located along a straight 
line at positions x1,...,xN 
(0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn 
layout and become aggressive towards 
each other once put into a stall. 
To prevent the cows from hurting each other, 
FJ wants to assign the cows to the stalls, 
such that the minimum distance between any 
two of them is as large as possible. 
What is the largest minimum distance?
*/ 
  #include<iostream>
  using namespace std;

bool isValid(int arr[], int n, int cows, int distanceLimit)
{
    int previousCowPosition = arr[0];
    int cowsPlacedUptillThisPoint = 1;
    for(int i=1; i<n; i++)
    {
        int currentCowPosition = arr[i];
        int gapBetweenCows = currentCowPosition - previousCowPosition;
        if(gapBetweenCows >= distanceLimit)
        {
            cowsPlacedUptillThisPoint++;
            previousCowPosition = arr[i];

            if(cowsPlacedUptillThisPoint == cows)
            {
                return true;
            }
        }
    }
    return false;
}
 int aggressiveCows(int arr[], int n, int cows)
 {
     sort(arr, arr+n);
     int minDist = 1;
     int maxDist = arr[n-1]-arr[0];
     int start = minDist;
     int end = maxDist;
     int ans = 0;

     while(start <= end)
     {
         int mid = start + (end - start)/2;

         if(isValid(arr, n, cows, mid))
         {
             ans = mid;
             start = mid+1; // to maximize your reange
         }
         else
         {
             end = mid - 1;
         }
         
     }
     return ans;
 }
  int main()
  {
      int barns[] = {2,1,4,9,8};
      int n = 5;
      int cows = 3;
      cout << aggressiveCows(barns, n, cows) << endl;
  }