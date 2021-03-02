#include<iostream>
using namespace std;

// void swap(int *ab, int *cd)
// {
//     int temp = *ab;
//     *ab = *cd;
//     *cd = temp;
// } 

void arrCount(int arr[], int n)
{
    int counter=1;
    int temp=-1;
    int count=0;
    while(counter < n)
    {  
        for(int i=0; i<n-counter; i++)
        {
            if(arr[i]>arr[i+1])
            {
               
                swap(arr[i], arr[i+1]);
                count++;
            }   
            
        }
        counter++;
    }
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
	cout << endl;
   cout << count << endl;
}

int main()
{
   // int arr[] = {2,13,14,25,6};
	 int arr[] = {4,3,1,2,9,8,6,5,7};
    int n = sizeof(arr)/sizeof(int);
    arrCount(arr, n);
}

/*

int merge(int arr[], int start, int end) {

    int invCount = 0;

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
            invCount = invCount + (mid - i);
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

    return invCount;
	//DONE
}

int mergeSort(int arr[], int start, int end) {
	// BASE CASE
    int invCount = 0;
	if (start == end) {
		return 0;
	}

	int mid = (start + end) / 2;

	invCount += mergeSort(arr, start, mid); // left Half
	invCount += mergeSort(arr, mid + 1, end); // right Half

	invCount += merge(arr, start, end);

    return invCount;
}


	int main()
	{
		int arr[]={5,3,12,8,19,16,2,4};
		
		int n = sizeof(arr)/sizeof(int);
		int ans = mergeSort(arr, 0, n-1);
        cout << "The no of inversions are  : " << ans << endl;
		// for(int i=0; i<n; i++)
		// {
		// 	cout << arr[i] << " ";
		// }
		// cout << endl;
		return 0;
	}

*/