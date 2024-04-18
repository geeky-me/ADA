#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to heapify a subtree rooted with node i which is an index in arr[]
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(vector<int>& arr, int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    // Seed the random number generator
    srand(time(0));

    // Varying input sizes from 100,000 to 500,000
    for (int size = 100000; size <= 500000; size += 100000) {
        // Generate random input
        vector<int> arr(size);
        for (int i = 0; i < size; ++i)
            arr[i] = rand();

        // Record the start time
        clock_t start = clock();

        // Perform heap sort
        heapSort(arr, size);

        // Record the end time
        clock_t end = clock();

        // Calculate the time taken
        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        // Output the time taken
        cout << "Time taken for sorting " << size << " elements: " << time_taken << " seconds\n";
    }

    return 0;
}
