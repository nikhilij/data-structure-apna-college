#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// Utility to print the list
void traverse(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Get tail of the linked list
Node *findTail(Node *head)
{
    while (head && head->next)
    {
        head = head->next;
    }
    return head;
}

// Partition the list
Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd)
{
    Node *pivot = end;
    Node *curr = head;

    Node *l1 = nullptr, *l2 = nullptr;
    Node *l1tail = nullptr, *l2tail = nullptr;

    while (curr != pivot)
    {
        Node *temp = curr->next;
        curr->next = nullptr;

        if (curr->data < pivot->data)
        {
            if (!l1)
                l1 = l1tail = curr;
            else
                l1tail = l1tail->next = curr;
        }
        else
        {
            if (!l2)
                l2 = l2tail = curr;
            else
                l2tail = l2tail->next = curr;
        }
        curr = temp;
    }

    if (l1)
    {
        *newHead = l1;
        l1tail->next = pivot;
    }
    else
    {
        *newHead = pivot;
    }

    pivot->next = l2;
    *newEnd = l2 ? l2tail : pivot;

    return pivot;
}

// Recursive quicksort
Node *quickSortRecur(Node *head, Node *end)
{
    if (!head || head == end)
        return head;

    Node *newHead = nullptr, *newEnd = nullptr;

    Node *pivot = partition(head, end, &newHead, &newEnd);

    // Sort the list before pivot
    if (newHead != pivot)
    {
        Node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = nullptr;

        newHead = quickSortRecur(newHead, tmp);
        findTail(newHead)->next = pivot;
    }

    // Sort the list after pivot
    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

// Wrapper for quicksort
Node *quickSort(Node *head)
{
    return quickSortRecur(head, findTail(head));
}

// Insert node at the end (handles nullptr head)
void insert(Node *&head, int val)
{
    Node *newnode = new Node(val);
    if (!head)
    {
        head = newnode;
        return;
    }
    Node *curr = head;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = newnode;
}

int main()
{
    Node *head = new Node(2); // Initialize head

    // Insert more nodes
    insert(head, 1);
    insert(head, 30);
    insert(head, 3);
    insert(head, 4);
    insert(head, 20);
    insert(head, 5);

    cout << "Before sorting:\n";
    traverse(head);

    head = quickSort(head);

    cout << "After sorting:\n";
    traverse(head);

    return 0;
}
