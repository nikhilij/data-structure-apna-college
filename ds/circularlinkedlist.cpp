//wap to learn circular linked list in cpp 
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
        n->next=n;
        return;
    }

    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}

void insertnodeAtHead(node* &head,int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        n->next=n;
        return;
    }

    node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }

    temp->next=n;
    n->next=head;
    head=n;
}

void insertatTail(node* &head,int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        n->next=n;
        return;
    }

    node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}

void traverse(node* head){
    node* temp=head;
    cout<<"Head -> ";
    do{
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }while(temp!=head);
    cout<<" Head ";
}


int main(){
    node*head=NULL;
    insertnode(head,1);
    insertnode(head,2);
    insertnode(head,3);
    insertnode(head,4);
    insertnodeAtHead(head,5);
    insertatTail(head,7);
    traverse(head);
}