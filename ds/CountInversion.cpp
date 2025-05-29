// C++ program to count inversions in an array using merge sort
// An inversion is when i < j but arr[i] > arr[j]
// Time Complexity: O(n log n), Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <algorithm>

class InversionCounter {
private:
    static int merge(std::vector<int>& arr, std::vector<int>& temp, int left, int mid, int right) {
        int i = left, j = mid + 1, k = 0;
        int invCount = 0;
        
        // Merge the two halves while counting inversions
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                // All elements from i to mid are greater than arr[j]
                invCount += (mid - i + 1);
            }
        }
        
        // Copy remaining elements
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        while (j <= right) {
            temp[k++] = arr[j++];
        }
        
        // Copy back the merged elements
        for (i = 0; i <= right; i++) {
            arr[i+left] = temp[i];
        }
        
        return invCount;
    }
    
    static int mergeSort(std::vector<int>& arr, std::vector<int>& temp, int left, int right) {
        int invCount = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            invCount += mergeSort(arr, temp, left, mid);
            invCount += mergeSort(arr, temp, mid + 1, right);
            invCount += merge(arr, temp, left, mid, right);
        }
        return invCount;
    }

public:
    static int countInversions(std::vector<int> arr) {
        int n = arr.size();
        std::vector<int> temp(n);
        return mergeSort(arr, temp, 0, n - 1);
    }
};

void printArray(const std::vector<int>& arr) {
    std::cout << "Array: ";
    for (const int& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Demo arrays
    std::vector<std::vector<int>> testCases = {
        {2, 4, 1, 3, 5},     // Expected: 3 inversions
        {5, 4, 3, 2, 1},     // Expected: 10 inversions (worst case)
        {1, 2, 3, 4, 5},     // Expected: 0 inversions (best case)
        {1, 20, 6, 4, 5},    // Expected: 5 inversions
        {8, 4, 2, 1}         // Expected: 6 inversions
    };
    
    std::cout << "=== Inversion Count Demo ===" << std::endl;
    
    for (size_t i = 0; i < testCases.size(); ++i) {
        std::vector<int> arr = testCases[i];
        printArray(arr);
        
        int invCount = InversionCounter::countInversions(arr);
        std::cout << "Number of inversions: " << invCount << std::endl;
        std::cout << std::string(30, '-') << std::endl;
    }
    
    // Interactive input option
    char choice;
    std::cout << "Do you want to test with custom input? (y/n): ";
    std::cin >> choice;
    
    if (choice == 'y' || choice == 'Y') {
        int n;
        std::cout << "Enter the size of array: ";
        std::cin >> n;
        
        std::vector<int> customArr(n);
        std::cout << "Enter elements: ";
        for (int i = 0; i < n; i++) {
            std::cin >> customArr[i];
        }
        
        printArray(customArr);
        int invCount = InversionCounter::countInversions(customArr);
        std::cout << "Number of inversions: " << invCount << std::endl;
    }
    
    return 0;
}