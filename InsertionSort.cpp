#include<iostream>
#include<cstdlib>
#include<chrono>
#include<vector>
using namespace std;
using namespace std::chrono;

void insertion_sort(vector<int>& arr, int i, int n) {
    if (i == n) {
        return;
    }
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
        swap(arr[j], arr[j - 1]);
        j--;
    }
    insertion_sort(arr, i + 1, n);
}

void random_generator(vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

void evaluate(vector<pair<int, int>>& store) {
    for (int i = 10; i < 1e4; i += 1000) {
        vector<int> arr(i);
        int t = 0;
        int avg = 0;
        random_generator(arr, i);
        for (int m = 0; m < 10; m++) {
            auto start = high_resolution_clock::now();
            insertion_sort(arr, 0, i);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            t += duration.count();
        }
        avg = t / 10;
        store.push_back({i, avg});
    }
}

int main() {
    vector<pair<int, int>> store;
    evaluate(store);
    cout << "Number of Inputs" << " " << "Time" << endl;
    for (auto i : store) {
        cout << i.first << " " << i.second << endl;
    }
}
