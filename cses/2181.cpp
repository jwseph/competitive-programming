#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9+7;
int N, M;
ll dp[2][1<<20];
vector<int> S;

void add(int i, int s, int v) {
    dp[i&1][s] += v;
    dp[i&1][s] %= MOD;
}

bool check(int s) {
    for (int p = 0; p < M; ++p) {
        if (s&1<<p) continue;
        if (s&1<<p+M) return 0;
    }
    return 1;
}

int main() {
    // O(n*3^m+4^m)
    cin >> M >> N;
    for (int s = 0; s < (1<<2*M); ++s) {
        if (check(s)) S.push_back(s);
    }
    add(0, 0, 1);
    for (int i = 0; i < N; ++i) {
        for (int s: S) {
            if (!dp[i&1][s]) continue;
            bool fnd = 0;
            for (int p = 0; p < M && !fnd; ++p) {
                if (s & 1<<p) continue;
                if (p+1 < M && !(s & 1<<p+1)) {
                    add(i, s | 1<<p | 1<<p+1, dp[i&1][s]), fnd = 1;
                }
                if (!(s & 1<<p+M)) {
                    add(i, s | 1<<p | 1<<p+M, dp[i&1][s]), fnd = 1;
                }
            }
            if (!fnd) add(i+1, s>>M, dp[i&1][s]);
            dp[i&1][s] = 0;
        }
    }
    cout << dp[N%2][0] << endl;
}