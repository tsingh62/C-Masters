
#include<iostream>
using namespace std;

//const int a=2;
//const int b=2;
void fun(int * arr, int a, int b)
{
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
        {
          //  cout << arr[i][j] << " ";
          cout << *(arr+i*b+j) << " ";
        }
    cout << endl;
    }
}
int main()
{
    int arr[2][2] = {{2,3},{1,4}};

    fun((int*)arr, 2,2);
    return 0;
}