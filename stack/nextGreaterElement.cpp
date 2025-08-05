// write the cpp program to find the next greater element for the following elements in the given array

/* Given an array arr[ ] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1. */


#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> nextgreater(vector<int> arr){
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n,-1);
    st.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        while(!st.empty() && arr[i]>=st.top()){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}


int main(){
    vector<int> d = {1, 3, 2, 4};
    vector<int> a = {6, 8, 0, 1, 3};
    vector<int> b = {10, 20, 30, 50};
    vector<int> c = {50, 40, 30, 10};

    vector<int> res = nextgreater(c);
    for(int c : res){
        cout<<c<<" ";
    }
    return 0;
}