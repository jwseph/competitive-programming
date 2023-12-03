#include <bits/stdc++.h>
using namespace std;

#define MAXN 5000

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }
    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void unite(int u, int v) {
        int U = find(u), V = find(v);
        if (U == V) return;
        if (rank[U] > rank[V]) swap(U, V);
        parent[U] = V;
        rank[U] += rank[U] == rank[V];
    }
};

int N, T, A[MAXN], res[MAXN];
vector<tuple<int, bool, int, int>> E;
DSU dsu(MAXN);

int main() {
    cin >> N >> T;
    for (int i = 0; i < N; ++i) A[i] = 1;
    for (int e = 0; e < N-1; ++e) {
        int i, j, w; cin >> i >> j >> w; --i; --j;
        E.push_back({w, 1, i, j});
    }
    for (int t = 0; t < T; ++t) {
        int k, i; cin >> k >> i; --i;
        E.push_back({k, 0, i, t});
    }
    sort(rbegin(E), rend(E));
    for (auto [w, e, i, j]: E) {
        if (!e) {
            res[j] = A[dsu.find(i)]-1;
            continue;
        }
        int tot = A[dsu.find(i)] + A[dsu.find(j)];
        dsu.unite(i, j);
        A[dsu.find(i)] = tot;
    }
    for (int t = 0; t < T; ++t) {
        cout << res[t] << endl;
    }
}