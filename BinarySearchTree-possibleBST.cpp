#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<queue>


// g++ sample.cpp -std=c++11
using namespace std;

class TreeNode
{
	public:

	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int data)
	{
		this->val = data;
		this->left = NULL;
		this->right = NULL;
	}
};
// tree starts from root
	// first insertion will start from the root

// left and the right
// once the left recursive call is complete
// only then we call the right values

// you can access child from parent 
// but not parent from child in trees

TreeNode * buildTree(TreeNode *root)
{
	int data;
	cin >> data;

	if(data == -1)
	{
		return NULL;
	}
	//if the data is not -1
	if(root ==NULL)
	{
		root = new TreeNode(data);
	}
	root->left = buildTree(root->left); // will return the address of the left child note
	root->right = buildTree(root->right); // will return the address of the right child note

	return root;
}

TreeNode *builtBST(TreeNode *root, int data)
{
	if(root == NULL)
	{
		root = new TreeNode(data);
		return root;
	}
	if(data > root->val)
	{
		root->right = builtBST(root->right, data);
	}
	else
	{
		root->left = builtBST(root->left, data);
	}
	return root;	
}

class Solution
{
	public:

	int numTrees(int n)
	{
		// base case
		if(n==0 || n==1)
		{
			return 1;
		}
		int ans =0;

		for(int i=1; 0<=n; i++)
		{
			int leftBSTCount = numTrees(i-1);
			int rightBSTCount = numTrees(n-i);

			int myCount = leftBSTCount * rightBSTCount;
			ans+=myCount;
		}
		return ans;
	}

};

int main()
{
	TreeNode *root = NULL;
	root = buildTree(root);
	return 0;
	
}