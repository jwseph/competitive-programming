// Not sure why DFS has segfault (see counting_acorns.cpp), but BFS seems to work.

#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000

int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};

int N;
bool A[MAXN][MAXN];

void sol(int r1, int c1) {
    queue<int> Q;
    A[r1][c1] = 0;
    Q.push(r1*N+c1);
    while (Q.size()) {
        int r = Q.front()/N, c = Q.front()%N;
        Q.pop();
        for (int d = 0; d < 4; ++d) {
            int i = r+dr[d], j = c+dc[d];
            if (i < 0 || i >= N || j < 0 || j >= N || !A[i][j]) continue;
            A[i][j] = 0;
            Q.push(i*N+j);
        }
    }
}

int main() {
    cin >> N;
    for (int r = 0; r < N; ++r) {
        string S; cin >> S;
        for (int c = 0; c < N; ++c) {
            A[r][c] = S[c] == '*';
        }
    }
    int res = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            if (!A[r][c]) continue;
            ++res;
            sol(r, c);
        }
    }
    cout << res << endl;
}