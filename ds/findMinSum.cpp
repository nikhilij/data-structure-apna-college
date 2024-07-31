// wao to find the size of minimum sum of subarray for which sum>x

#include <iostream>
using namespace std;

int findMinSumSubarray(int a[], int n, int x)
{
    int ans = n + 1;
    int sum = 0;
    int s = 0, e = 0;

    while (e < n)
    {
        while (sum <= x && e < n)
        {
            sum += a[e++];
        }

        while (sum > x && s < n)
        {
            if (e - s < ans)
            {
                ans = e - s;
            }
            sum -= a[s++];
        }
    }
    return ans;
}

int main()
{
    int a[] = {1, 4, 45, 6, 10, 19};
    int n = 6, x = 51;
    int minLength=findMinSumSubarray(a,n,x);

    (minLength==n+1)?cout<<"No such subarray exists":cout<<minLength<<endl;
}