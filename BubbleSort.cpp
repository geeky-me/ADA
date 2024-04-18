#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
using namespace std;
using namespace std::chrono;

void bubble_sort(vector<int>& arr, int n) {
    if (n <= 1) {
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
    bubble_sort(arr, n - 1);
}

void random_generator(vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

void evaluate(vector<pair<int, int>>& store) {
    for (int i = 1000; i <= 10000; i += 1000) { // Changed the increment value to 1000
        vector<int> arr(i);
        int t = 0;
        int avg = 0;
        random_generator(arr, i);
        for (int m = 0; m < 10; m++) {
            auto start = high_resolution_clock::now();
            bubble_sort(arr, i);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            t += duration.count();
        }
        avg = t / 10;
        store.push_back({ i, avg });
    }
}

int main() {
    vector<pair<int, int>> store;
    evaluate(store);
    for (auto i : store) {
        cout << i.first << " " << i.second << endl;
    }
}
