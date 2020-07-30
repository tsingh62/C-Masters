// Rotation of 2d array matrix

#include<iostream>
using namespace std;


void func(int arr[][3], int temp[][3],int row, int col)
{
    // transpose 
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            temp [j][i] = arr[i][j];
        }
    }

    // swapping values 
    for(int r=0; r<row; r++)
    {
        int i=0;
        int j=col-1;
        while(i<j)
        {
            // swap the temp array
            swap(temp[r][i], temp[r][j]);
            i++;
            j--;
        }
    }
}
 
int main()
{
    int arr[3][3] = {{1,2,3},
                        {4,5,6},
                        {7,8,9}};
    int temp[3][3];   
    
    func(arr, temp,3,3);

    // printing values;
    for(int i=0; i<3; i++)
    {
        for(int  j=0; j<3; j++)
        {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }

     return 0;
}