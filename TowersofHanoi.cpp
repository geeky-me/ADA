#include <iostream>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n >= 1) {
        tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
        cout << "Move disk " << n << " from " << from_rod << " to " << to_rod << endl;
        tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
    }
}

int main() {
    int* arr = new int(100000);
    float a[2][5];

    for (int i = 15; i <= 30; i += 1) {
        auto start = high_resolution_clock::now();
        for (int m = 1; m <= 10; m++) {
            tower_of_hanoi(i, 'A', 'C', 'B');
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start) / 10;
        cout << "Inputs: " << i << "\t Time taken: " << duration.count() << " nanoseconds" << endl;
    }

    delete[] arr;
    return 0;
}
