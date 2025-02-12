
#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

Node* reverse(Node *head){
    Node* curr=head;
    Node* temp = NULL;
    Node* prev = NULL;
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head=prev;
    return head;
}

void traverse(Node *head)
{

    while (head)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL";
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next= new Node(3);
    head->next->next->next= new Node(4);
    head=reverse(head);
    traverse(head);
}