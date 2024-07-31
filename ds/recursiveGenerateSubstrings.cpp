#include <iostream>
using namespace std;

// Helper function to generate substrings starting from a given index
void generateSubstrings(string s, int start, int end)
{
    // Base case: When start index exceeds end index
    if (start > end)
    {
        return;
    }

    // Print the substring from start to end index
    cout << s.substr(start, end - start + 1) << endl;

    // Recursively generate substrings by incrementing the end index
    generateSubstrings(s, start, end - 1);
}

// Recursive function to initiate substring generation for each start index
void initiateSubstringGeneration(string s, int start)
{
    if (start >= s.length())
    {
        return;
    }

    // Generate substrings starting from 'start' to end of string
    generateSubstrings(s, start, s.length() - 1);

    // Recursively initiate substring generation for next start index
    initiateSubstringGeneration(s, start + 1);
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "All substrings of \"" << s << "\" are:" << endl;
    initiateSubstringGeneration(s, 0);

    return 0;
}
