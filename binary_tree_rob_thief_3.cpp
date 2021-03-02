/*
 	 The thief has found himself a new place for his
	 thievery again. There is only one entrance to
	 this area, called the 'root'. Besides the root,
	 each house has one and only one parent house.
	 After a tour, the smart thief relalized that
	 'all houses in the place form a binary tree'.
	 It will automatically contact the poloce if two 
	 directly-linked houses were broken into on 
	 the same night.

	 Determine the max amount of money the thief can 
	 rob tonight without alerting the police. 

	 Definition for a nibary tree node - 
	 struct TreeNode
	 {
		 int val;
		 TreeNode *left;
		 TreeNode *right;
		 TreeNode() : val(0), left(nullptr), right(nullptr) {}
		 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}		 
	 };
*/
#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
class Solution
{
	public:
	unordered_map<TreeNode*, int> mp;
	int rob(TreeNode* root)
	{
		if(root == NULL)
			return 0;
		if(mp.count(root))
			return mp[root];
		int total = 0;
		if(root->left)
			total += rob(root->left->left) + rob(root->left->right);
		if(root->right)
			total+=rob(root->right->left) + rob(right->right->right);
		return mp[root] = max(root->val+total, rob(root->left)+rob(root0>right));
	}
};

int main()
{

 	// input =3,2,2,null,3,null,1 // output 7
	Solution s;
	cout << s.rob(nums) << endl;
}