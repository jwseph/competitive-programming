#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, ll>;
const int mod = 1e9+7;

ll exp(ll a, ll b) {
    if (b < 0) return 0;
    ll res = 1;
    while (b) {
        if (b&1) res *= a, res %= mod;
        a *= a, a %= mod;
        b >>= 1;
    }
    return res;
}

struct ConvexHull {
    map<ll, ll> ys;
    bool right_turn(ll x1, ll x2, ll x3) {  // left_turn
        return (ys[x2]-ys[x1])*(x3-x2) > (ys[x3]-ys[x2])*(x2-x1);  // <
    }
    void insert(ll x, ll y) {
        if (ys.count(x)) {
            if (y <= ys[x]) return;  // >=
            update_point(x, -1);
            ys.erase(x);
        }
        ys[x] = y;
        update_point(x, 1);
        for (;;) {
            auto it = ys.upper_bound(x);
            bool ch = 0;
            for (int t = 0; t < 3 && it != begin(ys); ++t) {
                --it;
                while (it != end(ys) && next(it) != end(ys) && next(next(it)) != end(ys)) {
                    ll a = it->first, b = next(it)->first, c = next(next(it))->first;
                    if (right_turn(a, b, c)) break;  // left_turn
                    update_point(b, -1);
                    ys.erase(b);
                    ch = 1;
                }
            }
            if (!ch) break;
        }
    }
    void update_point(ll x, int m) {
        auto it = ys.lower_bound(x);
        ll l = prev(it)->first;
        update_gap(l, x, m);
        if (next(it) != end(ys)) {
            ll r = next(it)->first;
            update_gap(x, r, m);
            update_gap(l, r, -m);
        }
    }
    ll res = 0;
    void update_gap(ll x1, ll x2, int m) {  // added -> m=1, deleted -> m=-1
        ll x = x2-x1, y = ys[x2]-ys[x1];
        if (y <= 0) return;
        ll p = y/x, a = y%x, b = x-a;
        res += a*exp(3, p)%mod*m, res = (res%mod+mod)%mod;
        res += b*exp(3, p-1)%mod*m, res = (res%mod+mod)%mod;
    }
};

int n;
ConvexHull ch;

int main() {
    cin >> n;
    ch.insert(0, 0);
    while (n--) {
        ll m, b; cin >> m >> b;
        ch.insert(m, b);
        cout << ch.res << endl;
    }
}