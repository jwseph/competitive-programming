// dp[i][]

#include <bits/stdc++.h>
using namespace std;

#define MAXN 2003

int N, A, B, dp[MAXN][MAXN][2]{}, P[MAXN], C[MAXN], X[MAXN];

int main() {
    cin >> N >> A >> B;
    for (int i = 0; i < N; ++i) cin >> P[i] >> C[i] >> X[i];
    int res = 0;
    for (int i = 0; i < N; ++i) {
        for (int c = 0; c <= A; ++c) {
            for (int x = 0; x <= B; ++x) {
                dp[c][x][1] = dp[c][x][0];
            }
        }
        for (int d = 0; d <= C[i]; ++d) {
            int c1 = C[i]-d, x1 = X[i]*d;
            for (int c = c1; c <= A; ++c) {
                for (int x = x1; x <= B; ++x) {
                    dp[c-c1][x-x1][0] = max(dp[c-c1][x-x1][0], dp[c][x][1]+P[i]);
                    res = max(res, dp[c-c1][x-x1][0]);
                }
            }
        }
    }
    cout << res << endl;
}