// write the cpp code to add number list in cpp

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *reverseList(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *temp = NULL;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node *removeLeadingZeros(Node *head)
{
    while (head != NULL && head->data == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    return head;
}

Node *addtwonumberList(Node *num1, Node *num2)
{

    Node *p1 = reverseList(num1);
    Node *p2 = reverseList(num2);

    int carry = 0;
    Node *dummy = new Node(0);
    Node *t = dummy;

    while (p1 != NULL || p2 != NULL || carry)
    {
        int sum = carry;
        if (p1)
        {
            sum += p1->data;
            p1 = p1->next;
        }

        if (p2)
        {
            sum += p2->data;
            p2 = p2->next;
        }

        carry = sum / 10;
        Node *newnode = new Node(sum % 10);
        t->next = newnode;
        t = t->next;
    }
    Node *result = reverseList(dummy->next);
    return removeLeadingZeros(result);
}

void printList(Node *head)
{
    if (head == nullptr)
        return;
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *num1, *num2;
    num1 = new Node(0);
    num1->next = new Node(0);
    num1->next->next = new Node(3);
    num1->next->next->next = new Node(4);
    num1->next->next->next->next = new Node(5);

    num2 = new Node(0);
    num2->next = new Node(6);
    num2->next->next = new Node(7);
    num2->next->next->next = new Node(8);

    Node *sumList = addtwonumberList(num1, num2);

    printList(sumList);
}