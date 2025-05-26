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

const int ext = 1e6, M = 2e6+6;
int n;
vector<int> add[M], sub[M];
vector<array<int, 2>> qs[M];
BIT t(M);

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1 += ext, y1 += ext, x2 += ext, y2 += ext;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        if (x1 == x2) qs[x1].push_back({y1, y2});
        else {
            add[x1].push_back(y1);
            sub[x2].push_back(y1);
        }
    }
    ll res = 0;
    for (int x = 0; x < M; ++x) {
        for (int y: add[x]) t.update(y, 1);
        for (auto [y1, y2]: qs[x]) {
            res += t.query(y1, y2+1);
        }
        for (int y: sub[x]) t.update(y, -1);
    }
    cout << res << endl;
}