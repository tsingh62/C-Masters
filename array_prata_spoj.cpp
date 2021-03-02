#include <iostream>
using namespace std;
#define endl "\n"
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);cout.tie(NULL);
   
   
   long long int t;
   cin>>t;
   while(t--)
   {
       long long int p;
       cin>>p;
       
       long long int n,i;
       cin>>n;
       
       long long int a[n],l=0,h,ans=0,mx=0;
       for(i=0;i<n;++i)
           {  cin>>a[i];
              mx=max(mx,a[i]);
           }
           
        h=(p*((p+1)*mx))/2;   
       
       while(l<=h)
       {
           long long int mid=l+(h-l)/2;
           
           long long int sum=0;
           
           for(i=0;i<n;++i)
           {
               long long int sum1=0,cnt=0,x=a[i];
               while(1)
               {
                   sum1+=x;
                  if(sum1<=mid)
                     cnt++;
                  
                  else
                    break;
                    
                   x+=a[i];
        
               }
               
               sum+=cnt;
           }
           
           if(sum>=p)
            {
                ans=mid;
                h=mid-1;
            }
            
           else
             l=mid+1;
           
       }
       
       cout<<ans<<endl;
              
            
   }
     
          
     return 0;
} 

// #include <iostream>
// using namespace std;

// const int MAX = 3005;

// int T, N, M;
// int a[MAX];

// int getRoot(int N) {
//     int low = 0, high = 10000, middle, best = low;
//     while (low <= high) {
//         int middle = (low + high + 1) >> 1;
//         if (middle * (middle + 1) / 2 <= N) {
//             best = middle;
//             low = middle + 1;
//         }
//         else {
//             high = middle - 1;
//         }
//     }
//     return best;
// }

// int main() {
//     cin >> T;
//     while (T --) {
//         cin >> N >> M;
//         for (int i = 0; i < M; i ++) {
//             cin >> a[i];
//         }
//         int low = 0, high = 1 << 25, middle, best = high;
//         while (low <= high) {
//             middle = (low + high + 1) >> 1;
//             int done = 0;
//             for (int i = 0; i < M && done < N; i ++) {
//                 done += getRoot(middle / a[i]);
//             }
//             if (done >= N) {
//                 best = middle;
//                 high = middle - 1;
//             }
//             else {
//                 low = middle + 1;
//             }
//         }
//         cout << best << endl;
//     }
    
//     return 0;
// }

/*
#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long 
int n;
ULL get_num(int a,ULL sum)
{
    ULL d = (ULL)sqrt(a*a + 8*a*sum);
    d-=a;
    return d / (2*a);
}
int check(int arr[],ULL chef,ULL tim)
{
    ULL count = 0;
    for(ULL i =0 ;i<chef;i++)
    {
        count += get_num(arr[i],tim);
        if(count >= n)
            return 1;
    }
    return 0;
}
ULL binary_search(int arr[],ULL chef,ULL max)
{
    ULL low = 1,mid,high = max;
    while(low<high)
    {
        mid = (low+high)>>1;
        if(check(arr,chef,mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int chef;
        scanf("%d%d",&n,&chef);
        int arr[chef+9],ma = -1;
        for(int i = 0;i<chef ; i++){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+chef);
        ULL res = binary_search(arr,chef,(ULL)10*n*(n+1)/2);
        printf("%lld\n",res);
    }
    return 0;
}
*/