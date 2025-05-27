// write the cpp program to find the unique number in an array where every other number appears three times

#include <iostream>
using namespace std;

int findUnique(int arr[],int n){
    int result = 0;
    for(int i=0;i<32;i++){
        int count =0;
        for(int j=0;j<n;j++){
            if((arr[j]>>i)&1){
                count++;
            }
        }
        if(count %3 != 0){
            result = result | (1 << i);
        }
    }
    return result;
}

int main(){
    int arr[] = {2, 2, 3, 2, 5, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The unique number is: " << findUnique(arr, n) << endl;
    printf("the size of int %d", sizeof(int));
    return 0;
}