// find the lca of given two nodes in binary tree using cpp 

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

node* findlca(node* root,int n1,int n2){
    if(root==nullptr){
        return nullptr;
    }
    if(root->data==n1 || root->data==n2) return root;
    node *leftlca= findlca(root->left,n1,n2);
    node*rightlca= findlca(root->right,n1,n2);

    if(leftlca && rightlca){
        return root;
    }

    return (leftlca!=nullptr)?leftlca:rightlca;


};

int main(){
    node* root= new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left=new node(4);
    root->right->left = new node(5);
    root->right->right= new node(6);
    root->right->left->left = new node(7);

    int n1=7;
    int n2=6;

    node* lca = findlca(root,n1,n2);
    if(lca!=nullptr){
        cout<<lca->data;
    }
}
