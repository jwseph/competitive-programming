#include <bits/stdc++.h>
using namespace std;

using arr2 = array<int, 2>;

struct DSU {
    int nc = 0;
    vector<int> p;
    DSU(int n) { p.assign(n, -1); }
    int size(int i) { return -p[find(i)]; }
    int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
    int unite(int i, int j) {
        i = find(i), j = find(j);
        if (i == j) return i;
        nc--;
        if (-p[i] < -p[j]) swap(i, j);
        p[i] += p[j], p[j] = i;
        return i;
    }
};

int n, m, k;

int main() {
    cin >> n >> m >> k;
    vector<arr2> edges(m), rev(k), del(k);
    for (int e = 0; e < m; ++e) {
        int i, j; cin >> i >> j;
        if (i > j) swap(i, j);
        edges[e] = {i, j};
    }
    for (int e = 0; e < k; ++e) {
        int i, j; cin >> i >> j;
        if (i > j) swap(i, j);
        del[e] = rev[e] = {i, j};
    }
    sort(begin(del), end(del));
    DSU dsu(n+1);
    dsu.nc = n;
    for (auto ij: edges) {
        if (binary_search(begin(del), end(del), ij)) continue;
        dsu.unite(ij[0], ij[1]);
    }
    reverse(begin(rev), end(rev));
    stack<int> res;
    for (auto [i, j]: rev) {
        res.push(dsu.nc);
        dsu.unite(i, j);
    }
    while (res.size()) {
        cout << res.top() << ' ';
        res.pop();
    }
}