//wap to find the intersection of two linked list in cpp
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

void insertnode(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        head = n;
        return;
    }

    node* temp = head;
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

    cout<<" NULL "<<endl;
}

void createintersection(node* head1,node* head2,int pos){
    node* temp1=head1;
    while(--pos && temp1!=NULL){
        temp1=temp1->next;
    }
    node*temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}

node* findintersection(node* head1,node* head2){

    if (!head1 || !head2) return NULL;

    node* ptr1=head1;
    node* ptr2=head2;

    while(ptr1!=ptr2){
        ptr1 = (ptr1==NULL)?head1:ptr1->next;
        ptr2 = (ptr2==NULL)?head2:ptr2->next;
    }
    return ptr1;
}



int main(){


    node*head1=NULL,*head2=NULL;
    cout << "Enter the data for linked list 1:" << endl;
    cout<<"How many nodes do you require : ";
    int n1,data;
    cin>>n1;
    cout<<"Enter the data: ";
    for(int i=0;i<n1;i++){
        cin>>data;
        insertnode(head1,data);
    }
    traverse(head1);


    cout<<"Enter the data for linked list 2:"<<endl;
    cout<<"How many node do you require :";
    int n2;
    cin>>n2;
    cout<<"Enter the data: ";
    for(int i=0;i<n2;i++){
        cin>>data;
        insertnode(head2,data);
    }
    traverse(head2);

    int pos;
    cout<<"Enter the position to create intersection :";
    cin>>pos;
    createintersection(head1,head2,pos);

    traverse(head1);
    traverse(head2);

    node* intersectionpoint=findintersection(head1,head2);

    if(intersectionpoint!=NULL){
        cout<<" The intersection point is : "<< intersectionpoint->data<<endl;
    }
    else{
        cout<<"there is not intersection in the linked list"<<endl;
    }



    return 0;
}
