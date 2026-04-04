// Greedy Graph - Prim's MST + Dijkstra
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

// Prim's MST - O((V+E) log V)
int primMST(int V, vector<vector<pii>>& adj) {
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    key[0] = 0;
    pq.push({0, 0});
    int totalCost = 0;
    cout << "Prim's MST edges:\n";
    vector<int> parent(V, -1);

    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        totalCost += w;
        if (parent[u] != -1)
            cout << "  " << parent[u] << " - " << u << " : " << w << "\n";
        for (auto [wt, v] : adj[u]) {
            if (!inMST[v] && wt < key[v]) {
                key[v] = wt;
                parent[v] = u;
                pq.push({wt, v});
            }
        }
    }
    return totalCost;
}

// Dijkstra - O((V+E) log V)
vector<int> dijkstra(int src, int V, vector<vector<pii>>& adj) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [w, v] : adj[u])
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
    }
    return dist;
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);
    auto addEdge = [&](int u, int v, int w) {
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    };
    addEdge(0,1,2); addEdge(0,3,6); addEdge(1,2,3);
    addEdge(1,3,8); addEdge(1,4,5); addEdge(2,4,7); addEdge(3,4,9);

    cout << "MST Cost: " << primMST(V, adj) << "\n\n";

    auto dist = dijkstra(0, V, adj);
    cout << "Dijkstra from 0:\n";
    for (int i = 0; i < V; i++)
        cout << "  to " << i << ": " << dist[i] << "\n";
}
