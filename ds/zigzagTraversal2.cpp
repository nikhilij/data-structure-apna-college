// wap to zigzag Traversal of a binary tree
#include <iostream>
#include <stack>
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

node *buildbst(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }

    if (root->data > val)
    {
        root->left = buildbst(root->left, val);
    }
    else
    {
        root->right = buildbst(root->right, val);
    }
    return root;
}

void inorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void zigzagTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<node *> currlevel;
    stack<node *> nextlevel;
    bool lefttoright = true;
    currlevel.push(root);
    while (!currlevel.empty())
    {
        node *temp = currlevel.top();
        currlevel.pop();

        if (temp)
        {
            cout << temp->data << " ";

            if (lefttoright)
            {
                if (temp->left)
                {
                    nextlevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextlevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nextlevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextlevel.push(temp->left);
                }
            }
        }
        if (currlevel.empty())
        {
            lefttoright = !lefttoright;
            swap(currlevel, nextlevel);
        }
    }
}

int main()
{
    int a[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int n = sizeof(a) / sizeof(a[0]);

    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = buildbst(root, a[i]);
    }

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Zigzag Traversal: ";
    zigzagTraversal(root);
    cout << endl;

    return 0;
}