#include <bits/stdc++.h>
using namespace std;

#define MAXN 1503
#define ll long long

int N, NQ, C[MAXN][MAXN], A[MAXN][MAXN]{};
string S[MAXN];
ll res = 0;

void dfs(int r, int c, int f) {
    A[r][c] += f;
    if (r == N || c == N) {
        res += (ll) f * C[r][c];
        return;
    }
    if (S[r][c] == 'R') dfs(r, c+1, f);
    else dfs(r+1, c, f);
}

int main() {
    cin >> N;
    for (int r = 0; r < N; ++r) {
        cin >> S[r] >> C[r][N];
    }
    for (int c = 0; c < N; ++c) {
        cin >> C[N][c];
    }
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            A[r][c]++;
            if (S[r][c] == 'R') A[r][c+1] += A[r][c];
            else A[r+1][c] += A[r][c];
        }
    }
    for (int r = 0; r < N; ++r) res += (ll) C[r][N] * A[r][N];
    for (int c = 0; c < N; ++c) res += (ll) C[N][c] * A[N][c];
    cout << res << endl;
    cin >> NQ;
    while (NQ--) {
        int r, c; cin >> r >> c; --r; --c;
        int f = A[r][c];
        dfs(r, c, -f);
        S[r][c] = S[r][c] == 'R' ? 'D' : 'R';
        dfs(r, c, f);
        cout << res << endl;
    }
}