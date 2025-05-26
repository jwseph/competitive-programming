#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N =200005, MOD = 1e9+7;

struct BIT {
    vector<ll> t; int n;
    BIT(int n): t(n), n(n) {}
    void update(int i, int v) {
        for (; i < n; i |= i+1) t[i] += v, t[i] %= MOD;
    }
    ll query(int r) {
        ll res = 0;
        for (r = max(0, min(n, r)); r; r &= r-1) res += t[r-1], res %= MOD;
        return res;
    }
    ll query(int l, int r) {
        return (query(r) - query(l) + MOD) % MOD;
    }
};

template<class I>
void compress(I l, I r) {
    vector<int> v(l, r);
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    map<int, int> inv;
    for (int a: v) inv[a] = inv.size();
    while (l != r) *(l++) = inv[*l]+1;
}

int n;
int a[N];
BIT t(N);

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    compress(a, a+n);
    for (int i = 0; i < n; ++i) {
        t.update(a[i], (t.query(a[i])+1) % MOD);
    }
    cout << t.query(n+1) << endl;
}