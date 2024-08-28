// wap to insertion sort in cpp

#include<iostream>
using namespace std;


int main(){
    int a[]={8,4,1,2,9,3};

    int n=6;

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    // insertion sort

    for(int i=1;i<n;i++){
        int j=i-1;
        int key=a[i];
        while(j>=0 and  a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        

    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}