#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct BIT {
    vector<ll> t; int n;
    BIT(int n): t(n), n(n) {}
    void update(int i, int v) {
        for (; i < n; i |= i+1) t[i] += v;
    }
    ll query(int r) {
        ll res = 0;
        for (r = max(0, min(n, r)); r; r &= r-1) res += t[r-1];
        return res;
    }
    ll query(int l, int r) {
        return query(r) - query(l);
    }
};

const int N = 2e5+5;

int n, nq, a[N], res[N];
vector<int> ys;
array<int, 4> qs[N];
vector<array<int, 4>> checks[N];  // l, r, sgn, q

int inv(int y) {
    return lower_bound(begin(ys), end(ys), y) - begin(ys);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> nq;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ys.push_back(a[i]);
    }
    for (int q = 0; q < nq; ++q) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        --a; ++d;
        qs[q] = {a, b, c, d};
        ys.push_back(c);
        ys.push_back(d);
    }
    sort(begin(ys), end(ys));
    ys.erase(unique(begin(ys), end(ys)), end(ys));
    int m = ys.size();
    for (int i = 0; i < n; ++i) {
        a[i] = inv(a[i]);
    }
    for (int q = 0; q < nq; ++q) {
        qs[q][2] = inv(qs[q][2]);
        qs[q][3] = inv(qs[q][3]);
        auto [a, b, c, d] = qs[q];
        checks[a].push_back({c, d, -1, q});
        checks[b].push_back({c, d, 1, q});
    }
    BIT bit(m);
    for (int i = 0; i <= n; ++i) {
        for (auto [l, r, sgn, q]: checks[i]) {
            res[q] += sgn * bit.query(l, r);
        }
        if (i < n) bit.update(a[i], 1);
    }
    for (int q = 0; q < nq; ++q) {
        cout << res[q] << endl;
    }
}

