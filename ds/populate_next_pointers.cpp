// write the cpp program to populate the next right pointers of given binary tree

#include <iostream>
#include <queue>
using namespace std;

// Definition for a Node
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }
};

// Function to connect the next pointers
class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return nullptr;
        Node* level = root;
        while(level->left){
            Node* curr = level;
            while(curr){
                curr->left->next=curr->right;
                if(curr->next){
                    curr->right->next = curr->next->left;
                }
                curr=curr->next;
            }
            level = level->left;
        }
        return root;
    }
};

// Helper function to print the tree using next pointers (Level order traversal)
void printTree(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();

            cout << node->val;
            if (node->next)
                cout << " -> ";
            else
                cout << " -> NULL"; // End of level

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl; // New line for the next level
    }
}

// Driver code
int main() {
    // Creating the example tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    root = sol.connect(root); // Populate next pointers

    // Print the tree to verify next pointers
    printTree(root);

    return 0;
}

