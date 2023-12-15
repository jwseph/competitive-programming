#include <bits/stdc++.h>
using namespace std;

#define MAXN 202

int N, R, C;
char A[MAXN][MAXN];
vector<int> rows, cols;
vector<tuple<int, int, char>> pts;
unordered_map<int, int> rm, cm;
int V[MAXN][MAXN][4]{}, vi = 1;

bool sol(int r, int c, int dr, int dc) {
    ++vi;
    while (0 <= r && r < R && 0 <= c && c < C) {
        int d = dr == 1 ? 0 : dr == -1 ? 1 : dc == 1 ? 2 : 3;
        if (V[r][c][d] == vi) return 0;
        V[r][c][d] = vi;
        if (A[r][c] == 'A') return 1;
        if (A[r][c] == '/') swap(dr, dc);
        if (A[r][c] == '\\') {
            swap(dr, dc);
            dr = -dr, dc = -dc;
        }
        r += dr;
        c += dc;
    }
    return 0;
}

int main() {
    cin >> N;
    int a, b; cin >> a >> b;
    rows.push_back(0); cols.push_back(0);
    rows.push_back(a); cols.push_back(b);
    for (int i = 0; i < N; ++i) {
        int r, c; char t; cin >> r >> c >> t;
        pts.push_back({r, c, t});
        rows.push_back(r); cols.push_back(c);
    }
    sort(begin(rows), end(rows));
    sort(begin(cols), end(cols));
    R = rows.size(), C = cols.size();
    for (int r = 0; r < R; ++r) rm[rows[r]] = r;
    for (int c = 0; c < C; ++c) cm[cols[c]] = c;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            A[r][c] = '.';
        }
    }
    a = rm[a], b = cm[b];
    A[a][b] = 'A';
    for (auto [r, c, t]: pts) {
        A[rm[r]][cm[c]] = t;
    }
    A[rm[0]][cm[0]] = 'H';
    if (sol(rm[0], cm[0], 1, 0)) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < N; ++i) {
        auto [r, c, t] = pts[i];
        r = rm[r], c = cm[c];
        A[r][c] = t == '/' ? '\\' : '/';
        if (sol(rm[0], cm[0], 1, 0)) {
            cout << i+1 << endl;
            return 0;
        }
        A[r][c] = t;
    }
    cout << -1 << endl;
}