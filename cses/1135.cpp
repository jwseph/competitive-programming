#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
int N, M, L, timer = 0;
vector<int> A[MAXN];
int P[MAXN][20], D[MAXN], tin[MAXN], tout[MAXN];

void dfs(int i, int p, int t) {
    tin[i] = ++timer;
    D[i] = t;
    P[i][0] = p;
    for (int k = 1; k <= L; ++k) {
        P[i][k] = P[P[i][k-1]][k-1];
    }
    for (int j: A[i]) {
        if (j == p) continue;
        dfs(j, i, t+1);
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

int sol(int i, int j) {
    int h = lca(i, j);
    return D[i] + D[j] - 2*D[h];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    L = ceil(log2(N));
    for (int e = 0; e < N-1; ++e) {
        int i, j; cin >> i >> j;
        A[i].push_back(j), A[j].push_back(i);
    }
    dfs(1, 1, 0);
    while (M--) {
        int i, j; cin >> i >> j;
        cout << sol(i, j) << endl;
    }
}