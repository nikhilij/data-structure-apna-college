// write the cpp program to find whether any subset available whose xor is equal to k

#include <iostream>
#include <vector>
using namespace std;

bool subsetXOR(int arr[], int n, int index, int currXOR, int k)
{
    if (index == n)
    {
        return currXOR == k;
    }

    // include the element
    if(subsetXOR(arr,n,index+1,currXOR^arr[index],k)){
        return true;
    }
    // exclude the element
    if(subsetXOR(arr,n,index+1,currXOR,k)){
        return true;
    }
    return false;
}


int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 2;

    if (subsetXOR(arr, n, 0, 0, K))
    {
        cout << "Yes, a subset with XOR = " << K << " exists!" << endl;
    }
    else
    {
        cout << "No, such a subset does not exist." << endl;
    }

    return 0;
}