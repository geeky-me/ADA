#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <numeric>
// Function to perform partition around a given element
int partition(std::vector<int>& arr, int low, int high, int pivot) {
    // Move pivot to the end
    std::swap(arr[pivot], arr[high]);

    int i = low - 1;

    // Iterate through the array
    for (int j = low; j < high; j++) {
        if (arr[j] <= arr[high]) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    // Move pivot back to its correct position
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform quicksort partitioning
void quicksortPartition(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Choose a random pivot
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(low, high);
        int pivot = dis(gen);

        // Perform partition
        int pivotIndex = partition(arr, low, high, pivot);

        // Recursively partition the two halves
        quicksortPartition(arr, low, pivotIndex - 1);
        quicksortPartition(arr, pivotIndex + 1, high);
    }
}

int main() {
    // Input sizes
    std::vector<int> inputSizes = {1000, 5000, 10000, 50000, 100000};

    for (int size : inputSizes) {
        // Generate a random list
        std::vector<int> arr(size);
        std::iota(arr.begin(), arr.end(), 1);
        std::random_shuffle(arr.begin(), arr.end());

        // Choose a random element n
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, size);
        int n = dis(gen);

        auto start = std::chrono::high_resolution_clock::now();

        // Perform partitioning
        quicksortPartition(arr, 0, size - 1);

        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

        // Output time and input size
        std::cout << "Input Size: " << size << "\tTime taken: " << duration.count() << " microseconds" << std::endl;
    }

    return 0;
}
