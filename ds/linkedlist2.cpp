// deletion in linkedlist using cppp

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

    node*temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    };

    temp->next=n;
}

void traverse(node* head){
    node* temp=head;
    cout<<"Head -> ";
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<" NULL"<<endl;
}


// to delete a node; we have two methods 
// first one is two pointer approach where we use prev and curr as pointer

void deletenode(node* &head,int val){
    node* prev=NULL;
    node* curr=head;

    node* temp = head;
    if(head->data==val){
        temp=head;
        head=head->next;
        delete temp;
        cout<<"Done"<<endl;
        return;
    }

    while(curr!=NULL && curr->data!=val){
        prev=curr;
        curr=curr->next;
    }

    if(curr==NULL){
        cout<<"Value was not found";
        return;
    }

    prev->next=curr->next;
    cout<<"Done"<<endl;
    delete curr;
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
    deletenode(head,1);
    traverse(head);


}