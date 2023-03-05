#include <bits/stdc++.h>
using namespace std;

int dr[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dc[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int R, C, A[50+2][50+2];

int main() {
    cin >> R >> C;
    memset(A, -1, sizeof A);
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            cin >> A[r][c];
        }
    }
    int res = -1;
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            for (int i = 0; i < 8; ++i) {
                if (A[r][c] == A[r+dr[i]][c+dc[i]]) {
                    res = max(res, A[r][c]);
                    break;
                }
            }
        }
    }
    cout << res << endl;
}