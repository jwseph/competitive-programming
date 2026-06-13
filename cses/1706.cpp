#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, m, v[N];
vector<int> adj[N];

int dfs(int i) {
    if (v[i]) return 0;
    v[i] = 1;
    int res = 1;
    for (int j: adj[i]) {
        res += dfs(j);
    }
    return res;
}

int main() {
    cin >> n >> m;
    while (m--) {
        int i, j; cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    bitset<N> res;
    res[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (v[i]) continue;
        int x = dfs(i);
        res |= res<<x;
    }
    for (int i = 1; i <= n; ++i) {
        cout << res[i];
    }
    cout << endl;
}