#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int N, M, a, b;
vector<array<int, 2>> E;
vector<int> A[MAXN];
bool V[MAXN];

void dfs(int i) {
    if (V[i]) return;
    V[i] = 1;
    for (int j: A[i]) dfs(j);
}

bool solve(bool s) {
    for (int i = 0; i < N; ++i) A[i] = {}, V[i] = 0;
    for (auto [i, j]: E) {
        if (s) swap(i, j);
        A[i].push_back(j);
    }
    dfs(0);
    for (int i = 0; i < N; ++i) {
        if (V[i]) continue;
        a = 0, b = i;
        if (s) swap(a, b);
        return 0;
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int e = 0; e < M; ++e) {
        int i, j; cin >> i >> j; --i, --j;
        E.push_back({i, j});
    }
    if (solve(0) && solve(1)) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl << a+1 << ' ' << b+1 << endl;
}