// wap to heapify and heapsort

#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &a,int n, int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left < n && a[left]>a[largest]){
        largest=left;
    }
    if(right < n && a[right]>a[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(a[largest],a[i]);
        heapify(a,n,i);
    }
}

void heapSort(vector<int> &a)
{
    int n=a.size();

    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }

    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

int main(){
    vector<int> a = {12, 11, 13, 5, 6, 7};
    heapSort(a);
    for(auto it : a){
        cout<<it<<" ";
    }
}