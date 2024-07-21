// wap to flatten a binary tree using cpp 
// Flattening a binary tree involves transforming it into a "linked list" where each node's left child is nullptr, and the right child points to the next node in the preorder traversal of the tree.


#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

// Function to flatten the binary tree in-place
void flatten(node* root) {
    node* curr=root;
    while(curr!=nullptr){
        if(curr->left!=nullptr){
            node* rightmost=curr->left;

            while(rightmost->right!=nullptr)
            {
                rightmost=rightmost->right;
            }
            rightmost->right=curr->right;
            curr->right=curr->left;
            curr->left=nullptr;
        }
        curr=curr->right;
    }
}

// Function to print the flattened tree
void printFlattened(node* root) {
    while (root != nullptr) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    // Create the binary tree
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->right = new node(6);

    // Flatten the binary tree
    flatten(root);

    // Print the flattened tree
    printFlattened(root);

    return 0;
}