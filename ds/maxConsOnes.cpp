#include<iostream>
using namespace std;

int findMaxConsOnes(int arr[], int n){
    int count = 0;
    int maxCount = 0; // Corrected variable name

    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            count++;
            // Update maxCount if current count is greater
            if(count > maxCount){
                maxCount = count;
            }
        } else {
            // Reset count when encountering 0
            count = 0;
        }
    }
    return maxCount;
}

int main(){
    // Test arrays
    int arr1[] = {0,1,1,1,0,0,1,1,0,0,1,1,1,1};
    int arr2[] = {1,1,1,0,0,0,1,1,1,1,0};
    
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // Output the maximum length of consecutive ones
    cout << "Max consecutive ones in arr1: " << findMaxConsOnes(arr1, size1) << endl;
    cout << "Max consecutive ones in arr2: " << findMaxConsOnes(arr2, size2) << endl;

    return 0;
}
