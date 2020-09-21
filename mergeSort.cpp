
#include<iostream>
using namespace std;

void merge(int arr[], int start, int end) {

	int mid = (start + end) / 2;

	int i = start; // iterate left Half
	int j = mid + 1; // iterate right Half


	int temp[end - start + 1];
	int k = 0; // iterate temp array

	while (i <= mid and j <= end) {

		if (arr[i] < arr[j]) {
			temp[k] = arr[i];
			i++;
			k++;

		} else {
			temp[k] = arr[j];
			j++;
			k++;
		}
	}

	while (j <= end) {
		temp[k] = arr[j];
		j++;
		k++;
	}

	while (i <= mid) {
		temp[k] = arr[i];
		i++;
		k++;
	}

	// temp is sorted but arr is not sorted

	int pos = 0;
	for (int x = start; x <= end; x++) {
		arr[x] = temp[pos];
		pos++;
	}

	//DONE
}

void mergeSort(int arr[], int start, int end) {
	// BASE CASE
	if (start == end) {
		return;
	}

	int mid = (start + end) / 2;

	mergeSort(arr, start, mid); // left Half
	mergeSort(arr, mid + 1, end); // right Half

	merge(arr, start, end);
}


	int main()
	{
		int arr[]={5,3,12,8,19,16,2,4};
		
		int n = sizeof(arr)/sizeof(int);
		mergeSort(arr, 0, n-1);

		for(int i=0; i<n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		return 0;
	}
