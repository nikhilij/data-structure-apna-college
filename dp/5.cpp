class Solution
{
public:
    void findLast(vector<int> arr, int x)
    {
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int mid = right - (left + right) / 2;
            if (arr[mid] == x)
                return mid;
            if (arr[mid] <= x)
                left++;
            if (arr[mid] > x){
                right--;
        }
    }
    }
    vector<int> find(vector<int> arr, int x)
    {
        // code here
        // for log n as tc we need to implement
        // binary search for this
    }
};
