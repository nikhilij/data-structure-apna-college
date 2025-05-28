// write the cpp program to find the xor of xor of all subset XORs of an array
#include <iostream>
using namespace std;

int xorOfAllSubsetXORs(int arr[], int n)
{
    int totalSubsets = 1 << n;
    int result = 0;

    for (int mask = 0; mask < totalSubsets; mask++)
    {
        int subsetXor = 0;
        cout << "Subset: { ";
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                subsetXor ^= arr[i];
                cout << arr[i] << " ";
            }
        }
        cout << "} -> xor = " << subsetXor << endl;
        result ^= subsetXor;
    }
    return result;
}

// we can also do that using the property of XOR

/* 

int getXorofAllSubsetXors(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    return 0;
}

*/

int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = xorOfAllSubsetXORs(arr, n);
    cout << "XOR of all subset XORs = " << result << endl;
    return 0;
}