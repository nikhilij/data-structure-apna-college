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

node* findMIN(node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

// function for deletion of node from a binary tree
node* deleteNode(node* root,int val){
    if(root==NULL){
        cout<<"Element is not present";
        return nullptr;
    }
    if(root->data>val){
        root->left=deleteNode(root->left,val);
    }else if(root->data<val){
        root->right=deleteNode(root->right,val);
    }
    else{
        //node to be deleted found
        //case 1: deleting the leaf node ( no children )
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //case 2: deleting a node with only one child
        else if(root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }

        // case 3: Deleting a node with two children
        else{
            node* temp=findMIN(root->right);
            //here we have used findMIN(root->right)
            // because of inorder successor that means we have to find the 
            // smallest in the right subtree
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
            // deleting the inorder successor
        }
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
    int s=sizeof(a)/sizeof(a[0]);

    node* root=NULL;
    for(int i=0;i<s;i++){
        root=buildBST(root,a[i]);
    }
    preorder(root);
    cout<<"\n";
    
    searchValue(root,3)?cout<<"true":cout<<"false";

    cout<<"\n";

    deleteNode(root,3);
    preorder(root);
}