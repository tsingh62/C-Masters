#include<iostream>
using namespace std;


// Palindrome string

bool isPal(char a[])
{
    int i=0;
    int j=strlen(a)-1;

    while(i<j)
    {
        if(a[i]==a[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}


int main ()
{

    char a[1000];
    cin.getline(a,1000);

    if(isPal(a))
    {
        cout << "Pal" << endl;
    }
    else
    {
        cout << "Not a Pal " << endl;
    }
    
}


/*
#include<iostream>
using namespace std;

bool func(string str)
{
    int n = str.length();
    if(str.length()-1 == 1 )
    {
        return true;
    }

    bool ch = str[0];
    string subproblem = str.substr(1);
    bool rec = func(subproblem);

    int left = 0;
    int right = n-1;
    while(left < right)
    {
        if(str[left] != str[right])
        {
            return false;
        }
        else
        {
        if((ch + rec)==true)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        }
    }
    return true;
}
int main()
{
    string str;
    cin >> str;
    cout << boolalpha << func(str) << endl;
}
*/