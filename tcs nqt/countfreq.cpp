#include<bits/stdc++.h>
using namespace std;

void frequencyCount(const vector<int>& arr) {
    unordered_map<int, int> freqMap;

    for (int num : arr) {
        freqMap[num]++;
    }

    cout << "Element Frequency Count:" << endl;
    for (const auto& pair : freqMap) {
        cout << "Element: " << pair.first << ", Frequency: " << pair.second << endl;
    }
}

int main() {
    vector<int> numbers = {2, 5, 1, 3, 2, 4, 5, 1, 2};
    frequencyCount(numbers);
    return 0;
}