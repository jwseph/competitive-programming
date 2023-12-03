#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

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

int N, M;
queue<pair<int, int>> Q;
tuple<int, int, int> E[MAXN];
DSU dsu(MAXN);

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int j; cin >> j; --j;
        Q.push({i, j});
    }
    for (int e = 0; e < M; ++e) {
        int i, j, h; cin >> i >> j >> h; --i; --j;
        E[e] = {h, i, j};
    }
    sort(rbegin(E), rend(E));
    int res = -1;
    for (auto [h, i, j]: E) {
        while (Q.size() && dsu.find(Q.front().first) == dsu.find(Q.front().second)) {
            Q.pop();
        }
        if (!Q.size()) break;
        res = h;
        dsu.unite(i, j);
    }
    cout << res << endl;
}