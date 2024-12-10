// write a cpp program to construct a min Stack such that we can pop push and retrive the minimum element in O(1) time
#include<iostream>
#include <stack>
using namespace std;

class MinStack{
    public:
    stack<int> st;
    stack<int> minSt;
    MinStack(){

    }

    void push(int val){
        st.push(val);
        if(minSt.empty() || val<=minSt.top()){
            minSt.push(val);
        }
    }
    void pop(){
        if(st.empty()) return;
        if(st.top() == minSt.top()){
            return minSt.pop();
        }
        st.pop();
    }

    int top(){
        return st.top();
    }
    int getMin(){
        return minSt.top();
    }
};

int main() {
    MinStack minStack;
    minStack.push(3);
    minStack.push(5);
    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 3
    minStack.push(2);
    minStack.push(1);
    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 1
    minStack.pop();
    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 2
    minStack.pop();
    cout << "Top element: " << minStack.top() << endl; // Output: 5
    cout << "Minimum element: " << minStack.getMin() << endl; // Output: 3
    return 0;
}