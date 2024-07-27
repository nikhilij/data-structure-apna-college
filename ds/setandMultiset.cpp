// wap to learn set and multiset in cpp 
// set do not have duplicates in them
// sets are implemented using balanced binary search tree
// sets are are in sorted order
// random access is not possible. that means we cannot access the element at ith index value

// present in #include<Set>

// multisets can contains the duplicates 
// all same as sets
// we can use erase functions 

// insertion deletion and lower and upperbound time complexity is BigO(log n)

#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);

    for(auto i=s.begin();i!=s.end();i++){
        cout<<*i<<" ";
    }
    cout<<endl;
    cout<<s.size();


}