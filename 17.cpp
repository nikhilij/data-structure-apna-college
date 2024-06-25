// wap to generate all the subsets of a given set

#include<iostream>
using namespace std;

void subsets(int arr[],int n){
    for(int i=0;i<(1<<n);i++){
        cout<<"{ ";
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<"}"<<endl;

    }
}
int main(){
    int n[3]={1,2,3};
    subsets(n,3);

}