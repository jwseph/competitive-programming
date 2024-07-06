#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
using ll = long long;

struct ConvexHull {
    map<ll, ll> ys;
    bool right_turn(ll x1, ll x2, ll x3) {
        return (ys[x2]-ys[x1])*(x3-x2) > (ys[x3]-ys[x2])*(x2-x1);  ////
    }
    void insert(ll x, ll y) {
        if (ys.count(x)) {
            if (y <= ys[x]) return;  ////
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
                    if (right_turn(a, b, c)) break;
                    update_point(b, -1);
                    ys.erase(b);
                    ch = 1;
                }
            }
            if (!ch) break;
        }
    }
    void update_point(ll x, int m) {  // m=1 inserts, m=2 deletes
        auto it = ys.lower_bound(x);
        ll l = prev(it)->first;
        update_gap(l, x, m);
        if (next(it) != end(ys)) {
            ll r = next(it)->first;
            update_gap(x, r, m);
            update_gap(l, r, -m);
        }
        ////
    }
    void update_gap(ll x1, ll x2, int m) {}  ////
};

const int N = 1e5+5, K = 1e5;
int n;
ConvexHull ch;

ll query(ll x) {
    if (ch.ys.count(x)) return ch.ys[x]*K;
    auto it = ch.ys.lower_bound(x);
    ll x1 = it->first, x2 = (--it)->first;
    if (ch.ys[x1] > ch.ys[x2]) swap(x1, x2);
    return K*ch.ys[x1]+K*(ch.ys[x2]-ch.ys[x1])*(x-x1)/(x2-x1);
}

int main() {
    ifstream cin("balance.in");
    ofstream cout("balance.out");
    cin >> n;
    ch.insert(0, 0);
    ch.insert(n+1, 0);
    FOR(i, 1, n+1) {
        int y; cin >> y;
        ch.insert(i, y);
    }
    FOR(i, 1, n+1) cout << query(i) << endl;
}