// wap to Convert Sorted List to Binary Search Tree

#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        // Convert this to array by traversing 
        vector<int> nums;
        while (head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }

        return bst(nums, 0, nums.size() - 1);
    }

    TreeNode* bst(vector<int> nums, int left, int right) {
        if (left > right) {
            return NULL;
        }
        int midpoint = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[midpoint]);

        node->left = bst(nums, left, midpoint - 1);
        node->right = bst(nums, midpoint + 1, right);

        return node;
    }
};

// Helper function to create a sorted linked list
ListNode* createSortedList(vector<int>& nums) {
    if (nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;

    for (size_t i = 1; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print inorder traversal of the tree
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
    Solution solution;

    // Create a sorted linked list
    vector<int> sortedList = {-10, -3, 0, 5, 9};
    ListNode* head = createSortedList(sortedList);

    // Convert the sorted linked list to a height-balanced BST
    TreeNode* bstRoot = solution.sortedListToBST(head);

    // Print the inorder traversal of the created BST
    cout << "Inorder Traversal of the BST: ";
    inorderTraversal(bstRoot);
    cout << endl;

    return 0;
}
