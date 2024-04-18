#include <iostream>
#include <vector>

using namespace std;

enum class State { UNVISITED, VISITING, VISITED };

bool hasCycleDFS(int u, const vector<vector<int>>& graph, vector<State>& state) {
    state[u] = State::VISITING; // Mark current vertex as visiting

    for (int v : graph[u]) {
        if (state[v] == State::VISITING) {
            return true; // Detected a back edge, indicating a cycle
        } else if (state[v] == State::UNVISITED && hasCycleDFS(v, graph, state)) {
            return true; // Recursive call found a cycle
        }
    }

    state[u] = State::VISITED; // Mark current vertex as visited
    return false;
}

bool hasCycle(const vector<vector<int>>& graph) {
    int n = graph.size(); // Number of vertices in the graph
    vector<State> state(n, State::UNVISITED); // Array to track state of each vertex

    // Perform DFS from each vertex
    for (int u = 0; u < n; ++u) {
        if (state[u] == State::UNVISITED && hasCycleDFS(u, graph, state)) {
            return true; // If cycle detected, return true
        }
    }

    return false; // No cycle found
}

int main() {
    // Example graph represented using adjacency list
    vector<vector<int>> graph = {
        {1},     // Vertex 0 is connected to vertex 1
        {2},     // Vertex 1 is connected to vertex 2
        {0, 3},  // Vertex 2 is connected to vertices 0 and 3
        {4},     // Vertex 3 is connected to vertex 4
        {2}      // Vertex 4 is connected to vertex 2
    };

    // Check if the graph contains a cycle
    if (hasCycle(graph)) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }

    return 0;
}
