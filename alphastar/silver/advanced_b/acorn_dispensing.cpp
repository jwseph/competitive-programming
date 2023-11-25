#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};

int N, M;
bool V[MAXN][MAXN]{}, L[MAXN][MAXN]{};
vector<pair<int, int>> G[MAXN][MAXN];
queue<pair<int, int>> Q;

int main() {
    cin >> N >> M;
    while (M--) {
        int r, c, i, j; cin >> r >> c >> i >> j; --r; --c; --i; --j;
        G[r][c].push_back({i, j});
    }
    V[0][0] = L[0][0] = 1;
    Q.push({0, 0});
    while (Q.size()) {
        auto [r, c] = Q.front();
        Q.pop();
        for (int d = 0; d < 4; ++d) {
            int i = r+dr[d], j = c+dc[d];
            if (i < 0 || i >= N || j < 0 || j >= N || V[i][j] || !L[i][j]) continue;
            V[i][j] = 1;
            Q.push({i, j});
        }
        for (auto [i, j]: G[r][c]) {
            if (L[i][j]) continue;
            L[i][j] = 1;
            if (V[i][j]) continue;
            int cnt = 0;
            for (int d = 0; d < 4; ++d) {
                int a = i+dr[d], b = j+dc[d];
                if (a < 0 || a >= N || b < 0 || b >= N) continue;
                cnt += V[a][b];
            }
            if (!cnt) continue;
            V[i][j] = 1;
            Q.push({i, j});
        }
    }
    int res = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            res += L[r][c];
        }
    }
    cout << res << endl;
}