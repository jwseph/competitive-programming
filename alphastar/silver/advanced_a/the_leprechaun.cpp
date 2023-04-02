#include <bits/stdc++.h>
using namespace std;

#define MAXN 200

int dr[4] = {0, 1, 1, 1};
int dc[4] = {1, 0, 1, -1};

int N, A[MAXN][MAXN], res = INT_MIN;

void sol(int r, int c, int d) {
    int S = 0, s = 0, M = INT_MIN, m = INT_MAX, sum = 0;
    for (int i = 0; i < N; ++i) {
        int x = A[(r+i*dr[d]+3*N)%N][(c+i*dc[d]+3*N)%N];
        sum += x;
        S = max(S+x, x);
        s = min(s+x, x);
        M = max(M, S);
        m = min(m, s);
    }
    if (M < 0) res = max(res, M);
    else res = max({res, M, sum-m});
}

int main() {
    cin >> N;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> A[r][c];
        }
    }
    for (int c = 0; c < N; ++c) {
        for (int d = 1; d < 4; ++d) {
            sol(0, c, d);
        }
    }
    for (int r = 0; r < N; ++r) {
        sol(r, 0, 0);
    }
    cout << res << endl;
}