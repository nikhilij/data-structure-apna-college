#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

int main() {
    vector<int> numbers = {2, 5, 1, 3, 0, 4};
    reverseArray(numbers);
    cout << "Reversed array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}