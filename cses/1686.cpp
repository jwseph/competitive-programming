#include <bits/stdc++.h>
using namespace std;

struct SCC {
    int N, NC = 0;
    vector<vector<int>> A[2];
    vector<int> C, O;
    vector<bool> V;
    SCC(int N) : N(N) {
        A[0].resize(N), A[1].resize(N), V.resize(N), C.assign(N, -1);
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
        for (int i: O) if (C[i] < 0) dfs2(i, NC++);
    }
};

using ll = long long;

const int MAXN = 1e5+5;
int N, M;
int C[MAXN];
ll P[MAXN];
vector<int> A[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> C[i];
    SCC G(N);
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j; --i, --j;
        G.add(i, j);
    }
    G.sol();
    for (int i = 0; i < N; ++i) {
        P[G.C[i]] += C[i];
        for (int j: G.A[0][i]) {
            A[G.C[i]].push_back(G.C[j]);
        }
    }
    ll res = 0;
    for (int i = 0; i < G.NC; ++i) {
        auto& adj = A[i];
        sort(begin(adj), end(adj));
        adj.erase(unique(begin(adj), end(adj)), end(adj));
        ll cur = 0;
        for (int j: adj) {
            if (j == i) continue;
            cur = max(cur, P[j]);
        }
        res = max(res, P[i] += cur);
    }
    cout << res << endl;
}