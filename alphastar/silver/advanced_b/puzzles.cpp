#include <bits/stdc++.h>
using namespace std;

#define MAXN 30

int dr[4] = {-1, -1, 1, 1}, dc[4] = {-1, 1, -1, 1};

int N, K = 0;
string A[MAXN];
vector<pair<int, int>> res, cur;

bool dfs(int r, int c, int k) {
    cur.push_back({r+1, c+1});
    if (k == 0) return 1;
    for (int d = 0; d < 4; ++d) {
        int a = r+dr[d], b = c+dc[d], i = a+dr[d], j = b+dc[d];
        if (i < 0 || i >= N || j < 0 || j >= N || A[i][j] == 'K') continue;
        if (A[a][b] != 'o') continue;
        A[a][b] = '+';
        bool s = dfs(i, j, k-1);
        A[a][b] = 'o';
        if (s) return 1;
    }
    cur.pop_back();
    return 0;
}

int main() {
    cin >> N;
    for (int r = 0; r < N; ++r) {
        cin >> A[r];
        for (int c = 0; c < N; ++c) {
            K += A[r][c] == 'o';
        }
    }
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (A[r][c] != 'K') continue;
            cur = {};
            if (dfs(r, c, K)) {
                res = res.size() ? min(res, cur) : cur;
            }
        }
    }
    for (auto [r, c]: res) {
        cout << r << ' ' << c << endl;
    }
}