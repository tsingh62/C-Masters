
#include<iostream>
using namespace std;

void spiralPrint(int arr[][4], int row, int col)
{
int start_row=0;
int start_col=0;
int end_row=row-1;
int end_col= col-1;

int noOfElementsPrinted=0;

while(noOfElementsPrinted < row*col)
{
    //left to right 
    for(int i=start_col; i<=end_col; i++)
    {
        cout << arr[start_row][i] << " ";
        noOfElementsPrinted++;
    }
    start_row++;
    
    // top to down
    for(int i=start_row; i<=end_row; i++)
    {
        cout << arr[i][end_row] << " ";
        noOfElementsPrinted++;
    }
    end_col--;

    // right to left
    for(int i=end_col; i>=start_col; i--)
    {
        cout << arr[end_row][i] << " ";
        noOfElementsPrinted++;
    }
    end_row--;

    // down to top
    for(int i=end_row; i>=start_row; i--)
    {
        cout << arr[i][start_col] << " ";
        noOfElementsPrinted++;
    }
    start_col++;

}
cout << endl;
}




int main()
{
    int arr[4][4]={{1,2,3,4},
                {5,6,7,8},
                {9,10,11,12},
                {13,14,15,16}};

    spiralPrint(arr,4,4);

    return 0;
}