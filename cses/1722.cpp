#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9+7;

map<ll, ll> dp;

ll fib(ll n) {
    if (dp.count(n)) return dp[n];
    // F_{2m-1} = F_m^2 + F_{m-1}^2
    // F_{2m} = F_m^2 + 2F_mF_{m-1}
    if (n <= 1) return n;
    if (n&1) {
        ll m = (n+1)/2, a = fib(m), b = fib(m-1);
        return dp[n] = (a*a % mod + b*b % mod) % mod;
    }
    ll m = n/2, a = fib(m), b = fib(m-1);
    return dp[n] = (a*a % mod + 2*a*b % mod) % mod;
}

ll n;

int main() {
    cin >> n;
    cout << fib(n) << endl;
}