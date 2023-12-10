#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

#define MAXN 1003

int N, A[MAXN][MAXN];

int main() {
    cin >> N;
    for (int r = 0; r < N; ++r) {
        string S; cin >> S;
        for (int c = 0; c < N; ++c) {
            A[r][c] = S[c] == 'R';
        }
    }
    for (int r = 0; r < N; ++r) {
        if (A[r][0] == 0) continue;
        for (int c = 0; c < N; ++c) A[r][c] ^= 1;
    }
    for (int c = 0; c < N; ++c) {
        if (A[0][c] == 0) continue;
        for (int r = 0; r < N; ++r) A[r][c] ^= 1;
    }
    vector<pii> res;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (A[r][c]) res.push_back({r, c});
        }
    }
    if (res.size() > 1) {
        for (int r = 0; r < N; ++r) {
            if (A[r][N-1] == 0) continue;
            for (int c = 0; c < N; ++c) A[r][c] ^= 1;
        }
        for (int c = 0; c < N; ++c) {
            if (A[N-1][c] == 0) continue;
            for (int r = 0; r < N; ++r) A[r][c] ^= 1;
        }
        res = {};
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                if (A[r][c]) res.push_back({r, c});
            }
        }
    }
    if (res.size() != 1) {
        cout << -1 << endl;
        return 0;
    }
    if (N == 2) {
        cout << "1 1" << endl;
        return 0;
    }
    cout << res[0].first+1 << " " << res[0].second+1 << endl;
}