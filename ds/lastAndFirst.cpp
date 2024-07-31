#include<iostream>
using namespace std;


int firstoc(int a[],int n,int key,int i=0){
    if(i==n){
        return -1;
    }
    if(a[i]==key){
        return i;
    }

    return firstoc(a,n,key,i+1);

}

int lastoc(int a[],int n,int key,int i=0){

    if(i==n){
        return -1;
    }
    int restarr=lastoc(a,n,key,i+1);

    if(restarr!=-1){
        return restarr;
    }
    if(a[i]==key){
        return i;
    }
    return -1;
}

void checkoccr(int a[], int n, int key){
    cout<<firstoc(a,n,key)<<" ";
    cout<<lastoc(a,n,key);

}

int main(){
    int n;
    cin>>n;
    int a[n];


    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    checkoccr(a,n,key);
    return 0;
}