#include <bits/stdc++.h>
using namespace std;

struct Lift {
    int N, L, timer = 0;
    vector<vector<int>> A, P;
    vector<int> tin, tout;
    Lift(int N): N(N), A(N), tin(N), tout(N) {
        L = ceil(log2(N));
        P.resize(N, vector<int>(L+1));
    }
    void add(int i, int j) { A[i].push_back(j), A[j].push_back(i); }
    void dfs(int i, int p = -1) {
        tin[i] = timer++;
        P[i][0] = p >= 0 ? p : i;
        for (int k = 1; k <= L; ++k) {
            P[i][k] = P[P[i][k-1]][k-1];
        }
        for (int j: A[i]) {
            if (j == p) continue;
            dfs(j, i);
        }
        tout[i] = timer++;
    }
    bool is_ans(int a, int i) {
        return tin[a] <= tin[i] && tout[i] <= tout[a];
    }
    int lca(int i, int j) {
        if (is_ans(i, j)) return i;
        if (is_ans(j, i)) return j;
        for (int k = L; k >= 0; --k) {
            if (!is_ans(P[i][k], j)) i = P[i][k];
        }
        return P[i][0];
    }
};

const int MAXN = 1e5+5;
int N, M;
int C[MAXN], res[MAXN], cnt[MAXN];
Lift G(MAXN);
vector<array<int, 3>> Q[MAXN];

void dfs(int i, int p = -1) {
    cnt[C[i]]++;
    for (auto [q, c, m]: Q[i]) {
        res[q] += cnt[c]*m;
    }
    for (int j: G.A[i]) {
        if (j == p) continue;
        dfs(j, i);
    }
    cnt[C[i]]--;
}

int main() {
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> C[i];
    for (int e = 0; e < N-1; ++e) {
        int i, j; cin >> i >> j; --i, --j;
        G.add(i, j);
    }
    G.dfs(0);
    for (int q = 0; q < M; ++q) {
        int i, j, c; cin >> i >> j >> c; --i, --j;
        int a = G.lca(i, j);
        Q[i].push_back({q, c, 1});
        Q[j].push_back({q, c, 1});
        Q[a].push_back({q, c, -2});
        res[q] += C[a] == c;
    }
    dfs(0);
    for (int q = 0; q < M; ++q) {
        cout << (res[q] > 0);
    }
    cout << endl;
}