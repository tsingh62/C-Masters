#include<iostream>
#include<queue>
using namespace std;

void printNonRepeat()
{
    queue <char> q;

    int freq[256] ={0}; // character range
                            // max so that there is not memory constraint
    
    char data;
    cin >> data;

    while(data !='.')
    {
        // push in queue and add the frequencey
        q.push(data);
        freq[data] += 1;

        while(!q.empty())
        {
            char firstOption = q.front();

            // if the 1st option is > 1 then we pop is out
            if(freq[firstOption]>1)
            {
                q.pop();
            }
            else /* if its < 1 - then print it */
            {
                   cout << firstOption << " ";
                   break;
            }
            
        }
        // if you are here 
		// eithre you break the loop or 
		// queue got empty - then print -1

        if(q.empty())
        {
            cout << " -1 ";
        }
        cin >> data;
    }

}

int main()
{
    printNonRepeat();
    cout << endl;
    return 0;
}
// g++ sample.cpp -std=c++11
// input 
// aabccbxhx.