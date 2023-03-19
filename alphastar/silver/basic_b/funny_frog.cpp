#include <bits/stdc++.h>
using namespace std;

#define N_MAX 15

int R, C;
char A[N_MAX][N_MAX];

int dfs(int r, int c) {
    if (r == R-1 && c == C-1) return 1;
    int res = 0;
    for (int i = r+1; i < R; ++i) {
        for (int j = c+1; j < C; ++j) {
            if (A[r][c] == A[i][j]) continue;
            res += dfs(i, j);
        }
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
    cout << dfs(0, 0) << endl;
}