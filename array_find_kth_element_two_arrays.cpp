// Program to find kth element from two sorted arrays
#include <iostream>
using namespace std;

// int kth(int arr1[], int arr2[], int m, int n, int k)
// {
// 	int sorted1[m + n];
// 	int i = 0, j = 0, d = 0;
// 	while (i < m && j < n)
// 	{
// 		if (arr1[i] < arr2[j])
// 		// look in the right side of a[i]
// 		// and left side of b[j]
// 			sorted1[d++] = arr1[i++];
// 		else
// 		// when a[i] > b[j] - we look in thr left side
// 		// of a[i] and right side of b[j].
// 			sorted1[d++] = arr2[j++];
// 	}
// 	while (i < m)
// 		sorted1[d++] = arr1[i++];
// 	while (j < n)
// 		sorted1[d++] = arr2[j++];
// 	return sorted1[k - 1];
// }

// // Driver Code
// int main()
// {
// 	int arr1[5] = {2, 3, 6, 7, 9};
// 	int arr2[4] = {1, 4, 8, 10};
// 	int k = 5;  // when you combine the two arrays what 
// 	// will be the 5th smallest element in the array
// 	cout << kth(arr1, arr2, 5, 4, k) << endl;
// 	return 0;
// } 


// better approach

// Program to find k-th element from two sorted arrays
#include <iostream>
using namespace std;

int kth(int *arr1, int *arr2, int *end1, int *end2, int k)
{
	if (arr1 == end1)
		return arr2[k];
	if (arr2 == end2)
		return arr1[k];
	int mid1 = (end1 - arr1) / 2;
	int mid2 = (end2 - arr2) / 2;
	if (mid1 + mid2 < k)
	{
		if (arr1[mid1] > arr2[mid2])
			return kth(arr1, arr2 + mid2 + 1, end1, end2,
				k - mid2 - 1);
		else
			return kth(arr1 + mid1 + 1, arr2, end1, end2,
				k - mid1 - 1);
	}
	else
	{
		if (arr1[mid1] > arr2[mid2])
			return kth(arr1, arr2, arr1 + mid1, end2, k);
		else
			return kth(arr1, arr2, end1, arr2 + mid2, k);
	}
}

int main()
{
	int arr1[5] = {2, 3, 6, 7, 9};
	int arr2[4] = {1, 4, 8, 10};

	int k = 8;
	cout << kth(arr1, arr2, arr1 + 5, arr2 + 4, k - 1);
	return 0;
} 

