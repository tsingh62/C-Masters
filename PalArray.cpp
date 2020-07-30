


#include<iostream>
using namespace std;

int main()
{
    int arr[]={1,2,0,2,1};
    int n=5;
    int left = 0;
    int right = n-1;
    bool pal = false;

    
    while(left<right)
    {
        if(arr[left]!=arr[right])
        {
            cout << "Not a Palindrome" << endl;
            pal = false;
            break;
        }
        else
        {
            pal = true;
            left++;
            right--;

        }  
    }
    if(pal==true)
    {
        cout << "Palindrome" << endl;
    }
     
    return 0;
}