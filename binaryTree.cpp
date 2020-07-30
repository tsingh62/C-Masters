#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<queue>

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
// Time : O(n)
// Space : O(n)
void preOrder(TreeNode *root)
{
	//Base case
	if(root == NULL)
	{
		return;
	}
	// N - (root) - L - R
	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
	
}
// Time : O(n)
// Space : O(n)
void inOrder(TreeNode *root)
{
	// base case
	if(root == NULL)
	{
		return;
	}
	// L - N(root) - R
	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);

}
// Time : O(n)
// Space : O(n)
void postOrder(TreeNode *root)
{
	// base case
	if(root == NULL)
	{
		return;
	}
	// L - R - N(root) 
	postOrder(root->left);
	postOrder(root->right);
	cout << root->val << " ";
}
//*****************************
// Problem solving - No of nodes
// in a tree problem you are just given a root value
// Time : O(n)
// Space : O(n)
int countNodes(TreeNode *root)
{	// Base case
	if(root == NULL)
	{
		return 0;
	}

	// rec
	int left = countNodes(root->left);
	int right = countNodes(root->right);

	int total = left+1+right;
	// plus one for the root value 

	return total;
}
// **************** Sum of all nodes **********//
// Time : O(n)
// Space : O(n)
int sumOfNodes(TreeNode *root)
{	// base case
	if(root == NULL)
	{
		return 0;
	}
	// rec
	int sumLeft = sumOfNodes(root->left);
	int sumRight = sumOfNodes(root->right);

	int ans = sumLeft+root->val+sumRight;
	return ans;
}

//****************** Search *****************//
// Time : O(n)
// Space : O(n)
bool serachKey(TreeNode *root, int key)
{
	// base case
	if(root == NULL)
	{
		return false;
	}
	// key at root
	if(root->val==key)
	{
		return true;
	}
	// rec
	bool sLeft = serachKey(root->left, key);
	bool sRight = serachKey(root->right, key);

	// if(sRight || sLeft)
	// {
	// 	return true;
	// }
	// return false; // or

	return sLeft || sRight;
}
// Time : O(n)
// Space : O(n)
int height(TreeNode *root)
{
	if(root==NULL)
	{				// A
		return -1; // if made 0 it will increase the 
					// height by extra 1
					// to correct it we use -1
	}
	
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int totalHeight= max(leftHeight, rightHeight)+1;
	// B
	// or use -1 here - any one A or B

	return totalHeight;
}
int diameter(TreeNode *root)
{
	if(root==NULL)
	{
		return 0;
	}
	//*****************************//
	// left height -
	// right height - + the edges(2) from the root
	//*****************************//
	// int leftDia = diameter(root->left);
	// int rightDia = diameter(root->right);

	int leftHeight = height(root->left); // using previous ht fun
	int rightHeight = height(root->right);

	int myDia = leftHeight+2+rightHeight; 

	int maxDia = max(myDia, max(leftHeight, rightHeight));

	return maxDia;
}
//************* Hard Questions ************//
//******************************//
// Diameter and height //
// incomplete --- 

class DiaHeight
{
	public :

