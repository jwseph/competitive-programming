#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int N, M;
vector<int> A[MAXN];

int dp[MAXN], p[MAXN];
int dfs(int i) {
    if (i == N) return 1;
    if (dp[i]) return dp[i];
    int res = -1e9;
    for (int j: A[i]) {
        if (res < dfs(j)+1) {
            res = dfs(j)+1;
            p[i] = j;
        }
    }
    return dp[i] = res;
}

int main() {
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j;
        A[i].push_back(j);
    }
    int res = dfs(1);
    if (res < 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << res << endl;
    for (int j = 1; j; j = p[j]) {
        cout << j << ' ';
    }
    cout << endl;
}