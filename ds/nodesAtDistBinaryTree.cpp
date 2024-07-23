// wap to print all nodes at distance k in binary Tree

// case 1: Node's Subtree

// case 2: Node's Ancestor


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

// case 1: Node's Subtree

void printSubtreeNodes(node* root,int k){
    if(root==NULL||k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
    }

    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);
}

// case 2: Node's Ancestor

int printNodesAtk(node* root,node* target, int k){
    if(root==NULL){
        return -1;
    }
    if(root==target){
        printSubtreeNodes(root,k);
        return 0;
    }
    int dl=printNodesAtk(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<< root->data<<" ";
        }else{
            printSubtreeNodes(root->right,k-dl-2);
        }
        return 1+dl;
    }
    int dr=printNodesAtk(root->right,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<< root->data<<" ";
        }else{
            printSubtreeNodes(root->left,k-dr-2);
        }
        return 1+dr;
    }
    return -1;
}


/*

Purpose: Check if the target node is in the left subtree.
Action: Call printNodesAtk on the left child. If the target node is found (dl != -1):
Calculate Distance: The distance from the current node to the target node through the left child is dl + 1.
Print Current Node: If the distance dl + 1 equals k, print the current node's data.
Opposite Subtree Check: If the current node is not at distance k (dl + 1 != k), find nodes in the right subtree that are at distance k - dl - 2. This formula comes from the following:
Explanation of k - dl - 2: The total distance from the current node to the target node is dl + 1. To find nodes at distance k from the target, the remaining distance in the opposite subtree (right subtree in this case) is k - (dl + 1) - 1 which simplifies to k - dl - 2. The extra -1 accounts for the current node itself.
Return: Return the distance from the current node to the target node, which is 1 + dl.

same with the right subtree check for the target node


*/
int main(){
    node* root = new node(1);
    root->left= new node(2);
    root->right= new node(3);
    root->left->left= new node(4);

    printNodesAtk(root,root->left,1);
    return 0;
}
