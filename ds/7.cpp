// write a program to multiply two matrix 
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n1,n2,n3,n4;
    cout<<"Enter row and column of first matrix : ";

    cin>>n1>>n2;

    cout<<"Enter row and column  of second matrix: ";
    cin>>n3>>n4;

    if(n2!=n3){
        cout<<"mulitplication not possible ";
        return 0;
    }


    // declaring the matrices

    int m1[n1][n2];
    int m2[n3][n4];

    // now take input from the user for both matrix

    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            cin>>m1[i][j];
        }
    }
    for(int i=0;i<n3;i++){
        for(int j=0;j<n4;j++){
            cin>>m2[i][j];
        }
    }

    // now we have taken input 
    
    int ans[n1][n4]={0};

    for(int i=0;i<n1;i++){
        for(int j=0;j<n4;j++){
            ans[i][j]=0;
        }
    }

    for(int i=0;i<n1;i++){
        for(int j=0;j<n4;j++){
            for(int k=0;k<n2;k++){
                ans[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }

    // now output 

    for(int i=0;i<n1;i++){
        for(int j=0;j<n4;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }



    return 0;
}   