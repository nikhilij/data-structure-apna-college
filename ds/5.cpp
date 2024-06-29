#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Printing maximum sum of all subarrays
    // int ans=INT_MIN;

    // for(int i=0;i<n;i++){
    //     int sum=0;
    //     for(int j=i;j<n;j++){
    //         sum+=a[j];
    //         ans=max(ans,sum);
    //     }
    // }
    // another approach to solve this 
    // ---------------------------------

    int mxc=a[0];
    int mxg=a[0];
    for(int i =1;i<n;i++){
        mxc=max(a[i],a[i]+mxc);
        if(mxc>mxg){
            mxg=mxc;
        }
    }

    cout<<mxg;
    return 0;
}
