#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int N, R, C, D[MAXN][2]{};
string S;
vector<vector<int>> A;

int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};

void bfs(int r1, int c1) {
    queue<int> Q;
    Q.push(r1*C+c1);
    while (Q.size()) {
        int r = Q.front()/C, c = Q.front()%C;
        Q.pop();
        for (int d = 0; d < 4; ++d) {
            int i = r+dr[d], j = c+dc[d];
            if (i < 0 || i >= R || j < 0 || j >= C || A[i][j]) continue;
            A[i][j] = 1;
            Q.push(i*C+j);
        }
    }
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'N') D[i][0] = 1;
        if (S[i] == 'S') D[i][0] = -1;
        if (S[i] == 'E') D[i][1] = 1;
        if (S[i] == 'W') D[i][1] = -1;
    }
    int a = 0, b = 0, am = 0, aM = 0, bm = 0, bM = 0;
    for (int i = 0; i < N; ++i) {
        a += 2*D[i][0];
        b += 2*D[i][1];
        am = min(am, a);
        aM = max(aM, a);
        bm = min(bm, b);
        bM = max(bM, b);
    }
    R = aM-am+3, C = bM-bm+3;
    A = vector<vector<int>>(R, vector<int>(C));
    a = -am+1, b = -bm+1;
    A[a][b] = 1;
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < 2; ++k) {
            a += D[i][0];
            b += D[i][1];
            A[a][b] = 1;
        }
    }
    int res = -1;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            if (A[r][c]) continue;
            ++res;
            bfs(r, c);
        }
    }
    cout << res << endl;
}