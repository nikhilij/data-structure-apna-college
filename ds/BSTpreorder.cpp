// wap to build binary search tree using given preorder
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

node *buildBSTFromPreorder(int preorder[], int &index, int min, int max, int size)
{
    if (index >= size || preorder[index] < min || preorder[index] > max)
    {
        return NULL;
    }

    int val = preorder[index];
    node *root = new node(val);
    index++;

    root->left = buildBSTFromPreorder(preorder, index, min, val, size);
    root->right = buildBSTFromPreorder(preorder, index, val, max, size);

    return root;
}

node *buildBST(int preorder[], int size)
{
    int index = 0;
    return buildBSTFromPreorder(preorder, index, INT_MIN, INT_MAX, size);
}

void inorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){
    int preorder[] = {8, 5, 1, 7, 10, 12};
    int size = sizeof(preorder) / sizeof(preorder[0]);
    node* root = buildBST(preorder, size);

    cout << "Inorder traversal of the constructed BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}