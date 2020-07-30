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
