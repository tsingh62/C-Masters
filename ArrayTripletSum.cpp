
#include<iostream>
using namespace std;

int main()
{
  // int arr[] = {1,4,25,6,10,8};
  int arr[] = {5,7,3,1,2,4,6};
  int sum = 10;
  int n = sizeof(arr)/sizeof(int);
  int count =0;

  // fix the 1st element as a[i]
  for(int i=0; i<n-2; i++)
  {
    //fix the second element as a[j]
    for(int j=i+1; j<n-1; j++)
    {
      //now look for the third number
      for(int k=j+1; k<n; k++)
      {
        if(arr[i]+arr[j]+arr[k]==sum)
        {
       //   cout << arr[i] << "," << arr[j] <<","<< arr[k];
         // return true;
         count++;
        }
      }
    }
  } 
  cout << count << endl;
//  cout << endl;
  return 0;
}


/*
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[1005];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int target;
    cin >> target;

    sort(a, a + n);


    for (int i = 0; i < n; i++)
    {
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            if (a[i] + a[l] + a[r] == target)
            {
                cout << a[i] << ", " << a[l] << " and " << a[r] << endl;
                l++;
                r--;
            }
            else if (a[i] + a[l] + a[r] < target)
                l++;
            else
                r--;
        }
    }

    return 0;
}

*/