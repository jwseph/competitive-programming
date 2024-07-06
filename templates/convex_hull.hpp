/**
 * Author: Joseph Jackson
 * Date: 2024-07-02
 * License: CC0
 * Time: O(nlogn)
 * Description: Right-turn convex hull (slow impl)
 * Usage: ConvexHull ch; ch.insert(2, 4); ch.ys[2] == 4;
 *        Edit update_gap to know when intervals are added/deleted
 * Status: tested
 */

using ll = long long;

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
    void update_gap(ll x1, ll x2, int m) {}  // added -> m=1, deleted -> m=-1
};