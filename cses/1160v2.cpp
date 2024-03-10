#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5, MAXLOG = 20;
int N, Q, P[MAXN][MAXLOG], D[MAXN], cyc[MAXN];
vector<int> A[MAXN];
vector<map<int, int>> cps;

void dfs(int i, int d) {
    if (D[i] == 0) return;
    D[i] = d;
    for (int k = 1; k < MAXLOG; ++k) {
        P[i][k] = P[P[i][k-1]][k-1];
    }
    for (int j: A[i]) dfs(j, d+1);
}

void solve(int i) {
    if (D[i] >= 0) return;
    while (D[i] == -1) {
        D[i] = -2;
        i = P[i][0];
    }
    vector<int> cycle;
    map<int, int> cp;
    while (D[i] == -2) {
        D[i] = 0;
        cycle.push_back(i);
        cp[i] = cp.size();
        cyc[i] = cps.size();
        i = P[i][0];
    }
    cps.push_back(cp);
    for (int a: cycle) {
        for (int k = 0; k < MAXLOG; ++k) {
            P[a][k] = a;
        }
        for (int b: A[a]) dfs(b, 1);
    }
}

int nth_parent(int i, int n) {
    for (int k = 0; k < MAXLOG; ++k) {
        if (n&1<<k) i = P[i][k];
    }
    return i;
}

int query(int i, int p) {
    int pi = nth_parent(i, D[i]), pp = nth_parent(p, D[p]);
    if (cyc[pi] != cyc[pp]) return -1;
    if (pi == pp) {
        int d = D[i]-D[p];
        if (d < 0) return -1;
        return nth_parent(i, d) == p ? d : -1;
    }
    if (p != pp) return -1;
    auto& cp = cps[cyc[pi]];
    int res = (cp[pp]-cp[pi]+cp.size()) % cp.size();
    return res + D[i];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(D, -1, sizeof D);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        cin >> P[i][0];
        A[P[i][0]].push_back(i);
    }
    for (int i = 1; i <= N; ++i) {
        solve(i);
    }
    while (Q--) {
        int i, p; cin >> i >> p;
        cout << query(i, p) << endl;
    }
}