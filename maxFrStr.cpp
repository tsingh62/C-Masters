
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