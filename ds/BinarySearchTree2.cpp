// Search and Delete in Binary Search Tree
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

node* buildBST(node* root,int val){
    if(root==NULL){
        return new node(val);
    }
    if(val<root->data){
        root->left=buildBST(root->left,val);
    }
    else{
        root->right=buildBST(root->right,val);
    }
    return root;
}

bool searchValue(node* root,int val){
    if(root==NULL){
        return false;
    }
    if(val==root->data){
        return true;
    }
    if(val<root->data){
        return searchValue(root->left,val);
    }
    else{
        return searchValue(root->right,val);
    }
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
    int s=sizeof(a)/sizeof(a[0]);

    node* root=NULL;
    for(int i=0;i<s;i++){
        root=buildBST(root,a[i]);
    }
    preorder(root);
    cout<<"\n";
    
    searchValue(root,3)?cout<<"true":cout<<"false";
}