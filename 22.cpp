// wap to find the gcd of two numbers:

#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;

    int r=1;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }

    // while (a != b) {
    //     if (a > b) {
    //         a = a - b; // Subtract the smaller number from the larger
    //     } else {
    //         b = b - a;
    //     }
    // }
    // another method

    cout<<a;
    

}