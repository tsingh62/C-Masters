
#include<iostream>
using namespace std;


int maxFr(string str)
{
    int freq[123]={0};
    for(int i=0; i<str.length(); i++)
    {
        int val = str[i];
        freq[val]++;

    }

    int maxfreq=INT_MIN;

    for(int i=0; i<123; i++)
    {
        if(freq[i]>maxfreq)
        {
            maxfreq=freq[i];
        }
    }
    return maxfreq;
}
int main()
{
    string str= "aabbbeedd";

    cout << maxFr(str) << endl;
    return 0;
}

/*
#include<iostream>
using namespace std;

void func(string str)
{
    int freq[256]= {0};
    for(int i = 0; i<str.length(); i++)
    {
        freq[str[i]]++;
    }
    int ans = 0;
    char res;
    for(int i=0; i<256; i++)
    {
        if(freq[i]>0)
        {
            if(freq[i]>ans)
            {
                ans = freq[i];
                res = char(i);
            }
        }
    }
    cout << ans << " " << res;
}
int main()
{
    string str;
    cin >> str;
    func(str); 
}
*/