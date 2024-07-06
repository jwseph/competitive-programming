#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
int N, M, L, timer = 0;
int P[MAXN][20], tin[MAXN], tout[MAXN];
vector<int> A[MAXN];

void dfs(int i) {
    tin[i] = ++timer;
    for (int j: A[i]) dfs(j);
    tout[i] = ++timer;
}

bool is_ans(int a, int i) {
    return tin[a] <= tin[i] && tout[i] <= tout[a];
}

int lca(int i, int j) {
    if (is_ans(j, i)) return j;
    if (is_ans(i, j)) return i;
    for (int k = L; k >= 0; --k) {
        if (!is_ans(P[j][k], i)) {
            j = P[j][k];
        }
    }
    return P[j][0];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    L = ceil(log2(N));
    for (int i = 2; i <= N; ++i) {
        cin >> P[i][0];
        A[P[i][0]].push_back(i);
    }
    P[1][0] = 1;
    for (int k = 1; k <= L; ++k) {
        for (int i = 1; i <= N; ++i) {
            P[i][k] = P[P[i][k-1]][k-1];
        }
    }
    dfs(1);
    while (M--) {
        int i, j; cin >> i >> j;
        cout << lca(i, j) << endl;
    }
}