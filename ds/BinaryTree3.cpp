// wap to build tree from postorder and inorder in cpp

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

int search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

node* buildTree(int postorder[],int inorder[],int start,int end){
    static int index=end;
    if(start>end){
        return NULL;
    }
    int curr=postorder[index];
    index--;
    node* n = new node(curr);

    if(start==end){
        return n;
    }
    int pos=search(inorder,start,end,curr);

    n->right=buildTree(postorder,inorder,pos+1,end);
    n->left=buildTree(postorder,inorder,start,pos-1);

    return n;
    

}



void postorderTraversal(node* root){
    if(root==NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}


void inorderTraversal(node* root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};

    node* root=buildTree(postorder,inorder,0,4);

    cout<<"PostOrder Traversal: ";
    postorderTraversal(root);
    cout<<" \n";
    cout<<"Inorder Traversal: ";
    inorderTraversal(root);
    cout<<"\n";
}