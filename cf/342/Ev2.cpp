#include <bits/stdc++.h>
using namespace std;

struct Centroid {
    int n;
    vector<vector<int>> ad;
    vector<vector<pair<int, int>>> an;
    vector<int> sz, pa, dp;
    Centroid(int n): n(n), ad(n), an(n), sz(n), pa(n, -1), dp(n, 1e9) {}
    void add(int i, int j) { ad[i].push_back(j), ad[j].push_back(i); }
    #define ADJ for (int j: ad[i]) if (j != p && pa[j] < 0)
    int dfs_sz(int i, int p) {
        sz[i] = 1;
        ADJ sz[i] += dfs_sz(j, i);
        return sz[i];
    }
    int dfs_ce(int i, int p, int k) {
        ADJ if (sz[j] > k/2) return dfs_ce(j, i, k);
        return i;
    }
    void dfs(int i, int p, int a, int d) {
        an[i].push_back({a, d});
        ADJ dfs(j, i, a, d+1);
    }
    void build(int i, int p = -1) {
        i = dfs_ce(i, -1, dfs_sz(i, -1));
        pa[i] = p >= 0 ? p : i;
        dfs(i, -1, i, 0);
        ADJ build(j, i);
    }
    #undef ADJ
    void update(int i) {
        dp[i] = 0;
        for (auto [a, d]: an[i]) {
            dp[a] = min(dp[a], d);
        }
    }
    int query(int i) {
        int res = 1e9;  // every node is its own first ancestor
        for (auto [a, d]: an[i]) {
            res = min(res, d+dp[a]);
        }
        return res;
    }
};

int n, m;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    Centroid g(n+1);
    for (int e = 0; e < n-1; ++e) {
        int i, j; cin >> i >> j;
        g.add(i, j);
    }
    g.build(1);
    g.update(1);
    while (m--) {
        int t, i; cin >> t >> i;
        if (t == 1) {
            g.update(i);
            continue;
        }
        cout << g.query(i) << endl;
    }
}