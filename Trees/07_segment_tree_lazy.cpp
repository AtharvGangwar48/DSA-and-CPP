// Segment Tree - Lazy Propagation (Range Update + Range Query)
#include <bits/stdc++.h>
using namespace std;

class LazySegTree {
    int n;
    vector<long long> tree, lazy;

    void build(vector<int>& arr, int node, int l, int r) {
        if (l == r) { tree[node] = arr[l]; return; }
        int mid = (l + r) / 2;
        build(arr, 2*node, l, mid);
        build(arr, 2*node+1, mid+1, r);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void pushDown(int node, int l, int r) {
        if (lazy[node]) {
            int mid = (l + r) / 2;
            tree[2*node]   += lazy[node] * (mid - l + 1);
            tree[2*node+1] += lazy[node] * (r - mid);
            lazy[2*node]   += lazy[node];
            lazy[2*node+1] += lazy[node];
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            tree[node] += val * (r - l + 1);
            lazy[node] += val;
            return;
        }
        pushDown(node, l, r);
        int mid = (l + r) / 2;
        update(2*node, l, mid, ql, qr, val);
        update(2*node+1, mid+1, r, ql, qr, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        pushDown(node, l, r);
        int mid = (l + r) / 2;
        return query(2*node, l, mid, ql, qr) + query(2*node+1, mid+1, r, ql, qr);
    }

public:
    LazySegTree(vector<int>& arr) {
        n = arr.size();
        tree.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(arr, 1, 0, n-1);
    }

    void update(int l, int r, long long val) { update(1, 0, n-1, l, r, val); }
    long long query(int l, int r) { return query(1, 0, n-1, l, r); }
};

// Range Min Segment Tree (no lazy, point update)
class MinSegTree {
    int n;
    vector<int> tree;
public:
    MinSegTree(vector<int>& arr) {
        n = arr.size();
        tree.assign(4*n, INT_MAX);
        build(arr, 1, 0, n-1);
    }
    void build(vector<int>& arr, int node, int l, int r) {
        if (l == r) { tree[node] = arr[l]; return; }
        int mid = (l+r)/2;
        build(arr, 2*node, l, mid);
        build(arr, 2*node+1, mid+1, r);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) { tree[node] = val; return; }
        int mid = (l+r)/2;
        idx <= mid ? update(2*node, l, mid, idx, val) : update(2*node+1, mid+1, r, idx, val);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return INT_MAX;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l+r)/2;
        return min(query(2*node, l, mid, ql, qr), query(2*node+1, mid+1, r, ql, qr));
    }
    void update(int idx, int val) { update(1, 0, n-1, idx, val); }
    int query(int l, int r) { return query(1, 0, n-1, l, r); }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};

    // Lazy Seg Tree - range add + range sum
    LazySegTree lst(arr);
    cout << "Sum [1,4]: " << lst.query(1, 4) << "\n";   // 3+5+7+9 = 24
    lst.update(1, 3, 10);                                 // add 10 to [1..3]
    cout << "After +10 on [1,3], Sum [1,4]: " << lst.query(1, 4) << "\n"; // 54
    cout << "Sum [0,5]: " << lst.query(0, 5) << "\n";   // 66

    // Min Seg Tree
    MinSegTree mst(arr);
    cout << "\nMin [1,4]: " << mst.query(1, 4) << "\n"; // 3
    mst.update(2, 1);                                     // arr[2] = 1
    cout << "After update arr[2]=1, Min [1,4]: " << mst.query(1, 4) << "\n"; // 1
}
