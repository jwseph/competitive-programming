#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, mod = 1e9+7;

int main() {
    cin >> n;
    ll dp[3] = {1, 0};
    for (int i = 2; i <= n; ++i) {
        dp[i%3] = (i-1) * (dp[(i+2)%3] + dp[(i+1)%3]) % mod;
    }
    cout << dp[n%3] << endl;
}