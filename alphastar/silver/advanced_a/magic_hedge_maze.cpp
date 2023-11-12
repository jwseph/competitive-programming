#include <bits/stdc++.h>
using namespace std;

#define MAXN 300

int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};

int R, C;
string A[MAXN];
unordered_map<char, int> M;
unordered_map<int, int> P;
queue<int> Q;
bool V[MAXN][MAXN]{};

int main() {
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        cin >> A[r];
        for (int c = 0; c < C; ++c) {
            char X = A[r][c];
            if ('A' <= X && X <= 'Z') {
                if (M.find(X) != M.end()) {
                    int p = M[X];
                    P[r*C+c] = p;
                    P[p] = r*C+c;
                }
                M[X] = r*C+c;
            }
            if (X == '@') {
                Q.push(r*C+c);
                V[r][c] = 1;
            }
        }
    }
    for (int res = 0;; ++res) {
        for (int qs = Q.size(); qs > 0; --qs) {
            int r = Q.front()/C, c = Q.front()%C;
            Q.pop();
            if (A[r][c] == '=') {
                cout << res << endl;
                return 0;
            }
            for (int d = 0; d < 4; ++d) {
                int i = r+dr[d], j = c+dc[d];
                if (i < 0 || i >= R || j < 0 || j >= C || V[i][j] || A[i][j] == '#') continue;
                V[i][j] = 1;
                if ('A' <= A[i][j] && A[i][j] <= 'Z') {
                    Q.push(P[i*C+j]);
                    continue;
                }
                Q.push(i*C+j);
            }
        }
    }
}