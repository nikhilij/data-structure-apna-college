// write the cpp program to find the median of two sorted array of same size
// this is  tc O(n) and space c of O(1); 
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        double medianOf2(vector<int>& a, vector<int>& b) {
                int n = a.size();
                int i = 0, j = 0, m1 = -1, m2 = -1, count;
                
                for(count = 0; count <= n; count++){
                        if(i == n){
                                m1 = m2;
                                m2 = b[j];
                                j++;
                        }
                        else if(j == n){
                                m1 = m2;
                                m2 = a[i];
                                i++;
                        }
                        else if(a[i] <= b[j]){
                                m1 = m2;
                                m2 = a[i];
                                i++;
                        }
                        else{
                                m1 = m2;
                                m2 = b[j];
                                j++;
                        }
                }
                return (m1 + m2) / 2.0;
        }
};

int main(){
        Solution sol;
        
        vector<int> arr1 = {1, 12, 15, 26, 38};
        vector<int> arr2 = {2, 13, 17, 30, 45};
        
        cout << "Array 1: ";
        for(int x : arr1) cout << x << " ";
        cout << endl;
        
        cout << "Array 2: ";
        for(int x : arr2) cout << x << " ";
        cout << endl;
        
        double median = sol.medianOf2(arr1, arr2);
        cout << "Median of two sorted arrays: " << median << endl;
        
        return 0;
}