//
#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &a, int key)
{
    int left = 0;
    int right = a.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        if (a[left] <= a[mid])
        {
            if (key < a[left] || key > a[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        else
        {
            if (key > a[mid] || a[mid] < a[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    cout << find(a, 3) << endl;
    return 0;
}