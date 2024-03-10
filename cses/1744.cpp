#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e2+5;
int N, M, dp[MAXN][MAXN];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = 1e9;
            for (int h = 1; h <= i/2; ++h) {
                dp[i][j] = min(dp[i][j], dp[h][j]+dp[i-h][j]+1);
            }
            for (int h = 1; h <= j/2; ++h) {
                dp[i][j] = min(dp[i][j], dp[i][h]+dp[i][j-h]+1);
            }
        }
    }
    cout << dp[N][M] << endl;
}