
#include<iostream>
using namespace std;

void quickSort(int arr[], int start, int end) 
{
	// BASE CASE
	if (start >= end) 
    {
		return;
	}

	int mid = (start + end) / 2;

	int left = start;
	int right = end;

	int pivot = arr[mid];

	while (left <= right) {

		while (arr[left] < pivot) {
			left++;
		}

		while (arr[right] > pivot) {
			right--;
		}

		if (left <= right) {
			swap(arr[left], arr[right]);
			left++;
			right--;
		}
	}
// when left crosses right 
	quickSort(arr, start, right); // left Subproblem
	quickSort(arr, left, end); // right Subproblem
}

int main()
{
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
	int n = 7;

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}