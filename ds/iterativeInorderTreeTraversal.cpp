// write the program to do the iterative inorder traversal of tree

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorderTraversal(Node *root)
{
    vector<int> res;
    stack<Node *> st;
    Node *curr = root;
    while (curr != nullptr || !st.empty())
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        Node *temp = st.top();
        res.push_back(temp->data);
        curr = curr->right;
    }
}

int main()
{

    stack<int> st;

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    inorderTraversal(root);

    return 0;
}