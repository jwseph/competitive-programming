#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9+7;

ll exp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b&1) res *= a, res %= mod;
        a *= a, a %= mod;
        b >>= 1;
    }
    return res;
}

int gcd(int a, int b) {
    return a == 0 ? b : gcd(b%a, a);
}

int n, m;

int main() {
    cin >> n >> m;
    // 1/n sum k=[1,n] m**gcd(k, n)
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        res += exp(m, gcd(i, n)), res %= mod;
    }
    res *= exp(n, mod-2), res %= mod;
    cout << res << endl;
}