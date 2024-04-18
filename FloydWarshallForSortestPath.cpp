#include <iostream>
using namespace std;

#define V 4
#define INF 99999

void printShortestDistances(int dist[][V]);
void floydWarshall(int dist[][V]) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF)) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printShortestDistances(dist);
}

void printShortestDistances(int dist[][V]) {
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 5, 7, INF},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {2, INF, INF, 0}
    };
    floydWarshall(graph);
    return 0;
}
