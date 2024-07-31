// wap to merge sort

#include<iostream>
using namespace std;
void merge(int a[],int s, int mid, int e){
    int n1 = mid-s+1;
    int n2 = e-mid;

    int p[n1],q[n2];
    
    for(int i=0;i<n1;i++){
        p[i]=a[s+i];
    }

    for(int i=0;i<n2;i++){
        q[i]=a[mid+1+i];
    }

    int i=0,j=0,k=s;
    while(i<n1 && j<n2){
        if(p[i]<=q[j]){
            a[k]=p[i];
            i++;
        }
        else{
            a[k]=q[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        a[k]=p[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=q[j];
        j++;
        k++;
    }

}


void mergesort(int a[],int s,int e){
    if(s<e){
        int mid=s+(e-s)/2;
        mergesort(a,s,mid);
        mergesort(a,mid+1,e);

        merge(a,s,mid,e);        
    }

}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    mergesort(a,0,n-1);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    
}