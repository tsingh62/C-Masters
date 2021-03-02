// C++ program to sort an array according to
// count of set bits using std::sort()
#include <iostream>
using namespace std;

// a utility function that returns total set bits
// count in an integer
int countBits(int a)
{
	int count = 0;
	while (a)
	{
		if (a & 1 )
			count+= 1;
		a = a>>1;
	}
	return count;
}

// custom comparator of std::sort
int cmp(int a,int b)
{
	int count1 = countBits(a);
	int count2 = countBits(b);

	// this takes care of the stability of
	// sorting algorithm too
	if (count1 <= count2)
		return false;
	return true;
}

// Function to sort according to bit count using
// std::sort
void sortBySetBitCount(int arr[], int n)
{
	stable_sort(arr, arr+n, cmp);

	/*
	https://stackoverflow.com/questions/1517793/what-is-stability-in-sorting-algorithms-and-why-is-it-important#:~:text=A%20sorting%20algorithm%20is%20said,Sort%2C%20Bubble%20Sort%2C%20etc.
	
	A sorting algorithm is said to be stable 
	if two objects with equal keys appear in 
	the same order in sorted output as they 
	appear in the input array to be sorted. 
	Some sorting algorithms are stable by nature 
	like Insertion sort, Merge Sort, 
	Bubble Sort, etc. And some sorting algorithms are not, 
	like Heap Sort, Quick Sort, etc.

	Background: a "stable" sorting algorithm keeps 
	the items with the same sorting key in order. 
	Suppose we have a list of 5-letter words:
	*/
}

// Utility function to print an array
void printArr(int arr[], int n)
{
	for (int i=0; i<n; i++)
		cout << arr[i] << " ";
}

// Driver Code
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(arr)/sizeof(arr[0]);
	sortBySetBitCount(arr, n);
	printArr(arr, n);
	return 0;
}
