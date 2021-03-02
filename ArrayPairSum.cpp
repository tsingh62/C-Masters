#include<iostream>
using namespace std;


int main()
{
int arr[] = {5,2,3,4,5,6};
int n = sizeof(arr)/sizeof(int);
int count =0;

int sum = 7;

for(int i=0; i<n; i++)
{
    for(int j= i+1; j<n; j++)
    {
        if(arr[i]+arr[j]==sum)
        {
            count ++;
        }
    
    }
}
cout << " No of Pairs :" << count <<  endl;
cout << endl;

return 0;

}


/*

void func(int arr[], int n, int k)
{
    int ans=0;
    sort(arr, arr+n);
    int left = 0;
    int right = n-1;
    while(left <= right)
    {
        if(arr[left]+arr[right]>k){
             right--;
            
        }
        else 
        {
            ans +=(right - left);
            left++; right--;
        }
    }
    cout << ans << endl;
}
int main()
{
    int arr[] = {1, 5, 7, 1};
    int n = 4;
    int k = 6;
    func(arr, n, k);
}
*/