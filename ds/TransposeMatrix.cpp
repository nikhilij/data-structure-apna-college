// write a program to transpose a matrix

#include<bits/stdc++.h>
using namespace std;

int main(){

    int r,c;
    cout<<"Enter row and column: ";
    cin>>r>>c;

    int m[r][c];

    //taking input

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>m[i][j];
        }
    }

    // now transpose it 

    cout<<"Transpose of the matrix: \n";

    for(int i=0;i<r;i++){
        for(int j=i;j<c;j++){
            swap(m[i][j],m[j][i]);
        }
    }

    // printing the matrix

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }


    return 0;
}