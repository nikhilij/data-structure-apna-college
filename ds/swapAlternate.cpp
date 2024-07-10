// wap to swap alternate elements 
#include<iostream>
using namespace std;

void swapAlternate(int arr[],int n){
    for(int i=0;i<n;i+=2){
        if(i+1<n){
            swap(arr[i],arr[i+1]);
        }
    }
}

int main(){
    int even[8]={5,2,9,4,7,6,1,0};
    int odd[5]={11,33,9,76,43};
    swapAlternate(even,8);
    for(int i=0;i<8;i++){
        cout<<even[i]<<" ";
    }
    cout<<"\n";
    swapAlternate(odd,5);
    for(int i=0;i<5;i++){
        cout<<odd[i]<<" ";
    }
}