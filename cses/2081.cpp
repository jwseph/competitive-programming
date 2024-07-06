#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct BIT {
    vector<ll> t; int n;
    BIT(int n): t(n), n(n) {}
    void update(int i, int v) {
        for (; i < n; i |= i+1) t[i] += v;
    }
    ll query(int i) {
        ll res = 0;
        for (i = max(0, min(n, i)); i; i &= i-1) res += t[i-1];
        return res;
    }
    ll query(int l, int r) {
        return query(r) - query(l);
    }
};

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
    ll dfs(int i, int p, int d, BIT& dis, vector<int>& cnt, int k1, int k2) {
        ll res = dis.query(k1-d, k2+1-d);
        while (d >= cnt.size()) cnt.push_back(0);
        cnt[d]++;
        ADJ res += dfs(j, i, d+1, dis, cnt, k1, k2);
        return res;
    }
    ll build(int i, int p, int k1, int k2) {
        int s = dfs_sz(i, -1);
        i = dfs_ce(i, -1, s);
        pa[i] = p >= 0 ? p : i;
        BIT dis(s+1);
        dis.update(0, 1);
        ll res = 0;
        ADJ {
            vector<int> cnt;
            res += dfs(j, i, 1, dis, cnt, k1, k2);
            for (int d = 0; d < cnt.size(); ++d) dis.update(d, cnt[d]);
        }
        ADJ res += build(j, i, k1, k2);
        return res;
    }
    #undef ADJ
};

int n, k1, k2;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k1 >> k2;
    Centroid g(n+1);
    for (int e = 0; e < n-1; ++e) {
        int i, j; cin >> i >> j;
        g.add(i, j);
    }
    cout << g.build(1, -1, k1, k2) << endl;
}