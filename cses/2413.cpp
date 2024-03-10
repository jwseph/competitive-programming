#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5, MOD = 1e9+7;
int T, N;
long long dp[2][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; ++i) {
            for (int s = 0; s < 2; ++s) {
                if (i == 1) {
                    dp[i%2][s] = 1;
                    continue;
                }
                if (s) {
                    dp[i%2][s] = (dp[(i+1)%2][0] + 4*dp[(i+1)%2][1]) % MOD;
                    continue;
                }
                dp[i%2][s] = (2*dp[(i+1)%2][0] + dp[(i+1)%2][1]) % MOD;
            }
        }
        cout << (dp[N%2][0] + dp[N%2][1]) % MOD << endl;
    }
}