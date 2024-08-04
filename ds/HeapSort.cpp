// //  wap to sort the given array using heap sort method 

// Solution Approach:
// Build a Max-Heap:

// Convert the array into a max-heap. In a max-heap, the parent node is always greater than or equal to the child nodes.
// This can be done by calling the heapify function from the last non-leaf node to the root node.
// Heap Sort:

// Swap the root element (maximum element) with the last element of the heap.
// Reduce the size of the heap by one.
// Call the heapify function on the root node to maintain the max-heap property.
// Repeat the process until the heap size is greater than 1.


#include <iostream>
#include <vector>

using namespace std;

// Function to heapify a subtree rooted with node i which is an index in arr[].
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;    // Initialize largest as root
    int left = 2 * i + 1;    // left = 2*i + 1
    int right = 2 * i + 2;   // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print an array
void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver code
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    cout << "Original array:\n";
    printArray(arr);

    heapSort(arr);

    cout << "Sorted array:\n";
    printArray(arr);
    
    return 0;
}
