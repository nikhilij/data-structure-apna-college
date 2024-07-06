// wap to learn linkedlist in cpp 

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* Next;

    node(int val){
        data = val;
        Next=NULL;
    }
};

void insertnode(node* &head,int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp = head;
    while(temp->Next!=NULL){
        temp=temp->Next;
    }
    temp->Next=n;
}

void insertathead(node* &head,int val){
    node* n = new node(val);
    n->Next=head;
    head=n;
}

void traverse(node* head){
    node* temp=head;
    cout<<"Head-> ";
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->Next;
    }
    cout<<"NULL";
}

bool search(node* head,int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->Next;
    }
    return false;

}

int main(){
    node* head=NULL;
    insertnode(head,1);
    insertnode(head,2);
    insertnode(head,3);
    insertathead(head,4);
    traverse(head);
    cout<<endl;
    cout<<search(head,4);
}