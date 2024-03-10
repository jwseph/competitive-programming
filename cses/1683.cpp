#include <bits/stdc++.h>
using namespace std;

struct SCC {
    int N, NC = 0;
    vector<vector<int>> A[2];
    vector<int> C, O;
    vector<bool> V;
    SCC(int N) : N(N) {
        A[0].resize(N);
        A[1].resize(N);
        V.resize(N);
        C.assign(N, -1);
    }
    void add(int i, int j) {
        A[0][i].push_back(j);
        A[1][j].push_back(i);
    }
    void dfs1(int i) {
        if (V[i]) return;
        V[i] = 1;
        for (int j: A[0][i]) dfs1(j);
        O.push_back(i);
    }
    void dfs2(int i, int c) {
        if (C[i] >= 0) return;
        C[i] = c;
        for (int j: A[1][i]) dfs2(j, c);
    }
    void sol() {
        for (int i = 0; i < N; ++i) {
            dfs1(i);
        }
        reverse(begin(O), end(O));
        for (int i: O) {
            if (C[i] >= 0) continue;
            dfs2(i, NC++);
        }
    }
};

int N, M;

int main() {
    cin >> N >> M;
    SCC G(N);
    while (M--) {
        int i, j; cin >> i >> j; --i, --j;
        G.add(i, j);
    }
    G.sol();
    cout << G.NC << endl;
    for (int c: G.C) cout << c+1 << ' ';
    cout << endl;
}