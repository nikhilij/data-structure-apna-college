// wap to 
// Given is an array with n elements that represents n positions along a straight line. Find k elements such that the minimum distance between any 2 elements is the maximum
// this is same as aggressive cows

#include<iostream>
#include<algorithm>
using namespace std;

bool isfeasible(int pos[],int n,int k,int dist){
    int c=1;
    int lastplaced=pos[0];
    for(int i=1;i<n;i++){
        if(pos[i]-lastplaced>=dist){
            c++;
            lastplaced=pos[i];
            if(c==k){
                return true;
            }
        }
    }
    return false;
}


int maxMinDist(int pos[],int n,int k){
    sort(pos,pos+n);
    int low=0;
    int high=pos[n-1]-pos[0];
    int res=0;

    while(low<=high){
        int mid=low+(high-low)/2;
        if(isfeasible(pos,n,k,mid)){
            res=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return res;
}


int main(){
    int a[]={6, 7,  9, 11, 13, 15};

    cout<<maxMinDist(a,5,4);

}