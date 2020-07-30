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
// build from preorder to inorder
int preOrderIndex;
// build from preorder to inorder
TreeNode *buildTreeFromPreOrderInder(int pre[], int in[], int start, int end)
{
		// base case;
		if(start > end)
		{
			return NULL;
		}
		int data = pre[preOrderIndex];
		TreeNode *root = new TreeNode(data);
		int mid;

		for(int i=start; i<=end; i++)
		{
			if(in[i]==data)
			{
				mid=i;
				break;
			}
		}
	preOrderIndex++;
	root->left = buildTreeFromPreOrderInder(pre, in, start, mid-1);
	root->right = buildTreeFromPreOrderInder(pre, in, mid+1, end);

	return root;
}
int main()
{
	TreeNode *root = NULL;
	root = buildTree(root);
	
	// Preorder and Inorder
	int pre[]={4,2,1,3,5,8,7};
	int in[]={1,2,3,4,8,5,7};
	int n=7;

	return 0;
	
}