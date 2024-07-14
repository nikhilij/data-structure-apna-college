#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to perform level-order traversal
void levelOrderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
}

int main() {
    // Constructing a simple binary tree
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left= new node(6);
    root->right->right= new node(7);

    cout << "Level-order traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
