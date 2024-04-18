#include<bits/stdc++.h>
#include<chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

void generate_all_subsets(int k, int n, int *arr) {
    if(k == n + 1) {
        for(int i = 0; i < k; i++) {
            cout << arr[i];
        }
        cout << endl;
        return;
    } else {
        arr[k] = 1;
        generate_all_subsets(k + 1, n, arr);

        arr[k] = 0;
        generate_all_subsets(k + 1, n, arr);
    }
}

int main() {
    for(int subset_size = 1; subset_size <= 10000; subset_size = subset_size + 1) {
        int *arr = new int[100000];
        auto start = high_resolution_clock::now();
        for(int m = 1; m <= 10; m++) {
            generate_all_subsets(0, subset_size, arr);
        }
        auto stop = high_resolution_clock::now();
        auto duration = (duration_cast<nanoseconds>(stop - start)) / 10;
        cout << "Subset Size: " << subset_size + 1 << "\t Time taken: " << duration.count() << " nanoseconds" << endl;
        delete[] arr;
    }

    return 0;
}
