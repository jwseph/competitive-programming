#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9+7;
struct Modular {
    int n;
    vector<ll> fac, inv;
    Modular(int n): n(n), fac(n+1), inv(n+1) {
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

const int N = 1003, M = 102;
int n, m;
string s;
Modular md(0);

int dp[N][M];  // string of length i that doesn't contain s but contains s[:k]
int pc[M][128];

int shared(string t) {
    int k = t.size();
    while (s.substr(0, k) != t.substr(t.size()-k, k)) --k;
    return k;
}

int main() {
    cin >> n >> s; m = s.size();
    for (int k = 0; k < m; ++k) {
        for (char c = 'A'; c <= 'Z'; ++c) {
            pc[k][c] = shared(s.substr(0, k)+c);
        }
    }
    for (int i = n; i >= 0; --i) {
        for (int k = 0; k <= m; ++k) {
            if (k == m) {
                dp[i][k] = 0; continue;
            }
            if (i == n) {
                dp[i][k] = 1; continue;
            }
            for (char c = 'A'; c <= 'Z'; ++c) {
                dp[i][k] += dp[i+1][pc[k][c]], dp[i][k] %= mod;
            }
        }
    }
    cout << (md.exp(26, n)-dp[0][0] + mod) % mod << endl;
}