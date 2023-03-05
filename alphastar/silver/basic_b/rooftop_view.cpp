#include <bits/stdc++.h>
using namespace std;

int R, C;
bool V[1000][80];

int dfs(int r, int c) {
    if (!(0 <= r&&r < R && 0 <= c&&c < C) || V[r][c]) return 0;
    V[r][c] = true;
    return 1+dfs(r-1, c)+dfs(r+1, c)+dfs(r, c-1)+dfs(r, c+1);
}

int main() {
    cin >> C >> R;
    for (int r = 0; r < R; ++r) {
        string S; cin >> S;
        for (int c = 0; c < C; ++c) {
            V[r][c] = S[c] == '.';
        }
    }
    int res = 0;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            res = max(res, dfs(r, c));
        }
    }
    cout << res << endl;
}