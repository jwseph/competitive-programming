#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int n, m, req[N], vst[N];
vector<int> adj[N];
priority_queue<int> pq;

int main() {
    cin >> n >> m;
    for (int e = 0; e < m; ++e) {
        int i, j; cin >> i >> j;
        adj[j].push_back(i);
        req[i]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (req[i] == 0) {
            pq.push(i);
        }
    }
    vector<int> res;
    while (pq.size()) {
        int i = pq.top(); pq.pop();
        res.push_back(i);
        vst[i] = 1;
        for (int j: adj[i]) {
            if (vst[j]) continue;
            if (--req[j] == 0) {
                pq.push(j);
            }
        }
    }
    reverse(begin(res), end(res));
    for (int i: res) cout << i << ' ';
    cout << endl;
}