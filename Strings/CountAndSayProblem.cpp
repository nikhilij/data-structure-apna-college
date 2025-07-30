// write the cpp program to solve the leetcode problem "Count and Say"
/*
38. Count and Say
Medium
Topics
premium lock icon
Companies
Hint
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.

Example 1:

Input: n = 4

Output: "1211"

Explanation:

countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"
Example 2:

Input: n = 1

Output: "1"

Explanation:

This is the base case.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    if (n <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }
    string result = "1";

    for (int i = 1;i < n;i++) {
        string curr = "";
        int count = 1;
        for(int j=1;j<result.size();j++){
            if(result[j]==result[j-1]){
                count++;
            }else{
                curr = curr + to_string(count) + result[j-1];
                count = 1;
            }
        }
        curr = curr + to_string(count) + result.back(); // Handle the last group
        result = curr;
    }
    cout << "The " << n << "th element of the count-and-say sequence is: " << result << endl;
    return 0;
}