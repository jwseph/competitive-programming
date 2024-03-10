#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3+5;
int N, M, dp[MAXN][MAXN];
string A, B;

int main() {
    cin >> A >> B;
    N = A.size(), M = B.size();
    for (int i = N; i >= 0; --i) {
        for (int j = M; j >= 0; --j) {
            if (i == N && j == M) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = 1e9;
            if (i < N) dp[i][j] = min(dp[i][j], 1+dp[i+1][j]);
            if (j < M) dp[i][j] = min(dp[i][j], 1+dp[i][j+1]);
            if (i < N && j < M) dp[i][j] = min(dp[i][j], (A[i] != B[j]) + dp[i+1][j+1]);
        }
    }
    cout << dp[0][0] << endl;
}