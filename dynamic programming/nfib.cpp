// write the cpp program to find the nth term of the fibonacci series

#include<iostream>
using namespace std;

long long nthterm(int n) {
    if (n == 1 || n == 2) return 1;
    long long a = 1;
    long long b = 1;

    for (int i = 3;i <= n;i++) {
        long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    cout << "Enter the value of n to find nth term of fibonacci series: ";
    int n;
    cin >> n;
    cout << nthterm(n);
}