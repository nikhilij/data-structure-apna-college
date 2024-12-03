#include <vector>
using namespace std;

class Solution
{
public:
    int findLast(vector<int>& arr, int x)
    {
        int temp = -1;
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x) {
                temp = mid;
                left = mid + 1;
            }
            else if (arr[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return temp;
    }
    
    int findFirst(vector<int>& arr, int x)
    {
        int temp = -1;
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x) {
                temp = mid;
                right = mid - 1;
            }
            else if (arr[mid] < x)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return temp;
    }
    
    vector<int> find(vector<int> arr, int x)
    {
        int first = findFirst(arr, x);
        int last = findLast(arr, x);
        
        vector<int> res;
        res.push_back(first);
        res.push_back(last);
        return res;
    }
};