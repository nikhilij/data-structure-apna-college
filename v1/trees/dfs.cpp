// dfs of tree are : inorder, postorder, preorder

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v)
    {
        data = v;
        left = NULL;
        right = NULL;
    }
};
// recursive methods
//------------------------------------------------
void preorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

// iterative method--------------------

vector<int> preorderIterative(TreeNode *root)
{
    if (root == nullptr)
    {
        return {};
    }
    stack<TreeNode *> st;
    vector<int> res;
    st.push(root);
    while (!st.empty())
    {
        TreeNode *curr = st.top();
        st.pop();
        res.push_back(curr->data);

        if (curr->right)
        {
            st.push(curr->right);
        }
        if (curr->left)
        {
            st.push(curr->left);
        }
    }
    return res;
}

vector<int> inorderIterative(TreeNode *root)
{
    // given the root of the tree we need to perform the inorder traverse using iterative method
    if (root == nullptr)
        return {};
    vector<int> res;
    stack<TreeNode *> st;
    TreeNode *curr = root;

    // we will go deeper in left first
    while (curr != nullptr || !st.empty())
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }

        TreeNode *node = st.top();
        st.pop();
        res.push_back(node->data);
        curr = node->right;
    }
    return res;
}

// using two stacks
vector<int> postorderIterative(TreeNode *root)
{
    if (root == nullptr)
        return {};

    stack<TreeNode *> st1, st2;
    st1.push(root);
    vector<int> res;
    while (!st1.empty())
    {
        TreeNode *curr = st1.top();
        st1.pop();

        st2.push(curr);
        
        if(root->left) st1.push(root->left);
        if(root->right) st1.push(root->right);
    }

    while(!st2.empty()){
        res.push_back(st2.top()->data);
        st2.pop();
    }
    return res;
}


// postorderTraversal using single stack 

vector<int> postorderTraversal(TreeNode* root){
    if(root==nullptr) return{};

    TreeNode* lastvisited;
    stack<TreeNode*> st;
    vector<int> res;
    

}