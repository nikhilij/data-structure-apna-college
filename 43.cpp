//wap to count sort

#include<iostream>
#include<algorithm>
using namespace std;

void countsort(int a[],int n){
    int max = *max_element(a,a+n);

    int carray[max + 1]={0};

    for(int i=0;i<n;i++){
        carray[a[i]]++;
    }

    for(int i=1;i<=max;i++){
        carray[i]+=carray[i-1];
    }

    int output[n];

    for(int i=n-1;i>=0;i--){
        output[carray[a[i]]-1]=a[i];
        carray[a[i]]--;
    }

    for(int i=0;i<n;i++){
        a[i]=output[i];
    }
}
int main(){

    int arr[]={1,3,2,3,4,1,6,4,3};
    int n=9;
    countsort(arr,n);
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    return 0;   
}