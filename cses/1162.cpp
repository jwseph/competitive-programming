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

int main() {
    int n; cin >> n;
    vector<int> a(n), idx(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        idx[a[i]] = i;
    }
    
    long long res1 = 0;
    BIT bit(n+1);
    for (int i = n-1; i >= 0; --i) {
        res1 += bit.query(a[i]);
        bit.update(a[i], 1);
    }

    vector<int> lis;
    for (int x: a) {
        int l = lower_bound(begin(lis), end(lis), x) - begin(lis);
        if (l == lis.size()) lis.push_back(-1);
        lis[l] = x;
    }
    int res3 = n - lis.size();

    int y = n, r = 1e9;
    while (y > 0 && r > idx[y]) {
        r = idx[y];
        y--;
    }
    int res4 = y;

    int res2 = 0;
    for (int x = 1; x <= n; ++x) {
        if (idx[x]+1 == x) continue;
        res2++;
        int i = idx[x], j = x-1;
        swap(idx[a[i]], idx[a[j]]);
        swap(a[i], a[j]);
    }

    cout << res1 << ' ' << res2 << ' ' << res3 << ' ' << res4 << endl;
}