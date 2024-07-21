// wap to right view of tree using queue in cpp 

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


void rightview(node* root){
    if(root==NULL){
        return;
    }

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int levelsize=q.size();
        for(int i=0;i<levelsize;i++){
            node* curr=q.front();
            q.pop();

            //if the curr element is the last element of the curr level
            if(i==levelsize-1){
                cout<<curr->data<<" ";
            }

            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }

    }

}


int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    rightview(root);
}

