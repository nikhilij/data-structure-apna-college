// wap to sort the given linked list in cpp 

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case: if head is null or there's only one element
        if (!head || !head->next) {
            return head;
        }
        
        // Split the list into halves
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        // Merge the sorted halves
        return merge(left, right);
    }
    
private:
    // Function to find the middle of the linked list
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next;
        slow->next = nullptr;  // Split the list into two halves
        return mid;
    }
    
    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // Dummy node to simplify merging
        ListNode* current = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        // Attach the remaining elements
        if (l1) {
            current->next = l1;
        } else {
            current->next = l2;
        }

        return dummy.next; // Return the merged list, skipping the dummy node
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Main function to test the solution
int main() {
    Solution solution;

    // Test case 1
    int arr1[] = {4, 2, 1, 3};
    ListNode* head1 = createList(arr1, 4);
    cout << "Original list: ";
    printList(head1);
    ListNode* sorted1 = solution.sortList(head1);
    cout << "Sorted list: ";
    printList(sorted1);

    // Test case 2
    int arr2[] = {-1, 5, 3, 4, 0};
    ListNode* head2 = createList(arr2, 5);
    cout << "Original list: ";
    printList(head2);
    ListNode* sorted2 = solution.sortList(head2);
    cout << "Sorted list: ";
    printList(sorted2);

    // Test case 3 (empty list)
    ListNode* head3 = nullptr;
    cout << "Original list: ";
    printList(head3);
    ListNode* sorted3 = solution.sortList(head3);
    cout << "Sorted list: ";
    printList(sorted3);

    return 0;
}
