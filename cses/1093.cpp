#include <bits/stdc++.h>
using namespace std;

const int MAXK = 6.3e4, MOD = 1e9+7;
int N, K, dp[MAXK];

int main() {
    cin >> N;
    K = N*(N+1)/2;
    if (K&1) {
        cout << 0 << endl;
        return 0;
    }
    K /= 2;
    dp[1] = 1;
    for (int i = 2; i <= N; ++i) {
        for (int k = K; k >= i; --k) {
            dp[k] = (dp[k] + dp[k-i]) % MOD;
        }
    }
    cout << dp[K] << endl;
}