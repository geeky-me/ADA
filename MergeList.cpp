#include <iostream>
#include <vector>
#include <numeric>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Function to merge two sorted lists
void merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
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

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    // Input sizes
    vector<int> inputSizes = {100000, 500000, 1000000, 5000000, 10000000};

    for (int size : inputSizes) {
       
            // Generate a sorted list
            vector<int> arr(size);
            iota(arr.begin(), arr.end(), 1);

            // Choose a random index to split the list
            int j = size / 2;

            auto start = high_resolution_clock::now();

            // Merge the two sorted lists
            mergeSort(arr, 0, j - 1);
            mergeSort(arr, j, size - 1);
            merge(arr, 0, j - 1, size - 1);

            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start); // Change to microseconds

            // Output time and input size
            cout << "Input Size: " << size 
                 << "\tTime taken: " << duration.count() << " microseconds" << endl;
        
    }

    return 0;
}
