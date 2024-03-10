#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5;
int N, dp[MAXN];

int main() {
    cin >> N;
    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
        dp[i] = 1e9;
        for (int t = i; t; t /= 10) {
            int d = t%10;
            dp[i] = min(dp[i], 1+dp[i-d]);
        }
    }
    cout << dp[N] << endl;
}