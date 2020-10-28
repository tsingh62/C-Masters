#include<iostream>
using namespace std;
#include<vector>
int main()
{
    int n1;
    cin >> n1;
   
   int arr1[n1];

    for(int i=0; i<n1; i++)
    {
        cin >> arr1[i];
    }

    int n2;
    cin >> n2;
   
    int arr2[n2];

    for(int i=0; i<n2; i++)
    {
        cin >> arr2[i];
    }
    int m;
    if(n1 > n2)
    {
        m = n1;
    }
    else
    {
        m = n2;
    }
    
   int diff[m];

    int carry = 0;
    int i = n1-1;
    int j = n2-1;
    int k = m-1;

    while(k>=0)
    {
        int d = 0;
        // if i becomes -1 the arr[i] will becomes 0
        // else i >=0 will have the value of i in arr[i]
        int arr1val = i >= 0? arr1[i] : 0; 
        // taking a2 here as the bigger array
        if(arr2[j] + carry >= arr1val) // arr1val instead of arr[i]
        {
            d = arr2[j] + carry - arr1val;
            carry = 0;
        }
        else
        {
           d = arr2[j] + carry + 10 - arr1val;
           carry = -1;
        }
        diff[k] = d;
        i--;
        j--;
        k--;
    }
    int idx = 0;
    while(idx < diff[m])
    {
        if(diff[idx]== 0)
        {
            idx++;
        }
        else
        {
            break;
        }
        
    }

    while(idx < diff[m])
    {
       cout << diff[idx] << endl;
       idx++;
    }

    return 0;
}

// int main(int argc, char const *argv[]) {

// int a[50], b[50], c[50], i, j, k, n, m;
// cout << "n= "; cin >> n;

// //Read arrays
// for (i = 0; i < n; i++) {
//     cout << "a[" << i << "]: "; cin >> a[i];
// }
// cout << "\nm= "; cin >> m;
// for (j = 0; j < m; j++) {
//     cout << "b[" << j << "]: "; cin >> b[j];
// }

// //Show the arrays
// cout << endl;
// cout << "\na[ ";
// for (i = 0; i < n; i++) {
//     cout << a[i] << " ";
// }
// cout << "]";

// cout << endl;
// cout << "\nb[ ";
// for (j = 0; j < m; j++) {
//     cout << b[j] << " ";
// }
// cout << "]";

// //Calculate the difference
// k = 0; i = 0;
// //int k=0;
// for(int i=0;i<n;i++)
// {
//    int f=0;
//    for(int j=0;j<m;j++)
//    {
//       if(a[i]==b[j])
//           f=1;
//       if(!f)
//           c[k++]=a[i];
//    }
// }
// //Show the difference array
// cout << endl;
// cout << "\nc[ ";
// for (i = 0; i < k; i++) {
//     cout << c[i] << " ";
// }
// cout << "]";

// return 0;
// }


