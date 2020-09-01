
#include<iostream>
#include<vector>
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

TreeNode *buildTree(TreeNode *root)
{
    int data;
    cin >> data;

    if(data == -1)
    {
        return NULL;
    }
    if(root == NULL)
    {
         root = new TreeNode(data);
    }

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

TreeNode *buildBST(TreeNode *root, int data)
{
    if(root == NULL)
    {
        root = new TreeNode(data);
        return root;
    }
    if(data > root->val)
    {
        root->right = buildBST(root->right,data);
    }
    else
    {
        root->left = buildBST(root->left,data);
    }
    return root;
}
TreeNode *insert(TreeNode *root)
{
    int data;
    cin >> data;

    if(data==-1)
    {
        return NULL;
    }
    if(root==NULL)
    {
        root = new TreeNode(data);
    }

    while(data!=-1)
    {
        root = buildBST(root, data);
        cin >> data;
    }
    return root;
}

void inOrder(TreeNode *root)
{
    if(root==NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void preOrder(TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
bool searchInBST(TreeNode *root, int key)
{
    if(root == NULL)
    {
        return false;
    }
    if(root->val == key)
    {
        return true;
    }
    if(root->val < key)
    {
        return searchInBST(root->left), key;
    }
    else
    {
        return searchInBST(root->right, key);
    }
}

bool isBST(TreeNode *root)
{
    
}
int main()
{
    TreeNode *root = NULL;
    root = insert(root);
    
    inOrder(root);
    cout << endl;

    preOrder(root);
    cout << endl;


    return 0;

}

// 8 5 13 -1 -1 -1 10 4 -1 -1 7 -1 -1

// BST
//  8 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1 9 7 -1 -1 10 -1 -1
//  8 5 7 6 3 12 10 14 -1