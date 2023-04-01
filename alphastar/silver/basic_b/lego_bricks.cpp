#include <bits/stdc++.h>
using namespace std;

#define MAXN 50

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int R, C;
char A[MAXN][MAXN];
bool V[MAXN][MAXN];
queue<pair<int, int>> Q;

void fill(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C || V[r][c]) return;
    V[r][c] = true;
    if (A[r][c] == '.') {
        Q.push({r, c});
        return;
    }
    for (int d = 0; d < 4; ++d) {
        fill(r+dr[d], c+dc[d]);
    }
}

void add(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C || V[r][c]) return;
    V[r][c] = true;
    Q.push({r, c});
}

int main() {
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        string S; cin >> S;
        for (int c = 0; c < C; ++c) {
            A[r][c] = S[c];
        }
    }
    bool fnd = false;
    for (int r = 0; !fnd && r < R; ++r) {
        for (int c = 0; !fnd && c < C; ++c) {
            if (A[r][c] == 'X') {
                fill(r, c);
                fnd = true;
            }
        }
    }
    for (int res = 0; !Q.empty(); ++res) {
        for (int s = Q.size(); s > 0; --s) {
            int r = Q.front().first, c = Q.front().second;
            Q.pop();
            if (A[r][c] == 'X') {
                cout << res << endl;
                return 0;
            }
            for (int d = 0; d < 4; ++d) {
                add(r+dr[d], c+dc[d]);
            }
        }
    }
}