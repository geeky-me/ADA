#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

int* generate_input(int arr[], int k) {
    for (int j = 0; j < k; j++) {
        arr[j] = rand() % 1000;
    }
    return arr;
}

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

int main() {
    int* arr = new int[100000];
    srand(time(NULL));

    for (int i = 1000; i <= 100000; i += 500) {
        arr = generate_input(arr, i);

        auto start = high_resolution_clock::now();
        for (int m = 0; m < 10; m++) {
            selection_sort(arr, i);
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start) / 10;
        cout << "Input Size: " << i << "\t Time taken: " << duration.count() << " nanoseconds" << endl;
    }

    delete[] arr;
    return 0;
}
