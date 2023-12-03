#include <bits/stdc++.h>
using namespace std;

#define MAXN 10

int N = 9, A[MAXN][MAXN];
bool row[MAXN][MAXN]{}, col[MAXN][MAXN]{}, sub[MAXN][MAXN]{};

int loc(int r, int c) {
    return r/3*3 + c/3;
}

bool sol(int r, int c) {
    if (r == N) return 1;
    if (c == N) return sol(r+1, 0);
    if (A[r][c]) return sol(r, c+1);
    int l = loc(r, c);
    for (int i = 1; i <= N; ++i) {
        if (row[r][i] || col[c][i] || sub[l][i]) continue;
        A[r][c] = i;
        row[r][i] = col[c][i] = sub[l][i] = 1;
        if (sol(r, c+1)) return 1;
        row[r][i] = col[c][i] = sub[l][i] = 0;
        A[r][c] = 0;
    }
    return 0;
}

int main() {
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            int i; cin >> i;
            A[r][c] = i;
            if (i < 0) continue;
            int l = loc(r, c);
            row[r][i] = col[c][i] = sub[l][i] = 1;
        }
    }
    if (!sol(0, 0)) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cout << A[r][c] << ' ';
        }
        cout << endl;
    }
}