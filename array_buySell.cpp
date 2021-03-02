#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
         int maxPro = 0;
        int minPrice = INT_MAX;
        for(int i=0; i<prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        
       return maxPro; 
    }
};
int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    Solution s;
    cout << s.maxProfit(prices) << endl;
} 