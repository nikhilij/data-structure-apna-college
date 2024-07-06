#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

void insertnode(node*& head, int val) {
    node* n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    }

    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void traverse(node* head) {
    node* temp = head;
    cout << "Head -> ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node* reverseKNodes(node* head, int k) {
    if (!head || k == 1) return head;

    node* dummy = new node(0);
    dummy->next = head;
    node* curr = dummy, * nex = dummy, * prev = dummy;
    int count = 0;

    while (curr->next != NULL) {
        curr = curr->next;
        count++;
    }

    while (count >= k) {
        curr = prev->next;
        nex = curr->next;
        for (int i = 1; i < k; i++) {
            curr->next = nex->next;
            nex->next = prev->next;
            prev->next = nex;
            nex = curr->next;
        }
        prev = curr;
        count -= k;
    }
    return dummy->next;
}

int main() {
    node* head = NULL;
    insertnode(head, 1);
    insertnode(head, 2);
    insertnode(head, 3);
    insertnode(head, 4);
    insertnode(head, 5);
    insertnode(head, 6);
    insertnode(head, 7);
    insertnode(head, 8);

    int k = 3;
    cout << "Original List: ";
    traverse(head);

    head = reverseKNodes(head, 2);
    cout << "Reversed List in groups of " << k << ": ";
    traverse(head);

    return 0;
}
