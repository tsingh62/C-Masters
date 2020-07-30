
#include<iostream>
using namespace std;

int serachRotated(int arr[], int start, int end, int target)
{
	int mid = start+(end-start)/2;
	if(arr[mid]==target)
	{
		return mid;
	}

	if(arr[mid]>=arr[start])
	{
		if(target >=arr[start] && target < arr[mid])
		{
			return serachRotated(arr, start, mid-1, target);
		}
		else
		{
			return serachRotated(arr, mid+1, end, target);
		}
		
	}
	else
	{
		if(target > arr[mid] && target<=arr[end])
		{
			return serachRotated(arr, mid+1, end, target);
		}
		else
		{
			return serachRotated(arr, start, mid-1, target);
		}
		
	}
	
}
int main()
{
	int arr[]={4,5,6,7,0,1,2};
	int n = sizeof(arr)/sizeof(int);
	int target = 0;
	cout << serachRotated(arr, 0, n-1, target) << endl;
	return 0;
}