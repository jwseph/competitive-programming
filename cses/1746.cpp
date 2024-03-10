#include <bits/stdc++.h>
using namespace std;

const int MAXK = 1e2+5, MOD = 1e9+7;
int N, K, dp[2][MAXK];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        for (int k = 1; k <= K; ++k) {
            dp[i%2][k] = 0;
            if (a && a != k) continue;
            if (i == 0) {
                dp[i%2][k] = 1;
                continue;
            }
            for (int j = max(k-1, 1); j <= min(k+1, K); ++j) {
                dp[i%2][k] += dp[(i+1)%2][j];
                dp[i%2][k] %= MOD;
            }
        }
    }
    int res = 0;
    for (int k = 1; k <= K; ++k) {
        res += dp[(N+1)%2][k];
        res %= MOD;
    }
    cout << res << endl;
}