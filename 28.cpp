// wap to print the number in decreasing order

#include<iostream>
using namespace std;

void disp(int n){
    if(n==0){
        return;
    }

    cout<<n<<" ";
    disp(n-1);
}

// void incdisp(int n,int i=1){
//     if(i>n){
//         return;
//     }
//     cout<<i<<" ";
//     incdisp(n,i+1);
// }


void incdisp(int n){
    if(n<1){
        return;
    }
    incdisp(n-1);
    cout<<n<<" ";

}

int main(){
    int n;
    cin>>n;

    disp(n);
    cout<<endl;
    incdisp(n);
}