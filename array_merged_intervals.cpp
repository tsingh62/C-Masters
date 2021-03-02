#include<iostream>
using namespace std;
#include<vector>

class Solution
{
    public:

    vector<vector<int>> merge (vector<vector<int>> & intervals)
    {
        vector<vector<int>> mergedIntervals;

        if(intervals.size()==0)
        {
            return mergedIntervals;
        }

        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];

        for(auto it : intervals)
        {
            if(it[0] <= tempInterval[1])
            {
                tempInterval[1] = max(it[1], tempInterval[1]);
            }
            else
            {
                mergedIntervals.push_back(tempInterval);
                tempInterval = it;
            }
            
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};
int main()
{
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}}; 

    Solution s;
    vector<vector<int>> ans = s.merge(intervals);
  
    for(int i=0; i<ans.size(); i++)
    {
       for(auto it = ans[i].begin(); it!=ans[i].end(); it++)
       cout << *it << " ";
    }
    cout << endl;
}

