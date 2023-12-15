#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define MAXLOGN 20

int N, M, P[MAXN];
vector<int> A[MAXN];
string S;

int timer = 0, tin[MAXN], tout[MAXN], up[MAXN][MAXLOGN+1]{}, depth[MAXN];
void dfs(int i, int p, int d, int cur) {
    cur += S[i] == 'G';
    P[i] = cur;
    depth[i] = d;
    tin[i] = ++timer;
    up[i][0] = p;
    for (int b = 1; b <= MAXLOGN; ++b) {
        up[i][b] = up[up[i][b-1]][b-1];
    }
    for (int j: A[i]) {
        if (j == p) continue;
        dfs(j, i, d+1, cur);
    }
    tout[i] = ++timer;
}

bool is_parent(int i, int j) {
    return tin[i] <= tin[j] && tout[j] <= tout[i];
}

int lca(int i, int j) {
    if (is_parent(i, j)) return i;
    if (is_parent(j, i)) return j;
    for (int b = MAXLOGN; b >= 0; --b) {
        if (is_parent(up[i][b], j)) continue;
        i = up[i][b];
    }
    return up[i][0];
}

int main() {
    cin >> N >> M >> S;
    for (int e = 0; e < N-1; ++e) {
        int i, j; cin >> i >> j; --i; --j;
        A[i].push_back(j);
        A[j].push_back(i);
    }
    dfs(0, 0, 0, 0);
    while (M--) {
        int i, j; char t; cin >> i >> j >> t; --i; --j;
        int p = lca(i, j);
        int g = P[i]-P[p] + P[j]-P[p] + (S[p] == 'G');
        if (t == 'G') {
            cout << (g > 0);
        } else {
            cout << (g < depth[i]-depth[p] + depth[j]-depth[p] + 1);
        }
    }
    cout << endl;
}