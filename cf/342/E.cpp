#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5, inf = 1e9;
int n, m;
vector<int> ad[N], dp(N, inf);
vector<pair<int, int>> an[N];
int sz[N], pa[N];

#define ADJ for (int j: ad[i]) if (j != p && pa[j] <= 0)

int dfs_sz(int i, int p) {
    sz[i] = 1;
    ADJ sz[i] += dfs_sz(j, i);
    return sz[i];
}

int dfs_ce(int i, int p, int k) {
    ADJ if (sz[j] > k/2) return dfs_ce(j, i, k);
    return i;
}

void dfs_ds(int i, int p, int d, int a) {
    an[i].push_back({a, d});
    ADJ dfs_ds(j, i, d+1, a);
}

void build(int i = 1, int p = -1) {
    i = dfs_ce(i, -1, dfs_sz(i, -1));
    dfs_ds(i, -1, 0, i);
    pa[i] = p >= 0 ? p : i;
    ADJ build(j, i);
}

void update(int i) {
    dp[i] = 0;
    for (auto [a, d]: an[i]) {
        dp[a] = min(dp[a], d);
    }
}

int query(int i) {
    int res = dp[i];
    for (auto [a, d]: an[i]) {
        res = min(res, d+dp[a]);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int e = 0; e < n-1; ++e) {
        int i, j; cin >> i >> j;
        ad[i].push_back(j), ad[j].push_back(i);
    }
    build();
    update(1);
    while (m--) {
        int t, i; cin >> t >> i;
        if (t == 1) {
            update(i);
            continue;
        }
        cout << query(i) << endl;
    }
}