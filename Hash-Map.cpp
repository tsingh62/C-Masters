
#include<iostream>
#include<vector>
using namespace std;


int main()
{
	// int *a;
	// int n = 10;
	// a = (int *) malloc(n * sizeof(int)); // assigning memory
	// 					// n into x int

	// for(int i=0; i<n; i++)
	// {
	// 	a[i] = i;
	// 	cout << a[i] << '\n'; 
	// // 	cout << *(a+i) << '\n'; // same as above

	// //	a[i] = *(a+i);
	// }


//********** Pointer to a pointer *********//

	int **a; // a is a double pointer

	int n = 5, m = 10;
	
	a = (int **) malloc(n * sizeof(int *)); // assigning memory
						// n into x int

	for(int i=0; i<n; i++)
	{
		a[i] = (int *) malloc(m * sizeof(int ));
	//	cout << a[i] << '\n'; 

		for(int j=0; j<m; j++)
		{
			a[i][j] = i+j;
		}
	}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << '\n';
		}
	// 	cout << *(a+i) << '\n'; // same as above

	//	a[i] = *(a+i);
	

}

// g++ sample.cpp -std=c++11