// wap to determine the minimum depth of a given binary tree

// the minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node

#include <iostream>
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

int findMinDepth(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    if (!root->left)
    {
        return findMinDepth(root->right) + 1;
    }
    if (!root->right)
    {
        return findMinDepth(root->left) + 1;
    }
    return min(findMinDepth(root->left), findMinDepth(root->right)) + 1;
}

int main()
{

    node *Tree = new node(1);
    Tree->left = new node(2);
    Tree->right = new node(3);
    Tree->left->left = new node(4);
    Tree->left->right = new node(5);

    int minDepth = findMinDepth(Tree);

    cout << minDepth;
}