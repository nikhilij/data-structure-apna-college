// write the cpp program to get the maximum XOR of two numbers in a array

#include <iostream>
using namespace std;

struct TrieNode{
    TrieNode * children[2]={nullptr,nullptr};
};

void insert(int n, TrieNode *root){
    TrieNode *curr = root;
    for(int i=31;i>=0;i--){
        int bit =(n>>i)&1;
        if(!curr->children[bit]){
            curr->children[bit] = new TrieNode();
        }
        curr = curr->children[bit];
    }
}

int getMaxXor(int n, TrieNode *root){
    int maxXor = 0;
    for(int i=31;i>=0;i--){
        int bit = (n>>i)&1;
        int opp = 1-bit;
        if(root->children[opp]){
            maxXor = maxXor | (1<<i);
            root = root->children[opp];
        }else{
            root = root->children[bit];
        }
    }
    return maxXor;
}

int findMaxXor(int arr[], int n) {
    TrieNode *root = new TrieNode();
    for (int i = 0; i < n; i++) {
        insert(arr[i], root);
    }

    int maxXor = 0;
    for (int i = 0; i < n; i++) {
        maxXor = max(maxXor, getMaxXor(arr[i], root));
    }
    return maxXor;
}


int main()
{
    int arr [] = {3, 10, 5, 25, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum XOR of two numbers in the array: " << findMaxXor(arr, n) << endl;

    return 0;
}