//wap to learn doublylinkedlist in cpp
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};

void insertnode(node* &head,int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }

    node*temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void insertatHead(node* &head,int val){
    node*n = new node(val);

    if(head==NULL){
        head=n;
        return;
    }

    n->next=head;
    n->prev=NULL;
    head=n;

}

void insertatTail(node* &head, int val) {
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
    n->prev = temp; 
}


void traverse(node* head){
    node*temp = head;
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
    insertatHead(head,5);
    insertatTail(head,7);
    traverse(head);
}