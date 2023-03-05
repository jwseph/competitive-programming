#include <bits/stdc++.h>
using namespace std;

#define N_MAX 5

int D[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int N, res = 0;
string A[N_MAX];
bool V[N_MAX][N_MAX];

void dfs(int r, int c, int a, int b) {
    if (!(0 <= r && r < N && 0 <= c && c < N) || V[r][c]) return;
    if (b > 0 && A[r][c] != '>') return;
    V[r][c] = true;
    if (A[r][c] == '<') ++a;
    if (A[r][c] == '>') ++b;
    if (a == b) {
        res = max(res, a+b);
    }
    for (auto& p: D) {
        dfs(r+p[0], c+p[1], a, b);
    }
    V[r][c] = false;
}

int main() {
    cin >> N;
    for (int r = 0; r < N; ++r) {
        cin >> A[r];
    }
    dfs(0, 0, 0, 0);
    cout << res << endl;
}