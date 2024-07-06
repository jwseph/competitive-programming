#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n, m;
int loc[N], edges[N], vst[N], res[N];
vector<int> ad[N], unlock[N];
queue<int> q;

void add(int i) {
    if (vst[i] || loc[i] || edges[i] > 1) return;
    vst[i] = 1;
    q.push(i);
}

void dfs(int i, int p) {
    if (unlock[i].size()) return;
    res[i] = 1;
    for (int j: ad[i]) {
        if (j == p) continue;
        dfs(j, i);
    }
}

int main() {
    ifstream cin("gathering.in");
    ofstream cout("gathering.out");
    cin >> n >> m;
    for (int e = 0; e < n-1; ++e) {
        int i, j; cin >> i >> j;
        ad[i].push_back(j), ad[j].push_back(i);
        edges[i]++, edges[j]++;
    }
    while (m--) {
        int a, b; cin >> a >> b;  // a unlocks b
        unlock[a].push_back(b);
        loc[b]++;
    }
    for (int i = 1; i <= n; ++i) add(i);
    int rem = n;
    while (q.size()) {
        int i = q.front(); q.pop();
        if (!--rem) dfs(i, -1);
        for (int j: unlock[i]) loc[j]--, add(j);
        for (int j: ad[i]) edges[j]--, add(j);
    }
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << endl;
    }
}