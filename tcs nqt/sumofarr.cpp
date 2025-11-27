// Given an array, we have to find the sum of all the elements in the array.

#include <bits/stdc++.h>
using namespace std;

int sumOfArray(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}

int main() {
    vector<int> numbers = {2, 5, 1, 3, 0, 4};
    int totalSum = sumOfArray(numbers);
    cout << "The sum of all elements in the array is: " << totalSum << endl;
    return 0;
}