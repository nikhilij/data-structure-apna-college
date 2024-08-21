// wap to find the maximum path sum in a binary tree. The path can start and end at any node, and it must consist of at least one node.

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int maxPathSumutility(node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = max(0, maxPathSumutility(root->left, ans));
    int right = max(0, maxPathSumutility(root->right, ans));

    int nodemax = root->data + left + right;

    ans = max(ans, nodemax);
    return root->data + max(left, right);
}

int maxPathSum(node *root)
{
    int ans = INT_MIN;
    maxPathSumutility(root, ans);
    return ans;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(0);
    root->left->left = new node(-4);
    root->left->right = new node(1);
    root->right->left = new node(-6);
    root->right->right = new node(2);

    cout << maxPathSum(root) << endl;

    return 0;
}
