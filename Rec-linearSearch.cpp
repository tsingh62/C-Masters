
#include<iostream>
using namespace std;


int linearSearch(int si, int arr[], int n, int key) {
	// BASE CASE
	if (si == n) {
		return -1;
	}

	// RECURSIVE CASE
	if (arr[si] == key) {
		return si;
	} else {
		int index = linearSearch(si + 1, arr, n, key); // LS on rest of the array
		return index;
	}
}

int main()
{
    int arr[] = {3, 2, 4, 1, 5, 61, 7};
	int n = 7;
	int key = 61;
	int si = 0;

	cout << linearSearch(si, arr, n, key) << endl;

    return 0;
}