// wap to learn pairs in cpp

#include<iostream>
#include <iostream>
#include <utility>  // for std::pair
using namespace std;

int main() {
    // Creating a pair
    pair<int, int> p1;
    p1.first = 3;
    p1.second = 2;

    // Initializing a pair directly
    pair<int, string> p2 = make_pair(1, "Hello");

    // Using pairs in an array
    pair<string, int> arr[3];
    arr[0] = make_pair("Alice", 30);
    arr[1] = make_pair("Bob", 25);
    arr[2] = make_pair("Charlie", 35);

    // Printing the pairs
    cout << "Pair p1: (" << p1.first << ", " << p1.second << ")" << endl;
    cout << "Pair p2: (" << p2.first << ", " << p2.second << ")" << endl;

    cout << "Array of pairs:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << arr[i].first << ": " << arr[i].second << endl;
    }

    return 0;
}
