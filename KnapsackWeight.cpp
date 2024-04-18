// Sorted according to weights
#include<iostream>
#include<chrono>
#include<cstdlib>
#include<algorithm>
using namespace std;
using namespace std::chrono;

struct Item {
    int weight;
    int profit;
};

void KNAPSACK(int n, int max_weight, int p[], int w[]) {
    int given_weight = max_weight;
    int x[n];
    int i;

    for (i = 0; i < n; i++) {
        x[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (w[i] <= given_weight) {
            x[i] = 1;
            given_weight = given_weight - w[i];
        } else {
            break;
        }
    }

    if (i < n) {
        x[i] = static_cast<double>(given_weight) / w[i];
    }
}

int* generate_numbers(int g) {
    int* arr = new int[g];
    for (int j = 0; j < g; j++) {
        arr[j] = rand();
    }
    return arr;
}

int main() {
    int max_weight = 550000;

    for (int i = 100000; i <= 500000; i += 20000) {
        int* profits = generate_numbers(i);
        int* weights = generate_numbers(i);

        Item* items = new Item[i];
        for (int j = 0; j < i; j++) {
            items[j].weight = weights[j];
            items[j].profit = profits[j];
        }

        sort(items, items + i, [](const Item& a, const Item& b) {
            return a.weight < b.weight;
        });

        auto start = high_resolution_clock::now();

        for (int m = 1; m <= 10; m++) {
            KNAPSACK(i, max_weight, profits, weights);
        }

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start) / 10;

        cout << "(" << i << "," << "\t" << duration.count() << ")," << endl;

        delete[] profits;
        delete[] weights;
        delete[] items;
    }

    return 0;
}