#include <iostream>
#include <algorithm>
using namespace std;

bool isFeasible(int books[], int n, int m, int curr_min) {
    int studentsRequired = 1;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
        if (books[i] > curr_min) {
            return false;
        }

        if (curr_sum + books[i] > curr_min) {
            studentsRequired++;
            curr_sum = books[i];

            if (studentsRequired > m) {
                return false;
            }
        } else {
            curr_sum += books[i];
        }
    }
    return true;
}

int findPages(int books[], int n, int m) {
    int sum = 0;
    if (n < m) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        sum += books[i];
    }

    int start = *max_element(books, books + n);
    int end = sum;
    int result = INT_MAX;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (isFeasible(books, n, m, mid)) {
            result = min(result, mid);
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return result;
}

int main() {
    int books[] = {6,7,9,11,13,15};
    int n = sizeof(books) / sizeof(books[0]);
    int m = 4; // Number of students
    cout << "The minimum number of pages = " << findPages(books, n, m) << endl;
    return 0;
}
