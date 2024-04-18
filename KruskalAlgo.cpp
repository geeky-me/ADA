#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure for representing edges
struct Edge {
    int u;
    int v;
    int weight;
};

// Function to compare edges based on their weights for sorting
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Function to find the parent of a vertex using path compression technique
int findParent(int v, vector<int>& parent) {
    if (parent[v] == -1)
        return v;
    return parent[v] = findParent(parent[v], parent); // Path compression
}

// Function to perform union operation of two sets represented by their roots
void unionSets(int u, int v, vector<int>& parent) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);
    parent[rootV] = rootU; // Union operation
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void kruskal(vector<Edge>& edges, int n) {
    // Sort edges in non-decreasing order of their weights
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(n, -1); // Array to store parents of vertices
    vector<Edge> result; // Stores edges of the MST

    // Iterate through all edges in sorted order
    for (const Edge& edge : edges) {
        int rootU = findParent(edge.u, parent);
        int rootV = findParent(edge.v, parent);

        // If including the current edge does not form a cycle
        if (rootU != rootV) {
            result.push_back(edge); // Add edge to the MST
            unionSets(rootU, rootV, parent); // Merge the sets
        }
    }

    // Print the edges of the minimum spanning tree
    cout << "Edges of the minimum spanning tree:\n";
    for (const Edge& edge : result) {
        cout << "Edge: " << edge.u << " - " << edge.v << " Weight: " << edge.weight << endl;
    }
}

int main() {
    // Example graph represented using edge list
    vector<Edge> edges = {
        {0, 1, 4}, // Edge from vertex 0 to vertex 1 with weight 4
        {0, 2, 1}, // Edge from vertex 0 to vertex 2 with weight 1
        {1, 2, 2}, // Edge from vertex 1 to vertex 2 with weight 2
        {1, 3, 3}, // Edge from vertex 1 to vertex 3 with weight 3
        {2, 3, 5}  // Edge from vertex 2 to vertex 3 with weight 5
    };

    int n = 4; // Number of vertices

    // Call Kruskal's algorithm to find the minimum spanning tree
    kruskal(edges, n);

    return 0;
}
