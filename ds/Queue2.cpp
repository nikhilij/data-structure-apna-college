#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* back;

public:
    Queue() {
        front = NULL;
        back = NULL;
    }

    void enqueue(int val) {
        Node* n = new Node(val);
        if (front == NULL) {
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is Empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    int peek() {
        if (front == NULL) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return front->data;
    }

    void display() {
        Node* temp = front;
        cout << "Front -> ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    
    q.dequeue();
    q.display();

    cout << "Front element: " << q.peek() << endl;
    
    return 0;
}
