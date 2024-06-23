// video number 8.4 array apna college
// question is for record breaking 
// the i th element should be greater than its neighbour
// the code below is optimised approach

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;


    int a[n+1];
    a[n]=-1;


    for(int i = 0 ; i<n;i++){
        cin>> a[i];
    }

    if(n==1){
        return 0;
    }

    int ans=0;
    int mx=-1;

    for(int i = 0; i<n;i++){
        if(a[i]>mx && a[i]>a[i+1]){
            ans++;
        }
        mx=max(ans,a[i]);
    }
    cout<<ans<<endl;

    return 0;

}