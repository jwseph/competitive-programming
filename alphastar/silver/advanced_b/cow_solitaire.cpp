#include <bits/stdc++.h>
using namespace std;

#define MAXN 10

int N, dp[MAXN][MAXN];
string P = "0A23456789TJQK";

int main() {
    cin >> N;
    for (int r = N-1; r >= 0; --r) {
        for (int c = 0; c < N; ++c) {
            string S; cin >> S;
            dp[r+1][c+1] = P.find(S[0]);
        }
    }
    for (int r = 0; r <= N; ++r) dp[r][0] = 0;
    for (int c = 0; c <= N; ++c) dp[0][c] = 0;
    for (int r = 1; r <= N; ++r) {
        for (int c = 1; c <= N; ++c) {
            dp[r][c] += max(dp[r-1][c], dp[r][c-1]);
        }
    }
    cout << dp[N][N] << endl;
}