#include<iostream>
using namespace std;
// search in 2d sorted array
void search(int arr[][4], int row, int col, int key)
{
    int start_r=0;
    int start_c=col-1;

    // searhing all the rows of elemnet
    // if element is not present
    // condition to check all the rows
        // and cols
    while(start_r<row && start_c>=0)
    {   
        if (arr[start_r][start_c]==key)
        {
            cout << "Element found " << start_r << ", " << start_c << " " << endl;
            return;
        }
        // if key is > r and c
        else if (key>arr[start_r][start_c])
        {
            start_r++;
        }
        else
        {
            start_c--;
        }
    }
    cout << "Element not found : " << endl;
}




int main()
{
    int arr[4][4]={{1,2,3,4},
                {5,6,7,8},
                {9,10,11,12},
                {13,14,15,16}};

    int key =14;

    search(arr,4,4,key);

    return 0;
}