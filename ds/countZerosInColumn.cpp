// write the cpp program to find the column which have maximum zeros in the matrix

#include<iostream>
#include<vector>
using namespace std;

int findMaxZeros(vector<vector<int>>arr,int n){
    int max_zeros=0,max_col=-1;
    for(int j=0;j<arr.size();j++){
        int cnt_z=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i][j]==0){
                cnt_z++;
            }
        }
        if(cnt_z>max_zeros){
            max_zeros=cnt_z;
            max_col=j;
        }
    }
    return max_zeros==0?-1:max_col;
}

int main(){
    vector<vector<int>> matrix = {
        {1, 0, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 1}
    };
    int n = matrix.size();
    int col = findMaxZeros(matrix, n);
    if (col != -1) {
        cout << "The column with the maximum number of zeros is: " << col << endl;
    } else {
        cout << "No column contains zeros." << endl;
    }
}