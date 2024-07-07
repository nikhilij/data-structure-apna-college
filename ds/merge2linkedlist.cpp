// wap to merge two linked list in cpp
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertnode(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void traverse(node *head)
{
    node *temp = head;
    cout << "Head -> ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL"<<endl;
}

node *mergesortedlinkedlist(node *head1, node *head2)
{
    node *ptr1 = head1;
    node *ptr2 = head2;

    // creating a new linked list to merge these two

    node *dummy = new node(0);
    node *tail = dummy;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data <= ptr2->data)
        {
            tail->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            tail->next = ptr2;
            ptr2 = ptr2->next;
        }
        tail = tail->next;
    }

    if (ptr1 != NULL)
    {
        tail->next = ptr1;
    }
    else
    {
        tail->next = ptr2;
    }

    node *mergedHead = dummy->next;
    delete dummy;
    return mergedHead;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    cout << "Enter the data for the linked list 1: "<<endl;
    cout << "How many nodes in linked list 1: ";
    int n1, n2;
    cin >> n1;
    int data;
    cout<<"Enter the data: ";
    for(int i=0;i<n1;i++){
        cin>>data;
        insertnode(head1,data);
    }

    cout << "Enter the data for the linked list 2: "<<endl;
    cout << "How many nodes in linked list 2: ";
    cin >> n2;
    cout<<"Enter the data: ";
    for(int i=0;i<n2;i++){
        cin>>data;
        insertnode(head2,data);
    }

    traverse(head1);
    traverse(head2);

    node* mergedH=mergesortedlinkedlist(head1,head2);

    traverse(mergedH);


}