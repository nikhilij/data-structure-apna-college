#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to merge two sorted linked lists
Node* merge(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->data < l2->data) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

// Function to split the linked list into two halves
void split(Node* head, Node** front, Node** back) {
    Node* slow = head;
    Node* fast = head->next;
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = head;
    *back = slow->next;
    slow->next = nullptr;
}

// Function to perform merge sort on a linked list
Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;
    Node* front;
    Node* back;
    split(head, &front, &back);
    front = mergeSort(front);
    back = mergeSort(back);
    return merge(front, back);
}

// Main function to test the merge sort on a linked list
int main() {
    // Creating a linked list: 4 -> 2 -> 1 -> 3
    Node *head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    cout << "Original List: ";
    printList(head);

    // Sorting the linked list
    head = mergeSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
