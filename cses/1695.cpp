#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 5e2+5;
int N, M;
map<int, ll> A[MAXN];
int V[MAXN], v = 1;
vector<pair<int, int>> res;

ll sol(int i, ll w) {
    if (i == N-1) return w;
    if (V[i] == v) return 0;
    V[i] = v;
    for (auto [j, w0]: A[i]) {
        ll cut = sol(j, min(w, w0));
        if (cut) {
            A[i][j] -= cut;
            A[j][i] += cut;
            if (!A[i][j]) A[i].erase(j);
            return cut;
        }
    }
    return 0;
}

void dfs(int i) {
    if (V[i] == v) return;
    V[i] = v;
    for (auto [j, w]: A[i]) {
        dfs(j);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j; --i, --j;
        A[i][j]++, A[j][i]++;
    }
    while (sol(0, LLONG_MAX)) v++;
    v++;
    dfs(0);
    for (int j = 0; j < N; ++j) {
        for (auto [i, w]: A[j]) {
            if (V[i] == v && V[j] != v && !A[i][j]) {
                res.push_back({i, j});
            }
        }
    }
    cout << res.size() << endl;
    for (auto [i, j]: res) cout << i+1 << ' ' << j+1 << endl;
}