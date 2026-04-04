// Graph - Adjacency List, BFS, DFS
#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v, bool directed = false) {
        adj[u].push_back(v);
        if (!directed) adj[v].push_back(u);
    }

    void bfs(int src) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[src] = true;
        q.push(src);
        cout << "BFS: ";
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";
            for (int v : adj[u]) {
                if (!visited[v]) { visited[v] = true; q.push(v); }
            }
        }
        cout << "\n";
    }

    void dfsHelper(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";
        for (int v : adj[u])
            if (!visited[v]) dfsHelper(v, visited);
    }

    void dfs(int src) {
        vector<bool> visited(V, false);
        cout << "DFS: ";
        dfsHelper(src, visited);
        cout << "\n";
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1); g.addEdge(0, 2);
    g.addEdge(1, 3); g.addEdge(2, 4);
    g.addEdge(3, 5); g.addEdge(4, 5);

    g.bfs(0);
    g.dfs(0);
}
