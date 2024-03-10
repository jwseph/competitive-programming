#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3;
int R, C;
bool V[MAXN][MAXN];

const array<int, 2> d4[4] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
void dfs(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return;
    if (V[r][c]) return;
    V[r][c] = 1;
    for (auto [dr, dc]: d4) {
        dfs(r+dr, c+dc);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        string S; cin >> S;
        for (int c = 0; c < C; ++c) {
            V[r][c] = S[c] == '#';
        }
    }
    int res = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (V[r][c]) continue;
            ++res;
            dfs(r, c);
        }
    }
    cout << res << endl;
}