#include <bits/stdc++.h>
using namespace std;

struct Lift {
    int n, l, timer = 0;
    vector<vector<int>> a, p;
    vector<int> tin, tout, depth;
    Lift(int n): n(n), a(n), tin(n), tout(n), depth(n) {
        l = ceil(log2(n))+1;
        p.resize(n, vector<int>(l, -1));
    }
    void add(int i, int j) { a[i].push_back(j), a[j].push_back(i); }
    void dfs(int i, int d = 0) {
        depth[i] = d;
        tin[i] = ++timer;
        if (p[i][0] < 0) p[i][0] = i;
        for (int k = 1; k < l; ++k) {
            p[i][k] = p[p[i][k-1]][k-1];
        }
        for (int j: a[i]) {
            if (j == p[i][0]) continue;
            p[j][0] = i;
            dfs(j, d+1);
        }
        tout[i] = ++timer;
    }
    bool is_a(int a, int i) {
        return tin[a] <= tin[i] && tout[i] <= tout[a];
    }
    int top_before(int i, int j) {
        for (int k = l-1; k >= 0; --k) {
            if (!is_a(p[i][k], j)) i = p[i][k];
        }
        return i;
    }
    int lca(int i, int j) {
        if (is_a(i, j)) return i;
        if (is_a(j, i)) return j;
        return p[top_before(i, j)][0];
    }
    int dst(int i, int j) {
        int a = lca(i, j);
        return depth[i] + depth[j] - depth[a]*2;
    }
};

const int N = 2e5+5;

int n, nq, pre[N], up[N], E_total = 0;
Lift l(N);

void dfs_pre(int i, int p = -1) {
    for (int j: l.a[i]) {
        if (j == p) continue;
        dfs_pre(j, i);
        pre[i] += pre[j];
    }
}

void dfs_up(int i, int p = -1, int a = -1) {
    if (pre[i]) {
        a = i;
        E_total += p >= 1;
    }
    up[i] = a;
    for (int j: l.a[i]) {
        if (j == p) continue;
        dfs_up(j, i, a);
    }
}

int query(int a, int b) {
    return E_total*2 + l.dst(a, up[a]) + l.dst(b, up[b]) - l.dst(up[a], up[b]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> nq;
    int root = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> pre[i];
        if (pre[i]) root = i;
    }

    for (int e = 1; e <= n-1; ++e) {
        int i, j; cin >> i >> j;
        l.add(i, j);
    }
    l.dfs(root);
    
    dfs_pre(root);
    dfs_up(root);

    while (nq--) {
        int a, b; cin >> a >> b;
        cout << query(a, b) << endl;
    }
}