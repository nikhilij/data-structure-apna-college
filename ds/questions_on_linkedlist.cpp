// wap to put even elements after odd elements in linked list

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
        next = nullptr;
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
    cout << "Head ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    cout << "How many nodes :";
    int n;
    cin >> n;
    int data;
    cout<<"Enter the data: ";
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        insertnode(head,data);
    }

    traverse(head);
}