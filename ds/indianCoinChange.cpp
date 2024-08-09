// WAP TO FIND THE NUMBER OF DOMINATIONS REQUIRED TO PAY THE AMOUNT USING GREEDY ALGORITHM

#include<iostream>
#include<vector>

using namespace std;

vector<pair<int,int>> find_dominations(int amount){

    int arr[]={2000,500,200,100,50,20,10,5,2,1};
    int n= sizeof(arr)/sizeof(arr[0]);

    vector<pair<int,int>> result;
    for(int i=0;i<n;i++){
        int count=0;
        while(amount >=arr[i]){
            amount -= arr[i];
            count++;
        }
        if(count>0){
            result.push_back(make_pair(arr[i],count));
        }
    }
    return result;
}

int main(){

    int amount = 524;
    vector<pair<int,int>> dom = find_dominations(amount);

    for(const auto&it: dom){
        cout<< it.first << " : "<< it.second << endl;
    }

}