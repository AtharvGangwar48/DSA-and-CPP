// Dijkstra's Shortest Path Algorithm
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

vector<int> dijkstra(int src, int V, vector<vector<pii>>& adj) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [w, v] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);
    // {weight, neighbor}
    adj[0].push_back({4, 1}); adj[0].push_back({1, 2});
    adj[1].push_back({1, 3});
    adj[2].push_back({2, 1}); adj[2].push_back({5, 3});
    adj[3].push_back({3, 4});
    adj[4].push_back({2, 0});

    vector<int> dist = dijkstra(0, V, adj);
    cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < V; i++)
        cout << "  to " << i << ": " << dist[i] << "\n";
}
