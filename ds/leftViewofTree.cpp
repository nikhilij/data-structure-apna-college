// wap to left view of the binary tree using queue in cpp

#include <iostream>
#include <queue>
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

void leftview(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int levelsize = q.size();
        for (int i = 0; i < levelsize; i++)
        {
            node *curr = q.front();
            q.pop();

            if (i == 0)
            {
                cout << curr->data << " ";
            }

            if (curr->left != nullptr)
            {
                q.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                q.push(curr->right);
            }
        }
    }
}

int main()
{
    node *root = new node(5);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(4);
    // root->right->left = new node(6);
    // root->right->right = new node(7);

    leftview(root);
}
