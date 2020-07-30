#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

//g++ sample.cpp -std=c++11

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

TreeNode *insert(TreeNode *root) {

	int data;
	cin >> data;

	while (data != -1) {
		root = builtBST(root, data);
		cin >> data;
	}

	return root;
}

void inOrder(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	// L - N(root) - R
	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}
void preOrder(TreeNode *root)
{
	if(root==NULL)
	{
		return;
	}
	// N - (root) - L - R
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);

}
// **************** BST Search ********************//
// Time: O(n)
// Space: O(n)
bool searchBST(TreeNode *root, int key)
{
	if(root==NULL)
	{
		return false;
	}
	if(root->val == key)
	{
		return true;
	}
	// bool leftserach = searchBST(root->left, key);
	// bool rightserach = searchBST(root->right, key);

	// if(leftserach || rightserach)
	// {
	// 	return true;
	// }
	// return false;
	if(key > root->val)
	{
		return searchBST(root->right, key);
	}
	else
	{
		return searchBST(root->left, key);
	}
	
}
// ************ If a tree is a BST or not ******//
bool isBST(TreeNode *root, int minRange = INT_MAX, int maxRange= INT_MIN)
{
	// Base case
	if(root == NULL)
	{
		return true;
		// beacause a null tree is always as bst
	}

	// update the min and max range with my value (root->val)
	bool leftBST = isBST(root->left,minRange,root->val);
	bool rightBST = isBST(root->left, root->val,maxRange);

	if(leftBST && rightBST && root->val
		> minRange and root->val < maxRange)
		{
			return true;
		}
	return false;
}

// kth- smallest element //
//.
//.
//.
//.
//.

// ********* Largest BST in a binary tree ******* //
//************************************************//

// class TreeDetail
// {

// 	public:

// 	bool bst;
// 	int size;
// 	int minvalue;
// 	int maxValue;

// };

// TreeDetail largerstBSTinBinaryTree(TreeNode *root)
// {
// 	// obejct that will be returned by the
// 	// function
// 	TreeDetail val;

// 	if(root == NULL)
// 	{
// 		val.bst= true;
// 		val.size= 0;
// 		val.minvalue= INT_MAX;
// 		val.maxValue= INT_MIN;
// 		return val;
// 	}

// 	TreeDetail leftDetail =largerstBSTinBinaryTree(root->left);
// 	TreeDetail rightDetail =largerstBSTinBinaryTree(root->right);

// 	// left BST should be true and right bst should be tue
// 	// root value > maxvalue on left and root < minvalue

// 	if(leftDetail.bst==false || rightDetail.bst==false
// 		or root->val > rightDetail.minvalue or
// 		root->val< leftDetail.maxValue)
// 		{
// 			// i am not a bst
// 			val.bst=false;
// 			val.size = max(leftDetail.size, rightDetail.size);
// 			return val;
// 		}
// 		// if i am here that means i am a BST
// 		val.bst = true;
// 		val.size = leftDetail.size + rightDetail.size+1;

// 		// before returning i have to update
// 		//my min value as wil as my maxvalue
// 		int myMinValue;
// 		if(root->left == NULL)
// 		{
// 			myMinValue = root->val;
// 		}
// 		else
// 		{
// 			myMinValue = leftDetail.minvalue;
// 		}

// 		int myMaxValue;
// 		if(root->right == NULL)
// 		{
// 			myMaxValue = root->val;
// 		}
// 		else
// 		{
// 			myMaxValue = rightDetail.maxValue;
// 		}
		
// 		val.minvalue = myMinValue;

// 		val.maxValue = myMaxValue;
// }

int main()
{
	TreeNode *root = NULL;
	root = insert(root);

	cout << "********* Inorder ********" << endl;
	inOrder(root);
	cout << endl;


	cout << "********* Preorder ********" << endl;
	preOrder(root);
	cout << endl;

	cout << "********* BST Search ********" << endl;
	int key = 12;
//	searchBST(root, key);
	if(searchBST(root,key))
	{
		cout << "Key found" << endl;
	}
	else
	{
		cout << " Key not found" << endl;
	}
	
	cout << endl;
	return 0;




// 	// Input for Tree
// 	// 8 5 7 6 3 12 10 14 -1

// 	// Input for largest bst in a bt
// 	// 8 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1 9 7 -1 -1 10 -1 -1
}


//***************************************//
//***************************************//
// Only to run the largest BST code
//***************************************//
//***************************************//

// int main()
// {
// 	cout << "Largest BST in a Binary Tree" << endl;
// 	TreeNode *root = NULL;
//  	root=buildTree(root);

// 	TreeDetail val = largerstBSTinBinaryTree(root);

// 	cout << "Size is " << val.size << endl;

// 	return 0;

// }