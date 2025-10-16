#include <bits/stdc++.h>
using namespace std;

// Dijkstra’s Algorithm using adjacency list and priority queue
void dijkstra(int V, vector<pair<int, int>> adj[], int source) {
    // Distance array initialized to infinity
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    // Min-heap (priority queue)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source}); // {distance, node}

    while (!pq.empty()) {
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        // Skip if already visited with a smaller distance
        if (distance > dist[node]) continue;

        // Explore neighbors
        for (auto &edge : adj[node]) {
            int adjNode = edge.first;
            int weight = edge.second;

            if (distance + weight < dist[adjNode]) {
                dist[adjNode] = distance + weight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    // Print shortest distances
    cout << "Vertex\tDistance from Source (" << source << ")\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dist[i] << "\n";
}

int main() {
    int V = 5;
    vector<pair<int, int>> adj[V];

    // Create a weighted graph (undirected example)
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 5});
    adj[3].push_back({4, 3});

    int source = 0;
    dijkstra(V, adj, source);

    return 0;
}
