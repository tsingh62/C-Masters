
#include<iostream>
using namespace std;

void findPair(int arr[], int n)
{
    int xorPair=0;
    for(int i=0; i<n; i++)
    {
        xorPair = xorPair ^ arr[i];
    }

    int element=xorPair;
    int pos=0;

    while(element>0)
    {
        int temp = element&1;
        if(temp)
        {
            break;
        }
        pos++;
        element = element >>1;
    }
    int categoryWithOne =0;
    for(int i=0; i<n; i++)
    {
        int val =arr[i];
        int check = val >>pos;
        if(check&1)
        {
            categoryWithOne = categoryWithOne ^ arr[i];
        }
    }
    cout << categoryWithOne << endl;
    int categoryWithZero = categoryWithOne ^ xorPair;
    cout << categoryWithZero << endl; 
}
int main()
{
    int arr[] = {1,2,3,4,5,9,1,2,3,4};
    int n = sizeof(arr)/sizeof(int);
    findPair(arr,n);

    return 0;

}


/**************** 2 example ****************/

#include<iostream>
int main() {

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }

    int mask=0;
    for (int i = 0; i < n; i++) 
    {
        mask^=a[i];
    }
    int result=mask;
    int count=0;
    if(!(mask&1))
    {
        count++;
        mask>>=1;
    }
    mask = 1;
    while(count--)
    {
        mask<<=1;
    }

    int num1 =0;
    int num2 = 0;
    for (int i = 0; i < n; i++) {
        if((a[i]&mask)!=0){
            num1^=a[i];
        }
    }
    num2=result^num1;

    if(num1<num2){
        cout << num1<<" "<<num2 <<endl;
    }else{
        cout << num2<<" "<<num1 <<endl; 
    }

    return 0;
}
