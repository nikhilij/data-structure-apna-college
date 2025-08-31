// allocate minimum pages 
// n- number of pages in n different books
// m- number of students 
// all the books have to be divided among m students, consecutively. Allocate the pages in such a way that maximum pages allocated to a student is minimum

#include<iostream>
#include<algorithm>
using namespace std;

bool isfeasible(int a[],int n,int k,int size){
    int st=1;
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum+a[i]>size){
            st++;
            sum=a[i];
        }else{
            sum+=a[i];
        }
    }
    return st<=k;
}

int findmaxpages(int a[],int n,int k){
    int min= *max_element(a,a+n);
    int max=0;
    for(int i=0;i<n;i++){
        max+=a[i];
    }
    int low=min;
    int high=max;
    int res=low;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(isfeasible(a,n,k,mid)){
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return res;

}

int main(){
    int a[]={6, 7, 9, 11, 13, 15};

    cout<<findmaxpages(a,4,4);
    
}