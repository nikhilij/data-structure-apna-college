#include <iostream>
#include <vector>
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

node *BuildBST(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }

    if (root->data > val)
    {
        root->left = BuildBST(root->left, val);
    }
    if (root->data < val)
    {
        root->right = BuildBST(root->right, val);
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

    stack<node *> currentLevel;
    stack<node *> nextLevel;
    bool leftToRight = true;

    currentLevel.push(root);

    while (!currentLevel.empty())
    {
        node *temp = currentLevel.top();
        currentLevel.pop();

        if (temp)
        {
            cout << temp->data << " ";

            if (leftToRight)
            {
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
        }

        if (currentLevel.empty())
        {
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
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
        root = BuildBST(root, a[i]);
    }

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Zigzag Traversal: ";
    zigzagTraversal(root);
    cout << endl;

    return 0;
}
