#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e18;

const int MAXN = 2.5e3+5, MAXM = 5e3+5;
int N, M;
vector<array<int, 3>> E;
ll dp[MAXN];

int main() {
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j, t; cin >> i >> j >> t;
        E.push_back({i, j, t});
    }
    for (int i = 2; i <= N; ++i) dp[i] = -INF;
    for (int e = 0; e < N-1; ++e) {
        for (auto [i, j, t]: E) {
            dp[j] = max(dp[j], dp[i]+t);
        }
    }
    for (auto [i, j, t]: E) {
        if (dp[i] > -INF/10 && dp[j] < dp[i]+t) dp[j] = INF;
    }
    for (int e = 1; e < N-1; ++e) {
        for (auto [i, j, t]: E) {
            dp[j] = max(dp[j], dp[i]+t);
        }
    }
    cout << (dp[N] < INF/10 ? dp[N] : -1) << endl;
}