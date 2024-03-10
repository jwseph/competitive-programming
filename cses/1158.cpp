#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+5, MAXK = 1e5+5;
int N, K, H[MAXN], S[MAXN], dp[2][MAXK];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> H[i];
    for (int i = 0; i < N; ++i) cin >> S[i];
    for (int i = N-1; i >= 0; --i) {
        for (int k = 1; k <= K; ++k) {
            dp[i%2][k] = max(dp[i%2][k], dp[(i+1)%2][k]);
            if (k-H[i] >= 0) {
                dp[i%2][k] = max(dp[i%2][k], dp[(i+1)%2][k-H[i]] + S[i]);
            }
        }
    }
    cout << dp[0][K] << endl;
}