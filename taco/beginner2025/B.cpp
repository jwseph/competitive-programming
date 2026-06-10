#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using t4i = array<ll, 4>;
int nt, n;
ll a[100005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> nt;
    while (nt--) {
        cin >> n;
        for (int i = 0; i < n*n; ++i) {
            cin >> a[i];
        }
        vector<ll> res;
        for (;;) {
            // find best collection
            ll p = 0, pmin = 0, pmin_i = 0;
            t4i best = {-1, -1, -1, -1};
            for (int i = 1; i <= n*n; ++i) {
                p += a[i-1];
                t4i cur = {p-pmin, i-pmin_i, -pmin_i, -i};
                best = max(best, cur);
                if (pmin > p) {
                    pmin = p;
                    pmin_i = i;
                }
            }
            if (best[0] <= 0) break;
            res.push_back(best[0]);
            int l = -best[2], r = -best[3];
            for (int i = l; i < r; ++i) {
                a[i] = 0;
            }
        }
        cout << res.size() << endl;
        for (auto v: res) cout << v << ' ';
        cout << endl;
    }
}