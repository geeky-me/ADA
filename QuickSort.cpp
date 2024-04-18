#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition the array

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

        auto start = high_resolution_clock::now(); // Start time

        quickSort(arr, 0, size - 1); // Perform Quick Sort

        auto stop = high_resolution_clock::now(); // Stop time

        auto duration = duration_cast<milliseconds>(stop - start); // Calculate duration in milliseconds

        cout << "Size: " << size << ", Time taken: " << duration.count() << " milliseconds" << endl;
    }

    return 0;
}
