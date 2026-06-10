#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int nt, nq;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> nt;
    while  (nt--) {
        ll min_odd = 1ll+2*ll(INT_MAX);
        cin >> nq;
        while (nq--) {
            ll t, v; cin >> t >> v;
            if (t == 2) {
                if (v%2 == 1) {
                    min_odd = min<ll>(min_odd, v);
                }
                continue;
            }
            cout << ((v%2 == 0 || v >= min_odd) ? "YES" : "NO") << endl;
        }
    }
}