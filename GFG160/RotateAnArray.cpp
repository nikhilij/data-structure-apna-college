// write the cpp program to rotate an array by d positions 
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

void rotate(vector<int>& arr, int d) {
    d = d % arr.size();  // In case d >= n
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}
int main() {
    vector<int> arr = { 1, 2, 3, 4, 5 };
    rotate(arr, 2);
    cout << "Array after rotation: ";

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}