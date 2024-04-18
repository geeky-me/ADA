#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

int fact(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}

void evaluate(vector<pair<int, int>>& store) {
    for (int i = 1; i <= 40000; i+=500) { // Increased the range of inputs significantly
        int t = 0;
        int avg = 0;
        for (int m = 0; m < 50; m++) { // Increased the number of iterations significantly
            auto start = high_resolution_clock::now();
            fact(i);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            t += duration.count();
        }
        avg = t / 50; // Adjusted averaging for 50 iterations
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
