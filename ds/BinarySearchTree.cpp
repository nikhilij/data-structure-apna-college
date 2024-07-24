// wap to build binary search tree which is used to search the element/keys in bigO(log(N))

// rule 1:
/*
The left subtree of a node contains only nodes with keys lesser than the node's key.
*/
// rule 2:
/*
The right subtree of a node contains only nodes with keys greater than the node's key.
*/
// rule 3:
/*
The left and right subtree each must also be a binary search tree. There must be no duplicates nodes.
*/

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

node* buildBST(node* root , int val){
    if(root==NULL){
        return new node(val);
    }
    if(root->data>val){
        root->left=buildBST(root->left,val);
    }
    else{
        root->right=buildBST(root->right,val);
    }
    return root;
}

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


int main(){
    int a[]={5,1,3,4,2,7};
    node* root=NULL;
    root=buildBST(root,a[0]);

    for(int i=1;i<6;i++){
        buildBST(root,a[i]);
    }

    preorder(root);


}

