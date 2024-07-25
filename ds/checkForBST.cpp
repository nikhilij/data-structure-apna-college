// wap to check for bst
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

// approach 1: node>left child and node<right child this is completely wrong
// approach 2: max of left subtree and min of right subtree which is correct
// approach 3: min allowed max allowed these are the two pointers
// min allowed < node && node < max allowed

bool checkForBST(node* root,node* min,node* max){

    if(root==NULL){
        return true;
    }

    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }

    bool leftvalidity=checkForBST(root->left,min,root);
    bool rightvalidity=checkForBST(root->right,root,max);
    
    return leftvalidity && rightvalidity;
    
}

int main(){
    node* root = new node(1);
    root->left= new node(2);
    root->right= new node(3);

    checkForBST(root,NULL,NULL)? cout<<"True":cout<<"False";
}