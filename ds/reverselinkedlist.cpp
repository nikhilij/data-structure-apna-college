//wap to reverselinked list in cpp

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertnode(node* &head,int val){
    node* n = new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void reverselist(node* &head){
    if(head==NULL){
        cout<<"An Empty list";
        return;
    }
    node*prev=NULL;
    node*curr=head;
    node*temp=head;

    
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }

    head=prev;

}

// reversing a list using recursive method

node* reverse(node* head){
    if(head == NULL || head->next==NULL){
        return head;
    }
    node*rest=reverse(head->next);
    head->next->next=head;
    head->next=NULL;

    return rest;
}


void traverse(node* head){
    node* temp=head;
    cout<<"Head -> ";
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}


int main(){
    node* head=NULL;
    insertnode(head,1);
    insertnode(head,2);
    insertnode(head,3);
    insertnode(head,4);
    traverse(head);
    head=reverse(head);
    traverse(head);
}