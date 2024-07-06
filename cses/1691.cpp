#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5, MAXM = 2e5+5;
int N, M;
queue<pair<int, int>> A[MAXN];
vector<int> res;
bool V[MAXM];

void dfs(int i) {
    while (A[i].size()) {
        auto [j, e] = A[i].front(); A[i].pop();
        if (V[e]) continue;
        V[e] = 1;
        dfs(j);
    }
    res.push_back(i);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j;
        A[i].push({j, e});
        A[j].push({i, e});
    }
    for (int i = 1; i <= N; ++i) {
        if (A[i].size()&1) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    dfs(1);
    if (res.size() != M+1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i: res) cout << i << ' ';
    cout << endl;
}