// wap to find the size of the largest bst present in the binary tree
#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

struct Info {
    int sz;
    int max_val;
    int min_val;
    int ans;
    bool isBST;
};

Info dfs(TreeNode* node) {
    if (!node)
        return {0, INT_MIN, INT_MAX, 0, true};

    Info left_info = dfs(node->left);
    Info right_info = dfs(node->right);

    Info ret{
        1 + left_info.sz + right_info.sz,
        max(node->val, right_info.max_val),
        min(node->val, left_info.min_val),
        max(left_info.ans, right_info.ans),
        (left_info.isBST && right_info.isBST &&
         left_info.max_val < node->val && node->val < right_info.min_val)
    };

    if (ret.isBST)
        ret.ans = max(ret.ans, ret.sz);

    return ret;
}

int largestBSTBT(TreeNode* root) {
    return dfs(root).ans;
}

int main() {
    TreeNode* root = new TreeNode(60);
    root->left = new TreeNode(65);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(50);

    int largest_bst_size = largestBSTBT(root);
    cout << "Size of the largest BST is " << largest_bst_size << endl;

    // Clean up memory (not necessary in practice)
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
