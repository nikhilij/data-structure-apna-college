// write the cpp program to move all zeros to the end of the array

#include<iostream>
#include<vector>
using namespace std;

void moveAllZerosToEnd(vector<int>& arr){
    int i = -1;
    int j = 0;
    while(j<arr.size()){
        if(arr[j]!=0){
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
}

int main(){
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    moveAllZerosToEnd(arr);
    cout << "Array after moving all zeros to the end: ";
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}


