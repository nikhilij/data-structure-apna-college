// write the cpp program to compute the predecessor and successor of a given node in a binary search tree

#include<iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;
    Node* insert(Node* node, int val) {
        if (node == NULL) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insert(node->left, val);
        }
        else {
            node->right = insert(node->right, val);
        }
        return node;
    }
public:
    BST() {
        root = NULL;
    }
    void insert(int val) {
        root = insert(root, val);
    }
    Node* getRoot() {
        return root;
    }
};

vector<Node*> findPredecessorAndSuccessor(Node* root, int key) {
    vector<Node*> res(2, NULL);
    Node* prev = NULL;
    Node* suc = NULL;

    while (root) {
        if (root->data > key) {
            suc = root;
            root = root->left;
        }
        else if (root->data < key) {
            prev = root;
            root = root->right;
        }
        else {
            if (root->left) {
                Node* temp = root->left;
                while (temp->right) {
                    temp = temp->right;
                }
                prev = temp;
            }
            if (root->right) {
                Node* temp = root->right;
                while (temp->left) {
                    temp = temp->left;
                }
                suc = temp;
            }
        }
        break;
    }
    res[0] = prev ? prev : NULL;
    res[1] = suc ? suc : NULL;
    return res;
}

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    int key = 65;

    vector<Node*> result = findPredecessorAndSuccessor(bst.getRoot(), key);
    Node* predecessor = result[0];
    Node* successor = result[1];

    if (predecessor) {
        cout << "Predecessor of " << key << " is " << predecessor->data << endl;
    }
    else {
        cout << "No Predecessor found for " << key << endl;
    }

    if (successor) {
        cout << "Successor of " << key << " is " << successor->data << endl;
    }
    else {
        cout << "No Successor found for " << key << endl;
    }

    return 0;
}