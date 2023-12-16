#include <bits/stdc++.h>
using namespace std;

#define MAXN 12

int N, X[MAXN], Y[MAXN], A[MAXN];
map<int, map<int, int>> rows;
set<pair<int, int>> V;

bool dfs2(int x, int y) {
    if (V.find({x, y}) != V.end()) return 1;
    V.insert({x, y});
    auto& row = rows[y];
    auto it = row.lower_bound(x);
    if (it == row.end()) return 0;
    int i = it->second;
    int j = A[i];
    return dfs2(X[j]+1, Y[j]);
}

int dfs(int i) {
    if (i == N) {
        for (auto& [y, row]: rows) {
            for (auto [x, j]: row) {
                V = {};
                if (dfs2(x, y)) return 1;
            }
        }
        return 0;
    }
    if (A[i] >= 0) return dfs(i+1);
    int res = 0;
    for (int j = i+1; j < N; ++j) {
        if (A[j] >= 0) continue;
        A[i] = j; A[j] = i;
        res += dfs(i+1);
        A[i] = A[j] = -1;
    }
    return res;
}

int main() {
    memset(A, -1, sizeof A);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
        rows[Y[i]][X[i]] = i;
    }
    cout << dfs(0) << endl;
}