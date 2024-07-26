// wap to check for given two bst identical or not

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


node* buildBST(node* r,int val){
    if(r==NULL){
        return new node(val);
    }
    if(r->data>val){
        r->left=buildBST(r->left,val);
    }
    if(r->data<val){
        r->right=buildBST(r->right,val);
    }
    return r;

}

void inorderTraversal(node* r){
    if(r==NULL){
        return;
    }
    inorderTraversal(r->left);
    cout<<r->data<<" ";
    inorderTraversal(r->right);
}

bool checkIdenticalBST(node* root1,node*root2){
    node* temp1=root1;
    node* temp2=root2;

    if(root1==nullptr && root2==nullptr ){
        return true;
    }
    if(root1==nullptr ||  root2==nullptr){
        return false;
    }

    if(root1->data==root2->data){
        return true;
    }

    bool left=checkIdenticalBST(root1->left,root2->left);
    bool right=checkIdenticalBST(root1->right,root2->right);

    return left && right;
}

int main(){
    int a1[] = {5, 3, 7, 2, 4, 6, 8};
    int a2[] = {5, 3, 7, 2, 4, 6, 8};

    node* root1 = NULL;
    node* root2 = NULL;

    for (int i = 0; i < sizeof(a1)/sizeof(a1[0]); i++) {
        root1 = buildBST(root1, a1[i]);
    }
    for (int i = 0; i < sizeof(a2)/sizeof(a2[0]); i++) {
        root2 = buildBST(root2, a2[i]);
    }

    cout << "Inorder traversal of BST 1: ";
    inorderTraversal(root1);
    cout << endl;

    cout << "Inorder traversal of BST 2: ";
    inorderTraversal(root2);
    cout << endl;

    if (checkIdenticalBST(root1, root2)) {
        cout << "The two BSTs are identical." << endl;
    } else {
        cout << "The two BSTs are not identical." << endl;
    }

    return 0;
}