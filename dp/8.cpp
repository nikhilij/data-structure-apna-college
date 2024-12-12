#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
    ListNode(int val, ListNode *next)
    {
        this->val = val;
        this->next = next;
    }
    ListNode()
    {
        this->val = 0;
        this->next = NULL;
    }
};

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode* NewHead = reverseList(head->next);
    head->next->next = head; 
    head->next = nullptr;

    return NewHead;
}

void traverseList(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    head = reverseList(head);
    traverseList(head);
}