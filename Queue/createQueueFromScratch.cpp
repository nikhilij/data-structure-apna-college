// write the cpp program to create the queue from scratch

#include<iostream>
using namespace std;

#define MAX 100
class Queue {
    int front, rear;
    int arr[MAX];
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isFull() {
        return (rear == MAX - 1);
    }
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1) front = 0; // Initialize front if queue is empty
        arr[++rear] = x;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1; // or some error value
        }
        return arr[front++];
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; // or some error value
        }
        return arr[front];
    }
};
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.dequeue() << endl; // 10
    cout << q.dequeue() << endl; // 20
    cout << q.peek() << endl;    // 30
    cout << q.dequeue() << endl; // 30
    cout << q.dequeue() << endl; // Queue Underflow
    return 0;
}
