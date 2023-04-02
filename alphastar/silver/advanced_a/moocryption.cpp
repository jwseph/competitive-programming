#include <bits/stdc++.h>
using namespace std;

#define MAXR 50

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int R, C;
string A[MAXR];
unordered_map<string, int> cnt;

void sol(int r, int c, int d) {
    string S;
    for (int i = 0; i < 3; ++i) {
        S += A[r+dr[d]*i][c+dc[d]*i];
    }
    if (S[0] != S[1] && S[1] == S[2] && S[0] != 'M' && S[1] != 'O') ++cnt[S];
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        cin >> A[i];
    }
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            for (int d = 0; d < 8; ++d) {
                if (r+dr[d]*2 < 0 || r+dr[d]*2 >= R) continue;
                if (c+dc[d]*2 < 0 || c+dc[d]*2 >= C) continue;
                sol(r, c, d);
            }
        }
    }
    int res = 0;
    for (const auto& p: cnt) {
        res = max(res, p.second);
    }
    cout << res << endl;
}