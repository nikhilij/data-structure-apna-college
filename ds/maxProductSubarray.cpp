// write the cpp program to compute the max product subarray of the given array 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n=arr.size();
        int currMin=arr[0],currMax=arr[0];
        
        int res=arr[0];
        
        for(int i=1;i<n;i++){
            if(arr[i]<0){
                swap(currMin,currMax);
            }
            currMin=min(arr[i],currMin*arr[i]);
            currMax=max(arr[i],currMax*arr[i]);
            
            res = max(res,currMax);
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> arr = {-2,6,-3,-10,0,2};
    cout << "The maximum product subarray is: " << solution.maxProduct(arr) << endl;
    return 0;
}