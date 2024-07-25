// wap to build bst from sorted array 
// actually the sorted array is the inorder traversal of bst

// make middle element the root;
// recursively do  the same for subtree
// a. start to mid-1 for left subtree
// b. mid+1 to end for right subtree


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

node* buildBstfromsortedArray(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    node* root = new node(arr[mid]);

    root->left=buildBstfromsortedArray(arr,start,mid-1);
    root->right=buildBstfromsortedArray(arr,mid+1,end);

    return root;
}


void inorder(node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    int a[]={4,5,6,7,8,9};

    node* r=buildBstfromsortedArray(a,0,5);
    inorder(r);
}
