// wap for numbers are coming and  we have to tell median after each input 


// we take use of maxHeap and minHeap 
// we take the max of maxHeap and min of minHeap
//----------------------------------------------
// now we consider the size if size of maxHeap is > size of minHeap + 1
// we now move the element from maxHeap to minHeap



#include<iostream>
#include<queue>
using namespace std;

void addNumber(int num,priority_queue<int>&maxHeap,priority_queue<int,vector<int>,greater<int>>&minHeap){

    if(maxHeap.empty() || num<=maxHeap.top()){
        maxHeap.push(num);
    }else{
        minHeap.push(num);
    }

    // balance the heaps

    if(maxHeap.size()>minHeap.size()+1){
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else if(minHeap.size()>maxHeap.size()){
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}

double findMedian(priority_queue<int>&maxHeap,priority_queue<int,vector<int>,greater<int>>&minHeap){

    if(maxHeap.size()==minHeap.size()){
        return (maxHeap.top() + minHeap.top())/2.0;
    }
    else{
        return maxHeap.top();
    }
}

int main(){
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;

    int num;
    while(cin>>num){
        addNumber(num,maxHeap,minHeap);
        cout<<"Median after Input "<< num << " is: "<<findMedian(maxHeap,minHeap)<<endl;
    }
    return 0;
}