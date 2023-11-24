#include <bits/stdc++.h>
using namespace std;

#define MAXN 5

int R = 5, C = 5, A[MAXN][MAXN];
unordered_set<int> V;

void dfs(int r, int c, int k, int cur) {
    if (r < 0 || r >= R || c < 0 || c >= C) return;
    cur = cur*10+A[r][c];
    if (k == 1) {
        V.insert(cur);
        return;
    }
    dfs(r-1, c, k-1, cur);
    dfs(r+1, c, k-1, cur);
    dfs(r, c-1, k-1, cur);
    dfs(r, c+1, k-1, cur);
}

int main() {
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> A[r][c];
        }
    }
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            dfs(r, c, 6, 0);
        }
    }
    cout << V.size() << endl;
}