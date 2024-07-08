// wap to reverse a stack in cpp 
#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(int x,stack<int> &st){
    if(st.empty()){
        st.push(x);
        return;
    }
    int temp=st.top();
    st.pop();
    insertAtBottom(x,st);
    st.push(temp);
}

void reversestack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int x=st.top();
    st.pop();
    reversestack(st);
    insertAtBottom(x,st);

}

void display(stack<int> &st){
    if(st.empty()){
        return;
    }

    int x=st.top();
    st.pop();
    cout<<x<<" ";
    display(st);
    st.push(x);    
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reversestack(st);

    display(st);

}