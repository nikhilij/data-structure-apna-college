// wap to Recover Binary Search Tee
// 2 nodes of a BST are swapped. Our task is to restore(correct) the BST

// 2 elements in a sorted array are swapped

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

void inorderTraversal(node *root, node *&first, node *&middle, node *&last, node *&prev)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left, first, middle, last, prev);

    if (prev != NULL && root->data < prev->data)
    {
        if (first == NULL)
        {
            first = prev;
            middle = root;
        }
        else
        {
            last = root;
        }
    }
    prev = root;
    inorderTraversal(root->right, first, middle, last, prev);
}

void restoreBST(node *root)
{

    node *first = NULL;
    node *middle = NULL;
    node *last = NULL;
    node *prev = NULL;

    inorderTraversal(root, first, middle, last, prev);

    if (first && last)
    {
        swap(first->data, last->data);
    }
    else if (first && middle)
    {
        swap(first->data, middle->data);
    }
}

void inorderPrint(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}
int main()
{
    node *root = new node(6);
    root->left = new node(10);
    root->right = new node(2);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(12);
    root->right->left = new node(7);

    cout << "Inorder Traversal of the original tree: ";
    inorderPrint(root);
    cout << endl;

    restoreBST(root);

    cout << "Inorder Traversal of the fixed tree: ";
    inorderPrint(root);
    cout << endl;

    return 0;
}
