
#include<iostream>

#include<iostream>
using namespace std;

 // disctinct rectangles

int disctRect(int arr[], int n, int b)
{
    int left=0;
    int right=n-1;
    int count =0;

    while(left<=right)
    {
        if(arr[left]*arr[right]<b)
        {
            count = count + (right-left)*2+1;
            left++;
        }
        else
        {
            right--;
        }
    }
  return count;
  
}

int main()
{
    // disctinct rectangles

    int arr[]={2,3,4,5};
    int n=4;
    int b=15;
    cout << disctRect(arr, n, b) << endl;

    
    
}