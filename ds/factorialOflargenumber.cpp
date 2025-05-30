// write the cpp code for finding the factorial of large number
// Given an integer n, find its factorial. Return a list of integers denoting the digits that make up the factorial of n.
/*
Time Complexity: O(n * k), where k is number of digits in result

Space Complexity: O(k) to store result digits
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> factorial(int n)
{
    vector<int> result;
    result.push_back(1); // Initialize with 1

    for (int i = 2; i <= n; i++)
    {
        int carry = 0;

        // Multiply each digit with current number
        for (int j = 0; j < result.size(); j++)
        {
            int prod = result[j] * i + carry;
            result[j] = prod % 10;
            carry = prod / 10;
        }

        // Add remaining carry digits
        while (carry)
        {
            result.push_back(carry % 10);
            carry = carry / 10;
        }
    }

    // Reverse to get correct order (most significant digit first)
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> result = factorial(n);

    cout << "Factorial of " << n << " is: ";
    for (int digit : result)
    {
        cout << digit;
    }
    cout << endl;

    return 0;
}