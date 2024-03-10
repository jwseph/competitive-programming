#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2, MAXK = 1e6+5;
int N, K, A[MAXN], dp[MAXK];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A, A+N);
    for (int k = 1; k <= K; ++k) {
        dp[k] = 1e9;
        for (int i = 0; i < N && k-A[i] >= 0; ++i) {
            dp[k] = min(dp[k], 1+dp[k-A[i]]);
        }
    }
    cout << (dp[K] < 1e9 ? dp[K] : -1) << endl;
}