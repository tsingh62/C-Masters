#include<iostream>
using namespace std;

int editDist(string str1, string str2, int m , int n)
{
    int dp[m+1][n+1];

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0)
            dp[i][j] = j;

            else if(j==0)
            dp[i][j] = i;

        // if last characters are same, ignore last char
        // and recur for remanining string
            else if(str1[i-1]==str2[j-1])
            dp[i][j] = dp[i-1][j-1];

            // if the last char is diff, consider all possible options
            else
            // dp[i][j] = 1 + min(dp[i][j-1], // insert
            //                 dp[i-1][j], // remove
            //                 dp[i-1][j-1]); // replace
            dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    return dp[m][n];
}
int main()
{
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDist(str1, str2, str1.length(), str2.length());
} 