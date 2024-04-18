#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

// Recursive function to calculate power
long long power_recursive(int base, int exponent) {
    if (exponent == 0)
        return 1;
    else
        return base * power_recursive(base, exponent - 1);
}

// Iterative function to calculate power
long long power_iterative(int base, int exponent) {
    long long result = 1;
    while (exponent > 1) {
       base*=2;
       exponent-=1;
    }
    result=base;
    cout<<result;
    return result;
}

int main() {
    int base = 2; // Fix base as 2

    // Generate and print powers from 1 to 5
    for (int exponent = 30000; exponent <= 50000; exponent+=1000) {
        auto start_recursive = high_resolution_clock::now();
        long long result_recursive = power_recursive(base, exponent);
        auto stop_recursive = high_resolution_clock::now();

        auto start_iterative = high_resolution_clock::now();
        long long result_iterative = power_iterative(base, exponent);
        auto stop_iterative = high_resolution_clock::now();

        auto duration_recursive = duration_cast<nanoseconds>(stop_recursive - start_recursive);
        auto duration_iterative = duration_cast<nanoseconds>(stop_iterative - start_iterative);

        cout << "Base: " << base << ", Exponent: " << exponent << endl;
        cout << "Recursive Power: " << result_recursive << ", Time: " << duration_recursive.count() << " nanoseconds" << endl;
        cout << "Iterative Power: " << result_iterative << ", Time: " << duration_iterative.count() << " nanoseconds" << endl;
        cout << endl;
    }

    return 0;
}
