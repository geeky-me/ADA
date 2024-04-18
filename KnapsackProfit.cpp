// Sorted according to profits
#include<iostream>
#include<chrono>
#include<cstdlib>
#include<algorithm>
using namespace std;
using namespace std::chrono;

struct Item {
    int profit;
    int weight;
};

void KNAPSACK(int n, int max_weight, Item items[]) {
    int given_weight = max_weight;
    int x[n];
    int i;

    for (i = 0; i < n; i++) {
        x[i] = 0;
    }

    // Sort the items based on profits in non-increasing order
    sort(items, items + n, [](const Item& a, const Item& b) {
        return a.profit > b.profit;
    });

    for (i = 0; i < n; i++) {
        if (items[i].weight <= given_weight) {
            x[i] = 1;
            given_weight = given_weight - items[i].weight;
        } else {
            break;
        }
    }

    if (i < n) {
        x[i] = static_cast<double>(given_weight) / items[i].weight;
    }
}

Item* generate_items(int n) {
    Item* items = new Item[n];
    for (int j = 0; j < n; j++) {
        items[j].profit = rand();
        items[j].weight = rand();
    }
    return items;
}

int main() {
    int max_weight = 550000;

    for (int i = 100000; i <= 500000; i += 20000) {
        Item* items = generate_items(i);

        auto start = high_resolution_clock::now();

        for (int m = 1; m <= 10; m++) {
            KNAPSACK(i, max_weight, items);
        }

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start) / 10;

        cout << "(" << i << "," << "\t" << duration.count() << ")," << endl;

        delete[] items;
    }

    return 0;
}