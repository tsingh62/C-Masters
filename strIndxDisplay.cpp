#include<iostream>
using namespace std;

int main()
{
    char arr[]={'a','b','c','d','a','b','c','\0'};
    char key = 'a';
    int len = strlen(arr);
    int count=0;
    int frq[123]={0};
    int val={0};
    int idx =0;

    for(int i=0; i<len; i++)
    {
        if(arr[i]==key)
        {
            val = arr[i];
            idx=i;
            frq[val]++;
            count++;
        }
    }
    cout <<  idx << " and " << count << endl;
    return 0;
}