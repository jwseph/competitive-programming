#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20, MOD = 1e9+7;
int N, M;
vector<int> A[MAXN];
int dp[MAXN][1<<MAXN];

int sol(int i, int v) {
    if (i == N-1 && v == (1<<N)-1) return 1;
    if (i == N-1) return 0;
    if (dp[i][v] >= 0) return dp[i][v];
    int res = 0;
    for (int j: A[i]) {
        if (v&1<<j) continue;
        res = (res + sol(j, v|1<<j)) % MOD;
    }
    return dp[i][v] = res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(dp, -1, sizeof dp);
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j; --i, --j;
        A[i].push_back(j);
    }
    cout << sol(0, 1) << endl;
}