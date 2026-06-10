#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll
int nt, n;
int a[2][200005];
ll p[2][200005];
int lr[200005], lh[200005], rl[200005], rh[200005];

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> nt;
    while (nt--) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[0][i];
        for (int i = 0; i < n; ++i) cin >> a[1][i];
        lr[0] = 0;
        lh[0] = 0;
        for (int i = 0; i < n; ++i) {
            lr[i+1] = max(lr[i], a[1][i]-a[0][i]);
            lh[i+1] = max(lh[i], a[1][i]);
        }
        rl[n-1] = rh[n-1] = 0;
        for (int i = n-1; i; --i) {
            rl[i-1] = max(rl[i], a[0][i]-a[1][i]);
            rh[i-1] = max(rh[i], a[0][i]);
        }
        for (int r = 0; r < 2; ++r) {
            p[r][0] = 0;
            for (int i = 0; i < n; ++i) {
                p[r][i+1] = p[r][i] + a[r][i];
            }
        }
        // lr[0] = lh[0] = rl[n-1] = rh[n-1] = LLONG_MIN/4;
        
        ll res = LLONG_MIN;
        for (int h = 0; h < n; ++h) {
            ll cur = p[0][h+1] + p[1][n]-p[1][h];
            int hl = -a[1][h], hr = -a[0][h];
            res = max(res, cur + max(lr[h]+rl[h], max(lh[h]+hl, rh[h]+hr)));
            res = max(res, cur);
        }
        cout << res << endl;
    }
}