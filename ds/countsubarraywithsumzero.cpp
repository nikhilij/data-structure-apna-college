// wap to count number of subarrays with sum is zero

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int countsubarray(vector<int>& arr){
    int n=arr.size();
    unordered_map<int,int> prefixSum;
    prefixSum[0]=1;
    int sum=0;
    int count=0;

    for(int i=0;i<n;i++){

        sum+=arr[i];

        if(prefixSum.find(sum)!=prefixSum.end()){
            count+=prefixSum[sum];
        }

        prefixSum[sum]++;

    }

    return count;

}


int main(){
    vector<int> array={0, -1, 1, 2, -2, 3, -3}; // answer is 10

    int result = countsubarray(array);

    cout<<result;

}