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
        tin[i] = ++timer;
        P[i][0] = p >= 0 ? p : i;
        for (int k = 1; k <= L; ++k) {
            P[i][k] = P[P[i][k-1]][k-1];
        }
        for (int j: A[i]) {
            if (j == p) continue;
            dfs(j, i);
        }
        tout[i] = ++timer;
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

const int MAXN = 2e5+5;
int N, M, dep = 0;
int res[MAXN], ddep[MAXN];
vector<int> Q[MAXN];
Lift G(MAXN);

void dfs(int i, int p) {
    res[i] -= dep;
    for (int a: Q[i]) {
        ddep[a]--;
        dep++;
    }
    for (int j: G.A[i]) {
        if (j == p) continue;
        dfs(j, i);
    }
    dep += ddep[i];
    res[i] += dep;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int e = 0; e < N-1; ++e) {
        int i, j; cin >> i >> j;
        G.add(i, j);
    }
    G.dfs(1);
    while (M--) {
        int i, j; cin >> i >> j;
        int a = G.lca(i, j);
        res[a]++;
        Q[j].push_back(a), Q[i].push_back(a);
    }
    dfs(1, 1);
    for (int i = 1; i <= N; ++i) cout << res[i] << ' ';
    cout << endl;
}