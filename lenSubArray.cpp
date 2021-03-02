

#include<iostream>
using namespace std;

int sumArray(int arr[], int n, int s)
{
	int left=0;
	int right=0;
	int sum =0;
	int minLen =INT_MAX;

	while(right < n)
	{
		sum = sum + arr[right];

		while(sum > s)
		{
			int len = right - left+1;
			if(len < minLen)
			{
				minLen = len;
			}
			sum = sum - arr[left];
			left++;
		}
		right++;
	}
	if(minLen == INT_MAX)
	{
		return 0;
	}
	return minLen;
}
int main()
{
//	int arr[] ={2,3,1,2,4,3};
	int arr [] ={1, 4, 45, 6, 0, 19};
	int n = sizeof(arr)/sizeof(int);
	int s = 51;
	cout << sumArray(arr, n, s) << endl;
	return 0;
}