#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e6+5, M = 256, mod = 1e9+7;
int n;
string str;
int cnt[M];

ll exp(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b&1) res *= a, res %= mod;
        a *= a, a %= mod;
        b >>= 1;
    }
    return res;
}

ll fac[N+1], inv[N+1];
void build() {
    fac[0] = 1;
    for (int i = 1; i <= N; ++i) fac[i] = fac[i-1]*i % mod;
    inv[N] = exp(fac[N], mod-2);
    for (int i = N; i; --i) inv[i-1] = inv[i]*i % mod;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    build();
    cin >> str;
    n = str.size();
    for (char c: str) cnt[c]++;
    ll res = fac[n];
    for (int c = 0; c < M; ++c) {
        res *= inv[cnt[c]], res %= mod;
    }
    cout << res << endl;
}