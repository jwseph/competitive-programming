#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 5e2+5;
const ll INF = 1e18;
int N, M, Q;
ll dp[MAXN][MAXN];

int main() {
    cin >> N >> M >> Q;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j] = INF;
        }
        dp[i][i] = 0;
    }
    while (M--) {
        int i, j; ll t; cin >> i >> j >> t; --i, --j;
        dp[i][j] = min(dp[i][j], t);
        dp[j][i] = min(dp[j][i], t);
    }
    for (int h = 0; h < N; ++h) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][h] + dp[h][j]);
            }
        }
    }
    while (Q--) {
        int i, j; cin >> i >> j; --i, --j;
        ll res = dp[i][j];
        cout << (res < 1e18 ? res : -1) << endl;
    }
}