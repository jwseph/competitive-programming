#include <bits/stdc++.h>
using namespace std;

#define N_MAX 100

int R, C, fr, fc;
bool A[N_MAX][N_MAX];

void dfs(int r, int c, string S) {
    if (!(0 <= r && r < R && 0 <= c && c < C)) return;
    if (A[r][c]) return;
    A[r][c] = true;
    if (r == fr && c == fc) {
        cout << S << endl;
        return;
    }
    dfs(r-1, c, S+'U');
    dfs(r+1, c, S+'D');
    dfs(r, c-1, S+'L');
    dfs(r, c+1, S+'R');
}

int main() {
    cin >> R >> C;
    int sr, sc;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            char X; cin >> X;
            A[r][c] = X == '#';
            if (X == 'S') {
                sr = r;
                sc = c;
            }
            if (X == 'F') {
                fr = r;
                fc = c;
            }
        }
    }
    dfs(sr, sc, "");
}