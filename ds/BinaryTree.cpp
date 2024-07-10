// wap to learn binary tree in cpp 

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

void inorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left); // Traverse left subtree
    cout << root->data << " ";    // Print root node
    inorderTraversal(root->right);// Traverse right subtree
}

void preorderTraversal(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postordertraversal(node* root){
    if(root==NULL){
        return;
    }
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" ";
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);  

/*      1
       / \
      2   3
*/
    root->left->left = new node(4);
    root->left->right = new node(5);

/*         1
         /   \
        2     3
       / \
      4   5

*/
    inorderTraversal(root);
    cout<<"\n";
    preorderTraversal(root);
    cout<<"\n";
    postordertraversal(root);
}