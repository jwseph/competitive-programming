#include <bits/stdc++.h>
using namespace std;

#define MAXN 1003

int N, A[MAXN][MAXN];

int sol(int r1, int r2) {
    int cnt[2]{}, idx[2];
    for (int c = 0; c < N; ++c) {
        int cur = (A[r1][c]+A[r2][c])%2;
        cnt[cur]++;
        idx[cur] = c;
    }
    for (int t = 0; t < 2; ++t) {
        if (cnt[t] == 1) return idx[t];
    }
    return -1;
}

int main() {
    cin >> N;
    for (int r = 0; r < N; ++r) {
        string S; cin >> S;
        for (int c = 0; c < N; ++c) {
            A[r][c] = S[c] == 'R';
        }
    }
    int res_c = -1, res_d = 0;
    for (int r = 0; r < N; ++r) {
        int d = sol(0, r);
        res_d += d >= 0;
        res_c = max(res_c, d);
    }
    for (int r = 0; r < N; ++r) for (int c = r+1; c < N; ++c) {
        swap(A[r][c], A[c][r]);
    }
    int res_r = -1;
    for (int c = 0; c < N; ++c) {
        int d = sol(0, c);
        res_r = max(res_r, d);
    }
    if (res_r == 0) res_d = N-res_d;
    if (res_r == -1 || res_c == -1) {
        cout << -1 << endl;
        return 0;
    }
    if (N == 2) {
        cout << "1 1" << endl;
        return 0;
    }
    if (res_d != 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << res_r+1 << ' ' << res_c+1 << endl;
}