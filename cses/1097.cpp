#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 5e3+5;
int N, A[MAXN];
ll dp[MAXN][2];

int main() {
    cin >> N;
    ll res = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        res += A[i];
    }
    for (int w = 0; w <= N; ++w) {
        for (int i = 0, j = w; j <= N; ++i, ++j) {
            if (i == j) {
                dp[i][(j-i)%2] = 0;
                continue;
            }
            dp[i][(j-i)%2] = max(A[i]-dp[i+1][(j-i-1)%2], A[j-1]-dp[i][(j-i-1)%2]);
        }
    }
    res += dp[0][N%2];
    res /= 2;
    cout << res << endl;
}