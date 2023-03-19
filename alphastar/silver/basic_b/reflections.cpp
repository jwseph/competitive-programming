#include <bits/stdc++.h>
using namespace std;

#define N_MAX 1000

int R, C;
char A[N_MAX][N_MAX];

int sol(int r, int c, int dr, int dc) {
    int res = 0;
    while (0 <= r && r < R && 0 <= c && c < C) {
        swap(dr, dc);
        if (A[r][c] == '/') {
            dr = -dr;
            dc = -dc;
        }
        r += dr;
        c += dc;
        ++res;
    }
    return res;
}

int main() {
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        string S; cin >> S;
        for (int c = 0; c < C; ++c) {
            A[r][c] = S[c];
        }
    }
    int res = 0;
    for (int r = 0; r < R; ++r) {
        res = max(res, sol(r, 0, 0, 1));
        res = max(res, sol(r, C-1, 0, -1));
    }
    for (int c = 0; c < C; ++c) {
        res = max(res, sol(0, c, 1, 0));
        res = max(res, sol(R-1, c, -1, 0));
    }
    cout << res << endl;
}