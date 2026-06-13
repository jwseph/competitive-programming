#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+7;

int dp[N][2];

int main() {
    memset(dp, -1, sizeof dp);
    for (int i = 0; i*i < N; i++) {
        for (int j = i; i*i+j*j < N; j++) {
            int s = i*i+j*j;
            dp[s][0] = i;
            dp[s][1] = j;
        }
    }
    int nt; cin >> nt;
    while (nt--) {
        int n; cin >> n;
        for (int h = 0; h <= n/2; ++h) {
            if (dp[h][0] < 0 || dp[n-h][0] < 0) continue;
            cout << dp[h][0] << ' ' << dp[h][1] << ' ';
            cout << dp[n-h][0] << ' ' << dp[n-h][1] << endl;
            break;
        }
    }
}