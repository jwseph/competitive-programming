#include <bits/stdc++.h>
using namespace std;

const int N = 502, K = N*N, mod = 1e9+7;
int n, k;
int dp[2][K], pre[2][K];

int main() {
    cin >> n >> k;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (i == 0) {
                dp[i&1][j] = j == 0;
                continue;
            }
            dp[i&1][j] = pre[i+1&1][j+1] - pre[i+1&1][max(j-i+1, 0)] + mod;
            dp[i&1][j] %= mod;
        }
        pre[i&1][0] = 0;
        for (int j = 0; j <= k; ++j) {
            pre[i&1][j+1] = (pre[i&1][j] + dp[i&1][j]) % mod;
        }
    }
    cout << dp[n&1][k] << endl;
}