// wap to check whether the given tree is balanced or not 
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


int height(node* root){
    if(root==NULL){
        return 0;
    }

    int lh=height(root->left);
    int rh=height(root->right);

    return max(lh,rh)+1;
}


bool isBalanced(node* root){

    if(root==NULL){
        return true;
    }

    int lh=height(root->left);
    int rh=height(root->right);

    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }

    if(isBalanced(root->left)==false){
        return false;
    }
    if(isBalanced(root->right)==false){
        return false;
    }
    // this condition will do the check and take bigO(n^2)
}

bool isbalanced(node* root,int* height){
    if(root==nullptr){
        return true;
    }

    int lh=0,rh=0;
    if(isbalanced(root->left,&lh)==false){
        return false;
    }
    if(isbalanced(root->right,&rh)==false){
        return false;
    }


    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }

}

int main(){
    node* root = new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);


    node* root2= new node(1);
    root2->left=new node(2);
    root2->left->left=new node(3);



    int height=0;
    if(isbalanced(root2,&height)){
        cout<<"true";
    }
    else{
        cout<<"False";
    }
    // if(isBalanced(root2)){
    //     cout<<"true";
    // }
    // else{
    //     cout<<"False";
    // }
}