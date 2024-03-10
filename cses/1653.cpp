#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20, INF = 1e9;
int N, K, A[MAXN];
array<int, 2> dp[(1<<MAXN)+5];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int s = 0; s < (1<<N); ++s) {
        if (!s) {
            dp[s] = {1, 0};
            continue;
        }
        dp[s] = {INF, INF};
        for (int i = 0; i < N; ++i) if (s&1<<i) {
            auto [n, t] = dp[s^1<<i];
            dp[s] = min(dp[s], {n+1, A[i]});
            if (t+A[i] <= K) dp[s] = min(dp[s], {n, t+A[i]});
        }
    }
    cout << dp[(1<<N)-1][0] << endl;
}