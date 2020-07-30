
#include<iostream>
using namespace std;

int countPath(int sr, int sc, int er, int ec)
{
    if(sr == er && sc == ec)
    {
        return 1;
    }
    if(sr > er || sc > ec)
    {
        return 0;
    }
    int right = countPath( sr, sc+1, er, ec);
    int down = countPath(sr+1, sc, er, ec);
    int result = right + down;
    return result;
}
int  main()
{
    cout << countPath(0,0,2,2) << endl;
    return 0;

}