#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int* generate_input(int arr[], int k) {
    for (int i = 0; i < k; i++) {
        arr[i] = i + 1;
    }
    return arr;
}

int linear_search(int arr[], int i, int x, int n) {
    if (i == n) {
        return -1;
    }

    if (arr[i] == x) {
        return i;
    } else {
        return linear_search(arr, i + 1, x, n);
    }
}

int main() {
    int *arr = new int[100000];
    for (int i = 1000; i <= 20000; i += 1000) {
        arr = generate_input(arr, i);
        auto start = high_resolution_clock::now();
        for (int m = 1; m <= 10; m++) {
            int b = linear_search(arr, 0, -1, i);
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start) / 10;
        cout << "Array Size: " << i << "\t Average Time taken: " << duration.count() << " microseconds" << endl;
    }
    return 0;
}
