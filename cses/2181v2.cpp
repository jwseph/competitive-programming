#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int N, M, dp[1001][1<<10];
vector<array<int, 2>> S;

bool check(int s, int t) {
    int l = 0;
    for (int p = 0; p < M; ++p) {
        int a = s&1<<p, b = t&1<<p;
        if (a && b) return 0;
        if (!a && !b) ++l;
        else if (l&1) return 0;
    }
    if (l&1) return 0;
    return 1;
}

int main() {
    cin >> M >> N;
    for (int s = 0; s < (1<<M); ++s) {
        for (int t = 0; t < (1<<M); ++t) {
            if (check(s, t)) S.push_back({s, t});
        }
    }
    dp[0][0] = 1;
    for (int i = 0; i < N; ++i) {
        for (auto [s, t]: S) {
            dp[i+1][t] += dp[i][s];
            dp[i+1][t] %= MOD;
        }
    }
    cout << dp[N][0] << endl;
}