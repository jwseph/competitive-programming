#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;
int R, C;
string A[MAXN];
queue<array<int, 3>> Q;
char V[MAXN][MAXN];

const array<int, 2> d4[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
const string D1 = "RULD", D2 = "LDRU";

int main() {
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        cin >> A[r];
        for (int c = 0; c < C; ++c) {
            if (A[r][c] == 'M') {
                V[r][c] = 'X';
                Q.push({r, c, 0});
            }
        }
    }
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (A[r][c] == 'A') {
                V[r][c] = '*';
                Q.push({r, c, 1});
            }
        }
    }
    while (Q.size()) {
        auto [r, c, p] = Q.front();
        Q.pop();
        if (p && (r == 0 || r == R-1 || c == 0 || c == C-1)) {
            string res;
            while (V[r][c] != '*') {
                res += V[r][c];
                auto [dr, dc] = d4[D2.find(V[r][c])];
                r += dr, c += dc;
            }
            reverse(begin(res), end(res));
            cout << "YES" << endl;
            cout << res.size() << endl;
            cout << res << endl;
            return 0;
        }
        for (int d = 0; d < 4; ++d) {
            auto [dr, dc] = d4[d];
            int i = r+dr, j = c+dc;
            if (i < 0 || i >= R || j < 0 || j >= C) continue;
            if (V[i][j] || A[i][j] == '#') continue;
            V[i][j] = D1[d];
            Q.push({i, j, p});
        }
    }
    cout << "NO" << endl;
}