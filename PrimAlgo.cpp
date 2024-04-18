#include<iostream>
#include<climits>
using namespace std;

const int V = 5;

int find_min_distance(int dist[], bool near[]) {
    int min_index = -1;
    int min_dist = INT_MAX;
    for (int i = 0; i < V; i++) {
        if (!near[i] && dist[i] < min_dist) {
            min_dist = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void prims_algorithm(int graph[V][V]) {
    int t[V - 1][2];
    bool near[V];
    int dist[V];
    int mincost = 0;

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        near[i] = false;
    }

    dist[0] = 0;

    for (int i = 0; i < V; i++) {
        int u = find_min_distance(dist, near);
        near[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !near[v] && graph[u][v] < dist[v]) {
                dist[v] = graph[u][v];
                t[v - 1][0] = u;
                t[v - 1][1] = v;
            }
        }
    }

    for (int i = 0; i < V - 1; i++) {
        cout << t[i][0] << " " << t[i][1] << endl;
        mincost += graph[t[i][0]][t[i][1]];
    }

    cout << "Total cost of Minimum Spanning Tree: " << mincost << endl;
}

int main() {
    int graph[V][V] = { { 0, 2, 0, 6, 0},
                        { 2, 0, 3, 8, 5},
                        { 0, 3, 0, 0, 7},
                        { 6, 8, 0, 0, 9},
                        { 0, 5, 7, 9, 0}};

    prims_algorithm(graph);

    return 0;
}
