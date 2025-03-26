// write the cpp program to get all the paris whoose sum is == 0 
// i!=j and arr[i]+arr[j]==0 

#include<bits/stdc++.h>
using namespace std;


void findUniquePairWithSumZero(vector<int>& arr, vector<vector<int>>& res){
    int left = 0;
    int right = arr.size()-1;
    while(left<right){
        if(arr[left]+arr[right]==0){
            res.push_back({arr[left],arr[right]});
            while(left<right && arr[left]==arr[left+1]){
                left++;
            }
    
            while(left<right && arr[right]==arr[right-1]){
                right--;
            }
            left++; right--;
        }
        // skip duplicates
        else if (arr[left]+arr[right]<0){
            left++;
        }
        else{
            right--;
        }
    }
}

int main(){
    vector<int> arr =  {-1, 0, 1, 2, -1, -4};

    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    findUniquePairWithSumZero(arr, res);
    for(auto x:res){
        cout<<"{"<<x[0]<<", "<<x[1]<<"}"<<endl;
    }
}