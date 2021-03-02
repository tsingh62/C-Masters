#include <iostream>
using namespace std;
 
#define endl "\n"
 
int maxsumPath(int arr1[],int arr2[], int m, int n)
{
    int i = 0;
    int j = 0;
 
    int max_sum = 0;
 
    int sum1 = 0;
    int sum2 = 0;
 
    while(i < m && j < n)
    {
        if(arr1[i] < arr2[j])
        {
           sum1 +=arr1[i];
           i++;
        }
        else if(arr1[i] > arr2[j])
        {
           sum2 +=arr2[j];
           j++;
        }
        else
        {
           max_sum = max(sum1,sum2) + max_sum;
           max_sum = max_sum + arr1[i];
           sum1 = 0;
           sum2 = 0;
           i++;
           j++;
        }
    }
 
    while(i < m)
    {
       sum1  = sum1 + arr1[i];
       i++;
    }
 
    while(j < n)
    {
       sum2 = sum2 + arr2[j];
       j++;
    }
 
    max_sum = max_sum + max(sum1,sum2);
    return max_sum;
 
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);cout.tie(NULL);
   
   while(1)
   {
       int n1,n2,i;
       cin>>n1;
       if(!n1)
          break;
          
       int a[n1];
       for(i=0;i<n1;++i)
           cin>>a[i];
           
       cin>>n2;
       
       int b[n2];
       for(i=0;i<n2;++i)
           cin>>b[i];
           
       cout<<maxsumPath(a,b,n1,n2)<<endl;       
   }
   
   
     return 0;
} 