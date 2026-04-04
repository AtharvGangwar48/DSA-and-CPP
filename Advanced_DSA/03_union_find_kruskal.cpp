// Union-Find (Disjoint Set Union) - Path Compression + Union by Rank
#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rank_;
public:
    DSU(int n) : parent(n), rank_(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank_[px] < rank_[py]) swap(px, py);
        parent[py] = px;
        if (rank_[px] == rank_[py]) rank_[px]++;
        return true;
    }

    bool connected(int x, int y) { return find(x) == find(y); }
};

// Kruskal's MST using DSU
struct Edge { int u, v, w; };

int kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](auto& a, auto& b){ return a.w < b.w; });
    DSU dsu(V);
    int cost = 0;
    cout << "MST Edges:\n";
    for (auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            cout << "  " << e.u << " - " << e.v << " : " << e.w << "\n";
            cost += e.w;
        }
    }
    return cost;
}

int main() {
    DSU dsu(5);
    dsu.unite(0, 1); dsu.unite(1, 2);
    cout << "0 and 2 connected: " << dsu.connected(0, 2) << "\n";
    cout << "0 and 3 connected: " << dsu.connected(0, 3) << "\n";

    vector<Edge> edges = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    int mstCost = kruskalMST(4, edges);
    cout << "MST Cost: " << mstCost << "\n";
}
