#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;
int R, C;
string A[MAXN];
char V[MAXN][MAXN];
queue<array<int, 2>> Q;

const array<int, 2> d4[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
string D1 = "RULD", D2 = "LDRU";

int main() {
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        cin >> A[r];
        for (int c = 0; c < C; ++c) {
            if (A[r][c] == 'A') {
                Q.push({r, c});
                V[r][c] = '*';
            }
        }
    }
    while (Q.size()) {
        auto [r, c] = Q.front();
        Q.pop();
        if (A[r][c] == '#') continue;
        if (A[r][c] == 'B') {
            cout << "YES" << endl;
            string res;
            while (V[r][c] != '*') {
                res += V[r][c];
                int d = D2.find(V[r][c]);
                auto [dr, dc] = d4[d];
                r += dr, c += dc;
            }
            reverse(begin(res), end(res));
            cout << res.size() << endl;
            cout << res << endl;
            return 0;
        }
        for (int d = 0; d < 4; ++d) {
            auto [dr, dc] = d4[d];
            int i = r+dr, j = c+dc;
            if (i < 0 || i >= R || j < 0 || j >= C) continue;
            if (V[i][j]) continue;
            V[i][j] = D1[d];
            Q.push({i, j});
        }
    }
    cout << "NO" << endl;
}