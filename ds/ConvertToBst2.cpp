#include <iostream>  // For std::cout
#include <vector>    // For std::vector

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    ListNode* current = nullptr;

    // Function to convert sorted linked list to BST
    TreeNode* sortedListToBST(ListNode* head)
    {
        // Step 1: Count the number of nodes
        current = head;
        int count = 0;
        ListNode* temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }

        // Step 2: Recursively build the BST
        return bst(count);
    }

    // Helper function to construct BST
    TreeNode* bst(int n)
    {
        if (n <= 0) {
            return nullptr;
        }

        // Recursively construct the left subtree
        TreeNode* leftChild = bst(n / 2);

        // Create the root node for the current subtree
        TreeNode* node = new TreeNode(current->val);
        node->left = leftChild;

        // Move to the next list node
        current = current->next;

        // Recursively construct the right subtree
        node->right = bst(n - n / 2 - 1);

        return node;
    }
};

// Function to perform in-order traversal of BST
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    std::cout << root->val << " ";
    inorderTraversal(root->right);
}

// Helper function to create a sorted linked list from a vector of values
ListNode* createLinkedList(const std::vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    
    return head;
}

int main() {
    // Example sorted linked list
    std::vector<int> values = {-10, -3, 0, 5, 9};
    
    // Create the linked list from the vector
    ListNode* head = createLinkedList(values);

    // Create an instance of the Solution class
    Solution solution;

    // Convert the sorted linked list to a BST
    TreeNode* bstRoot = solution.sortedListToBST(head);

    // Print the in-order traversal of the BST (it should give the sorted values)
    std::cout << "In-order traversal of the BST: ";
    inorderTraversal(bstRoot);
    std::cout << std::endl;

    return 0;
}
