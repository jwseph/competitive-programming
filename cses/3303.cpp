#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n, m, k, v[N][2], dst[N][2];
vector<int> adj[N];

int main() {
    cin >> n >> m >> k;
    queue<array<int, 2>> q;
    while (k--) {
        int i; cin >> i;
        v[i][0] = i;
        dst[i][0] = 0;
        q.push({i, i});
    }
    while (m--) {
        int i, j; cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    for (int d = 0; q.size(); ++d) {
        for (int qs = q.size(); qs --> 0;) {
            auto [i, src] = q.front(); q.pop();
            for (int j: adj[i]) {
                if (v[j][0] && v[j][1] || src == v[j][0]) continue;
                int t = v[j][0] ? 1 : 0;
                v[j][t] = src;
                dst[j][t] = d+1;
                q.push({j, src});
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int cur = !v[i][0] ? -1 : v[i][0] != i ? dst[i][0] : !v[i][1] ? -1 : dst[i][1];
        cout << cur << ' ';
    }
    cout << endl;
}