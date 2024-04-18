#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

#define INF numeric_limits<int>::max()

// Define a structure for representing edges
struct Edge {
    int to;
    int weight;
};

// Dijkstra's algorithm to find shortest paths from a source vertex to all other vertices
void dijkstra(const vector<vector<Edge>>& graph, int source) {
    int n = graph.size(); // Number of vertices in the graph
    vector<int> dist(n, INF); // Initialize distances from source to all other vertices as infinity
    vector<bool> visited(n, false); // Initialize visited array

    // Priority queue to store vertices with their distances from the source
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0; // Distance from source to itself is 0
    pq.push({0, source}); // Push the source vertex into the priority queue

    while (!pq.empty()) {
        // Extract the vertex with the minimum distance from the priority queue
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue; // Skip if vertex is already visited
        visited[u] = true; // Mark the vertex as visited

        // Traverse all neighbors of vertex u
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // Relaxation step: Update distance if a shorter path is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v}); // Push the updated distance and vertex into the priority queue
            }
        }
    }

    // Print the shortest distances from the source vertex
    cout << "Shortest distances from vertex " << source << " to all other vertices:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Vertex " << i << ": " << (dist[i] == INF ? "INF" : to_string(dist[i])) << endl;
    }
}

int main() {
    // Example graph represented using adjacency list
    vector<vector<Edge>> graph = {
        {{1, 4}, {2, 1}}, // Edges from vertex 0 to vertex 1 with weight 4 and to vertex 2 with weight 1
        {{3, 2}},         // Edge from vertex 1 to vertex 3 with weight 2
        {{1, 1}, {3, 5}}, // Edges from vertex 2 to vertex 1 with weight 1 and to vertex 3 with weight 5
        {{4, 3}},         // Edge from vertex 3 to vertex 4 with weight 3
        {}                // No edges from vertex 4
    };

    int source = 0; // Source vertex

    // Call Dijkstra's algorithm to find shortest paths from the source vertex
    dijkstra(graph, source);

    return 0;
}
