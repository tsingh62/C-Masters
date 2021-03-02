#include<iostream>
using namespace std;

// int max(int a, int b); 
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(char* X, char* Y, int m, int n) 
{ 
    int L[m + 1][n + 1]; 
    int i, j; 
  
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note  
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (i = 0; i <= m; i++) 
    { 
        for (j = 0; j <= n; j++) 
        { 
            if (i == 0 || j == 0) 
                L[i][j] = 0; 
  
            else if (X[i - 1] == Y[j - 1]) 
                L[i][j] = L[i - 1][j - 1] + 1;  // when last characters matches
  
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); // when last characters do not match
        } 
    } 
  
    /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
    return L[m][n]; 
} 
  
/* Utility function to get max of 2 integers */
int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
} 
  
/* Driver program to test above function */
int main() 
{ 
    char X[] = "AGGTAB"; 
    char Y[] = "GXTXAYB"; 
  
    int m = strlen(X); 
    int n = strlen(Y); 
  
   // printf("Length of LCS is %d\n", lcs(X, Y, m, n)); 
   cout << lcs(X,Y, m, n) << endl;
  
    return 0; 
} 

/*
// longest common subseq between two strings

#include<iostream>
using namespace std;

int lcs(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();

    int dp[n+1][m+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<m; j++)
        {
            dp[i][j] = 0;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            
        }
    }
    return dp[n][m];
}
int main()
{
    string str1 = "aggatab";
    string str2 = "gxtxayb";
    cout << lcs(str1, str2) << endl;
}
*/