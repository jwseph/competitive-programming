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

const int MAXN = 1e5+5;
int N, M;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> M >> N;
    SCC G(N*2);
    for (int e = 0; e < M; ++e) {
        char a, b; int i, j; cin >> a >> i >> b >> j; --i, --j;
        i = i<<1 ^ (a == '+');
        j = j<<1 ^ (b == '+');
        G.add(i^1, j);
        G.add(j^1, i);
    }
    G.sol();
    for (int i = 0; i < 2*N; i += 2) {
        if (G.C[i] == G.C[i^1]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    for (int i = 0; i < 2*N; i += 2) {
        cout << (G.C[i|1] < G.C[i] ? '+' : '-') << ' ';
    }
    cout << endl;
}