
#include<iostream>
#include<map>
#include <unordered_map>
using namespace std;

int main(){
    map<int,int> m;
    m[8]=2;
    cout<<"Value in map for key 8: " <<m[8] <<endl;

    unordered_map<int,int> um;
    um[8]=3;
    cout<<"Value in unordered_map for key 8 : " << um[8] << endl;

    return 0;
}
