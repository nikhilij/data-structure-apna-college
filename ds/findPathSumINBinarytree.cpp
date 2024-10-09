// wap to find the path sum given the root node of a binary tree with a given target sum 


#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        stack<TreeNode*> node;
        stack<int> nodeval;

        node.push(root);
        nodeval.push(root->val);

        while (!node.empty()) {
            TreeNode* curr = node.top();
            int tempVal = nodeval.top();
            nodeval.pop();
            node.pop();

            // Check if it's a leaf node and the sum matches targetSum
            if (tempVal == targetSum && curr->left == nullptr && curr->right == nullptr) {
                return true;
            }

            // Add right child to stack if exists
            if (curr->right != nullptr) {
                node.push(curr->right);
                nodeval.push(tempVal + curr->right->val);
            }

            // Add left child to stack if exists
            if (curr->left != nullptr) {
                node.push(curr->left);
                nodeval.push(tempVal + curr->left->val);
            }
        }

        return false;
    }
};

// Helper function to create a tree
TreeNode* createTree() {
    // Constructing the following binary tree
    //         5
    //       /   \
    //      4     8
    //     /     / \
    //    11    13  4
    //   /  \        \
    //  7    2        1

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    return root;
}

int main() {
    Solution solution;

    // Create a sample tree
    TreeNode* root = createTree();
    
    // Test the hasPathSum function
    int targetSum = 22;
    
    if (solution.hasPathSum(root, targetSum)) {
        cout << "Path with sum " << targetSum << " exists in the tree." << endl;
    } else {
        cout << "No path with sum " << targetSum << " exists in the tree." << endl;
    }

    return 0;
}
