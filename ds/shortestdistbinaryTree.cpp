// wap to shortest distance binary tree

// to solve this question we need three steps to calculate this
// 1. find the lca of the given two numbers
// 2. find the level of the given data of a binary tree
// 3. find the distance between these two data

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

// 1. find the lca of a given number of a binary tree

node *findlca(node *root, int n1, int n2)
{
    if (root == nullptr) return nullptr;
    if (root->data == n1 || root->data == n2) return root;
    node *leftlca = findlca(root->left, n1, n2);
    node *righttlca = findlca(root->right, n1, n2);

    if (leftlca && righttlca)
        return root;

    return (leftlca != nullptr) ? leftlca : righttlca;
}

// 2. find the level of a given data of binary tree

int findlevel(node* root, int data, int level){
    if(root==nullptr) return -1;

    if(root->data==data) return level;

    int left= findlevel(root->left,data,level+1);
    if(left==-1){
        return findlevel(root->right,data,level+1);
    }
    return left;
}

// 3. find the distance between two nodes

int findDistance(node* root,int n1,int n2){
    node* lca = findlca(root,n1,n2);
    int d1= findlevel(lca,n1,0);
    int d2=findlevel(lca,n2,0);
    return d1+d2;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    int n1=4,n2=5;

    cout<<"Distance between "<<n1<<" and "<<n2<<" is "<<findDistance(root,n1,n2)<<endl;

    return 0;
}