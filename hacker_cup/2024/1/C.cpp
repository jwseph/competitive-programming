#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

int nt;

int main() {
    cin >> nt;
    for (int t = 1; t <= nt; ++t) {
        ll w, g, l; cin >> w >> g >> l;
        w %= MOD;
        g %= MOD;
        l %= MOD;
        cout << "Case #" << t << ": " << (w-g)*(2*l+1)%MOD << endl;
    }
}