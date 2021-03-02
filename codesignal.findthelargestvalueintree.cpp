#include<iostream>
using namespace std;


// 1
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        // <1> 
        // <3,2> 
        // <5,3,9>  
        vector<int> result;
        if(!root)
            return result;
        queue<TreeNode*> nodeQueue; 
        nodeQueue.push(root);
        while(!nodeQueue.empty()) {
            int size = nodeQueue.size(); 
            int maximumNumber = INT_MIN;
            while(size--) {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                if(maximumNumber < node->val)
                    maximumNumber = node->val;
                if(node->left)
                    nodeQueue.push(node->left);
                if(node->right)
                    nodeQueue.push(node->right);   
            }
            result.push_back(maximumNumber);
        }
        return result;
        
    }
};




// 2
class Solution {
public:
    vector<int> largestValues(TreeNode* root) 
	{
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        while (!q.empty()) 
		{
            int size = q.size();
            long max_level = LONG_MIN;
            for (int i = 0; i < size; i++) 
			{
                TreeNode* node = q.front(); q.pop();
                if (!node) continue;
                max_level = max(max_level, (long)node->val);
                q.push(node->left);
                q.push(node->right);
            }
            if (max_level != LONG_MIN)
                res.push_back(max_level);
        }
        return res;
    }
};