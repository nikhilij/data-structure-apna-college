// write the cpp program to create the stack from scratch

#include<iostream>
using namespace std;

#define MAX 100

class Stack {
    int top;
    int arr[MAX];
public:
    Stack(){
        top = -1;
    }

    bool isFull(){
        return (top == MAX - 1);
    }

    bool isEmpty(){
        return (top == -1);
    }

    void push(int x){
        if(isFull()){
            cout<<"Stack Overflow" << endl;
            return;
        }
        arr[++top] =x;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack Underflow" << endl;
            return -1; // or some error value
        }
        return arr[top--];
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << endl; // 30
    cout << s.pop() << endl; // 20
    cout << s.pop() << endl; // 10
    cout << s.pop() << endl; // Stack Underflow
    return 0;
}