#include <bits/stdc++.h>
using namespace std;

int nt, n, m;
int a[102][102];
int dp[102][1003];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> nt >> n >> m;
    for (int t = 0; t < nt; ++t) {
        for (int i = 0; i < n; ++i) {
            cin >> a[t][i];
        }
    }
    for (int t = 0; t < nt-1; ++t) {
        for (int i = n; i >= 0; --i) {
            for (int p = 0; p <= m; ++p) {
                if (i == n) {
                    dp[i][p] = p;
                    continue;
                }
                dp[i][p] = p;
                for (int k = 0; k <= p/a[t][i]; ++k) {
                    dp[i][p] = max(dp[i+1][p], dp[i+1][p-k*a[t][i]] + k*a[t+1][i]);
                }
            }
        }
        m = dp[0][m];
    }
    cout << m << endl;
}