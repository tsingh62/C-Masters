#include<iostream>
using namespace std;

// 2d wave layout
void wavePrint(int arr[][5], int row, int col)
{
    // since we need to print
    // top to down and bottom to top
    // for col, we will start from 
    // col and not row --- VIP
    for(int i=0; i<col; i++)
    {   // if odd the print from top
        if(i%2==0)
        {
           for(int j=0; j<row; j++)
           {
               cout << arr[j][i] << " ";
                 
           } 
          
        }
        
        else
        {   // if even the print from bottom
            for(int j=row-1; j>=0; j--)
            {
                cout <<arr[j][i]<<" ";
                 
            }
           
        } 
     
    }
}

int main()
{   
    int arr[3][5]={{1,2,3,4,5},
                    {6,7,8,9,10},
                    {11,12,13,14,15}};
    wavePrint(arr,3,5);
    return 0;
}