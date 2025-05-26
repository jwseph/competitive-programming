#include <bits/stdc++.h>
using namespace std;

const int N = 102, M = 1003;
int n, x;
int h[N], s[N], k[N], dp[N][M];  // i, money

int main() {
    // Probably a LineContainer problem convex hull?
    // No. Maybe by order of increasing price/page with binary jumping to find endpoint.
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> h[i];
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
        for (int m = 0; m < M; ++m) {
            for (int j = 0; j <= k[i] && j*h[i] <= m; ++j) {
                dp[i][m] = max(dp[i][m], dp[i-1][m-j*h[i]] + j*s[i]);
            }
        }
    }
    cout << dp[n][x] << endl;
}