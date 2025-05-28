// write the cpp program to count subsets with xor k
#include <iostream>
using namespace std;

int countSubsets(int arr[], int n, int index, int currXor, int k)
{
    if (index == n)
    {
        return currXor == k ? 1 : 0;
    }

    // include
    int include = countSubsets(arr, n, index + 1, currXor ^ arr[index], k);

    // exclude
    int exclude = countSubsets(arr, n, index + 1, currXor, k);

    return include + exclude;
}


int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 2;

    int result = countSubsets(arr, n, 0, 0, K);
    cout << "Number of subsets with XOR = " << K << " is: " << result << endl;

    return 0;
}