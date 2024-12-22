#include <iostream>
#include <limits>
#include <vector>

using namespace std;

double findMedian(vector<int> a, vector<int> b)
{
    if (a.size() > b.size())
    {
        swap(a, b);
    }
    int low = 0;
    int high = a.size();
    int m = a.size();
    int n = b.size();

    while (low <= high)
    {
        int p1 = (low + high) / 2;
        int p2 = (m + n + 1) / 2 - p1;
        // cout<<p1<<p2;
        int l1 = (p1 == 0) ? INT_MIN: a[p1-1];
        int r1 = (p1 == m) ? INT_MAX: a[p1];
        int l2 = (p2 == 0) ? INT_MIN: b[p2-1];
        int r2 = (p2 == n) ? INT_MAX: b[p2];

        if(l1<=r2 && l2<=r1){
            if((m+n)%2==0){
                return (max(l1, l2) + min(r1, r2))/2.0;
            }else{
                return max(l1,l2);
            }
        }
        else if(l2>r1){
            low=p1+1;
        }else{
            high=p1-1;
        }
    }
    return -1;
}

int main()
{
    vector<int> a = {1, 3, 8};
    vector<int> b = {7, 9, 10, 11};
    cout << findMedian(a, b);
}