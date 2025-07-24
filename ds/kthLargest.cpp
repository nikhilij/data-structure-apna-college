// write the cpp code to find the kth largest element in a binary search tree

#include<iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};
int count = 0;
void reverseInorder(int& result, Node* root, int& k) {
    if(!root || count>=k){
        return;
    }
    reverseInorder(result,root->right, k);

    count++;
    if(count == k){
        result = root->val;
        return;
    }

    reverseInorder(result,root->left, k);
}


int findKthLargest(Node* root, int k) {
    int result = -1;
    reverseInorder(result,root, k);
    return result;
}


int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    int k = 3; // Example: Find the 3rd largest element
    int result = findKthLargest(root, k);

    if (result != -1) {
        cout << "The " << k << "rd largest element is: " << result << endl;
    } else {
        cout << "The tree does not have " << k << " elements." << endl;
    }

    return 0;
}

