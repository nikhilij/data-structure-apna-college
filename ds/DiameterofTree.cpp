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

int ans=0;

int calHeight(node* root){
    if(root==NULL){
        return 0;
    }
    int lh=calHeight(root->left);
    int rh=calHeight(root->right);

    ans=max(ans,1+lh+rh);
    return (1 + max(lh,rh));
}





int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    calHeight(root);
    cout<<ans;
}