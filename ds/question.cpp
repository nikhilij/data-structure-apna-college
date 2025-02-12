#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Custom comparator for pair<string, int>
struct CompareStudents {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.first == b.first) {
            return a.second > b.second; // Sort by marks in descending order if names are the same
        }
        return a.first < b.first; // Otherwise, sort by name in ascending order
    }
};

void countStudents(multimap<string, int> &mmp)
{
    // Vector to store the (name, marks) pairs in order of appearance
    vector<pair<string, int>> students(mmp.begin(), mmp.end());

    // Display the vector of students
    for (const auto &student : students)
    {
        cout << student.first << " " << student.second << endl;
    }

    cout << "-------------------------------------------------------" << endl;

    // Sort the students by name and then by marks (descending) using custom comparator
    sort(students.begin(), students.end(), CompareStudents());

    for (const auto &student : students)
    {
        cout << student.first << " " << student.second << endl;
    }

    cout << "-------------------------------------------------------" << endl;

    // Now create a multiset with custom comparator
    multiset<pair<string, int>, CompareStudents> student_count(students.begin(), students.end());

    for (auto it = student_count.begin(); it != student_count.end();)
    {
        auto entry = *it;
        int count = student_count.count(entry);  // Count the occurrences of this element
        cout << entry.first << " " << entry.second << " Count: " << count << endl;
        it = student_count.upper_bound(entry); // Move iterator to the next unique element
    }
}

int main()
{
    multimap<string, int> mmp = {
        {"john", 50},
        {"ankit", 100},
        {"ankit", 100},
        {"john", 60},
        {"ankit", 30}
    };

    countStudents(mmp);

    return 0;
}
