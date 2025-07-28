// write the cpp program to find the second largest element in an array 
// the array consist of positive integers only and can have duplicates

#include <iostream>
#include <vector>
using namespace std;

int getSecondLargest(vector<int>& arr){
    int first = -1, second = -1;
    for(int i = 0; i< arr.size();i++){
        if(arr[i]>first){
            second = first;
            first = arr[i];
        }else if(first !=arr[i] && arr[i]>second){
            second = arr[i];
        }
    }
    return second;
}
int main(){
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout << "The second largest element is " << getSecondLargest(arr) << endl;
    return 0;
}