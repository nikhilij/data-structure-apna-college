// Find two non-repeating elements
// In an array where every element appears twice except two.

#include <iostream>
using namespace std;

void findTwoNonRepeating(int arr[], int n)
{
    int xor1 = 0;
    for (int i = 0; i < n; i++)
    {
        xor1 ^= arr[i];
    }

    //xor1 now contains the XOR of the two non-repeating elements

    int setBit = xor1 & -xor1;

    int num1 = 0, num2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & setBit)
        {
            num1 ^= arr[i];
            cout<<"num1: " << num1 << endl;
        }
        else
        {
            num2 ^= arr[i];
            cout<<"num2: " << num2 << endl;
        }
    }

    cout << "The two non-repeating elements are: " << num1 << " and " << num2 << endl;
}

int main()
{
    int arr[] = {4, 5, 6, 7, 4, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    findTwoNonRepeating(arr, n);
    return 0;
}
