// write the cpp program to sort the linked list using merge sort

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next = nullptr;
    }
};

Node* merge(Node* left, Node* right){
    if(!left || !right) return nullptr;

    Node* dummy = new Node(0);
    Node* curr=dummy;

    while(left && right){
        if(left->data<right->data){
            curr->next = left;
            left=left->next;
        }else{
            curr->next = right;
            right=right->next;
        }
        curr=curr->next;
    }

    if(left) curr->next=left;
    if(right) curr->next = right;

    return dummy->next;
}


Node* split(Node* head){
    if(head == nullptr || head->next!=nullptr){
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}


Node* mergeSort(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }

    Node* mid = split(head);
    Node* rightH = mid->next;
    mid->next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(rightH);

    return merge(left,right);
}

void insert(Node* head,int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        head=newNode;
    }

    Node* curr = head;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    curr->next = newNode;
}

void traverse(Node* head){
    if(head==nullptr){
        cout<<"List is empty";
        return;
    }
    cout<<"Head -> ";
    while(head){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<"NULL";
}

int main(){
    Node* head = new Node(3);
    insert(head,5);
    insert(head,4);
    insert(head,2);
    insert(head,1);
    head = mergeSort(head);
    traverse(head);
}