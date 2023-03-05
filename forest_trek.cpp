#include <bits/stdc++.h>
using namespace std;

int R, C, A[20][30], hr = -1, hc, tr, tc;

int main() {
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            char X; cin >> X;
            if (X == '.') A[r][c] = 0;
            if (X == 'R') A[r][c] = -1;
            if (X == 'B') {
                if (hr < 0) {
                    hr = r;
                    hc = c;
                    A[r][c] = 1;
                } else {
                    tr = r;
                    tc = c;
                    A[r][c] = 0;
                }
            }
        }
    }
    for (int r = 1; r < R; ++r) {
        if (A[r][0] < 0) continue;
        A[r][0] += max(A[r-1][0], 0);
    }
    for (int c = 1; c < C; ++c) {
        if (A[0][c] < 0) continue;
        A[0][c] += max(A[0][c-1], 0);
    }
    for (int r = 1; r <= tr; ++r) {
        for (int c = 1; c <= tc; ++c) {
            if (A[r][c] < 0) continue;
            A[r][c] += max(A[r-1][c], 0);
            A[r][c] += max(A[r][c-1], 0);
        }
    }
    cout << A[tr][tc] << endl;
}