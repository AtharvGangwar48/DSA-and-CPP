// Segment Tree - Range Sum Query + Point Update
#include <bits/stdc++.h>
using namespace std;

class SegTree {
    int n;
    vector<int> tree;
public:
    SegTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n-1);
    }

    void build(vector<int>& arr, int node, int l, int r) {
        if (l == r) { tree[node] = arr[l]; return; }
        int mid = (l + r) / 2;
        build(arr, 2*node+1, l, mid);
        build(arr, 2*node+2, mid+1, r);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) { tree[node] = val; return; }
        int mid = (l + r) / 2;
        if (idx <= mid) update(2*node+1, l, mid, idx, val);
        else update(2*node+2, mid+1, r, idx, val);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return query(2*node+1, l, mid, ql, qr) + query(2*node+2, mid+1, r, ql, qr);
    }

    void update(int idx, int val) { update(0, 0, n-1, idx, val); }
    int query(int l, int r) { return query(0, 0, n-1, l, r); }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegTree st(arr);

    cout << "Sum [1,3]: " << st.query(1, 3) << "\n";  // 3+5+7 = 15
    cout << "Sum [0,5]: " << st.query(0, 5) << "\n";  // 36

    st.update(1, 10);  // arr[1] = 10
    cout << "After update arr[1]=10, Sum [1,3]: " << st.query(1, 3) << "\n"; // 22
}
