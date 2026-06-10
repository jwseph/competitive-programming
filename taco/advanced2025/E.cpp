#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

struct DSU {
    vector<int> p;
    DSU(int n) { p.assign(n, -1); }
    int size(int i) { return -p[find(i)]; }
    int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
    int unite(int i, int j) {
        i = find(i), j = find(j);
        if (i == j) return i;
        if (p[i] > p[j]) swap(i, j);
        p[i] += p[j], p[j] = i;
        return i;
    }
};

int n, m, k;
int used[200005];
int selfloop[200005]{};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    vector<pii> edges;
    for (int e = 0; e < m; ++e) {
        int u, v; cin >> u >> v;
        edges.push_back({u, v});
        used[e] = 1;
    }
    // cout << endl << "done with edges" << endl;
    cin >> k;
    vector<int> ord;
    for (int i = 0; i < k; ++i) {
        int e; cin >> e;
        ord.push_back(e);
        used[e] = 0;
    }
    // cout << endl << "done with ord" << endl;
    reverse(ord.begin(), ord.end());

    DSU dsu(n+1);
    int cur = n, ones = n;
    for (int e = 0; e < m; ++e) {
        if (used[e]) {
            auto [u, v] = edges[e];
            // if (u == v) {
            //     if (dsu.size(u) > 1) continue;
            //     if (selfloop[u]) continue;
            //     selfloop[u] = 1;
            //     ones--;
            // }
            if (dsu.find(u) != dsu.find(v)) cur--;
            if (dsu.size(u) == 1 && !selfloop[u]) ones--;
            if (dsu.size(v) == 1 && !selfloop[v]) ones--;
            dsu.unite(u, v);
        }
    }
    vector<int> res;
    res.push_back(cur-ones);
    for (int e: ord) {
        auto [u, v] = edges[e];
        // if (u == v) {
        //     if (dsu.size(u) > 1) continue;
        //     if (selfloop[u]) continue;
        //     selfloop[u] = 1;
        //     ones--;
        // }
        if (dsu.find(u) != dsu.find(v)) cur--;
        if (dsu.size(u) == 1 && !selfloop[u]) ones--;
        if (dsu.size(v) == 1 && !selfloop[v]) ones--;
        dsu.unite(u, v);
        res.push_back(cur-ones);
    }
    reverse(res.begin(), res.end());
    for (int x: res) {
        cout << x << endl;
    }
}