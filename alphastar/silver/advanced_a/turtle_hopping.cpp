#include <bits/stdc++.h>
using namespace std;

#define MAXN 30

int R, C, X, Y, A[MAXN][MAXN];
bool V[MAXN][MAXN];
queue<pair<int, int>> Q;

int main() {
    cin >> R >> C >> X >> Y;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> A[r][c];
            if (A[r][c] == 3) {
                V[r][c] = 1;
                Q.push({r, c});
            }
        }
    }
    for (int res = 0; Q.size(); ++res)
    for (int s = Q.size(); s > 0; --s) {
        int r = Q.front().first, c = Q.front().second; Q.pop();
        if (A[r][c] == 4) {
            cout << res << endl;
            return 0;
        }
        if (A[r][c] == 0 || A[r][c] == 2) continue;
        int dr[] = {X, X, -X, -X, Y, Y, -Y, -Y};
        int dc[] = {Y, -Y, Y, -Y, X, -X, X, -X};
        for (int d = 0; d < 8; ++d) {
            int i = r+dr[d], j = c+dc[d];
            if (i < 0 || i >= R || j < 0 || j >= C || V[i][j]) continue;
            V[i][j] = 1;
            Q.push({i, j});
        }
    }
}