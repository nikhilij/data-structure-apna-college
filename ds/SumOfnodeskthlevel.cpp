// wap to find the sum of nodes at kth level
#include<iostream>
#include<queue>
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

int findSumKthlevel(node* root,int k){

    if(root==NULL){
        return 0;
    }
    queue<node*> q;
    q.push(root);
    int level=0;
    int sum=0;

    while(!q.empty()){
        int size=q.size();
        while(size--){
            node* curr = q.front();
            q.pop();

            if(level==k){
                sum+=curr->data;
            }
            else{
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
        level++;
    }

    return sum;
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left= new node(6);
    root->right->right= new node(7);

    int sum=findSumKthlevel(root,2);

    cout<<sum;
}