#include<iostream>
using namespace std;

bool isPossible(int arr[], int n, int painters, int deadline)
{
	int countPainters = 1;
	int painterTime = 0;

	for(int i=0; i<n; i++)
	{
		painterTime += arr[i];
		if(painterTime > deadline)
		{
			countPainters++;
			painterTime = arr[i];
			
			if(countPainters > painters)
				return false;
		}
	}
	return true;
}
int painterProblem(int arr[], int n, int painters, int perUnitTime)
{
	int minTime = INT_MIN;
	int maxTime =  0;

	for(int i=0; i<n; i++)
	{
		maxTime += arr[i];
		minTime = max(arr[i], minTime);
	}
	int start = minTime;
	int end = maxTime;

	int ans = maxTime;

	while(start <= end)
	{
		int mid = start + (end-start)/2;
		if(isPossible(arr, n, painters, mid))
		{
			ans = mid;
			end = mid-1;
		}
		else
		{
			start = mid+1;
		}
		
	}
	return ans;
}
int main()
{
	int arr[] = {10,20,30,40};
	int n = 4;
	int painters = 2;

	cout << painterProblem(arr, n, painters, 1) << endl;
}