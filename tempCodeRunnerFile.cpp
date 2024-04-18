#include <iostream>
#include <climits>
using namespace std;

const int V = 7;

int stage(int graph[V][V], int n, int i, int count) {
    count++;
    if (i == n - 1) {
        return count;
    }
    for (int j = 0; j < n; j++) {
        if (graph[i][j] != 0) {
            return stage(graph, n, j, count);
        }
    }
    return count;
}

int find_fun(int j, int graph[V][V], int fcost[], int n) {
    int m;
    int min = INT_MAX;
    for (int i = j + 1; i < n; i++) {
        if (graph[j][i] != 0) {
            if (graph[j][i] + fcost[i] < min) {
                m = i;
                min = graph[j][i] + fcost[i];
            }
        }
    }
    return m;
}

void f_cost(int graph[V][V], int n, int k) {
    int d[100000];
    int fcost[1000000];
    fcost[n - 1] = 0;
    for (int j = n - 2; j >= 0; j--) {
        int r = find_fun(j, graph, fcost, n);
        fcost[j] = graph[j][r] + fcost[r];
        d[j] = r;
    }
    int p[100000];
    p[0] = 0;
    p[k] = n;
    for (int j = 1; j < k; j++) {
        p[j] = d[p[j - 1]];
    }
    cout << "Min Cost: " << fcost[0] << endl;
    cout << "Path: ";
    for (int j = 0; j < k; j++) {
        cout << p[j] << " ";
    }
    cout << endl;
}

int main() {
    int graph[V][V] = {{0, 2, 3, 4, 0, 0, 0},
                       {0, 0, 0, 0, 8, 0, 0},
                       {0, 0, 0, 0, 5, 7, 0},
                       {0, 0, 0, 0, 0, 6, 0},
                       {0, 0, 0, 0, 0, 0, 9},
                       {0, 0, 0, 0, 0, 0, 1},
                       {0, 0, 0, 0, 0, 0, 0}};
    int number = stage(graph, V, 0, 0);
    cout << "Number of Stages: " << number << endl;
    int k = 4;
    f_cost(graph, 7, k);
    return 0;
}
