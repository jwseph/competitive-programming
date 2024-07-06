#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Centroid {
    int n;
    vector<vector<int>> ad;
    vector<int> sz, pa;
    Centroid(int n): n(n), ad(n), sz(n), pa(n, -1) {}
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
    ll dfs(int i, int p, int d, vector<int>& dis, vector<int>& cnt, int k) {
        ll res = 0 <= k-d && k-d < dis.size() ? dis[k-d] : 0;
        while (d >= cnt.size()) cnt.push_back(0);
        cnt[d]++;
        ADJ res += dfs(j, i, d+1, dis, cnt, k);
        return res;
    }
    ll build(int i, int p, int k) {
        int s = dfs_sz(i, -1);
        i = dfs_ce(i, -1, s);
        pa[i] = p >= 0 ? p : i;

        vector<int> dis(s+1), cnt;
        dis[0]++;
        ll res = 0;
        ADJ {
            res += dfs(j, i, 1, dis, cnt = {}, k);
            for (int d = 0; d < cnt.size(); ++d) dis[d] += cnt[d];
        }
        dis = {}, cnt = {};

        ADJ res += build(j, i, k);
        return res;
    }
    #undef ADJ
};

int n, k;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    Centroid g(n+1);
    for (int e = 0; e < n-1; ++e) {
        int i, j; cin >> i >> j;
        g.add(i, j);
    }
    cout << g.build(1, -1, k) << endl;
}