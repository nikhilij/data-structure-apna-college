// wap to heaps stl

//1. MAXHEAP : priority-queue<int,vector<int>>
//2 . MINHEAP : priority-queue<int,vector<int>,greater<int>>



#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // Max Heap
    priority_queue<int, vector<int>> maxHeap;
    maxHeap.push(5);
    maxHeap.push(4);
    maxHeap.push(10);
    maxHeap.push(7);
    maxHeap.push(9);

    cout << "Max Heap: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(5);
    minHeap.push(4);
    minHeap.push(10);
    minHeap.push(7);
    minHeap.push(9);

    cout << "Min Heap: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;
}
