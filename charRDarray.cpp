#include<iostream>
using namespace std;


void readline(char a[1000], int maxLen, char delim ='\n')
{
    int i=0; 
    char ch = cin.get();

    while(ch!=delim)
    {
        a[i]=ch;
        i++;
        if(i==(maxLen-1))
        {
            break;
        }
        ch=cin.get();
    }
    a[i]='\0';
}
int main()
{
    char  a[1000];
    readline(a,1000, '$');
    cout << a << endl;

    return 0;
    
}