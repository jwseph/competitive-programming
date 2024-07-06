#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

ll exp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b&1) res = res*a % mod;
        a = a*a % mod;
        b >>= 1;
    }
    return res;
}

int n;
vector<pair<ll, ll>> pf;

ll sig0() {
    ll res = 1;
    for (auto [p, k]: pf) res *= k+1, res %= mod;
    return res;
}

ll sig1() {
    ll res = 1;
    for (auto [p, k]: pf) {
        res *= exp(p, k+1)-1, res %= mod;
        res *= exp(p-1, mod-2), res %= mod;
    }
    return res;
}

ll prod() {
    ll res = 1, n = 1;
    for (auto [p, k]: pf) {
        res = exp(res, k+1) * exp(p, k*(k+1)/2 % (mod-1) * n % (mod-1)) % mod;
        n *= k+1, n %= mod-1;
    }
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int p, k; cin >> p >> k;
        pf.push_back({p, k});
    }
    cout << sig0() << ' ' << sig1() << ' ' << prod() << endl;
}