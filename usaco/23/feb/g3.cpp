// Source: http://usaco.org/current/data/sol_prob3_gold_feb23.html

#include <bits/stdc++.h>
using namespace std;

#define MN 302
#define vr vector
#define ll long long
#define MOD 1000000007
#define int ll

int N, X1, X2, A[MN], Q;
int dp[MN][20][20][3];

vr<vr<int>> sol(int X) {
    int T[20], W = 0;
    for (int t = X; t; t /= 10) T[W++] = t%10;
    reverse(T, T+W);

    // 0: less than, 1: equal to, 2: greater than
    vr<vr<int>> res(N, vr<ll>(N, 0));
    for (int i = 0; i < N; ++i) {
        memset(dp, 0, sizeof dp);
        for (int j = i; j < N; ++j) {
            for (int k = 0; k < W; ++k) {
                dp[j][k][k][0] += 2*(A[j] < T[k]);
                dp[j][k][k][1] += 2*(A[j] == T[k]);
                dp[j][k][k][2] += 2*(A[j] > T[k]);
            }
            if (i == j) continue;
            for (int l = W-1; l >= 0; --l) {
                for (int r = l; r < W; ++r) {
                    dp[j][l][r][0] += dp[j-1][l][r][0];
                    dp[j][l][r][1] += dp[j-1][l][r][1];
                    dp[j][l][r][2] += dp[j-1][l][r][2];
                    for (int c = 0; c < 3; ++c) dp[j][l][r][c] = dp[j][l][r][c] % MOD;
                    if (l == r) continue;  // no empty papers
                    if (A[j] > T[l]) {
                        dp[j][l][r][2] += dp[j-1][l+1][r][0];
                        dp[j][l][r][2] += dp[j-1][l+1][r][1];
                        dp[j][l][r][2] += dp[j-1][l+1][r][2];
                    }
                    if (A[j] < T[l]) {
                        dp[j][l][r][0] += dp[j-1][l+1][r][0];
                        dp[j][l][r][0] += dp[j-1][l+1][r][1];
                        dp[j][l][r][0] += dp[j-1][l+1][r][2];
                    }
                    if (A[j] == T[l]) {
                        dp[j][l][r][0] += dp[j-1][l+1][r][0];
                        dp[j][l][r][1] += dp[j-1][l+1][r][1];
                        dp[j][l][r][2] += dp[j-1][l+1][r][2];
                    }
                    dp[j][l][r][0] += dp[j-1][l][r-1][0] + dp[j-1][l][r-1][1]*(A[j] < T[r]);  //
                    dp[j][l][r][1] += dp[j-1][l][r-1][1]*(A[j] == T[r]);
                    dp[j][l][r][2] += dp[j-1][l][r-1][2] + dp[j-1][l][r-1][1]*(A[j] > T[r]);
                    for (int c = 0; c < 3; ++c) dp[j][l][r][c] = dp[j][l][r][c] % MOD;
                }
            }
            for (int k = 0; k < W; ++k) {
                res[i][j] += dp[j][k][W-1][0];
                res[i][j] += dp[j][k][W-1][1];
                if (k) res[i][j] += dp[j][k][W-1][2];
                res[i][j] %= MOD;
            }
        }
    }
    return res;
}

signed main() {
    cin >> N >> X1 >> X2;
    for (int i = 0; i < N; ++i) cin >> A[i];

    auto up = sol(X2), low = sol(X1-1);
    cin >> Q;
    while (Q--) {
        int l, r; cin >> l >> r; --l; --r;
        cout << (up[l][r]-low[l][r]+MOD)%MOD << endl;
    }
}