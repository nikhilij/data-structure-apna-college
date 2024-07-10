// wap to implement sliding window maximum problem

#include<iostream>
#include<vector>
#include<deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums,int k){
    deque<int> dq;
    vector<int> result;

    for(int i=0;i<nums.size();i++){
        // remove the elements not within the window
        if(!dq.empty() && dq.front()==i-k){
            dq.pop_front();
        }

        // check whether the previous elements are smaller than the current element,
        // if yes then pop it 
        while(!dq.empty() && nums[dq.back()]<=nums[i]){
            dq.pop_back();
        }

        dq.push_back(i);

        // check and add the maximum element in the result
        if(i>=k-1){
            result.push_back(nums[dq.front()]);
        }

    }

    return result;
}

int main(){

    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int> result=maxSlidingWindow(nums,k);

    for(int num:result){
        cout<<num<<" ";
    }
    cout<<"\n";
}