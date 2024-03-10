#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    DSU(int n) { p.assign(n, -1); }
    int size(int i) { return -p[find(i)]; }
    int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }
    bool unite(int i, int j) {
        i = find(i), j = find(j);
        if (i == j) return 0;
        if (p[i] > p[j]) swap(i, j);
        p[i] += p[j];
        p[j] = i;
        return 1;
    }
};

const int MAXN = 1e5+5, MAXM = 2e5+5;
int N, M;
array<int, 3> E[MAXM];

int main() {
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        cin >> E[e][1] >> E[e][2] >> E[e][0];
    }
    sort(E, E+M);
    DSU dsu(N+1);
    long long res = 0;
    for (auto [w, i, j]: E) {
        if (dsu.find(i) == dsu.find(j)) continue;
        dsu.unite(i, j);
        res += w;
    }
    if (dsu.size(1) < N-1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << res << endl;
}