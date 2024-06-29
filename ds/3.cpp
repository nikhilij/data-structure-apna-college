// first repeating element in this



#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    unordered_map<int, int> elementIndexMap;
    int firstRepeatingIndex = -1;

    for(int i = 0; i < n; i++){
        if(elementIndexMap.find(a[i]) != elementIndexMap.end())
        // this means that a[i] found in the map
        // the above if statement will check whether the element is present or not
        // basically if found it will initalize the firstrepeating element with the elementindexmap key 
        {
            if(firstRepeatingIndex == -1 || elementIndexMap[a[i]] < firstRepeatingIndex){
                firstRepeatingIndex = elementIndexMap[a[i]];
            }
        } else {
            elementIndexMap[a[i]] = i;
        }
    }

    if(firstRepeatingIndex != -1){
        cout << "First repeating element: " << a[firstRepeatingIndex] << " at index " << firstRepeatingIndex << endl;
    } else {
        cout << "No repeating elements found" << endl;
    }

    return 0;
}
