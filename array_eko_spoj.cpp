#include <iostream>
using namespace std;


 
int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);cout.tie(NULL);
   
  
       long long int n,m;
       cin>>n>>m; // 4  // 7
       
       long long int a[n],i,l=INT_MAX,h,ans=0;
       for(i=0;i<n;++i)  // 20 15 10 17
         { cin>>a[i];
            l=min(l,a[i]);
            h=max(h,a[i]);
         }
         
       while(l<=h)
       {
           long long int mid=l+(h-l)/2;
           long long int sum=0;
           
           for(i=0;i<n;++i)
               {
                   if(a[i]>mid)
                      sum+=a[i]-mid;
               }
               
           if(sum>=m)
            {
                ans=mid;
                l=mid+1;
            }
            
            else
               h=mid-1;
           
       }
       
       cout<<ans;
          
     return 0;
} 