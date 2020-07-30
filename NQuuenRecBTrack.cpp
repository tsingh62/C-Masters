#include<iostream>
using namespace std;

// is it safe to put the Queen
// in the epecific row or col
bool isSafe(int board[4][4], int n, int row, int col)
{
    // col
    // keep the col constant and traverse all the loops
    for(int i=row; i>=0; i--)
    {
        // if at any moment 
        // the board at i th row and col is containting 
        if(board[i][col]==1)
        {
            return false;
        }
    }
    // left Diagonal
    int x =row;
    int y=col;
    // even moment we are going row -1
    // and col -1
    // test all possible values till your value
    // exceeds the col and row
    while(x >=0 && y >=0)
    {
        //check if board of x,y 
        // exceeds 1 return false
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }
    // right diagonal

    x=row;
    y=col;
    // increaing my col value
    // decreasing my row value
    while(x>=0 && y<n)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y++;
    }

    return true;

}

bool Nqueens(int board[4][4],int row,int n)
{
    // Base case
    // recursion has moved to the end
    // means we have traversed all possible rows
    // and we have come to the end just return true
    // if(row==n)
    // {
    //     return true;
    // }
    //==============================//
    // Print the orientation 
    if(row==n)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j])
                {
                    cout << " Q";
                }
                else
                {
                    cout << " -";
                }
                
            }
            cout << endl;
        }
        cout << "*******************************" << endl;
        return false;
    }
    for( int col=0; col<n; col++)
    {
        // whether it is safe to put
        // the queen in the specific row or col
        if(isSafe(board, row, col, n))
        {
            // putting a queen on a specific
            // row and col and giving it value one;
            board[row][col]=1; // my work 

            // check the orinetation 
            // for the rest of the queens 
            bool rest_of_the_queens = Nqueens(board, row + 1, n); // rec

            // if(rest_of_the_queens)
            // {   // if orientation is correct return true
            //     return true;
            // }

            // when the sub-problem is false
            // before going to the next col 
            // remove the current Queen -- this is BACK-TRACKING
            // replace with zero
            board[row][col]=0;
        }
        
    }
    // after traversing the we can say the
    // orientation was not possible 
    // the queens could not be placed in the 
    // correct position so return false
    return false;
}
int main()
{
    int board[4][4]={0};
    int n=4;
    cout << Nqueens(board, 0,n) << endl;
    return 0;

}