	int diameter;
	int height;

};
// return type here is diaHeigth
// As we need to return the pair
// value of diameter and ht defined 
// in dia height
// constructor - parameterized
DiaHeight diameterOptimized (TreeNode *root)
{
	DiaHeight val;

	if(root == NULL)
	{
		val.diameter = 0;
		val.height = -1;
		return val;
	}
	// update the height and diameter of val object
	// and then return 
	DiaHeight leftPair = diameterOptimized(root->left);
	DiaHeight rightPair = diameterOptimized(root->right);

	int leftDiameter = leftPair.diameter;
	int rightDiameter = rightPair.diameter;

	int leftHeight = leftPair.height;
	int rightHeight = rightPair.height;

	int myDiameter = leftHeight+ 2 + rightHeight;

	int maxDiameter = max(myDiameter, max(leftDiameter, rightDiameter));
	val.diameter = maxDiameter;

	val.height = max(leftHeight, rightHeight) + 1;

	return val;
}
// ********************* Balanced tree *************** //
// Time: O(n^2) 
bool heightBalanced (TreeNode *root)
{
	if(root== NULL)
	{
		return true;
	}
	bool leftBalance = heightBalanced(root->left);
	bool rightBalance = heightBalanced(root->right);

	if(leftBalance || rightBalance ==false)
	{
		return false;
	}
	// if you are here
	// both my left sub tree and right subtree
	// are balanced

	// check if i am balanced or not
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int diff = abs(leftHeight - rightHeight);
	if(diff >1)
	{
		return false;
	}
	return true;
}
//************* root to leaf ************//
void display(vector<int> v)
{
	for (int i=0; i<v.size(); i++)
	{
		cout << v[i] << "-> ";
	}
	cout << endl;
}
void printRootToLeaf(TreeNode *root, vector<int> ans)
{
	if(root == NULL)
	{
		return;
	}
	if(root->left == NULL and root->right== NULL)
	{
		display(ans); //
		return;
	}

	ans.push_back(root->val);
	printRootToLeaf(root->left, ans);
	printRootToLeaf(root->right, ans);

}
//************* Height balanced optimized ************//
pair <bool,int> heightBalancedoptimized(TreeNode *root)
{	
	// obejct that will eventually be returned by the func
	pair<bool, int> val;

	// base case
	if(root == NULL)
	{
		val.first = true;
		val.second = -1;
		return val;
	}
	pair<bool, int> leftPair = heightBalancedoptimized(root->left);
	pair<bool, int> rightPair = heightBalancedoptimized(root->right);

	bool leftBalance = leftPair.first;
	bool rightBalance = rightPair.first;

	int leftHeight = leftPair.second;
	int rightHeight = rightPair.second;
	
	int myHeight = max(leftHeight, rightHeight +1);
	val.second = myHeight;

	if(leftBalance == false or rightBalance ==false)
	{
		val.first = false;
		return val;
	}

	int diff = abs(leftHeight - rightHeight);

	if(diff > 1)
	{
		val.first = false;
	}
	else
	{
		val.first = true;
	}
	return val;
}

int main()
{
	TreeNode *root = NULL;
	root = buildTree(root);
//	cout << "Root value is " <<root->val << endl;

	// preOrder(root); // enter these values - tree input
	// 				// 8 5 13 -1 -1 -1 10 4 -1 -1 7 -1 -1
	// cout << endl;
 	
	 // inOrder(root);
	// cout << endl;

	// postOrder(root);
	// cout << endl;
	//**************** Count problem ***************//
	// cout << countNodes(root);
	// cout << endl;

	//**************** Sum of all nodes ***************//
	//  cout << "Sum is : " << sumOfNodes(root);
	 
	//  cout << endl;
	

	//**************** Search key ***************//
	//cout << serachKey(root, 5); // key =5
	// int key =4;
	// if(serachKey(root, key))
	// {
	// 	cout << "key found" << endl;
	// }
	// else
	// {
	// 	cout << "key not found" << endl;
	// }
	
	// cout << endl; 

	//**************** height ***************//

	// cout << "height of the tree is " << height(root) << endl;

	//**************** Diameter ***************//
	// cout << "Diameter is : " << diameter(root) << endl;

	

	//**************** Diameter * and * height in Pair**************//
	// incomplete
	

	//**************** Balanced height ***************//
 	
	//  if(heightBalanced(root))
	//  {
	// 	 cout << "balance" << endl;
	//  }
	//  else
	//  {
	// 	 cout << "Not balanced" << endl;
	//  }
	 
//**************** Root to Leaf ***************//
	vector<int> temp;
	printRootToLeaf(root, temp);

	return 0;

	// Input for Tree
	// 8 5 13 -1 -1 -1 10 4 -1 -1 7 -1 -1
}