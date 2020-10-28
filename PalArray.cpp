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

/*
#include<iostream>
using namespace std;

bool isPal(int si, int arr[], int n)
{
    if(si ==n-1)
    {
        return true;
    }
    bool idx;
    int left = 0;
    int right = n-1;
    while(left < right)
    {
        if(arr[left]!=arr[right])
        {
            return false;
        }
        else
        {

            idx = isPal(si+1, arr, n);
            if(idx == true)
            {
                return true;
            }
            else
            {
                return false;
            }
           return idx; 
        }
        
    }
    return idx;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << boolalpha << isPal(0, arr, n) << endl;
    return 0;
}
*/