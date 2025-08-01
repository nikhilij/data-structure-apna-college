// write the cpp program to generate all the subsets of a given array using recursion

#include<iostream>
#include<vector>
using namespace std;

void generateSubsets(int index, vector<int>&curr, vector<vector<int>>&result,vector<int>&arr){
    if(index==arr.size()){
        result.push_back(curr);
        return;
    }
    //exclude the curr number
    generateSubsets(index+1,curr,result,arr);
    curr.push_back(arr[index]);
    generateSubsets(index+1,curr,result,arr);

    curr.pop_back();
}

int main(){
    vector<int> arr = {1,2,3};

    vector<vector<int>> result;
    vector<int> curr;

    generateSubsets(0,curr,result,arr);

    for(auto numlist : result){
        for(int n:numlist){
            cout<<n<<" ";
        }
        cout<<endl;
    }
}
