#include <iostream>
#include <vector>
#include <climits>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

pair<int, int> findMaxMin(const vector<int>& arr, int low, int high) {
    if (low == high) {
        // Base case: Only one element in the array
        return {arr[low], arr[low]};
    }

    if (high - low == 1) {
        // Base case: Two elements in the array
        return {min(arr[low], arr[high]), max(arr[low], arr[high])};
    }

    // Divide the array into two halves
    int mid = low + (high - low) / 2;
    pair<int, int> left = findMaxMin(arr, low, mid);
    pair<int, int> right = findMaxMin(arr, mid + 1, high);

    // Compare maximums and minimums of the two halves
    int globalMin = min(left.first, right.first);
    int globalMax = max(left.second, right.second);

    return {globalMin, globalMax};
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

        pair<int, int> result = findMaxMin(arr, 0, size - 1); // Find max and min

        auto stop = high_resolution_clock::now(); // Stop time

        auto duration = duration_cast<microseconds>(stop - start); // Calculate duration in microseconds

        cout << "Size: " << size << ", Time taken: " << duration.count() << " microseconds" << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <climits>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

pair<int, int> findMaxMin(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0) {
        cout << "Array is empty." << endl;
        return {-1, -1};
    }

    int maxNum = INT_MIN; // Initialize maxNum to the smallest possible integer
    int minNum = INT_MAX; // Initialize minNum to the largest possible integer

    for (int i = 0; i < n; ++i) {
        if (arr[i] > maxNum)
            maxNum = arr[i];
        if (arr[i] < minNum)
            minNum = arr[i];
    }

    return {maxNum, minNum};
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

        pair<int, int> result = findMaxMin(arr); // Find max and min

        auto stop = high_resolution_clock::now(); // Stop time

        auto duration = duration_cast<microseconds>(stop - start); // Calculate duration in microseconds

        cout << "Size: " << size << ", Time taken: " << duration.count() << " microseconds" << endl;
    }

    return 0;
}
