// Maximum Path Sum
// wap to find maximum possible sum of a path in the binary tree, starting & ending at any node

#include <iostream>
#include <algorithm>
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

int rec(node *temp, int &sum, int currSum)
{
    if (temp->right == NULL && temp->left == NULL)
    {
        sum = max(sum, currSum + temp->data);
        return 0;
    }
    if (temp->right)
    {
        rec(temp->right, sum, currSum + temp->data);
    }
    if (temp->left)
    {
        rec(temp->left, sum, currSum + temp->data);
    }

    return sum;
}

int maxPathSum(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    node *temp = root;
    int sum = INT_MIN;

    sum = rec(temp, sum, 0);

    return sum;
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

    cout << maxPathSum(root);

    return 0;
}