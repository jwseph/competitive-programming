#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2.5e3+5;
int N, M;
vector<array<int, 3>> E;
int p[MAXN];
ll dp[MAXN];

int main() {
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j, t; cin >> i >> j >> t;
        E.push_back({i, j, t});
    }
    int v = 0;
    for (int e = 0; e < N; ++e) {
        v = 0;
        for (auto [i, j, t]: E) {
            if (dp[j] > dp[i]+t) {
                dp[j] = dp[i]+t;
                p[j] = i;
                v = j;
            }
        }
    }
    if (!v) {
        cout << "NO" << endl;
        return 0;
    }
    for (int e = 0; e < N-1; ++e) v = p[v];  // Make sure node is part of the cycle, not just a reachable node
    vector<int> res;
    while (res.size() < 2 || res[0] != res.back()) {
        res.push_back(v);
        v = p[v];
    }
    reverse(begin(res), end(res));
    cout << "YES" << endl;
    for (int i: res) cout << i << ' ';
    cout << endl;
}