#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const int N = 1e5+5;
int n, m;
int v[N];
vector<int> a[N];
set<pii> res;

void dfs(int i, int p) {
    if (v[i]) {
        // cout << "rev" << " i=" << i << " p=" << p << endl;
        res.insert({i, p});
        return;
    }
    v[i] = 1;
    if (p >= 0) res.insert({p, i});
    for (int j: a[i]) {
        if (j == p) continue;
        if (res.count(pii{i, j}) || res.count(pii{j, i})) continue;
        dfs(j, i);
    }
}

int main() {
    cin >> n >> m;
    for (int e = 0; e < m; ++e) {
        int i, j; cin >> i >> j;
        a[i].push_back(j);
        a[j].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (!v[i]) dfs(i, -1);
    }
    for (auto [i, j]: res) {
        cout << i << ' ' << j << endl;
    }
}