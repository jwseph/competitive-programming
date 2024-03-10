#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+5, MOD = 1e9+7;
int N;
long long dp[MAXN][MAXN];

int main() {
    cin >> N;
    dp[0][0] = 1;
    for (int r = 0; r < N; ++r) {
        string S; cin >> S;
        for (int c = 0; c < N; ++c) {
            if (S[c] == '*') {
                dp[r][c] = 0;
                continue;
            }
            dp[r+1][c] = (dp[r+1][c]+dp[r][c]) % MOD;
            dp[r][c+1] = (dp[r][c+1]+dp[r][c]) % MOD;
        }
    }
    cout << dp[N-1][N-1] << endl;
}