#include<iostream>
using namespace std;
#define ll long long int
bool isValid(ll books[], ll n, ll k, ll ans)
{
    int students = 1;
    ll current_pages = 0;
    for(int i=0; i<n; i++)
    {
        // 10 + 20 max limit = 50
        if(current_pages + books[i]>ans)
        {
            current_pages = books[i];
            students++;
            if(students>k)
            {
                return false;
            }
        }
        else
        {
            current_pages += books[i];
        }
        
    }
    return true;
}
ll binarySearchBooks(ll books[], ll n, ll k)
{
    ll start = 0;
    ll end = n-1;
    ll total_pages = 0;
    for(int i=0; i<n; i++)
    {
        total_pages += books[i];
        start = max(start, books[i]);
    }
    end = total_pages;
    int finalAns = 0;
    while(start <= end)
    {
        ll mid = (start + end)/2;
        if(isValid(books, n, k, mid))
        {
            // true
            finalAns = mid;
            end = mid - 1;
        }
        else
        {
            // false
            start = mid + 1;

        }
        
    }
    return finalAns;
}
int main()
{
    ll n; // 4
    ll k; // 2

    cin >> n >> k;
    
    ll books[10005];

    for(int i=0; i<n; i++) // 12 34 67 98 
        cin >> books[i];

    cout << binarySearchBooks(books, n, k) << endl; // ans = 113
}