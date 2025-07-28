// write the cpp program to create the queue from scratch using vector

#include<iostream>
#include<vector>
using namespace std;

class Queue {
public:
    
    vector<int> arr;
    int front;

    Queue() {
        front = 0;
    }
    void enqueue(int x) {
        arr.push_back(x);
    }
    int dequeue() {
        if (!isEmpty()) {
            int value = arr[front];
            front++;
            return value;
        } else {
            cout << "Queue Underflow" << endl;
            return -1; // or some error value
        }
    }

    bool isEmpty() {
        return front >= arr.size();
    }

    int getFront() {
        if (!isEmpty()) {
            return arr[front];
        }
        else {
            cout << "Queue is empty" << endl;
            return -1; // or some error value
        }
    }

};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.getFront() << endl; // 10
    cout << q.dequeue() << endl; // 10
    cout << q.getFront() << endl; // 20
    cout << q.dequeue() << endl; // 20
    cout << q.getFront() << endl; // 30
    cout << q.dequeue() << endl; // 30
    cout << q.dequeue() << endl; // Queue Underflow
    return 0;
}