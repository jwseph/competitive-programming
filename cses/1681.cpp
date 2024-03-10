#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9+7;

const int MAXN = 1e5+5;
int N, M;
vector<int> A[MAXN];

ll dp[MAXN];
ll dfs(int i) {
    if (i == N) return 1;
    if (dp[i] >= 0) return dp[i];
    ll res = 0;
    for (int j: A[i]) {
        res += dfs(j);
        res %= MOD;
    }
    return dp[i] = res;
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j;
        A[i].push_back(j);
    }
    cout << dfs(1) << endl;
}