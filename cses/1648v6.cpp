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
        for (; i; i &= i-1) res += t[i-1];
        return res;
    }
    ll query(int l, int r) {
        return query(r) - query(l);
    }
};

const int N = 2e5+5;
int n, m;
int ar[N];

int main() {
    cin >> n >> m;
    BIT tr(n);
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
        tr.update(i, ar[i]);
    }
    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int i, a; cin >> i >> a; --i;
            tr.update(i, a-ar[i]);
            ar[i] = a;
            continue;
        }
        int l, r; cin >> l >> r; --l;
        cout << tr.query(l, r) << endl;
    }
}