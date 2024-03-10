#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
int N, Q;
int P[MAXN], C[MAXN], root[MAXN], tin[MAXN], tout[MAXN], pre[MAXN];
vector<map<int, int>> cps = {{}};
vector<int> A[MAXN];

void dfs(int i, int r, int& t, int w) {
    if (i != r && root[i]) return;
    root[i] = r;
    tin[i] = ++t;
    pre[i] = w;
    if (!C[i]) C[i] = -1;
    for (int j: A[i]) {
        if (j == i) continue;
        dfs(j, r, t, w+1);
    }
    tout[i] = ++t;
}

bool is_parent(int i, int p) {
    return tin[p] <= tin[i] && tout[i] <= tout[p];
}

int query(int i, int p) {
    int pi = root[i], pp = root[p];
    if (C[pi] != C[pp]) return -1;
    if (pi == pp) {
        if (!is_parent(i, p)) return -1;
        return pre[i]-pre[p];
    }
    if (p != pp) return -1;
    auto& cp = cps[C[pi]];
    return (cp[pp]-cp[pi]+cp.size())%cp.size() + pre[i]-pre[pi];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        int j; cin >> j;
        P[i] = j;
        A[j].push_back(i);
    }
    for (int i = 1; i <= N; ++i) {
        if (C[i]) continue;
        int j = i;
        while (!C[j]) {
            C[j] = -1;
            j = P[j];
        }
        vector<int> cycle;
        map<int, int> cp;
        while (C[j] == -1) {
            C[j] = cps.size();
            cycle.push_back(j);
            root[j] = j;
            cp[j] = cp.size();
            j = P[j];
        }
        cps.push_back(cp);
        for (int a: cycle) {
            int t = 0;
            dfs(a, a, t, 0);
        }
    }
    while (Q--) {
        int i, p; cin >> i >> p;
        cout << query(i, p) << endl;
    }
}