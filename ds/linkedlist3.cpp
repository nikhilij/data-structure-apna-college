// wap to detect cycle in a linkedlist
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

void traverse(node* head){
    node* temp=head;
    cout<<"Head -> ";
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

bool detectcycle(node* head){
    node* slow=head;
    node* fast=head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(fast==slow){
            cout<<"A cycle has been detected in the linked list"<<endl;
            return true;
        }
    }
    cout<<"Cycle not detected"<<endl;
    return false;
}


void makecycle(node* &head,int pos){
    node* temp=head;
    node* startnode;
    int count=1;

    while(temp->next!=NULL){
        if(count==pos){
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}

//to remove cycle from the linked list

void removecycle(node* &head){
    node* slow=head;
    node* fast=head;

    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);


    fast=head;
    while(fast->next!=slow->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
    cout<<"removed successfully"<<endl;
}

int main(){
    node* head=NULL;
    insertnode(head,1);
    insertnode(head,2);
    insertnode(head,3);
    insertnode(head,4);
    insertnode(head,5);
    insertnode(head,6);
    traverse(head);
    makecycle(head,4);
    cout<<detectcycle(head)<<endl;
    removecycle(head);
    cout<<detectcycle(head)<<endl;
}