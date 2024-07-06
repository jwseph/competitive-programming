#include <bits/stdc++.h>
using namespace std;

#define MAXN 1003
#define ll long long

int N, M, C, P[MAXN], dp[MAXN][MAXN];
vector<int> A[MAXN];

int main() {
    ifstream cin("time.in");
    ofstream cout("time.out");
    cin >> N >> M >> C;
    for (int i = 0; i < N; ++i) cin >> P[i];
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j; --i; --j;
        A[i].push_back(j);
    }
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for (int t = 0; t < MAXN-1; ++t) {
        for (int i = 0; i < N; ++i) {
            if (dp[t][i] < 0) continue;
            for (int j: A[i]) {
                dp[t+1][j] = max({dp[t+1][j], dp[t][i] + P[j]});
            }
        }
    }
    ll res = 0;
    for (int t = 0; t < MAXN; ++t) {
        res = max(res, dp[t][0] - (ll)C*t*t);
    }
    cout << res << endl;
}