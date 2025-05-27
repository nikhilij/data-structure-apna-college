// Check if two numbers differ in exactly one bit

// Check if A ^ B is a power of two.

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int diff = a ^ b;
    // Check if diff is a power of two
    if (diff && !(diff & (diff - 1))) {
        cout << "The two numbers differ in exactly one bit." << endl;
    } else {
        cout << "The two numbers do not differ in exactly one bit." << endl;
    }
    return 0;
}