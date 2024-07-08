// wap to implement stack
#include<iostream>
using namespace std;

#define n 100

class stack{
    int* arr;
    int top;

    public:
    stack(){
        arr=new int[n];
        top=-1;
    }

    bool isFull(){
        // if(top>=n-1){
            // cout<<"Stack Overflow";
            // return true;
        // }
        // else{
            // return false;
        // }

        // the above simplified version is this 
        return top>=n-1;
    }

    bool isEmpty(){
        return top==-1;
    }

    void push(int val){
        if(isFull()){
            cout<<"Stack Overflow "<<endl;
            return;
        }

        arr[++top]=val;
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack Underflow "<<endl;
            return -1;
        }
        return arr[top--];
    }

    int peek(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        return arr[top];
    }

    void display(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return;
        }

        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.display();
    cout<<"Popped Element: "<<st.pop()<<endl;
    st.display();
    cout<<"Top: "<<st.peek()<<endl;
}

