#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

vector<int> Generate(vector<int>& arr, int i) {
    int j = 0;
    for (j = 0; j < i; j++) {
        arr.push_back(rand());
    }
    return arr;
}

void store(int i, double avg) {
    cout << i << " " << avg << endl;
}

void BinaryS(vector<int>& arr, int i, int e) {
    int begin = 0;
    int end = i - 1;
    int mid;
    while (begin <= end) {
        mid = begin + (end - begin) / 2;
        if (arr[mid] == e) {
            return;
        }
        else if (arr[mid] > e) {
            end = mid - 1;
        }
        else if (arr[mid] < e) {
            begin = mid + 1;
        }
    }
    return;
}

void AC() {
    int i = 0;
    int k = 0;
    double avg = 0;
    vector<int> arr;
    for (i = 10000; i < 200000; i += 5000) {
        arr = Generate(arr, i);
        for (k = 1; k <= 10; k++) {
            clock_t clk = clock();
            BinaryS(arr, i, rand());
            clock_t clk2 = clock();
            avg += (double)(clk2 - clk) / CLOCKS_PER_SEC; // Computing time in seconds
        }
        // avg /= 10; // Computing average time
        store(i, avg);
    }
}

int main() {
    AC();
    return 0;
}
