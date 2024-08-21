// wap for vertical traversal of tree using map
#include <iostream>
#include <map>
#include <vector>
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

void getVerticalOrder(node *root, int hd, map<int, vector<int>> &m)
{
    if (root == NULL)
    {
        return;
    }

    m[hd].push_back(root->data);

    getVerticalOrder(root->left, hd - 1, m);
    getVerticalOrder(root->right, hd + 1, m);
}

void printVerticalOrder(node *root)
{
    map<int, vector<int>> m;
    int hd = 0;

    getVerticalOrder(root, hd, m);

    for (auto it : m)
    {
        for (int i : it.second)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    node *root = new node(10);
    root->left = new node(7);
    root->right = new node(4);
    root->left->left = new node(3);
    root->left->right = new node(11);
    root->right->left = new node(14);
    root->right->right = new node(6);

    printVerticalOrder(root);
    return 0;
}
