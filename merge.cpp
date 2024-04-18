#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    // Create temporary arrays to hold the left and right subarrays
    vector<int> L(n1);
    vector<int> R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0; // Initial index of left subarray
    int j = 0; // Initial index of right subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int main() {
    srand(time(0)); // Seed for random number generation

    for (int size = 1000; size <= 10000; size += 1000) {
        vector<int> arr(size);

        // Generate random numbers for the array
        for (int i = 0; i < size; i++) {
            arr[i] = rand() % 1000; // Generate random numbers between 0 and 999
        }

        // Set left and right indices for merge function
        int left = 0;
        int right = size - 1;
        int mid = left + (right - left) / 2;

        auto start = high_resolution_clock::now(); // Start time

        merge(arr, left, mid, right); // Perform merging

        auto stop = high_resolution_clock::now(); // Stop time

        auto duration = duration_cast<milliseconds>(stop - start); // Calculate duration in milliseconds

        cout << "Size: " << size << ", Time taken: " << duration.count() << " milliseconds" << endl;
    }

    return 0;
}
