#include <bits/stdc++.h>
using namespace std;

int palindrome(vector<int> A)
{
    // Write your code here.
    if(A.size() == 1) return 0;

    int left = 0, right = A.size() - 1, c = 0;
    while(left < right){
        if(A[left] == A[right]){
            left++;
            right--;
        }else if(A[left] < A[right]){
            A[left+1] = A[left+1] + A[left];
            left++;
            c++;
        }else{
            A[right-1] += A[right];
            right--;
            c++;
        }
    }
    return c;
}

int main()
{
    // Example usage
    vector<int> arr = {3, 1, 4, 1, 5};
    
    cout << "Original array: ";
    for(int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    
    int operations = palindrome(arr);
    cout << "Number of operations to make palindrome: " << operations << endl;
    
    return 0;
}