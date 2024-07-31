// wap to find the a unique element in an array where all other elements occur thrice

#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }

    int ones=0;
    int twos=0;
    for(int i=0;i<n;i++){
        twos=twos|(ones & a[i]);
        ones = ones ^ a[i];
        int cbit=~(ones & twos);
        ones=ones & cbit;
        twos=twos & cbit;
    }

    cout<<ones;
}