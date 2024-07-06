#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9+7;

struct Mod {
    int n;
    vector<ll> fac, inv;
    Mod(int n): n(n), fac(n+1), inv(n+1) {
        fac[0] = 1;
        for (int i = 1; i <= n; ++i) fac[i] = fac[i-1] * i % mod;
        inv[n] = exp(fac[n], mod-2);
        for (int i = n; i >= 1; --i) inv[i-1] = inv[i] * i % mod;
    }
    ll exp(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b&1) res *= a, res %= mod;
            a *= a, a %= mod;
            b >>= 1;
        }
        return res;
    }
    ll choose(int n, int k) {
        return fac[n] * inv[k] % mod * inv[n-k] % mod;
    }
};

int n;

int main() {
    cin >> n;
    if (n&1) {
        cout << 0 << endl;
        return 0;
    }
    Mod pc(n);
    cout << (pc.choose(n, n/2) - pc.choose(n, n/2-1) + mod) % mod << endl;
}