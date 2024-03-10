#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2, MAXK = 1e6+5, MOD = 1e9+7;
int N, K, A[MAXN];
long long dp[MAXK];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A, A+N);
    dp[0] = 1;
    for (int k = 1; k <= K; ++k) {
        for (int i = 0; i < N; ++i) {
            if (k-A[i] < 0) continue;
            dp[k] += dp[k-A[i]];
            dp[k] %= MOD;
        }
    }
    cout << dp[K] << endl;
}