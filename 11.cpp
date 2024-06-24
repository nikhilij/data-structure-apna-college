/*
Question:

You are given n arrays, each with a variable number of integers. Additionally, there are q queries. Each query consists of two integers, a and b. For each query, you need to output the integer located at index b of the array at index a.

Input:

The first line contains two integers, n and q, representing the number of arrays and the number of queries, respectively.

The next n lines each start with an integer k, followed by k integers. These represent the length of the array followed by the elements of the array.

The following q lines each contain two integers, a and b, indicating the query parameters as described.

Output:

For each query, output a single integer which is the element located at index b of the array located at index a.
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    // Vector to hold the variable-length arrays
    vector<vector<int>> arrays(n);

    // Read each array
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k; // Length of the current array
        arrays[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> arrays[i][j];
        }
    }

    // Process each query
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << arrays[a][b] << endl;
    }

    return 0;
}
