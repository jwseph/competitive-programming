#include <bits/stdc++.h>
using namespace std;

template<class K> using heap = priority_queue<K, vector<K>, greater<>>;
using ll = long long;
const ll MOD = 1e9+7, INF = 1e18;

const int MAXN = 1e5+5;
int N, M;
vector<pair<int, int>> A[MAXN];
heap<tuple<ll, int, int>> Q;
array<ll, 4> dp[MAXN];
bool V[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j, t; cin >> i >> j >> t;
        A[i].push_back({j, t});
    }
    for (int i = 1; i <= N; ++i) dp[i] = {INF, 0, INF, -INF};
    dp[0] = {0, 1, -1, -1};
    Q.push({0, 1, 0});
    while (Q.size()) {
        auto [t, i, p] = Q.top(); Q.pop();
        if (t > dp[i][0]) continue;
        dp[i][0] = t;
        dp[i][1] = (dp[i][1] + dp[p][1]) % MOD;
        dp[i][2] = min(dp[i][2], 1+dp[p][2]);
        dp[i][3] = max(dp[i][3], 1+dp[p][3]);
        if (V[i]) continue;
        V[i] = 1;
        for (auto [j, dt]: A[i]) {
            Q.push({t+dt, j, i});
        }
    }
    for (ll res: dp[N]) cout << res << ' ';
    cout << endl;
}