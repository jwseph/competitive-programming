#include <bits/stdc++.h>
using namespace std;

struct SCC {
    int N, NC = 0;
    vector<vector<int>> A[2];
    vector<int> C, O;
    vector<bool> V;
    SCC(int N): N(N), C(N, -1), V(N) {
        A[0].resize(N), A[1].resize(N);
    }
    void add(int i, int j) {
        A[0][i].push_back(j), A[1][j].push_back(i);
    }
    void dfs1(int i) {
        if (V[i]) return;
        V[i] = 1;
        for (int j: A[1][i]) dfs1(j);
        O.push_back(i);
    }
    void dfs2(int i, int c) {
        if (C[i] >= 0) return;
        C[i] = c;
        for (int j: A[0][i]) dfs2(j, c);
    }
    void sol() {
        for (int i = 0; i < N; ++i) dfs1(i);
        reverse(begin(O), end(O));
        for (int i: O) if (C[i] < 0) dfs2(i, i), NC++;
    }
};

int main() {
    int n, m; cin >> n >> m;
    SCC g(n);
    while (m--) {
        int i, j; cin >> i >> j; --i, --j;
        g.add(i, j);
    }
    g.sol();
    if (g.NC == 1) {
        cout << 0 << endl;
        return 0;
    }
    vector<bool> ind(n), out(n);
    for (int i = 0; i < n; ++i) {
        for (int j: g.A[0][i]) {
            int a = g.C[i], b = g.C[j];
            if (a == b) continue;
            out[a] = 1;
            ind[b] = 1;
        }
    }
    vector<int> src, dst;
    for (int i = 0; i < n; ++i) {
        if (i != g.C[i]) continue;
        if (ind[i] && !out[i]) dst.push_back(i);
        if (!ind[i] && out[i]) src.push_back(i);
    }
    while (dst.size() < src.size()) {
        dst.push_back(dst.back());
    }
    while (src.size() < dst.size()) {
        src.push_back(src.back());
    }
    cout << src.size() << endl;
    for (int i = 0; i < src.size(); ++i) {
        cout << dst[i]+1 << ' ' << src[i]+1 << endl;
    }
}