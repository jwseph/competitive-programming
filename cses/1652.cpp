#include <bits/stdc++.h>
using namespace std;

#define MAXN 1003

int N, NQ;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> N >> NQ;
    int P[N+1][N+1];
    memset(P, 0, sizeof P);
    for (int r = 0; r < N; ++r) {
        string S; cin >> S;
        for (int c = 0; c < N; ++c) {
            P[r+1][c+1] += (S[c] == '*') + P[r][c+1] + P[r+1][c] - P[r][c];
        }
    }
    while (NQ--) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2; --r1; --c1;
        int res = P[r2][c2] - P[r1][c2] - P[r2][c1] + P[r1][c1];
        cout << res << endl;
    }
}