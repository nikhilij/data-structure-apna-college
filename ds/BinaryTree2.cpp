#include <iostream>
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

// Function to search for an element in the inorder array
int search(int inorder[], int start, int end, int curr) {
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

// Function to build the tree
node* buildTree(int preorder[], int inorder[], int start, int end) {
    static int index = 0;

    if (start > end) {
        return NULL;
    }

    int curr = preorder[index];
    index++;
    node* n = new node(curr);

    if (start == end) {
        return n;
    }

    int pos = search(inorder, start, end, curr);
    n->left = buildTree(preorder, inorder, start, pos - 1);
    n->right = buildTree(preorder, inorder, pos + 1, end);

    return n; // Ensure the node is returned
}

// Function to perform inorder traversal
void inorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Function to perform preorder traversal
void preorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    node* root = buildTree(preorder, inorder, 0, 4);

    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}
