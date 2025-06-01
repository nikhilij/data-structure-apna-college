// write the cpp program to remove the duplicates from unsorted array 

#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

struct Node{
    int data;
    Node*next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};

Node* removeDuplicates(Node* head){
    unordered_set<int> st;
    Node* curr = head;
    Node* prev = nullptr;
    while(curr!=nullptr){
        if(st.find(curr->data)!=st.end()){
            prev->next = curr->next;
            Node* temp = curr;
            curr=curr->next;
            delete temp;
        }else{
            st.insert(curr->data);
            prev =curr;
            curr=curr->next;
        }
    }
    return head;
}

void insert(Node* head, int val){
    Node* curr=head;
    Node* newNode = new Node(val);
    if(head==nullptr){
        curr->next = newNode;
    }

    while(curr->next!=nullptr){
        curr=curr->next;
    }
    curr->next = newNode;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 2);
    insert(head, 4);
    insert(head, 1);
    insert(head, 5);
    
    cout << "Original list: ";
    printList(head);
    
    head = removeDuplicates(head);
    
    cout << "After removing duplicates: ";
    printList(head);
    
    return 0;
}