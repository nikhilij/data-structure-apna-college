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

void deleteNode(node* &head, int pos) {
    if (head == NULL) return; // If the list is empty, nothing to delete

    node* temp = head;

    if (pos == 0) { // Deleting the head node
        temp = head;
        head = head->next;
        if (head != NULL) { // If there's a next node, update its prev pointer
            head->prev = NULL;
        }
        delete temp;
        cout << "Deleted successfully\n";
        return;
    }

    int count = 0;
    while (temp != NULL && count < pos) { // Traverse to the position
        temp = temp->next;
        ++count;
    }

    if (temp == NULL) return; // If the position is out of bounds

    // Update the pointers of the surrounding nodes
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Deleted successfully\n";
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

    deleteNode(head,0);
    traverse(head);
}