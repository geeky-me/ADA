#include<bits/stdc++.h>
using namespace std;

#define N 8
#define INF INT_MAX

// Returns shortest distance from 0 to
// N-1 and stores the shortest path.
int shortestDist(int graph[N][N], vector<int>& path) {

    // dist[i] is going to store shortest
    // distance from node i to node N-1.
    int dist[N];
    int parent[N]; // To store parent node in the shortest path

    dist[N-1] = 0;
    parent[N-1] = -1; // No parent for the destination node

    // Calculating shortest path for
    // rest of the nodes
    for (int i = N-2 ; i >= 0 ; i--)
    {
        // Initialize distance from i to
        // destination (N-1)
        dist[i] = INF;
        int min_dist = INF;
        int min_index = -1;

        // Check all nodes of next stages
        // to find shortest distance from
        // i to N-1.
        for (int j = i ; j < N ; j++)
        {
            // Reject if no edge exists
            if (graph[i][j] == INF)
                continue;

            // We apply equation to
            // distance to target through j.
            // and compare with minimum distance
            // so far.
            if (graph[i][j] + dist[j] < dist[i]) {
                dist[i] = graph[i][j] + dist[j];
                parent[i] = j; // Update parent node
            }
        }
    }

    // Constructing the shortest path
    int current = 0; // Start from the source node
    path.push_back(current);
    while (parent[current] != -1) {
        current = parent[current];
        path.push_back(current);
    }

    // Return the distance from source to destination
    return dist[0];
}

// Driver code
int main()
{
    // Graph stored in the form of an
    // adjacency Matrix
    int graph[N][N] =
    {{INF, 1, 2, 5, INF, INF, INF, INF},
     {INF, INF, INF, INF, 4, 11, INF, INF},
     {INF, INF, INF, INF, 9, 5, 16, INF},
     {INF, INF, INF, INF, INF, INF, 2, INF},
     {INF, INF, INF, INF, INF, INF, INF, 18},
     {INF, INF, INF, INF, INF, INF, INF, 13},
     {INF, INF, INF, INF, INF, INF, INF, 2},
     {INF, INF, INF, INF, INF, INF, INF, INF}};

    vector<int> path;
    int shortest_distance = shortestDist(graph, path);
    
    // Print the shortest path
    cout << "Shortest Path: ";
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i];
        if (i != 0) cout << " -> ";
    }
    cout << endl;

    // Print the shortest distance
    cout << "Shortest Distance: " << shortest_distance << endl;

    return 0;
}
