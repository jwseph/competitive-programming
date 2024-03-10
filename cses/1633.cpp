#include <bits/stdc++.h>
using namespace std;

int main() {
    int MOD = 1e9+7;
    int N; cin >> N;
    int dp[N+6];
    memset(dp, 0, sizeof dp);
    dp[N] = 1;
    for (int i = N-1; i >= 0; --i) {
        for (int j = i+1; j <= i+6; ++j) {
            dp[i] = (dp[i]+dp[j]) % MOD;
        }
    }
    cout << dp[0] << endl;
}