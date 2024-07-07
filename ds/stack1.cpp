// learning stack using array in cpp
// in this i do not used any class for implementaation of stack 

#include<iostream>
using namespace std;

#define MAX 100

int stack[MAX];
int top= -1;

bool isFull(){
    if(top>=MAX-1){
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

void push(int data){
    if(isFull()){
        cout<<"Stack Overflow // stack is full"<<endl;
        return;
    }
    stack[++top]=data;
}

int pop(){
    if(isEmpty()){
        cout<<"Stack Underflow "<<endl;
        return -1;
    }
    return stack[top--];
}

int peek(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
        return -1;
    }
    return stack[top];
}


void display(){
    if(isEmpty()){
        cout<<"Stack is Empty"<<endl;
        return;
    }

    for(int i=top;i>=0;i--){
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display();
    cout<<"Popped element: "<<pop()<<endl;
    display();
    cout<<peek();
}
