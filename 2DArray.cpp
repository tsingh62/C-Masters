#include<iostream>
using namespace std;

//const int r = 3;
const int c = 3;

void funArray(int arr[][c], int r)
{
    
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
}

int main()
{
    int arr[3][3]= {{1,3,4},
                    {2,3,5},
                    {3,4,6}};
    funArray(arr,3);
    
    return 0;
}