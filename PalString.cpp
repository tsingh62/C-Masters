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

bool isPal(string str) 
{
   if(str.length()-1 == 1)
    {
        return true;
    }

    int left = 0;
    int right = str.length()-1;
    char ch = str[0];
    string subproblem = str.substr(1);
    
    while(left < right)
    {
        if(str[left]!=str[right])
        {
            return false;
        }
        else
        {
            bool rec = isPal(subproblem);
            if(rec == true)
            {
                return true;
            } 
            else
            {
                return false;
            }
            
            return rec;
        }
        
    }
    return true;
    
}
int main()
{
    string str;
    cin >> str;
    cout << boolalpha << isPal(str) << endl;
    return 0;
}
*/