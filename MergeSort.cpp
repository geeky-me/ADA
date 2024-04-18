#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

// Merge two sorted subarrays [left, mid] and [mid+1, right]
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
        arr[k++] = L[i++];

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
        arr[k++] = R[j++];
}

// Merge sort function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    // Input sizes from 1000 to 15000
    for (int size = 1000; size <= 15000; size += 3000) {
        // Create a vector of size 'size' with random values
        vector<int> arr(size);
        for (int i = 0; i < size; ++i)
            arr[i] = rand() % 1000; // Random values between 0 to 999

        // Measure the time taken for sorting
        auto start = high_resolution_clock::now();
        mergeSort(arr, 0, size - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);

        // Output the input size and time taken
        cout  << size << "\tTime taken: " << duration.count() << " nanoseconds" << endl;
    }

    return 0;
}
