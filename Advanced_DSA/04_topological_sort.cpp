// Topological Sort - DFS (stack) + Kahn's Algorithm (BFS/indegree)
#include <bits/stdc++.h>
using namespace std;

// Method 1: DFS-based
void dfsTopoHelper(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v]) dfsTopoHelper(v, adj, visited, st);
    st.push(u);
}

void topoSortDFS(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    stack<int> st;
    for (int i = 0; i < V; i++)
        if (!visited[i]) dfsTopoHelper(i, adj, visited, st);
    cout << "Topo (DFS): ";
    while (!st.empty()) { cout << st.top() << " "; st.pop(); }
    cout << "\n";
}

// Method 2: Kahn's Algorithm (BFS)
void topoSortKahn(int V, vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);
    for (int u = 0; u < V; u++)
        for (int v : adj[u]) indegree[v]++;

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0) q.push(i);

    cout << "Topo (Kahn): ";
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : adj[u])
            if (--indegree[v] == 0) q.push(v);
    }
    cout << "\n";
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    adj[5].push_back(2); adj[5].push_back(0);
    adj[4].push_back(0); adj[4].push_back(1);
    adj[2].push_back(3); adj[3].push_back(1);

    topoSortDFS(V, adj);
    topoSortKahn(V, adj);
}
