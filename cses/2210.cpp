#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

ll n;

ll exp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b&1) res *= a, res %= mod;
        a *= a, a %= mod;
        b >>= 1;
    }
    return res;
}

int main() {
    cin >> n;
    ll all = n*n % (mod-1), square = (n/2)*(n/2) % (mod-1), center = n&1, stick = n/2*center;
    ll res = exp(2, all);
    res += 2*exp(2, square+stick+center), res %= mod;
    res += exp(2, 2*square+2*stick+center), res %= mod;
    res *= exp(4, mod-2), res %= mod;
    cout << res << endl;
}