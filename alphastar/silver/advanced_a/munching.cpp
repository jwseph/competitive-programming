#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};

int R, C;
string A[MAXN];
queue<pair<int, int>> Q;

int main() {
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        cin >> A[r];
        for (int c = 0; c < C; ++c) {
            if (A[r][c] == 'C') {
                Q.push({r, c});
                A[r][c] = '*';
            }
        }
    }
    for (int res = 0; Q.size(); ++res) {
        for (int qs = Q.size(); qs > 0; --qs) {
            auto [r, c] = Q.front();
            Q.pop();
            for (int d = 0; d < 4; ++d) {
                int i = r+dr[d], j = c+dc[d];
                if (i < 0 || i >= R || j < 0 || j >= C || A[i][j] == '*') continue;
                if (A[i][j] == 'B') {
                    cout << res+1 << endl;
                    return 0;
                }
                A[i][j] = '*';
                Q.push({i, j});
            }
        }
    }
    cout << -1 << endl;
}