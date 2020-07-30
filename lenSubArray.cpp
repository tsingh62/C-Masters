

#include<iostream>
using namespace std;

int sumArray(int arr, int n, int s)
{
	int left=0;
	int right=0;
	int sum =0;
	int minLen =0;

	while(right < n)
	{
		sum += arr[right];

		if(sum >= s)
		{
			int len = right - left+1;
			if(len < minLen)
			{
				minLen = len;
			}
			sum -= arr[left];
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
	int arr[] ={2,3,1,2,4,3};
	int n = sizeof(arr)/sizeof(int);
	int s = 7;
	cout << sumArray(arr, n, s) << endl;
	return 0;
}